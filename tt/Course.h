/*
 * Course.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <iostream>
#include <vector>
#include "Slide.h"
#include "funcs.h"
using std::string;
using std::vector;

class Course {
private:
    long ObjectID;
    int coeff;
    std::string name;
    std::vector<Slide> program;
    int numOfTests;

public:
    Course(string N= "", vector<Slide> S= {}, int NoT = 1, int coeff = 0);
    long getObjectID() const { return ObjectID; }
    void setObject(long);
    int getCoeff() const;
    void setCoeff(int coeff);
    const std::string &getName() const;
    void setName(const std::string &name);
    int getNumOfTests() const;
    void setNumOfTests(int num);
    void setSlide(vector<Slide> &);
    const vector<Slide> *getSlide() const;
    friend std::ostream &operator<<(std::ostream &os, const Course &Course);
    friend std::istream &operator>>(std::istream &is, Course &Course);
};


#endif /* COURSE_H_ */
