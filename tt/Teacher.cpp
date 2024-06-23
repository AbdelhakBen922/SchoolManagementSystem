/*
 * Teacher.cpp
 *
 *  Created on: Jun 11, 2024
 *      Author: kali9
 */


#include "Teacher.h"
#include <iostream>
#include "fstream"
#include <string>
#include <vector>
#include "funcs.h"

Teacher::Teacher(std::string firstName, std::string familyName, std::string email, std::string phone, std::string photo, int age, long id, std::string rank, long officePlace, long officeHour)
    : Profile(firstName, familyName, email, phone, photo, age, id), rank(rank), officePlace(officePlace), officeHour(officeHour)
{
	ObjectID=GetNewID("Teacher");
}

void Teacher::setCoursesTeaching(const std::vector<long> &courses)
{
    coursesTeaching = courses;
}

const std::vector<long> &Teacher::getCoursesTeaching() const
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

void Teacher::setOfficePlace(long place)
{
    officePlace = place;
}

long Teacher::getOfficePlace() const
{
	return officePlace;
}

void Teacher::setOfficeHour(long hour)
{
    officeHour = hour;
}

long Teacher::getOfficeHour() const
{
    return officeHour;
}

std::ostream &operator<<(std::ostream &os, const Teacher &teacher)
{
    os << static_cast<const Profile &>(teacher) << "\n";
    os << teacher.rank << "\n";
    os << teacher.officePlace<< "\n";
    os << teacher.officeHour << "\n";
    for (auto &course : teacher.coursesTeaching)
    {
        os << course << "\n";
    }
    return os;
}
std::istream &operator>>(std::istream &is, Teacher &teacher)
{
    is >> static_cast<Profile &>(teacher);
    is >> teacher.rank;
    is >> teacher.officePlace ;
    is >> teacher.officeHour;
    return is;
}


Teacher::~Teacher(){
};





//
//std::ifstream infos("Places.txt");
//    std::string line;
//    bool isObject=false;
//    bool isID=false;
//    int i=0;
//    while(getline(infos,line)){
//    	if(isObject)i++;
//
//    	if(isID){
//    		if (officePlace ==int(line))isObject=true;}
//    	if (line=="/*******************/")isID=!true;
//
//    	if(i==1)return line;
//
//    }
//    return "";
//}
