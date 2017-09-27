#include <sstream>

using namespace std;

#include "computer.h"
#include "program.h"

Computer::Computer(unsigned int m)
{
    memory_size = m;
    memory = new uint8_t[memory_size];
    //Creating 16 generic registers

    //Here from R0 to R9
    for (int i = 0; i <= 9; i++)
    {
        stringstream str;
        str << "R" << i;
        registers[str.str()] = 0;
    }
    //Here from RA to RF
    for (char i = 'A'; i <= 'F'; i++)
    {
        stringstream str;
        str << "R" << i;
        registers[str.str()] = 0;
    }
}

void Computer::setRegisterValue(const string& name, unsigned int value)
{
    registers[name] = value;
}

unsigned int Computer::getRegisterValue(const string& name) const
{
    return registers.at(name);
}

uint8_t Computer::getMemoryValue(unsigned int address) const
{
    return memory[address];
}

void Computer::setMemoryValue(unsigned int address, uint8_t value)
{
    memory[address] = value;
}

void Computer::loadProgram(const string& filename)
{
    program = new Program(this,filename);
    PC = 0;
    running = true;
}

void Computer::run()
{
    program->execute();
}

bool Computer::containsLabel(const string& label) const
{
    if (labels.find(label) != labels.end())
        return true;
    return false;
}

void Computer::updatePC(const string& label)
{
    if (labels.find(label) == labels.end())
        throw runtime_error("Label not found in branch");
    PC = labels[label];
}

void Computer::setLabel(const string& label, unsigned int line_number)
{
    labels[label] = line_number;
}

vector<pair<string,unsigned int>> Computer::getRegisters(unsigned int from, unsigned int to)
{
    vector<pair<string,unsigned int>> temp;
    for (unsigned int i = from; i <= to; i++)
    {
        stringstream str;
        str << "R" << i;
        temp.push_back(make_pair(str.str(), registers[str.str()]));
    }
    return temp;
}

vector<pair<unsigned int,uint8_t>> Computer::getMemory(unsigned int from,unsigned int to)
{
    vector<pair<unsigned int,uint8_t>> temp;
    for (unsigned int i = from; i <= to; i++)
        temp.push_back(make_pair(i, getMemoryValue(i)));
    return temp;
}



