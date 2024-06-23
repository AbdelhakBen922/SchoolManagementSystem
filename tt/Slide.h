/*
 * Slide.h
 *
 *  Created on: Jun 13, 2024
 *      Author: kali9
 */

#ifndef SLIDE_H_
#define SLIDE_H_

#include <iostream>
#include "funcs.h"
#include <string>
using std::string;


class Slide {

    long ObjectID;

public:
    long getObjectID() const { return ObjectID; }
    void setObject(long);

private:
    std::string title;
    std::string filePath;

public:
    Slide(string t=" ",string f=" ");
    ~Slide();
    const std::string &getTitle() const;
    void setTitle(const std::string &t);
    const std::string &getFilePath() const;
    void setFilePath(const std::string &path);
    friend std::ostream &operator<<(std::ostream &os, const Slide &Slide);
    friend std::istream &operator>>(std::istream &is, Slide &Slide);
    bool operator==(const Slide&S2)const;

};

#endif /* SLIDE_H_ */
