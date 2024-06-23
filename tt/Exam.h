/*
 * Exam.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef EXAM_H_
#define EXAM_H_

#include <iostream>
#include "funcs.h"
#include "Time.h"
#include "Course.h"
class Exam {
    long ObjectID;
    long time;
    long course;
    float mark;
    int maxMark;
public:
    long getObjectID() const { return ObjectID; }
    void setObject(long);
    Exam(long t = -1, long c = -1, float m = 0, int mm = 0);
    long getTime() const;
    void setTime(long t);
    long getCourse() const;
    void setCourse(long c);
    float getMark() const;
    void setMark(float m);
    int getMaxMark() const;
    void setMaxMark(int mm);
    friend std::ostream &operator<<(std::ostream &os, const Exam &Exam);
    friend std::istream &operator>>(std::istream &is, Exam &Exam);
};






#endif /* EXAM_H_ */
