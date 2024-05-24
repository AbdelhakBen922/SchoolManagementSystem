#pragma once
#include <iostream>
#include <vector>
#include "Slide.h"
#include "SchoolManagementSystem.h"
using std::string;
using std::vector;
class Slide ;
template <class V> V*getObject(long);

class Course {
    long ObjectID;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID,"Course"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    }

private:
    int coeff;
    std::string name;
    std::vector<Slide> program;
    int numOfTests;

public:
    Course(string N= "", vector<Slide> S= {}, int NoT = 1, int coeff = 0);
    virtual ~Course() {}
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
