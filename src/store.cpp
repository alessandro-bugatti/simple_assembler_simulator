#include <iostream>

#include "store.h"
#include "utils.h"
#include "assembly_error.h"
#include "computer.h"

Store::Store(Computer *c, const string & line):Instruction(c, line)
{
    if (parameters.size() != 2)
        throw assembly_error("Wrong numbers of parameters in STORE " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(0)))
        throw assembly_error("The first parameter in STORE doesn't seem a valid register: STORE " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(1)))
        throw assembly_error("The second parameter in STORE doesn't seem a valid register: STORE " + parameters_str);
}


void Store::execute()
{
    uint16_t value, address;
    address = computer->getRegisterValue(parameters.at(0));
    value = computer->getRegisterValue(parameters.at(1));;
    computer->setMemoryValue(address,value & 0x00FF);
    computer->setMemoryValue(address + 1,(value & 0xFF00)>>8);
    /*16 bit version, outdated
    computer->setMemoryValue(address,value);
    */
    computer->incrementPC();
}
