#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
using std::string;
using std::vector;



bool CheckFile(const std::string &filePath);
bool ObjectNew(long,string);
long GetNewID(string);
bool NameValid(string N="");
template<class T> string TypeToString(T t){
    // avoiding first integer number which represent the length
    string s = typeid(t).name();
    std::size_t i = 0;
    
    // Skip leading digits
    while (i < s.length() && std::isdigit(s[i])) {
        ++i;
    }
    
    // Return the substring from the first non-digit character
    return s.substr(i);
};


template <class V>V* getObject(long id);
#include "SchoolManagementSystem.tpp"