/*
 * funcs.cpp
 *
 *  Created on: Jun 11, 2024
 *      Author: kali9
 */

#include "funcs.h"
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <ctime>
#include <random>
#include <iomanip>
#include <filesystem>
#include <boost/uuid/detail/md5.hpp>
#include <boost/algorithm/hex.hpp>

using namespace std;



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
        if (line == type + to_string(id))return false;
    }
    return true;
}
long GetNewID(const std::string type)
{
    std::ifstream file("Objects.txt");
    std::string line;
    long id = 0;
    std::string objectLine;

    // Read the contents of the file and find the last ID associated with the given object type
    while (std::getline(file, line))
    {
        if (line.substr(0, type.length()) == type)
        {
            id = std::stol(line.substr(type.length()));
            objectLine = line;
        }
    }

    // Increment the ID
    id++;

    // Open the file in append mode and add the object and its new ID
    std::ofstream outFile("Objects.txt", std::ios_base::app);
    if (outFile.is_open()) {
        outFile << type << id << std::endl;
        outFile.close();
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }

    // Return the new ID
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
    std::ifstream file(filePath, std::ios::binary);
    return file.good();
}
void RemoveID(std::string Object,long id){
    std::ifstream file("Objects.txt");
    std::ofstream temp("temp.txt",std::ios::app);
    bool found=false;
    std::string line,ID=to_string(id);
    while(std::getline(file,line)){
        if(line.substr(0,Object.length())==Object){
            if(line.substr(Object.length(),ID.length())==ID){
                found=true;
                continue;

            }
        }
        temp<<line<<std::endl;
    }
    file.close();
    temp.close();
    if (found) {
        if (remove("Objects.txt") != 0) {
            std::cerr << "Error: Unable to remove original file." << std::endl;
            return;
        }
        if (rename("temp.txt", "Objects.txt") != 0) {
            std::cerr << "Error: Unable to rename temporary file." << std::endl;
            return;
        }
    } else {
        // Remove the temporary file if the entry was not found
        remove("temp.txt");
    }

}



void RemoveEntryFromFile(std::string type,long id) {
    // Open the file for reading
    std::ifstream inFile(type+"s.txt");
    std::ifstream temp(type+"s.txt");
    // Open a temporary file for writing
    std::ofstream outFile("temp.txt",std::ios::app);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error: Unable to open files for reading/writing." << std::endl;
        return;
    }

    std::string line;
    std::string prev_line;
    bool found = false;
    std::getline(inFile, line);
    bool isID=false;
    prev_line=line;
    // Read each line of the file
    while (std::getline(inFile, line)) {
        // Check if the line contains the ID of the teacher object
        if ( line== std::to_string(id)) {
            isID=true;
            // Skip the ID line and continue reading until the end of the entry
            while (std::getline(inFile, line)) {
                if (line == "/*******************/") {
                    break;
                }
            }
            found = true;
        } else {
            // Write the line to the output file
            if (prev_line == "/*******************/"&&isID){
                isID=false;
                continue;
            }
            outFile << line << std::endl;
        }
        prev_line=line;
    }

    // Close the files
    temp.close();
    inFile.close();
    outFile.close();

    // Remove the original file and rename the temporary file
    if (found) {
        if (remove((type+"s.txt").c_str()) != 0) {
            std::cerr << "Error: Unable to remove original file." << std::endl;
            return;
        }
        if (rename("temp.txt", (type+"s.txt").c_str()) != 0) {
            std::cerr << "Error: Unable to rename temporary file." << std::endl;
            return;
        }
    } else {
        // Remove the temporary file if the entry was not found
        remove("temp.txt");
    }
}

void CleanExactDataDuplicates(std::string fileName) {
    std::ifstream file(fileName);
    std::string type = RemoveSuffix(fileName, "s.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return;
    }

    std::vector<std::string> uniqueObjects;
    std::unordered_map<std::string, std::string> seenData; // Map data to its ID
    std::string line, objectData;
    bool readingObject = false;
    std::string objectID;

    while (std::getline(file, line)) {
        if (line == "/*******************/") {
            if (readingObject) {
                // Finish reading the current object
                std::string objectDataWithoutID = objectData.substr(23+objectID.size()); // Remove the ID from data
                if (seenData.find(objectDataWithoutID) == seenData.end()) {
                    uniqueObjects.push_back(objectData);
                    seenData[objectDataWithoutID] = objectID;
                }
                objectData.clear();
            }
            objectID = "";
            readingObject = true;
            objectData += line + "\n";
        } else if (readingObject) {
            objectData += line + "\n";
            if (objectID.empty()) {
                objectID = line; // The ID is the first line after delimiter
            }
        }
    }
    // Check the last object
    if (readingObject) {
        std::string objectDataWithoutID = objectData.substr(objectID.size() + 1); // Remove the ID from data
        if (seenData.find(objectDataWithoutID) == seenData.end()) {
            uniqueObjects.push_back(objectData);
            seenData[objectDataWithoutID] = objectID;
        }
    }

    file.close();

    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    for (const auto& obj : uniqueObjects) {
        outFile << obj;
    }

    outFile.close();

    std::ifstream Obj("Objects.txt");
    while (std::getline(Obj, line)) {
        if (type == line.substr(0, type.length())) {
            std::string id = line.substr(type.length());
            if (seenData.empty()) {
                RemoveID(type, std::stol(id));
            } else {
                bool found = false;
                for (const auto& [data, storedID] : seenData) {
                    if (storedID == id) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    RemoveID(type, std::stol(id));
                }
            }
        }
    }

    Obj.close();
}
void Clean(std::string fileName) {

    std::ifstream file(fileName);
    std::string type =RemoveSuffix(fileName,"s.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return;
    }

    std::vector<std::string> uniqueObjects;
    std::set<std::string> seenIDs;
    std::string line, objectData;
    bool readingObject = false;
    std::string objectID;

    while (std::getline(file, line)) {
        if (line == "/*******************/") {
            if (readingObject) {
                // Finish reading the current object
                if (seenIDs.find(objectID) == seenIDs.end()) {
                    uniqueObjects.push_back(objectData);
                    seenIDs.insert(objectID);

                }
                objectData.clear();
            }
            objectID="";
            readingObject = true;
            objectData += line + "\n";
        } else if (readingObject) {
            objectData += line + "\n";
            if (objectID.empty()) {
                objectID = line;// The ID is the first line after delimiter

            }
        }
    }
    // Check the last object
    if (readingObject && seenIDs.find(objectID) == seenIDs.end()) {
        uniqueObjects.push_back(objectData);
    }

    file.close();

    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return;
    }

    for (const auto& obj : uniqueObjects) {
        outFile << obj;
    }

    outFile.close();
    std::ifstream Obj("Objects.txt");
    while(std::getline(Obj,line)){
        if (type==line.substr(0,type.length())){
            if (seenIDs.size()==0)RemoveID(type,std::stol(line.substr(type.length())));
            else {
                int i=0;
                for(auto id: seenIDs ){

                    if (id==line.substr(type.length())){
                        break;
                    }
                    i++;
                }
                if (i==seenIDs.size())RemoveID(type,std::stol(line.substr(type.length())));
            }
        }
    }
    Obj.close();
    CleanExactDataDuplicates(fileName);
}

void CleanALL(){
    const std::filesystem::path src{"~/tt/build/Desktop_Qt_6_8_0_64-Debug/"};
    for (auto const& dir_entry : std::filesystem::directory_iterator{src}){
        std::string currentfile=dir_entry.path();
        if(currentfile.substr(10)=="Objects.txt")continue;
        std::string currentType=currentfile.substr(10, currentfile.length()-15);
        if(currentfile.substr(currentfile.length()-5,5)=="s.txt"&&std::filesystem::exists("../../"+currentType+".h")){
            Clean(currentfile.substr(10));
        }
    }

}
std::string RemoveSuffix(const std::string& str, const std::string suffix) {
    if (str.size() >= suffix.size() &&
        str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0) {
        return str.substr(0, str.size() - suffix.size());
    }
    return str; // Return the original string if suffix is not found
}
bool FoundLine(const std::string &fileName, const std::string &searchString) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string FirstString;
        iss>>FirstString;
        if ( FirstString == searchString) {
            return true;
        }
    }

    return false;
}

// Function to convert a byte array to a hexadecimal string
std::string bytesToHex(const unsigned char* bytes, int length) {
    std::ostringstream oss;
    for (int i = 0; i < length; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)bytes[i];
    }
    return oss.str();
}


// Function to generate a random salt
std::string generateSalt(int length) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    std::stringstream ss;
    for (int i = 0; i < length; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << dis(gen);
    }
    return ss.str();
}

// Function to hash a password with a given salt
std::string hashPassword(const std::string& password, const std::string& salt) {
    std::string saltedPassword = password + salt;
    boost::uuids::detail::md5 hash;
    boost::uuids::detail::md5::digest_type digest;

    hash.process_bytes(saltedPassword.data(), saltedPassword.size());
    hash.get_digest(digest);

    const auto charDigest = reinterpret_cast<const char*>(&digest);
    std::string result;
    boost::algorithm::hex(charDigest, charDigest + sizeof(digest), std::back_inserter(result));
    return result;
}

// Function to register a user
void registerUser(const std::string fileName,const std::string& username, const std::string& password) {
    std::string salt = generateSalt(16); // Generate a 16-byte salt
    std::string hashedPassword = hashPassword(password, salt);

    // Save the username, salt, and hashed password to a file
    std::ofstream file(fileName, std::ios::app);
    file << username << " " << salt << " " << hashedPassword << std::endl;
    file.close();
}
// Function to check if a username exists and verify the password
bool verifyPassword(const std::string fileName,const std::string& username, const std::string& password) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        return false;
    }

    std::string line, storedUsername, storedSalt, storedHash;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> storedUsername >> storedSalt >> storedHash;
        if (storedUsername == username) {
            std::string hashedPassword = hashPassword(password, storedSalt);
            return hashedPassword == storedHash;
        }
    }
    return false; // User not found or password mismatch
}

// Function to return the last word of a given line
std::string getLastWord(const std::string& line) {
    std::istringstream stream(line);
    std::string word, lastWord;

    // Read each word from the line
    while (stream >> word) {
        lastWord = word; // Keep updating lastWord to the current word
    }

    return lastWord;
}
