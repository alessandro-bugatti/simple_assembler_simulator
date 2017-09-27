/*
  Copyright (C) 2015 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

/*! \file
 *  \brief PRINT instruction
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione 2017-09-24
 *  \date  Ultima modifica 2017-09-24
 */

#ifndef PRINT_H
#define PRINT_H

#include <string>

using namespace std;

#include "instruction.h"

class Print : public Instruction
{
    public:
        /** \brief PRINT instruction

         This instruction has been added only to allow 
         some form of printing to improve assembler usability
         and debugging.
         The parameter can be both a register and a memory address
         PRINT Rx | Mem
         
         * \param c The computer where the instruction will be executed
         * \param line Parameters of the instruction
         *
         */
        Print(Computer *c, const string & line);
        /** \brief Execute the instruction
         */
        void execute();
};

#endif // PRINT_H
