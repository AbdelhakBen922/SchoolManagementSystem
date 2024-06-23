/*
 * Year.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef YEAR_H_
#define YEAR_H_
#include <iostream>
#include <vector>
#include "funcs.h"
#include "Section.h"
using std::vector;
class Year {
    long ObjectID;

public:
    long getObjectID() const { return ObjectID; }
    void setObject(long);
private:
    int yearNumber;
    std::vector<long> sections;
public:
    explicit Year(int y=0);
    void setSections(const std::vector<long> &sections);
    std::vector<long> &getSections();
    int getYearNumber() const;
    void setYearNumber(int y);

    friend std::ostream &operator<<(std::ostream &os, const Year &Year);
    friend std::istream &operator>>(std::istream &is, Year &Year);
};

#endif /* YEAR_H_ */
