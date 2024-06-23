/*
 * Teacher.h
 *
 *  Created on: Jun 11, 2024
 *      Author: kali9
 */

#ifndef TEACHER_H_
#define TEACHER_H_

#include "Profile.h"

class Teacher : public Profile
{
    std::vector<long > coursesTeaching;
    std::string rank;
    long officePlace;
    long officeHour;

public:
    Teacher(std::string = " ", std::string = " ", std::string = " ", std::string = " ", std::string = " ", int = 0, long = 0, std::string = " ", long =-1, long =-1);
    ~Teacher();
    void setCoursesTeaching(const std::vector<long> &courses);
    const std::vector<long> &getCoursesTeaching() const;
    void setRank(const std::string &rank);
    const std::string &getRank() const;
    void setOfficePlace(long place);
    long getOfficePlace() const;
    void setOfficeHour(long hour);
    long getOfficeHour() const;
    friend std::ostream &operator<<(std::ostream &os, const Teacher &Teacher);
    friend std::istream &operator>>(std::istream &is, Teacher &Teacher);
};

#endif /* TEACHER_H_ */
