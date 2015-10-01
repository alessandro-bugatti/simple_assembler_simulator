#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>

using namespace std;

#include "instruction.h"
#include "computer.h"

class Program
{
    public:
        /** Default constructor */
        Program(Computer *c, const string& filename);
        void execute();
    protected:
    private:
        vector <Instruction*> instructions;
        Computer *computer;
};

#endif // PROGRAM_H
