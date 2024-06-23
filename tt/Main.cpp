/*
 * Main.cpp
 *
 *  Created on: Jun 11, 2024
 *      Author: kali9
 */

#include "Teacher.h"
#include "funcs.h"
#include "Place.h"
#include "Schedule.h"
#include "Adminstrator.h"
#include "Time.h"
#include "Student.h"
#include <fstream>
using namespace std;
#include <iostream>
int main(){

	std::string FirstN, FamilyN, Email, PhoneN, PhotoPath;
	    int age;
	    long schoolid;

	        FirstN="Abdelhak";
	        FamilyN="Benbouziane";
	        Email="abdlehak.benbouziane@ensia.edu.dz";
	        PhoneN="0542482728";
	        PhotoPath="/home/kali9/Pictures/P1000583.jpg";
	        age=18;
	        schoolid=0;
	        Schedule s;
	        Year OneCP(1);
	        Section A(OneCP.getObjectID(),1);
	        Group G2(2,A.getObjectID(),s.getObjectID());
	        Student Ab(FirstN,FamilyN,Email,PhoneN,PhotoPath,age,schoolid,G2.getObjectID(),-1);
	        saveToFile(Ab);
	        Student AB = GetObject<Student>(Ab.getObjectID());
	        CleanALL();




	return 0;
}

