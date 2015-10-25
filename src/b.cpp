using namespace std;

#include "b.h"
#include "assembly_error.h"

B::B(Computer *c, const string& line):Instruction(c,line)
{
   if (parameters.size() != 1)
        throw assembly_error("Wrong numbers of parameters in branch " + parameters_str);
    if (!c->containsLabel(parameters.at(0)))
        throw assembly_error("The parameter is not a valid label: Branch " + parameters_str);
}

void B::execute()
{
    computer->updatePC(parameters.at(0));
}
