/*
 * SCourse.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef SCOURSE_H_
#define SCOURSE_H_
#include <iostream>
#include <vector>
#include "funcs.h"
#include "Course.h"
#include "Exam.h"
class Exam;
class SCourse{
private:
    long ObjectID;
    long course;
    float cc;
    Exam midterm;
    Exam final;
    std::vector<Exam > tests;

public:
    SCourse(long course=-1);
    long getObjectID() const { return ObjectID; }
    void setObject(long);
    long getCourse()const;
    friend std::ostream &operator<<(std::ostream &os, const SCourse &SCourse);
    friend std::istream &operator>>(std::istream &is, SCourse &SCourse);
};



#endif /* SCOURSE_H_ */
