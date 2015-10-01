#ifndef STORE_H
#define STORE_H


#include <string>

using namespace std;

#include <instruction.h>

class Store : public Instruction
{
    public:
        /** Default constructor */
        Store(Computer *c, const string & line);
        /** @brief (one liner)
          *
          * (documentation goes here)
          */
        void execute();
    protected:
    private:
};

#endif // STORE_H
