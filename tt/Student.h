/*
 * Student.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include "Profile.h"

#include <iostream>
#include <vector>
#include <string>

#include "SCourse.h"

#include "Session.h"



class Student: public Profile {

    std::vector<long> absences;

    long group;
    long semestre;

    std::vector<SCourse > courses;

public:
    Student(std::string firstName = " ", std::string familyName = " ", std::string email = " ", std::string phone = " ", std::string Photo = " ", int age = 0, long schoolId = 0, long g = -1,long Semestre=-1);
    Session getSession(Time *t=nullptr);
    std::vector<SCourse*> getCourses()const;
    long getGroup()const;
    long getSemestre()const;
    friend std::ostream &operator<<(std::ostream &os, const Student &Student);
    friend std::istream &operator>>(std::istream &is, Student &Student);
};




#endif /* STUDENT_H_ */
