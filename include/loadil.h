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
 *  \brief LOADiL instruction
 *  \author Alessandro Bugatti
 *
 *  \version
 *  \date  Creazione 2015-09-25
 *  \date  Ultima modifica 2015-09-25
 */

#ifndef LOADIL_H
#define LOADIL_H

#include <string>

using namespace std;

#include "instruction.h"



class LoadiL : public Instruction
{
    public:
        /** \brief LOADiL instruction <br>
         *  LOADiL Rx Val <br>
         *  Val will be stored in the low byte of register x (0..F)
         * \param c The computer where the instruction will be executed
         * \param line Parameters of the instruction
         *
         */
        LoadiL(Computer *c, const string & line);
        /** \brief Execute the instruction
         */
        void execute();
};

#endif // LOADIL_H
