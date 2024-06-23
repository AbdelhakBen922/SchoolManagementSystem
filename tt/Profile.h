/*
 * Profile.h
 *
 *  Created on: Jun 11, 2024
 *      Author: kali9
 */

#ifndef PROFILE_H_
#define PROFILE_H_
#include <string>
#include "funcs.h"
#include <vector>
//#include <nlohmann/json.hpp>
class Profile {

     std::string FirstN, FamilyN, Email, PhoneN, PhotoPath;
    int Age;
    long schoolId;
protected:
    long ObjectID;
    friend bool NameValid(std::string );
    bool EmailIsValid(std::string email = "") const;
    bool isPhoneNValid(std::string Phone = "") const;

public:
    Profile(std::string = "", std::string = "", std::string = "", std::string = "", std::string = "", int = 0, long = 0);
    void setFristN(std::string = "");
    void setFamilyN(std::string = "");
    std::string getPhoto() const;
    void setPhoto(std::string = "");
    std::string getFirstN() const;
    std::string getFamilyN() const;
    void setAge(int = 17);
    int getAge() const;
    void setID(long);
    long getID() const;
    void setEmail(std::string = "");
    std::string getEmail() const;
    void setPhoneN(std::string = "");
    std::string getPhoneN() const;
    long getObjectID() const { return ObjectID; };
    void setObject(long);

    friend std::ostream &operator<<(std::ostream &os, const Profile &Profile);
    friend std::istream &operator>>(std::istream &is, Profile &Profile);
};

#endif /* PROFILE_H_ */
