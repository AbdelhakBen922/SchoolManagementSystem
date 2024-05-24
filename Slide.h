#pragma once
#include <iostream>
#include "SchoolManagementSystem.h"
using std::vector;
using std::string;

bool ObjectNew(long,string);


class Slide {

    long ObjectID;

public:
    long getObjectID() const { return ObjectID; }
    void setObject(long)
    {
        if (ObjectNew(ObjectID,"Slide"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    };

private:
    std::string title;
    std::string filePath;

public:
    Slide(string t="",string f="");
    const std::string &getTitle() const;
    void setTitle(const std::string &t);
    const std::string &getFilePath() const;
    void setFilePath(const std::string &path);
    friend std::ostream &operator<<(std::ostream &os, const Slide &Slide);
    friend std::istream &operator>>(std::istream &is, Slide &Slide);
    bool operator==(const Slide&S2)const;
};


