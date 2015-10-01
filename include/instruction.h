#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <vector>

using namespace std;

#include "computer.h"
#include "utils.h"

class Instruction
{
    public:
        /** Default constructor */
        Instruction(Computer *c, const string& line):computer(c)
        {
            parameters_str = line;
            parameters = Utils::split(line);
        };
        virtual void execute() = 0;
    protected:
        Computer *computer;
        vector <string> parameters;//< A string containing parameters for the instruction
        string parameters_str;//< The parameters as a string
    private:
};

#endif // INSTRUCTION_H
