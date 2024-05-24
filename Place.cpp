#include "Place.h"
#include "func.h"
Place::Place(const std::string &n)  {
    setObject(GetNewID("Place"));
    setName(n);
}

const std::string &Place::getName() const
{
    return name;
}

void Place::setName(const std::string &n)
{
    name = n;
}
Course *Place::currentUse(Schedule *T) const
{
    int day;
    int hour;
    {
        Time T = getcurrentTime();
        day = T.getDate()->getDayOfWeek();
        hour = T.getSessionNumber();
    }
    if (day >= 5 || hour > 7)
        return nullptr;
    return T->getCourse(day, hour - 1);
}
std::ostream& operator<<(std::ostream &os, const Place &Place)
{
    os << Place.ObjectID << std::endl;
    os << Place.name<<std::endl;
    return os;
}
std::istream& operator>>(std::istream &is, Place &Place)
{
    is >> Place.ObjectID;
    is >> Place.name;
    return is;
}