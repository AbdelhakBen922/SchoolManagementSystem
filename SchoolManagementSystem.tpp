#include "SchoolManagementSystem.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <ctime>
#include <chrono>
#include <vector>
#include "func.h"
// Forward declarations

bool CheckFile(const std::string &filePath);
bool isLeapYear(int year);
int getNumOfDay(int month, int year);
int GetDayOfWeek(int day, int month, int year);


bool NameValid(string N)
{
    for (int i = 0; i < N.length(); i++)
    {
        if (!isalpha(N[i]))
            return true;
    }
    return false;
}

bool ObjectNew(long id, string type)
{
    ifstream file("Objects.txt");
    string line;
    while (getline(file, line))
    {
        if (line == type + to_string(id))
            return false;
    }
    return true;
}
long GetNewID(string type)
{
    ifstream file("Objects.txt");
    string line;
    long id = 0;
    while (getline(file, line))
    {
        if (line.substr(0, type.length()) == type)
        {
            id = stol(line.substr(type.length())) + 1;
        }
    }
    return id;
}


bool isLeapYear(int year)
{
    // A leap year is divisible by 4, but years divisible by 100 are not leap years,
    // unless they are also divisible by 400.
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            return (year % 400 == 0);
        }
        else
        {
            return true;
        }
    }
    return false;
}

int getNumOfDay(int month, int year)
{
    switch (month)
    {
    case 1:
        return 31; // January
    case 2:
        return isLeapYear(year) ? 29 : 28; // February
    case 3:
        return 31; // March
    case 4:
        return 30; // April
    case 5:
        return 31; // May
    case 6:
        return 30; // June
    case 7:
        return 31; // July
    case 8:
        return 31; // August
    case 9:
        return 30; // September
    case 10:
        return 31; // October
    case 11:
        return 30; // November
    case 12:
        return 31; // December
    default:
        std::cerr << "Invalid month. Please enter a valid month (1-12)." << std::endl;
        return -1; // Return an error code for invalid month
    }
}
int GetDayOfWeek(int day, int month, int year)
{
    // Structure to hold the specific day
    tm timeStruct = {};
    timeStruct.tm_year = year - 1900; // Year since 1900
    timeStruct.tm_mon = month - 1;    // Month, from 0 (January) to 11 (December)
    timeStruct.tm_mday = day;         // Day of the month

    // Make time
    time_t specificDay = mktime(&timeStruct);

    // Extract day of the week
    tm *dayInfo = localtime(&specificDay);
    int dayOfWeek = dayInfo->tm_wday; // Day of week, 0=Sunday, 1=Monday, ..., 6=Saturday

    return dayOfWeek;
}
bool CheckFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    return file.good();
}
template <class V>V* getObject(long id){
    vector<V*> objects = GetPointers<V>(getSchool());
    for (V* object : objects){
        if (object->getObjectID() == id){
            return object;
        }
    }
    return nullptr;
}
