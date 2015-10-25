using namespace std;

#include "branch.h"
#include "assembly_error.h"

Branch::Branch(Computer *c, const string& line):Instruction(c,line)
{
   if (parameters.size() != 3)
        throw assembly_error("Wrong numbers of parameters in branch " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(0)))
        throw assembly_error("The first parameter in the branch doesn't seem a valid register: Branch " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(1)))
        throw assembly_error("The second parameter in the branch doesn't seem a valid address: Branch " + parameters_str);
    if (!c->containsLabel(parameters.at(2)))
        throw assembly_error("The third parameter is not a valid label: Branch " + parameters_str);
}

void Branch::execute()
{
    if (condition())
        computer->updatePC(parameters.at(2));
    else
        computer->incrementPC();
}


