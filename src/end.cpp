#include "end.h"
#include "assembly_error.h"


End::End(Computer* c, const string& line):Instruction(c, line)
{
   if (parameters.size() != 0)
        throw assembly_error("END doesn't need parameters");
}

void End::execute()
{
    computer->stopRunning();
}
