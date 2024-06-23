/*
 * Place.h
 *
 *  Created on: Jun 12, 2024
 *      Author: kali9
 */

#ifndef PLACE_H_
#define PLACE_H_

#include <iostream>
#include <string>
#include "funcs.h"

using std::string;

class Place {
    long ObjectID;
    std::string name;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long);
    explicit Place(const std::string &n = " ");
    const std::string &getName() const;
    void setName(const std::string &name);
    long currentUse(long) const;
    friend std::ostream &operator<<(std::ostream &os, const Place &Place);
    friend std::istream &operator>>(std::istream &is, Place &Place);
};



#endif /* PLACE_H_ */
