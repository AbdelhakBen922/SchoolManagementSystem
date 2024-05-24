#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
#include "Year.h"
#include "Group.h"
#include "Section.h"
#include "Schedule.h"
#include "Date.h"
#include "Time.h"
#include "Semestre.h"
#include "Course.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"
#include "Place.h"

// class School;
// class Year;
// class Group;
// class Section;
// class Schedule;
// class Date;
// class Time;
// class Semestre;
// class Course;
// class Student;
// class Teacher;
// class Administrator;
// class Place;

class School {
    long ObjectID;
    std::vector<Year> years;
    std::vector<Group> groups;
    std::vector<Section> sections;
    std::vector<Schedule> timeTables;
    std::vector<Date> calendar;
    std::vector<Time> time;
    std::vector<Course> courses;
    std::vector<Semestre> semestres;
    std::vector<Student> students;
    std::vector<Teacher> tutors;
    std::vector<Administrator> Admins;
    std::vector<Place> places;

public:
    School(bool newSchool = false);

    template <class V>
    friend std::vector<V *> GetPointers(School *);

    template <class V>
    friend V *GetPointers(int, School *);

    template <class V>
    friend V *GetPointers(V &, School *d);

    // Methods for managing the school data
    void SetUpSchool();
    void AddYear(const Year &);
    void AddSection(const Section &);
    void AddGroup(const Group &);
    void AddSchedule(const Schedule &);
    void AddDate(const Date &);
    void AddTime(const Time &);
    void AddSemestre(const Semestre &);
    void AddStudent(const Student &);
    void AddTeacher(const Teacher &);
    void AddAdmin(const Administrator &);
    void AddPlace(const Place &);
    void RemoveYear(int);
    void RemoveSection(int);
    void RemoveGroup(int);
    void RemoveSchedule(int);
    void RemoveDate(int);
    void RemoveTime(int);
    void RemoveSemestre(int);
    void RemoveStudent(int);
    void RemoveTeacher(int);
    void RemoveAdmin(int);
    void RemovePlace(int);
    void UpdateYear(int, const Year &);
    void UpdateSection(int, const Section &);
    void UpdateGroup(int, const Group &);
    void UpdateSchedule(int, const Schedule &);
    void UpdateDate(int, const Date &);
    void UpdateTime(int, const Time &);
    void UpdateSemestre(int, const Semestre &);
    void UpdateStudent(int, const Student &);
    void UpdateTeacher(int, const Teacher &);
    void UpdateAdmin(int, const Administrator &);
    void UpdatePlace(int, const Place &);

    friend bool ObjectNew(long, std::string);
    friend std::ostream &operator<<(std::ostream &os, const School &School);
    friend std::istream &operator>>(std::istream &is, School &School);
};
#include "School.tpp"


