#pragma once
#include <iostream>
#include "Profile.h"

class Profile;
class Administrator : public Profile
{
    std::string position;
public:
    Administrator(std::string="", std::string="", std::string="", std::string="", std::string="", std::string="");
    friend std::ostream &operator<<(std::ostream &os, const Administrator &Administrator);
    friend std::istream &operator>>(std::istream &is, Administrator &Administrator);
};
