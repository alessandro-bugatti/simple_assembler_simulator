#include <iostream>
#include "load.h"
#include "assembly_error.h"

Load::Load(Computer* c, const string& line):Instruction(c,line)
{
    if (parameters.size() != 2)
        throw assembly_error("Wrong numbers of parameters in LOAD " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(0)))
        throw assembly_error("The first parameter in LOAD doesn't seem a valid register: LOAD " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(1)))
        throw assembly_error("The second parameter in LOAD doesn't seem a valid address: LOAD " + parameters_str);
}

void Load::execute()
{
    unsigned int value;
    uint16_t low = computer->getMemoryValue(computer->getRegisterValue(parameters.at(1)));
    uint16_t high = computer->getMemoryValue(computer->getRegisterValue(parameters.at(1))+1);
    value = low | (high << 8);
    computer->setRegisterValue(parameters.at(0),value);
    /*16 bit version, outdated
    computer->setRegisterValue(parameters.at(0),
                                   computer->getMemoryValue(computer->getRegisterValue(parameters.at(1))));
    */
    computer->incrementPC();
}

