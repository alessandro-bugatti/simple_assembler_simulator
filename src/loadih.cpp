#include <iostream>

#include "loadih.h"
#include "utils.h"
#include "assembly_error.h"
#include "computer.h"

LoadiH::LoadiH(Computer *c, const string & line):Instruction(c,line)
{
    if (parameters.size() != 2)
        throw assembly_error("Wrong numbers of parameters in LOADhL " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(0)))
        throw assembly_error("The first parameter in LOADhL doesn't seem a valid register: LOADiL " + parameters_str);
    if (!Utils::isAddressValue(parameters.at(1)))
        throw assembly_error("The second parameter in LOADhL doesn't seem a valid address: LOADhL " + parameters_str);
}


void LoadiH::execute()
{
    stringstream str;
    str << parameters.at(1);
    unsigned int value, old_value;
    str >> std::hex >> value;
    old_value = computer->getRegisterValue(parameters.at(0)) & 0x00FF;
    value = (value << 8) | old_value;
    computer->setRegisterValue(parameters.at(0),value);
    computer->incrementPC();
}
