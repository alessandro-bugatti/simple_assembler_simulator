#ifndef LOADIH_H
#define LOADIH_H

#include <string>

using namespace std;

#include "instruction.h"


class LoadiH : public Instruction
{
    public:
        /** Default constructor */
        LoadiH(Computer *c, const string & line);
        /** @brief (one liner)
          *
          * (documentation goes here)
          */
        void execute();
    protected:
    private:
};

#endif // LOADIH_H
