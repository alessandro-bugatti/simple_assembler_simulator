#include "utils.h"

Utils::Utils()
{
    //ctor
}

vector <string> Utils::split(const string & s)
{
    vector <string> v;
    istringstream iss(s);
    string sub;
    while (iss >> sub)
        v.push_back(sub);
    return v;
}

bool Utils::isRegisterValue(const string& s)
{
    if (s.at(0) != 'R') return false;
    for (auto i = s.begin()+1; i != s.end();++i)
        if (!isxdigit(*i)) return false;
    return true;
}

bool Utils::isAddressValue(const string& s)
{
    if (s.at(0) != '0' || s.at(1) != 'x') return false;
    for (auto i = s.begin()+2; i != s.end();++i)
        if (!isxdigit(*i)) return false;
    return true;
}

bool Utils::areEquals(const string& s1, const string& s2)
{
    return s1 == s2;
}

bool Utils::containCode(const string& s)
{
    for (auto i: s)
        if (i != ' ' && i != '\t')
            return true;
    return false;
}
