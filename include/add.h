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
 *  \brief ADD instruction
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione 2015-09-25
 *  \date  Ultima modifica 2015-09-25
 */

#ifndef ADD_H
#define ADD_H

#include <string>

using namespace std;

#include "instruction.h"

class Add : public Instruction
{
    public:
        /** \brief ADD instruction

         This instruction has two forms:
         1. First form: **register/register/register**

            ADD Rx Ry Rz

            The sum of Ry + Rz will be stored in Rx

         2. Second form: **register/register/immediate**

            ADD Rx Ry Val

            The sum of Ry + Val will be stored in Rx


         * \param c The computer where the instruction will be executed
         * \param line Parameters of the instruction
         *
         */
        Add(Computer *c, const string & line);
        /** \brief Execute the instruction
         */
        void execute();
};

#endif // ADD_H
