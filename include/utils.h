#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Utils
{
    public:
        /** Default constructor */
        Utils();
        static vector <string> split(const string& s);
        static bool isRegisterValue(const string& s);
        static bool isAddressValue(const string& s);
        /** \brief
         * Check if two string are equals in respect to a criteria
         * \param s1 The first string
         * \param s2 The second string
         * \return True if they are equals, false otherwise
         * \note This method is useful because you can change the definition
         * of "equals" (for example to be case-insensitive) and you have not to modify the client code
         */

        static bool areEquals(const string& s1, const string& s2);
    protected:
    private:

};

#endif // UTILS_H
