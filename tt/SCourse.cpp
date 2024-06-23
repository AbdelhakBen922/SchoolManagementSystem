/*
 * SCourse.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "SCourse.h"

SCourse::SCourse(long course): midterm({}), final({})
{
    this->course=course;
    tests=std::vector<Exam >();
    setObject(GetNewID("SCourse"));
}

std::ostream& operator<<(std::ostream &os, const SCourse &SCourse)
{
    os << SCourse.getObjectID() <<std::endl;
    os << SCourse.course <<std::endl;
    os << SCourse.midterm <<std::endl;
    os << SCourse.final <<std::endl;
    for (Exam i : SCourse.tests){
        os << i <<std::endl;
    }
    return os;
}
std::istream& operator>>(std::istream &is, SCourse &SCourse)
{
	std::string ignore;
	std::getline(is,ignore);
    is >> SCourse.ObjectID;
    is>>SCourse.course;
    is >> SCourse.midterm;
    is >> SCourse.final;
    Exam i;
    while(is>>i){
        SCourse.tests.push_back(i);
    }
    return is;

}

void SCourse::setObject(long ObjectID)
    {
        if (ObjectNew(ObjectID ,"Schedule"))
        {
            this->ObjectID = ObjectID;
        }
        else
            ObjectID = 0;
    }
    long SCourse::getCourse()const{return course;};
