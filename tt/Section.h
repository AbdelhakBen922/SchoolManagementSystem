/*
 * Section.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef SECTION_H_
#define SECTION_H_

#pragma once
#include <iostream>
#include <vector>
#include "Group.h"
#include "funcs.h"

#include "Year.h"
using std::vector;
class Section {

    long ObjectID;

public:
    long getObjectID() const { return ObjectID; }
    void setObject(long);

private:
    int sectionNumber;
    long year;
    std::vector<long > groups;

public:
    Section(long y=-1, int sn=0);
    void setGroups(vector<long>);
    long getYear()const;
    int getSectionNumber() const;
    void setSectionNumber(int sn);
    friend std::ostream &operator<<(std::ostream &os, const Section &Section);
    friend std::istream &operator>>(std::istream &is, Section &Section);
};



#endif /* SECTION_H_ */
