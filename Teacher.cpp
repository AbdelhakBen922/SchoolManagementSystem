#include "Profile.h"

#include "Teacher.h"
#include <iostream>
#include <vector>
#include "Course.h"
#include "Place.h"
#include "Time.h"

Teacher::Teacher(std::string firstName, std::string familyName, std::string email, std::string phone, std::string photo, int age, long id, std::string rank, Place *officePlace, Time *officeHour)
    : Profile(firstName, familyName, email, phone, photo, age, id), rank(rank), officePlace(officePlace), officeHour(officeHour)
{
}

void Teacher::setCoursesTeaching(const std::vector<Course *> &courses)
{
    coursesTeaching = courses;
}

const std::vector<Course *> &Teacher::getCoursesTeaching() const
{
    return coursesTeaching;
}

void Teacher::setRank(const std::string &rank)
{
    this->rank = rank;
}

const std::string &Teacher::getRank() const
{
    return rank;
}

void Teacher::setOfficePlace(Place *place)
{
    officePlace = place;
}

Place *Teacher::getOfficePlace() const
{
    return officePlace;
}

void Teacher::setOfficeHour(Time *hour)
{
    officeHour = hour;
}

Time *Teacher::getOfficeHour() const
{
    return officeHour;
}

std::ostream &operator<<(std::ostream &os, const Teacher &teacher)
{
    os << static_cast<const Profile &>(teacher) << "\n";
    os << teacher.rank << "\n";
    os << teacher.officePlace->getObjectID() << "\n";
    os << teacher.officeHour->getObjectID() << "\n";
    for (auto &course : teacher.coursesTeaching)
    {
        os << course->getObjectID() << "\n";
    }
    return os;
}
std::istream &operator>>(std::istream &is, Teacher &teacher)
{
    is >> static_cast<Profile &>(teacher);
    is >> teacher.rank;
    long id;
    is >> id;
    teacher.officePlace = getObject<Place>(id);
    is >> id;
    teacher.officeHour = getObject<Time>(id);
    return is;
}

