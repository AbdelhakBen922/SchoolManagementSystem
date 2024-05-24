#include "Course.h"
#include "Slide.h"
#include <algorithm>
#include "SchoolManagementSystem.h"
using std::string;
using std::vector;
Course::Course(string N, vector<Slide> S, int NoT , int coeff )
{
    ObjectID = GetNewID("Course");
    setName(N);
    setSlide(S);
    setNumOfTests(NoT);
    setCoeff(coeff);
}
int Course::getCoeff() const
{
    return coeff;
}

void Course::setCoeff(int c)
{
    coeff = (c > 0 && c <= 7) ? c : 0;
}

const std::string &Course::getName() const
{
    return name;
}

void Course::setName(const std::string &n)
{
    if (NameValid(n))
        name = n;
    else
        name = "";
}

int Course::getNumOfTests() const
{
    return numOfTests;
}

void Course::setNumOfTests(int num)
{
    numOfTests = (num > 0 && num < 5) ? num : 1;
}
void Course::setSlide(vector<Slide> &S)
{
    for (Slide s : S)
    {
        if (!CheckFile(s.getFilePath()) || !NameValid(s.getTitle()))
        {
            auto it = std::find(S.begin(), S.end(),s);

            if (it != S.end())
            {
                S.erase(it);
            }
        }
    }
    program = S;
}
const vector<Slide> *Course::getSlide() const
{
    return &program;
}
std::ostream &operator<<(std::ostream &os, const Course &course)
{
    os << course.ObjectID << "\n";
    os << course.coeff <<"\n" << course.name << "\n" << course.numOfTests << "\n";
    os << course.program.size() << "\n";
    for (const auto &slide : course.program)
    {
        os << slide << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Course &course)
{
    is >> course.ObjectID;
    is >> course.coeff >> course.name >> course.numOfTests;
    size_t programSize;
    is >> programSize;
    course.program.clear();
    Slide tempSlide;
    for (size_t i = 0; i < programSize; ++i)
    {
        is >> tempSlide;
        course.program.push_back(tempSlide);
    }
    return is;
}

