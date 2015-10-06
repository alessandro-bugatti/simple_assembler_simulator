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
 *  \date  Last change 2015-09-29
 *
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include "version.h"
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
    cout << "Assembly simulator 0.1" << endl;
    cout << "Version " << MAJOR << "." << MINOR << "." << BUILD << "." << REVISION
         << " Builds count:" << BUILDS_COUNT << endl;
    cout << "Copyright 2015 - Alessandro Bugatti" << endl;

}

pair <unsigned int, unsigned int> getRange()
{
    unsigned int from, to;
    cout << "From: ";
    cin >> from;
    cout << "To: ";
    cin >> to;
    return make_pair(from,to);
}

int main(int argc, char *argv[])
{
    string filename;
    vector<pair<string,unsigned int>> registers;
    vector<pair<unsigned int, uint8_t>> memory;
    pair<unsigned int, unsigned int> range;
    header();
    chrono::milliseconds timespan(1000); // or whatever
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
        bool passo = true;
        do
        {
            cout << endl;
            if (passo)
            {
                menu();
                cin >> scelta;
                switch(scelta)
                {
                    case 1: //passo = false;
                        c->run();
                        break;
                    case 2: ;
                        cout << "Insert the range to view the values of registers (e.g. from 1 to 5 will show R1, R2, R3, R4, R5)" << endl;
                        range = getRange();
                        registers = c->getRegisters(range.first,range.second);
                        for (auto i: registers)
                            cout << i.first << std::showbase << std::setw(8) <<   hex << (uint16_t)i.second << std::setw(8) << dec << (uint16_t)i.second << endl;
                        break;
                    case 3: ;
                        cout << "Insert the range to view the content of the memory (e.g. from 256 to 512 will show the content of the memory from address 256 to address 512 included)" << endl;
                        range = getRange();
                        memory = c->getMemory(range.first,range.second);
                        for (auto i: memory)
                            cout <<  i.first << std::showbase << std::setw(8) << hex << (unsigned int)i.second << std::setw(8) << dec << (unsigned int)i.second << endl;

                        break;
                }
            }
        }while (scelta != 0);
    }
    catch(assembly_error e)
    {
        cout << e.what() << endl;
    }
    catch(exception e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

