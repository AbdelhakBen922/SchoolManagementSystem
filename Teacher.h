#pragma once
#include <iostream>
#include <vector>
#include "Course.h"
#include "Place.h"
#include "Time.h"
#include "Profile.h"

class Time;
class Place;
class Course;
class Profile;

class Teacher : public Profile
{
    std::vector<Course *> coursesTeaching;
    std::string rank;
    Place *officePlace;
    Time *officeHour;

public:
    Teacher(std::string = "", std::string = "", std::string = "", std::string = "", std::string = "", int = 0, long = 0, std::string = "", Place * = nullptr, Time * = nullptr);
    void setCoursesTeaching(const std::vector<Course *> &courses);
    const std::vector<Course *> &getCoursesTeaching() const;
    void setRank(const std::string &rank);
    const std::string &getRank() const;
    void setOfficePlace(Place *place);
    Place *getOfficePlace() const;
    void setOfficeHour(Time *hour);
    Time *getOfficeHour() const;
    friend std::ostream &operator<<(std::ostream &os, const Teacher &Teacher);
    friend std::istream &operator>>(std::istream &is, Teacher &Teacher);
};