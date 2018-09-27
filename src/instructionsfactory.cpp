#include "instructionsfactory.h"
#include "loadih.h"
#include "loadil.h"
#include "store.h"
#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"
#include "load.h"
#include "move.h"
#include "blt.h"
#include "ble.h"
#include "bgt.h"
#include "bge.h"
#include "beq.h"
#include "bne.h"
#include "b.h"
#include "end.h"
#include "print.h"
#include "computer.h"
#include "utils.h"
#include "assembly_error.h"

#include <iostream>

using namespace std;


InstructionsFactory::InstructionsFactory()
{
    //ctor
}

Instruction* InstructionsFactory::CreateInstruction(Computer *c,const string& line)
{
    vector <string> tokens;
    //Preprocessing to find a label
    tokens = Utils::split(line);
    if (tokens.at(0).back() == ':')
        tokens.erase(tokens.begin());
    string type = tokens.at(0);
    string parameters;
    for (int i = 1; i < tokens.size() ; i++)
    {
        parameters += tokens.at(i) + " ";
    }
    if (!parameters.empty())
        parameters.pop_back();
    if (Utils::areEquals(type,"LOADiL"))
        return new LoadiL(c, parameters);
    if (Utils::areEquals(type,"LOADiH"))
        return new LoadiH(c, parameters);
    if (Utils::areEquals(type,"STORE"))
        return new Store(c, parameters);
    if (Utils::areEquals(type,"ADD"))
        return new Add(c, parameters);
    if (Utils::areEquals(type,"SUB"))
        return new Sub(c, parameters);
    if (Utils::areEquals(type,"MUL"))
        return new Mul(c, parameters);
    if (Utils::areEquals(type,"DIV"))
        return new Div(c, parameters);
    if (Utils::areEquals(type,"LOAD"))
        return new Load(c, parameters);
    if (Utils::areEquals(type,"MOVE"))
        return new Move(c, parameters);
    if (Utils::areEquals(type,"BLT"))
        return new Blt(c, parameters);
    if (Utils::areEquals(type,"BLE"))
        return new Ble(c, parameters);
    if (Utils::areEquals(type,"BGT"))
        return new Bgt(c, parameters);
    if (Utils::areEquals(type,"BGE"))
        return new Bge(c, parameters);
    if (Utils::areEquals(type,"BEQ"))
        return new Beq(c, parameters);
    if (Utils::areEquals(type,"BNE"))
        return new Bne(c, parameters);
    if (Utils::areEquals(type,"B"))
        return new B(c, parameters);
    if (Utils::areEquals(type,"END"))
        return new End(c, parameters);
    if (Utils::areEquals(type, "PRINT"))
        return new Print(c, parameters);
    throw assembly_error("Instruction not found: " + type + " " + parameters );
}
