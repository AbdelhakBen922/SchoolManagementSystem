#include "Administrator.h"
#include "Profile.h"
#include <iostream>
Administrator::Administrator(std::string fn, std::string ln, std::string bd, std::string em, std::string ph, std::string pos) : Profile(fn, ln, bd, em, ph)
{
    position = pos;
}

std::ostream &operator<<(std::ostream &os, const Administrator &Administrator)
{
    os << Profile(Administrator);
    os  << Administrator.position << std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, Administrator &Administrator)
{
    is >> static_cast<Profile&>(Administrator);
    is >> Administrator.position;
    return is;
}

