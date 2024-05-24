#include "Schedule.h"
#include "Teacher.h"
Schedule::Schedule()
{
    setObject(GetNewID("Schedule"));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            timeTable[i][j] = nullptr;
            tutors[i][j] = nullptr;
            places[i][j] = nullptr;
        }
    }
}
Schedule::Schedule(Course *tt[5][6], Teacher *t[5][6], Place *p[5][6])
{
    setObject(GetNewID("Schedule"));
    // Assuming simple direct assignment for illustrative purposes
    std::copy(&tt[0][0], &tt[0][0] + 5 * 6, &timeTable[0][0]);
    std::copy(&t[0][0], &t[0][0] + 5 * 6, &tutors[0][0]);
    std::copy(&p[0][0], &p[0][0] + 5 * 6, &places[0][0]);
}

void Schedule::setCourses(Course *tt[5][6])
{
    std::copy(&tt[0][0], &tt[0][0] + 5 * 6, &timeTable[0][0]);
}

void Schedule::setTutors(Teacher *t[5][6])
{
    std::copy(&t[0][0], &t[0][0] + 5 * 6, &tutors[0][0]);
}

void Schedule::setPlaces(Place *p[5][6])
{
    std::copy(&p[0][0], &p[0][0] + 5 * 6, &places[0][0]);
}
Course *Schedule::getCourse(int day, int hour) const
{
    if ((day < 0 || day >= 5) || (hour < 0 || hour >= 7))
        return nullptr;
    return timeTable[day][hour];
}
Teacher *Schedule::getTeacher(int day, int hour) const
{
    if ((day < 0 || day >= 5) || (hour < 0 || hour >= 7))
        return nullptr;
    return tutors[day][hour];
}
Place *Schedule::getPlace(int day, int hour) const
{
    if ((day < 0 || day >= 5) || (hour < 0 || hour >= 7))
        return nullptr;
    return places[day][hour];
}

std::ostream &operator<<(std::ostream &os, const Schedule &Schedule)
{
    os << Schedule.ObjectID << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            os << Schedule.timeTable[i][j]->getObjectID() << " ";
            os << Schedule.tutors[i][j]->getObjectID() << " ";
            os << Schedule.places[i][j]->getObjectID() << " ";
        }
        os << std::endl;
    }
    return os;
}
std::istream &operator>>(std::istream &is, Schedule &Schedule)
{
    is >> Schedule.ObjectID;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            long courseID, teacherID, placeID;
            is >> courseID >> teacherID >> placeID;
            Schedule.timeTable[i][j]=getObject<Course>(courseID);
            Schedule.tutors[i][j]=getObject<Teacher>(teacherID);
            Schedule.places[i][j]=getObject<Place>(placeID);
        }
    }
    return is;
}
