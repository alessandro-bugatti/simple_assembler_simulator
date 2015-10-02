#include <iostream>

#include "mul.h"
#include "assembly_error.h"

Mul::Mul(Computer* c, const string& line):Instruction(c,line)
{
    if (parameters.size() != 3)
        throw assembly_error("Wrong numbers of parameters in MUL " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(0)))
        throw assembly_error("The first parameter in MUL doesn't seem a valid register: MUL " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(1)))
        throw assembly_error("The second parameter in MUL doesn't seem a valid address: MUL " + parameters_str);
    if (!(Utils::isRegisterValue(parameters.at(2)) ||
        Utils::isAddressValue(parameters.at(2))))
        throw assembly_error("The third parameter in MUL doesn't seem a valid address or value: MUL " + parameters_str);
}

void Mul::execute()
{
    if (Utils::isRegisterValue(parameters.at(2)))
        computer->setRegisterValue(parameters.at(0),
                                   computer->getRegisterValue(parameters.at(1)) *
                                   computer->getRegisterValue(parameters.at(2)));
    else
    {
        stringstream str;
        str << parameters.at(2);
        unsigned int value;
        str >> std::hex >> value;
        computer->setRegisterValue(parameters.at(0),
                                   computer->getRegisterValue(parameters.at(1)) * value);
    }
    computer->incrementPC();
}

