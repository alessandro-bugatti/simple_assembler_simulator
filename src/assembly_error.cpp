#include "assembly_error.h"

const char* assembly_error::what() const throw()
{
    string error = "Assembly error: " + message;
    return error.c_str();
}
