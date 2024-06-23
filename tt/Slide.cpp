/*
 * Slide.cpp
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#include "Slide.h"

using std::string;

Slide::Slide(string t,string f):title(t){
    setObject(GetNewID("Slide"));
    setFilePath(f);
}
const std::string &Slide::getTitle() const
{
    return title;
}

void Slide::setTitle(const std::string &t)
{
    title = t;
}

const std::string &Slide::getFilePath() const
{
    return filePath;
}

void Slide::setFilePath(const std::string &path)
{
    if(CheckFile(path)){
        filePath = path;
    }
    else filePath="";
}
std::ostream &operator<<(std::ostream &os, const Slide &slide)
{
    os << slide.title << "\n" << slide.filePath<<std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Slide &slide)
{
	std::string ignore;
	std::getline(is,ignore);
    std::getline(is, slide.title) ;
    std::getline(is,slide.filePath);
    return is;
}

bool Slide::operator==(const Slide & S2)const{
    return (title == S2.title && filePath == S2.filePath);
}
void Slide::setObject(long ObjectID)
{
    if (ObjectNew(ObjectID,"Place"))
    {
        this->ObjectID = ObjectID;
    }
    else
        ObjectID = 0;
}
Slide::~Slide(){

};
