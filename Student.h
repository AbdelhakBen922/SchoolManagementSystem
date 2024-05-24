#pragma once
#include <iostream>
#include <vector>
#include "Profile.h"
#include "Time.h"
#include "Year.h"
#include "School.h"
#include "Group.h"
#include "SCourse.h"
#include "Session.h"
class Year;
class Group;
class SCourse;
class Session;
class Profile;


class Student: public Profile {

    std::vector<Time *> absences;
    Year *year;
    Group *group;
    std::vector<SCourse > courses;

public:
    Student(std::string firstName = "", std::string familyName = "", std::string email = "", std::string phone = "", std::string Photo = "", int age = 0, long schoolId = 0, Year *y = nullptr, Group *g = nullptr);
    Session getSession();
    friend std::ostream &operator<<(std::ostream &os, const Student &Student);
    friend std::istream &operator>>(std::istream &is, Student &Student);
};


