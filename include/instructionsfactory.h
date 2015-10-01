#ifndef INSTRUCTIONSFACTORY_H
#define INSTRUCTIONSFACTORY_H

#include "instruction.h"
/**
 *  \brief Factory for the instruction objects
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione  2015-09-24
 *  \date  Ultima modifica 2015-09-24
 *
 */class InstructionsFactory
{
    public:
     /** \brief
     *
     * \param c Reference to the computer where the instruction will run
     * \param line The raw instruction as extracted from the source code
     * \return The object which models the instruction (e.g. LoadiL, Store,...)
     * \warning At the moment the label has to be a word followed by
     * a colon, without spaces between, otherwise the instruction
     * is considered not correct
     * \warning The instructions have to be written exactly as in the assembly
     * language documentation, because actually the comparison is case-sensitive
     * \todo Would we change the case-sensitive comparison to become case-insensitive?
     */
    static Instruction* CreateInstruction(Computer *c,const string& line);
    protected:
    private:
        /** Default constructor */
        InstructionsFactory();
};

#endif // INSTRUCTIONSFACTORY_H
