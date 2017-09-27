#include <iostream>
#include <iomanip>

#include "print.h"
#include "assembly_error.h"

Print::Print(Computer* c, const string& line):Instruction(c,line)
{
    if (parameters.size() != 1)
        throw assembly_error("Wrong numbers of parameters in PRINT " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(0)) &&
        !Utils::isAddressValue(parameters.at(0)))
        throw assembly_error("The parameter in PRINT doesn't seem a register nor a memory address: PRINT " + parameters_str);
}

void Print::execute()
{
    int width = 10;
    int width_s = 5;
    if (Utils::isRegisterValue(parameters.at(0)))
        cout << std::left << std::setw(width) << (parameters.at(0) + " ->") 
        << std::setw(width_s) << "hex: " << std::setw(width) << std::hex << computer->getRegisterValue(parameters.at(0)) 
        << std::setw(width_s) << "dec: " << std::setw(width) << std::dec << computer->getRegisterValue(parameters.at(0)) << endl;
    else
    {
        stringstream ss;
        unsigned int address;
        ss << std::hex << parameters.at(0);
        ss >> address;
        cout << std::left << std::setw(width) << (parameters.at(0) + " ->");  
        cout << std::setw(width_s) << "hex: " << std::setw(width)<< std::hex << (unsigned int) computer->getMemoryValue(address)
        << std::setw(width_s) << "dec: " << std::setw(width) << std::dec << (unsigned int) computer->getMemoryValue(address)<< endl;
    }
    computer->incrementPC();
}
