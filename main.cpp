/*
  Copyright (C) 2012 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/*! \file
 *  \brief
 *  \author Alessandro Bugatti
 *
 *  \date  Creation  2015-09-29
 *  \date  Last change 2018-09-15
 *
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <sstream>
#include "version.h"
#include "utils.h"
#include "computer.h"
#include "version.h"
#include "assembly_error.h"

using namespace std;
using namespace AutoVersion;


void menu()
{
    cout << "1) Run" << endl;
    cout << "2) Show registers" << endl;
    cout << "3) Show memory" << endl;
    cout << "0) Exit" << endl;
}

void header()
{
    cout << "Assembly simulator" << endl;
    cout << "Version " << MAJOR << "." << MINOR << "." << BUILD << "." << REVISION
         << " Builds count:" << BUILDS_COUNT << endl;
    cout << "Copyright 2018 - Alessandro Bugatti" << endl;

}

void registers_dump(vector<pair <string, unsigned int>> registers)
{
    const int width = 14;
    const int width_s = width - 2;
    cout << std::setw(width) << "Register |"
    << std::setw(width) << "Value(hex) |"
    << std::setw(width) << "Value(dec) |" << endl;
    for (int i = 0; i < width*3; i++)
        cout << '-';
    cout << endl;
    for (auto i: registers)
        cout << std::showbase << std::setw(width_s) << i.first << " |"
        << std::setw(width_s) << std::hex << (uint16_t)i.second << " |"
        << std::setw(width_s) << std::dec << (uint16_t)i.second << " |" << endl;
}

void memory_dump(vector<pair <unsigned int, unsigned char>> memory)
{
    const int width = 14;
    const int width_s = width - 2;
    cout << std::setw(width) << "Addr(hex) |"
    << std::setw(width) << "Addr(dec) |"
    << std::setw(width) << "Value(hex) |"
    << std::setw(width) << "Value(dec) |" << endl;
    for (int i = 0; i < width*4; i++)
        cout << '-';
    cout << endl;
    for (auto i: memory)
        cout << std::showbase
        << std::setw(width_s) << std::hex << i.first << " |"
        << std::setw(width_s) << std::dec <<  i.first << " |"
        << std::setw(width_s) << std::hex << (unsigned int)i.second << " |"
        << std::setw(width_s) << std::dec << (unsigned int)i.second << " |" <<endl;
}

pair <unsigned int, unsigned int> getRange()
{
    unsigned int from, to;
    string s;
    stringstream ss;
    cout << "From: ";
    cin >> s;
    if (Utils::isAddressValue(s))
    {
        ss << std::hex << s;
        ss >> from;
    }
    else
    {
        ss << std::dec << s;
        ss >> from;
    }
    ss.clear();
    cout << "To: ";
    cin >> s;
    if (Utils::isAddressValue(s))
    {
        ss << std::hex << s;
        ss >> to;
    }
    else
    {
        ss << std::dec << s;
        ss >> to;
    }
    return make_pair(from,to);
}

int main(int argc, char *argv[])
{
    string filename;
    vector<pair<string,unsigned int>> registers;
    vector<pair<unsigned int, uint8_t>> memory;
    pair<unsigned int, unsigned int> range;
    header();
    chrono::milliseconds timespan(500); // or whatever
    this_thread::sleep_for(timespan);
    if (argc != 2)
    {
        cout << "Load file: " ;
        cin >> filename;
    }
    else
        filename = argv[1];
    try{
        Computer *c = new Computer();
        c->loadProgram(filename);
        int scelta = 1;
        do
        {
            cout << endl;
            menu();
            cin >> scelta;
            switch(scelta)
            {
                case 1:
                    c->run();
                    this_thread::sleep_for(timespan);
                    cout << "Finished with success." << endl;
                    break;
                case 2: ;
                    cout << "Insert the range to view the values of registers (e.g. from 1 to 5 will show R1, R2, R3, R4, R5)" << endl;
                    range = getRange();
                    registers = c->getRegisters(range.first,range.second);
                    registers_dump(registers);
                    break;
                case 3: ;
                    cout << "Insert the range to view the content of the memory, the values can be either hex or decimal number (e.g. from 256 (0x100) to 512 (0x200) will show the content of the memory from address 256 (0x100) to address 512 (0x200) included)" << endl;
                    range = getRange();
                    memory = c->getMemory(range.first,range.second);
                    memory_dump(memory);
                    break;
            }
        }while (scelta != 0);
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
        cout << "The program will be terminated." << endl;
        chrono::milliseconds timespan(1000);
        for (int i = 0; i < 5; i++){
            cout << ".";
            this_thread::sleep_for(timespan);
        }
    }

    return 0;
}

