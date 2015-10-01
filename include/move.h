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
 *  \brief MOVE instruction
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione 2015-09-27
 *  \date  Ultima modifica 2015-09-27
 */

#ifndef MOVE_H
#define MOVE_H

#include <instruction.h>


class Move : public Instruction
{
    public:
        /** \brief MOVE instruction

         Copy the content of one register into another

          ** MOVE Rx Ry

         The content of Ry is copied into Rx

         * \param c The computer where the instruction will be executed
         * \param line Parameters of the instruction
         *
         */
        Move(Computer *c, const string& line);
        /** \brief Execute the instruction
         */
        void execute();
    protected:
    private:
};

#endif // MOVE_H
