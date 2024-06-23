/*
 * Profile.cpp
 *
 *  Created on: Jun 11, 2024
 *      Author: kali9
 */

#include "Profile.h"

#include <iostream>
#include <string>
#include <fstream>
using std::string;
Profile::Profile(string first, string family, string email, string phoneN, string photo, int age, long id)
{
    setObject(0);
    setFristN(first);
    setFamilyN(family);
    setPhoneN(phoneN);
    setAge(age);
    setEmail(email);
    setPhoto(photo);
    setID(id);
}
void Profile::setFristN(string N)
{
    if (NameValid(N))
        FirstN = "";
    else
        FirstN = N;
}
void Profile::setFamilyN(string N)
{
    if (NameValid(N))
        FamilyN = "";
    else
        FamilyN = N;
}
string Profile::getFirstN() const { return FirstN; }
void Profile::setPhoto(string P)
{
    if (CheckFile(P))
        PhotoPath = P;
    else
        P = "";
}
string Profile::getPhoto() const { return PhotoPath; }
string Profile::getFamilyN() const { return FamilyN; }
void Profile::setAge(int a)
{
    Age = (a <= 17) ? 17 : a;
}
int Profile::getAge() const { return Age; }
void Profile::setID(long id) { schoolId = (id > 0) ? id : 0; }
long Profile::getID() const { return schoolId; }
void Profile::setEmail(string email)
{
    if (EmailIsValid(email))
        Email = email;
    else
        Email = "";
}
string Profile::getEmail() const { return Email; }
void Profile::setPhoneN(string phone)
{
    if (isPhoneNValid(phone))
        PhoneN = phone;
}
string Profile::getPhoneN() const { return PhoneN; }

bool Profile::EmailIsValid(string email) const
{

    int i = 0;
    for (;i < email.length(); i++)
    {
        if (email[i] == '@')
        {
           i++;
            break;
        }
    }
    if (i+12!=email.length())return false;
    if (email.substr(i, 12) == "ensia.edu.dz")
        return true;
    return false;
}
bool Profile::isPhoneNValid(string Phone) const
{
    if (Phone.length() != 10)
        return false;
    if (Phone[0] != '0')
        return false;
    for (char i : Phone){
        if (!isdigit(i))return false;
    }
    return true;
}


std::ostream &operator<<(std::ostream &os, const Profile &Profile)
{

    os << Profile.ObjectID << std::endl;
    os << Profile.FirstN << std::endl;
    os  << Profile.FamilyN << std::endl;
    os  << Profile.Email << std::endl;
    os  << Profile.PhoneN << std::endl;
    os <<Profile.PhotoPath << std::endl;
    os  << Profile.Age << std::endl;
    os  << Profile.schoolId;
    return os;
}
std::istream &operator>>(std::istream &is, Profile &Profile)
{
	std::string ignore;
	is >> ignore;
    is >> Profile.ObjectID;
    is >> Profile.FirstN;
    is >> Profile.FamilyN;
    is >> Profile.Email;
    is >> Profile.PhoneN;
    is >> Profile.PhotoPath;
    is >> Profile.Age;
    is >> Profile.schoolId;
    return is;
}
void Profile::setObject(long ObjectID)
{
    if (ObjectNew(ObjectID,"Place"))
    {
        this->ObjectID = ObjectID;
    }
    else
        ObjectID = 0;
}



// JSON Serialization
//    void to_json(nlohmann::json& j, const Profile& p) {
//       j = nlohmann::json{
//           {"FirstN", p.FirstN}, {"FamilyN", p.FamilyN}, {"Email", p.Email},
//           {"PhoneN", p.PhoneN}, {"PhotoPath", p.PhotoPath}, {"Age", p.Age},
//           {"schoolId", p.schoolId}, {"ObjectID", p.ObjectID}
//       };
//   }
//
//   // JSON Deserialization
//    void from_json(const nlohmann::json& j, Profile& p) {
//       j.at("FirstN").get_to(p.FirstN);
//       j.at("FamilyN").get_to(p.FamilyN);
//       j.at("Email").get_to(p.Email);
//       j.at("PhoneN").get_to(p.PhoneN);
//       j.at("PhotoPath").get_to(p.PhotoPath);
//       j.at("Age").get_to(p.Age);
//       j.at("schoolId").get_to(p.schoolId);
//       j.at("ObjectID").get_to(p.ObjectID);
//   }

   // Save Profiles to JSON file
//   static void saveProfiles(const std::vector<Profile>& profiles) {
//       nlohmann::json j = profiles;
//       std::ofstream file(json_File);
//       if (file.is_open()) {
//           file << j.dump(4); // Pretty-print with 4-space indentation
//           file.close();
//       }
//   }
//
//   // Load Profiles from JSON file
//   static std::vector<Profile> loadProfiles() {
//       std::ifstream file(json_File);
//       std::vector<Profile> profiles;
//       if (file.is_open()) {
//           nlohmann::json j;
//           file >> j;
//           profiles = j.get<std::vector<Profile>>();
//           file.close();
//       }
//       return profiles;
//   }

   // Add a Profile to JSON file
//   static void addProfile(const Profile& profile) {
//       std::vector<Profile> profiles = loadProfiles();
//       profiles.push_back(profile);
//       saveProfiles(profiles);
//   }

// Initialize the static member


