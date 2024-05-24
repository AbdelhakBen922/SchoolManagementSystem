#include "SCourse.h"
#include <iostream>

SCourse::SCourse(Course* course): midterm({}), final({})
{   
    this->course=course;
    tests=std::vector<Exam >();
    setObject(GetNewID("SCourse"));
}

std::ostream& operator<<(std::ostream &os, const SCourse &SCourse)
{
    os << SCourse.getObjectID() <<std::endl;
    os << SCourse.midterm <<std::endl;
    os << SCourse.final <<std::endl;
    for (Exam i : SCourse.tests){
        os << i <<std::endl;
    }
    return os;
}
std::istream& operator>>(std::istream &is, SCourse &SCourse)
{
    is >> SCourse.ObjectID;
    long id;
    is >> id;
    SCourse.course= getObject<Course>(id);
    is >> SCourse.midterm;
    is >> SCourse.final;
    Exam i;
    while(is>>i){
        SCourse.tests.push_back(i);
    }
    return is;
    
}