#include <iostream>

#include "div.h"
#include "assembly_error.h"

Div::Div(Computer* c, const string& line):Instruction(c,line)
{
    if (parameters.size() != 3)
        throw assembly_error("Wrong numbers of parameters in DIV " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(0)))
        throw assembly_error("The first parameter in DIV doesn't seem a valid register: DIV " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(1)))
        throw assembly_error("The second parameter in DIV doesn't seem a valid address: DIV " + parameters_str);
    if (!(Utils::isRegisterValue(parameters.at(2)) ||
        Utils::isAddressValue(parameters.at(2))))
        throw assembly_error("The third parameter in DIV doesn't seem a valid address or value: DIV " + parameters_str);
}

void Div::execute()
{
    if (Utils::isRegisterValue(parameters.at(2)))
        computer->setRegisterValue(parameters.at(0),
                                   computer->getRegisterValue(parameters.at(1)) /
                                   computer->getRegisterValue(parameters.at(2)));
    else
    {
        stringstream str;
        str << parameters.at(2);
        unsigned int value;
        str >> std::hex >> value;
        computer->setRegisterValue(parameters.at(0),
                                   computer->getRegisterValue(parameters.at(1)) / value);
    }
    computer->incrementPC();
}

