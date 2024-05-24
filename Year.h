#pragma once
#include <iostream>
#include <vector>
#include "SchoolManagementSystem.h"
#include "Section.h"
class Section;
using std::string;
using std::vector;
class Year {
    long ObjectID;

public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID,"Year"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    }

private:
    int yearNumber;
    std::vector<Section *> sections;
public:
    explicit Year(int y=0);
    void setSections(const std::vector<Section *> &sections);
    std::vector<Section *> &getSections();
    int getYearNumber() const;
    void setYearNumber(int y);
    friend std::ostream &operator<<(std::ostream &os, const Year &Year);
    friend std::istream &operator>>(std::istream &is, Year &Year);
};
