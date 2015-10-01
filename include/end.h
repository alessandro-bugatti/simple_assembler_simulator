#ifndef END_H
#define END_H

#include "instruction.h"


class End : public Instruction
{
    public:
        /** \brief END instruction

            When the program reaches this instruction it ends

         * \param c The computer where the instruction will be executed
         * \param line Parameters of the instruction
         *
         */
        End(Computer* c, const string& line);
        /** \brief Execute the instruction
         */
        void execute();
    protected:
    private:
};

#endif // END_H
