/*
 * Adminstrator.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "Adminstrator.h"

Administrator::Administrator(std::string fn, std::string ln, std::string bd, std::string em, std::string ph,int age, long id, std::string pos) : Profile(fn, ln, bd, em, ph,age,id)
{
    position = pos;
    ObjectID=GetNewID("Administrator");
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
    std::getline(is,Administrator.position);
    return is;
}
