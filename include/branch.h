#ifndef BRANCH_H
#define BRANCH_H

#include "instruction.h"


class Branch : public Instruction
{
    public:
        /** \brief Parent of all branch instructions, only a abstract class


         * \param c The computer where the instruction will be executed
         * \param line Parameters of the instruction
         *
         */
        Branch(Computer *c, const string& line);
        void execute();
        virtual bool condition() = 0;
    protected:
    private:
};

#endif // BRANCH_H
