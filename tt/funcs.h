/*
 * funcs.h
 *
 *  Created on: Jun 11, 2024
 *      Author: kali9
 */

#ifndef FUNCS_H_
#define FUNCS_H_

#include<string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <openssl/sha.h>
#include <openssl/rand.h>

bool ObjectNew(long,std::string);
long GetNewID(std::string);

bool isLeapYear(int year);

bool NameValid(std::string);
int getNumOfDay(int month, int year);
int GetDayOfWeek(int day, int month, int year);
bool CheckFile(const std::string &filePath);
void RemoveID(std::string Object,long id);
template<class T> std::string TypeToString(T t){
    // avoiding first integer number which represent the length
    std::string s = typeid(t).name();
    std::size_t i = 0;

    // Skip leading digits
    while (i < s.length() && std::isdigit(s[i])) {
        ++i;
    }

    // Return the substring from the first non-digit character
    return s.substr(i);
}
void RemoveEntryFromFile(std::string type,long id);
template<class Type>void RemoveObject(Type &o){
	std::string type=TypeToString(o);
	long id=o.getObjectID();
	RemoveID(type,id);
	RemoveEntryFromFile(type,id);
}
template<typename T>
T GetObject(long id) {
    T Object;
    if (id<0)return Object;
    std::string type = TypeToString(Object);
    std::ifstream File(type + "s.txt");
    std::ofstream temp("temp.txt");
    if (!File.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return Object; // Return a default-constructed object
    }
    temp <<"/*******************/"<<std::endl;
    temp << id<<std::endl;
    std::string line;
    while (std::getline(File, line)) {
        if (line == std::to_string(id)) {
            while(std::getline(File, line)){
            	if (line == "/*******************/")break;
            	temp<<line<<std::endl;
            }
            break;
        }
    }
    temp.close();
    File.close();
    std::ifstream tmp("temp.txt");
    tmp >> Object;
    tmp.close();
    remove("temp.txt");
    return Object;
}
template<class T>
void saveToFile(T &a){
	std::ofstream file;
	std::string type=TypeToString(a);
	file.open(type+"s.txt",std::ios::app);
	file <<"/*******************/"<<std::endl;
	file<<a;
	file.close();
}
// Assuming the function is templated to return any object type
template<typename T>
T GetObjectByAttribute(const std::string &fileName, int lineN, const std::string &attribute) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return T();
    }

    std::string line, objectData;
    T object;
    bool readingObject = false;
    int currentLine = 0;
    bool objectFound = false;

    while (std::getline(file, line)) {
        if (line == "/*******************/") {
            if (readingObject) {
                // Finish reading the current object
                if (objectFound) {
                    std::istringstream objStream(objectData);
                    objStream >> object;
                    return object;
                }
                objectData.clear();
            }
            readingObject = true;
            currentLine = 0;
            objectFound = false;
            objectData = line + "\n";
        } else if (readingObject) {
            objectData += line + "\n";
            currentLine++;
            if (currentLine == lineN && line == attribute) {
                objectFound = true;
            }
        }
    }

    // Check the last object
    if (readingObject && objectFound) {
        std::istringstream objStream(objectData);
        objStream >> object;
        return object;
    }

    std::cerr << "Error: Object not found." << std::endl;
    return object;
}// Function to return the last word of a given line
std::string getLastWord(const std::string& line);
void Clean(std::string);
void CleanALL();
std::string RemoveSuffix(const std::string& str, const std::string suffix);
bool FoundLine(const std::string &fileName, const std::string &searchString);
std::string bytesToHex(const unsigned char* bytes, int length);
std::string generateSalt(int length);
std::string hashPassword(const std::string& password, const std::string& salt);
void registerUser(const std::string fileName,const std::string& username, const std::string& password);
bool verifyPassword(const std::string fileName,const std::string& username, const std::string& password);
#endif /* FUNCS_H_ */
