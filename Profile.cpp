#include "Profile.h"
#include <string>
using std::vector;
using std::string;
Profile::Profile(string first, string family, string email, string phoneN, string photo, int age, long id)
{
    ObjectID=GetNewID("Profile");
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
    bool at = false;
    bool sign = false;
    int i = 0;
    for (i < email.length(); i++;)
    {
        if (email[i] == '@')
        {
            at == true;
            break;
        }
    }
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
    os  << Profile.Age << std::endl;
    os  << Profile.schoolId << std::endl;
    return os;
}
std::istream &operator>>(std::istream &is, Profile &Profile)
{
    is >> Profile.ObjectID;
    is >> Profile.FirstN;
    is >> Profile.FamilyN;
    is >> Profile.Email;
    is >> Profile.PhoneN;
    is >> Profile.Age;
    is >> Profile.schoolId;
    return is;
}
