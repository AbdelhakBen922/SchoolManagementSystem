#include "func.h"
#include "School.h"
#include "Time.h"
#include <ctime>
#include <chrono>
void setSchool(School *s){Myschool=s;}
School *getSchool(){return Myschool;}
Time getcurrentTime()
{
    time_t t=std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    Time CurrentT(t);
    return CurrentT;
}
