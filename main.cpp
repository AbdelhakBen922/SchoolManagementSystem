#include "Administrator.h"
#include "Course.h"
#include "Date.h"
#include "Exam.h"
#include "Group.h"
#include "Place.h"
#include "Profile.h"
#include "SCourse.h"
#include "Schedule.h"
#include "School.h"
#include "SchoolManagementSystem.h"
#include "Section.h"
#include "Semestre.h"
#include "Session.h"
#include "Slide.h"
#include "Student.h"
#include "Teacher.h"
#include "Time.h"
#include "Year.h"
#include "func.h"
#include <iostream>
#include "School.h"

int main() {
    // Create a new school
    School school(true);
    setSchool(&school);
    // Add some data to the school
    Year year1(1);
    school.AddYear(year1);

    Section section1(&year1, 1);
    school.AddSection(section1);

    Group group1(1, &section1, nullptr);
    school.AddGroup(group1);

    Student student1;
    school.AddStudent(student1);

    // Print the school data
    std::cout << school;

    // Add more data to the school
    Year year2(2);
    school.AddYear(year2);

    Section section2(&year2, 2);
    school.AddSection(section2);

    Group group2(2, &section2, nullptr);
    school.AddGroup(group2);

    Student student2;
    school.AddStudent(student2);

    // Print the updated school data
    std::cout << school;

    // Remove some data from the school
    school.RemoveYear(1);
    school.RemoveSection(1);
    school.RemoveGroup(1);
    school.RemoveStudent(1);

    // Print the final school data
    std::cout << school;

    return 0;
}