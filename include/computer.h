/*
  Copyright (C) 2008 Alessandro Bugatti (alessandro.bugatti@istruzione.it)

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
 *  \brief
 *  \author Alessandro Bugatti
 *
 *  \version 0.1
 *  \date  Creazione 2015-09-25
 *  \date  Ultima modifica 2015-09-25
 */

#ifndef COMPUTER_H
#define COMPUTER_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class Program;

class Computer
{
    public:
        /** Default constructor */
        Computer(unsigned int memory_size = 65535);
        unsigned int getRegisterValue(const string& name) const;
        void setRegisterValue(const string& name, unsigned int value);
        uint8_t getMemoryValue(unsigned int address) const;
        void setMemoryValue(unsigned int address, uint8_t value);
        /** \brief
         *  Load a program in memory from a file, set the Program Counter to 0 and the state to running
         * \param filename The name of the file loaded
         * \exception Throw a runtime_error exception if it is not possible
         * to open the file
         * \exception Throw a assembly_error exception if the source code inside the file contains errors
         */
        void loadProgram(const string& filename);
        void run();
        bool containsLabel(const string& label) const;
        void setLabel(const string & label, unsigned int line_number);
        void updatePC(const string& label);
        void incrementPC(){PC++;}
        unsigned int getPC() const {return PC;}
        bool isRunning() const {return running;}
        void stopRunning(){running = false;}
        vector<pair<string,unsigned int>> getRegisters(unsigned int from,
                                                       unsigned int to);
        vector<pair<unsigned int,uint8_t>> getMemory(unsigned int from,
                                                          unsigned int to);
    protected:
    private:
        unsigned int memory_size; //!< The size of the memory
        uint8_t *memory;
        map<string,unsigned int> registers;
        map<string,unsigned int> labels;
        unsigned PC; ///< Program Counter
        bool running;
        Program *program;
};

#endif // COMPUTER_H
