#include "move.h"
#include "assembly_error.h"


Move::Move(Computer* c, const string& line):Instruction(c,line)
{
    if (parameters.size() != 2)
        throw assembly_error("Wrong numbers of parameters in MOVE " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(0)))
        throw assembly_error("The first parameter in MOVE doesn't seem a valid register: MOVE " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(1)))
        throw assembly_error("The second parameter in MOVE doesn't seem a valid address: MOVE " + parameters_str);
}

void Move::execute()
{
    computer->setRegisterValue(parameters.at(0),
                               computer->getRegisterValue(parameters.at(1)));
    computer->incrementPC();
}
