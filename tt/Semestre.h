/*
 * Semestre.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef SEMESTRE_H_
#define SEMESTRE_H_
#include <iostream>
#include "Course.h"
#include "Year.h"
#include "funcs.h"


class Semestre {
    long ObjectID;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long);

private:
    long year;
    int semesterNumber;

    std::vector<long> courses;

public:
    Semestre(long y=-1, int sn=0);
    void setCourses(const std::vector<long> &courses);
    std::vector<long> & getCourses();

    int getSemesterNumber() const;
    void setSemesterNumber(int sn);
    friend std::ostream &operator<<(std::ostream &os, const Semestre &Semestre);
    friend std::istream &operator>>(std::istream &is, Semestre &Semestre);
};



#endif /* SEMESTRE_H_ */
