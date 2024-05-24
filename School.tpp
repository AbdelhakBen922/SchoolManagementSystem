#include "School.h"
#include <vector>
#include "Teacher.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

using namespace std;


School::School(bool newSchool) : students({}), tutors({}), Admins({})
{
    if (newSchool)
        SetUpSchool();
    else
    {
        years = {};
        groups = {};
        sections = {};
        timeTables = {};
        calendar = {};
        time = {};
        semestres = {};
        places = {};
    }
}
void School::SetUpSchool()
{
//     int getNumOfDay(int month, int year);
//     int GetDayOfWeek(int day, int month, int year);
//     for (int i = 0; i < 3; i++)
//     {
//         years.push_back(Year{i + 1});
//         semestres.push_back(Semestre{&years[i], 1});
//         semestres.push_back(Semestre{&years[i], 2});
//         for (int j = 0; j < 3; j++)
//         {
//             sections.push_back(Section{&years[i], j + 1});
//             for (int t = 0; t < 4; t++)
//             {
//                 groups.push_back(Group{j * 4 + t + 1, &sections[j], nullptr});
//             }
//         }
//     }
//     for (int i = 9; i < 17; i++)
//     {

//         int year = (i / 12 == 0) ? 2023 : 2024;
//         int n = getNumOfDay(i % 12 + 1, 2024);
//         for (int j = 0; j < n; j++)
//         {
//             int numOfWeek = GetDayOfWeek(j, i % 12 + 1, year);
//             Date Today{j, n, year};
//             calendar.push_back(Today);
//             if (numOfWeek < 5)
//             {
//                 for (int t = 0; i < 6; i++)
//                 {
//                     time.push_back(Time{&*calendar.end(), t + 1});
//                 }
//             }
//         }
//     }
//     for (int i = 1; i <= 8; i++)
//         places.push_back(Place{"Amphi " + to_string(i)});
//     for (int i = 1; i <= 25; i++)
//         places.push_back(Place{"Tuto " + to_string(i)});
//     for (int i = 1; i <= 9; i++)
//         places.push_back(Place{"Lab " + to_string(i)});
//     for (int i = 1; i <= 9; i++)
//         places.push_back(Place{"Eng Lab " + to_string(i)});
}
void School::AddYear(const Year &y)
{
    years.push_back(y);
};
void School::AddSection(const Section &s)
{
    sections.push_back(s);
}

void School::AddSchedule(const Schedule &s)
{
    timeTables.push_back(s);
}

void School::AddDate(const Date &d)
{
    calendar.push_back(d);
}

void School::AddTime(const Time &t)
{
    time.push_back(t);
}

void School::AddSemestre(const Semestre &s)
{
    semestres.push_back(s);
}
void School::AddGroup(const Group &g)
{
    groups.push_back(g);
}

void School::AddStudent(const Student &s)
{
    students.push_back(s);
}

void School::AddTeacher(const Teacher &t)
{
    tutors.push_back(t);
}

void School::AddAdmin(const Administrator &a)
{
    Admins.push_back(a);
}

void School::AddPlace(const Place &p)
{
    places.push_back(p);
}

void School::RemoveYear(int index)
{
    years.erase(years.begin() + index);
}

void School::RemoveSection(int index)
{
    sections.erase(sections.begin() + index);
}

void School::RemoveGroup(int index)
{
    groups.erase(groups.begin() + index);
}

void School::RemoveSchedule(int index)
{
    timeTables.erase(timeTables.begin() + index);
}

void School::RemoveDate(int index)
{
    calendar.erase(calendar.begin() + index);
}

void School::RemoveTime(int index)
{
    time.erase(time.begin() + index);
}

void School::RemoveSemestre(int index)
{
    semestres.erase(semestres.begin() + index);
}

void School::RemoveStudent(int index)
{
    students.erase(students.begin() + index);
}

void School::RemoveTeacher(int index)
{
    tutors.erase(tutors.begin() + index);
}

void School::RemoveAdmin(int index)
{
    Admins.erase(Admins.begin() + index);
}

void School::RemovePlace(int index)
{
    places.erase(places.begin() + index);
}

void School::UpdateYear(int index, const Year &y)
{
    years[index] = y;
}

void School::UpdateGroup(int index, const Group &g)
{
    groups[index] = g;
}

void School::UpdateSection(int index, const Section &s)
{
    sections[index] = s;
}

void School::UpdateSchedule(int index, const Schedule &s)
{
    timeTables[index] = s;
}

void School::UpdateDate(int index, const Date &d)
{
    calendar[index] = d;
}

void School::UpdateSemestre(int index, const Semestre &s)
{
    semestres[index] = s;
}

void School::UpdateTeacher(int index, const Teacher &t)
{
    tutors[index] = t;
}

void School::UpdateAdmin(int index, const Administrator &a)
{
    Admins[index] = a;
}

void School::UpdatePlace(int index, const Place &p)
{
    places[index] = p;
}

void School::UpdateStudent(int index, const Student &s)
{
    students[index] = s;
}
void School::UpdateTime(int index, const Time &t)
{
    time[index] = t;
}

ostream &operator<<(ostream &os, const School &School)
{
    os << School.students.size() << endl;
    for (auto student : School.students)
    {
        os << student << endl;
    }
    os << School.tutors.size() << endl;
    for (auto tutor : School.tutors)
    {
        os << tutor << endl;
    }
    os << School.Admins.size() << endl;
    for (auto admin : School.Admins)
    {
        os << admin << endl;
    }
    os << School.places.size() << endl;
    for (auto place : School.places)
    {
        os << place << endl;
    }
    os << School.time.size() << endl;
    for (auto t : School.time)
    {
        os << t << endl;
    }
    os << School.calendar.size() << endl;
    for (auto date : School.calendar)
    {
        os << date << endl;
    }
    os << School.semestres.size() << endl;
    for (auto semestre : School.semestres)
    {
        os << semestre << endl;
    }
    os << School.years.size() << endl;
    for (auto year : School.years)
    {
        os << year << endl;
    }
    os << School.sections.size() << endl;
    for (auto section : School.sections)
    {
        os << section << endl;
    }
    os << School.groups.size() << endl;
    for (auto group : School.groups)
    {
        os << group << endl;
    }
    os << School.timeTables.size() << endl;
    for (auto timeTable : School.timeTables)
    {
        os << timeTable << endl;
    }
    return os;
}
istream &operator>>(istream &is, School &School)
{
    int size;
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Student student;
        is >> student;
        School.students.push_back(student);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Teacher tutor;
        is >> tutor;
        School.tutors.push_back(tutor);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Administrator admin;
        is >> admin;
        School.Admins.push_back(admin);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Place place;
        is >> place;
        School.places.push_back(place);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Time t;
        is >> t;
        School.time.push_back(t);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Date date;
        is >> date;
        School.calendar.push_back(date);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Semestre semestre;
        is >> semestre;
        School.semestres.push_back(semestre);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Year year;
        is >> year;
        School.years.push_back(year);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Section section;
        is >> section;
        School.sections.push_back(section);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Group group;
        is >> group;
        School.groups.push_back(group);
    }
    is >> size;
    for (int i = 0; i < size; i++)
    {
        Schedule timeTable;
        is >> timeTable;
        School.timeTables.push_back(timeTable);
    }
    return is;
}

template <class V>
std::vector<V *> GetPointers(School *school) {
    std::vector<V *> Result;
    if constexpr (std::is_same_v<V, Year>) {
        for (Year &i : school->years) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Section>) {
        for (Section &i : school->sections) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Group>) {
        for (Group &i : school->groups) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Course>) {
        for (Course &i : school->courses) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Schedule>) {
        for (Schedule &i : school->timeTables) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Time>) {
        for (Time &i : school->time) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Date>) {
        for (Date &i : school->calendar) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Semestre>) {
        for (Semestre &i : school->semestres) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Student>) {
        for (Student &i : school->students) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Teacher>) {
        for (Teacher &i : school->tutors) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Administrator>) {
        for (Administrator &i : school->Admins) {
            Result.push_back(&i);
        }
    } else if constexpr (std::is_same_v<V, Place>) {
        for (Place &i : school->places) {
            Result.push_back(&i);
        }
    }
    return Result;
}

template <class V>
V *GetPointers(int index, School *school) {
    if constexpr (std::is_same_v<V, Year>) {
        if (index >= 0 && index < school->years.size())
            return &school->years[index];
    } else if constexpr (std::is_same_v<V, Section>) {
        if (index >= 0 && index < school->sections.size())
            return &school->sections[index];
    } else if constexpr (std::is_same_v<V, Group>) {
        if (index >= 0 && index < school->groups.size())
            return &school->groups[index];
    } else if constexpr (std::is_same_v<V, Course>) {
        if (index >= 0 && index < school->courses.size())
            return &school->courses[index];
    } else if constexpr (std::is_same_v<V, Schedule>) {
        if (index >= 0 && index < school->timeTables.size())
            return &school->timeTables[index];
    } else if constexpr (std::is_same_v<V, Time>) {
        if (index >= 0 && index < school->time.size())
            return &school->time[index];
    } else if constexpr (std::is_same_v<V, Date>) {
        if (index >= 0 && index < school->calendar.size())
            return &school->calendar[index];
    } else if constexpr (std::is_same_v<V, Semestre>) {
        if (index >= 0 && index < school->semestres.size())
            return &school->semestres[index];
    } else if constexpr (std::is_same_v<V, Student>) {
        if (index >= 0 && index < school->students.size())
            return &school->students[index];
    } else if constexpr (std::is_same_v<V, Teacher>) {
        if (index >= 0 && index < school->tutors.size())
            return &school->tutors[index];
    } else if constexpr (std::is_same_v<V, Administrator>) {
        if (index >= 0 && index < school->Admins.size())
            return &school->Admins[index];
    } else if constexpr (std::is_same_v<V, Place>) {
        if (index >= 0 && index < school->places.size())
            return &school->places[index];
    }
    return nullptr;
}
template <class V>
V *GetPointers(V &v, School &school) {
    std::vector<V *> Objects = GetPointers<V>(&school);
    for (auto &object : Objects) {
        if (*object == v)
            return object;
    }
    return nullptr;
}
