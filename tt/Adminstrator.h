/*
 * Adminstrator.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef ADMINSTRATOR_H_
#define ADMINSTRATOR_H_
#include <iostream>
#include "Profile.h"

class Administrator : public Profile
{
    std::string position;
public:
    Administrator(std::string fn=" ", std::string ln=" ", std::string bd=" ", std::string em=" ", std::string ph=" ",int age= 0, long id= 0, std::string pos=" ");
    friend std::ostream &operator<<(std::ostream &os, const Administrator &Administrator);
    friend std::istream &operator>>(std::istream &is, Administrator &Administrator);
};

#endif /* ADMINSTRATOR_H_ */
