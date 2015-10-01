#ifndef ASSEMBLY_ERROR_H
#define ASSEMBLY_ERROR_H

#include <exception>
#include <string>

using namespace std;


class assembly_error : public exception
{
    public:
        /** Default constructor */
        assembly_error(const string &m):message(m){};
        virtual const char* what() const throw();
    protected:
    private:
        string message;
};

#endif // ASSEMBLY_ERROR_H
