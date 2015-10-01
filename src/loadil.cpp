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

#include <sstream>
#include <iostream>

#include "loadil.h"
#include "utils.h"
#include "assembly_error.h"
#include "computer.h"

LoadiL::LoadiL(Computer *c, const string & line):Instruction(c,line)
{
    if (parameters.size() != 2)
        throw assembly_error("Wrong numbers of parameters in LOADiL " + parameters_str);
    if (!Utils::isRegisterValue(parameters.at(0)))
        throw assembly_error("The first parameter in LOADiL doesn't seem a valid register: LOADiL " + parameters_str);
    if (!Utils::isAddressValue(parameters.at(1)))
        throw assembly_error("The second parameter in LOADiL doesn't seem a valid address: LOADiL " + parameters_str);
}


void LoadiL::execute()
{
    stringstream str;
    str << parameters.at(1);
    unsigned int value, old_value;
    str >> std::hex >> value;
    old_value = computer->getRegisterValue(parameters.at(0)) & 0xFF00;
    value = value | old_value;
    computer->setRegisterValue(parameters.at(0),value);
    computer->incrementPC();
}
