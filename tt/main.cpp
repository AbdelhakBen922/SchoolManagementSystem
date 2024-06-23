#include <QApplication>
#include "mainwindow.h"
#include "Student.h"
#include "Semestre.h"
#include "Group.h"
#include "Place.h"
#include "Teacher.h"
#include "funcs.h"

void SetUpSchool(){
    std::vector<long> years;
    std::vector<long> sections;
    std::vector<long> calendar;
    std::vector<long> places;
    std::vector<long> Times;
    std::vector<long> Teachers;
    std::vector<long> TimeTables;
    for (int i = 9; i < 17; i++)
    {

        int year = (i / 12 == 0) ? 2023 : 2024;
        int n = getNumOfDay(i % 12 + 1, 2024);
        for (int j = 0; j < n; j++)
        {
            int numOfWeek = GetDayOfWeek(j, i % 12 + 1, year);
            Date Today{j, n, year};
            saveToFile(Today);
            calendar.push_back(Today.getObjectID());
            Clean("Dates.txt");
            if (numOfWeek < 5)
            {
                for (int t = 0; t < 6; t++)
                {
                    Time T {*(calendar.end()-1), t + 1};
                    saveToFile(T);
                    Times.push_back(T.getObjectID());
                    Clean("Times.txt");
                }
            }
        }
    }
    for (int i = 1; i <= 8; i++){
        Place p{"Amphi " + std::to_string(i)};
        saveToFile(p);
        places.push_back(p.getObjectID());
        Clean("Places.txt");
    }
    for (int i = 1; i <= 25; i++){
        Place p{"Tuto " + std::to_string(i)};
        saveToFile(p);
        places.push_back(p.getObjectID());
        Clean("Places.txt");
    }
    for (int i = 1; i <= 9; i++){
        Place p{"Lab " + std::to_string(i)};
        saveToFile(p);
        places.push_back(p.getObjectID());
        Clean("Places.txt");
    }
    for (int i = 1; i <= 9; i++){
        Place p{"Eng Lab " + std::to_string(i)};
        saveToFile(p);
        places.push_back(p.getObjectID());
        Clean("Places.txt");
    }
    int i=0;
        Year y{i+1};
        years.push_back(y.getObjectID());
        saveToFile(y);
        Semestre s1{years[i], 1};
        Semestre s2{years[i], 2};
        saveToFile(s1);
        saveToFile(s2);
        Clean("Years.txt");
        Clean("Semestres.txt");
        for(int a=1;a<13;i++){
            std::ifstream places("PlacesY"+std::to_string(i+1)+"G"+std::to_string(a)+".txt");
            std::vector<long>PlacesPerG;
            std::string line;
            while(std::getline(places,line))PlacesPerG.push_back(GetObjectByAttribute<Place>("Places.txt",2,line).getObjectID());
            places.close();
            std::ifstream teachers("PlacesY"+std::to_string(i+1)+"G"+std::to_string(a)+".txt");
            std::vector<long>TeachersPerG;
            while(std::getline(teachers,line)){
                std::string lastName=getLastWord(line);
                Teacher tutor(line.substr(0,line.length()-lastName.length()-1),lastName);
                saveToFile(tutor);
                Clean("Teachers.txt");
                TeachersPerG.push_back(tutor.getObjectID());
            }

            teachers.close();
            long timeTable[5][6],tutors[5][6],ps[5][6];
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    timeTable[i][j] = Times[i*5+j] ;
                    tutors[i][j] = TeachersPerG[i*5+j];
                    ps[i][j] = PlacesPerG[i*5+j];
                }
            }
            Schedule sG(timeTable,tutors,ps);
            saveToFile(sG);
            Clean ("Schedules.txt");
            TimeTables.push_back(sG.getObjectID());
        }

        for (int j = 0; j < 3; j++)
        {
            Section s{ years[i], j + 1};
            saveToFile(s);
            sections.push_back(s.getObjectID());
            Clean("Sections.txt");
            for (int t = 0; t < 4; t++)
            {
                Group g{j * 4 + t + 1, sections[j],TimeTables[i*3+j*4+t] };
                saveToFile(g);
                Clean("Groups.txt");
            }
        }


}

int main(int argc, char **argv) {
    registerUser("StudentsUsers.txt","abdelhak.benbouziane","test");
    std::string FirstN, FamilyN, Email, PhoneN, PhotoPath;
    int age;
    long schoolid;
    FirstN="Abdelhak";
    FamilyN="Benbouziane";
    Email="abdelhak.benbouziane@ensia.edu.dz";
    PhoneN="0542482728";
    PhotoPath="/home/kali9/Pictures/unnamed.png";
    age=18;
    schoolid=0;
    //SetUpSchool();
    Year FirstYear(1);
    saveToFile(FirstYear);
    Section A(FirstYear.getObjectID(),1);
    saveToFile(A);
    Group G2(2,A.getObjectID());
    saveToFile(G2);
    Semestre S1(FirstYear.getObjectID(),1);
    saveToFile(S1);
    Student Abdelhak(FirstN,FamilyN,Email,PhoneN,PhotoPath,age,schoolid,G2.getObjectID(),S1.getObjectID());
    saveToFile(Abdelhak);
    QApplication app(argc, argv);
    MainWindow window;
    window.show();


    return app.exec();
}
