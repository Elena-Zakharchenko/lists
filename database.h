#pragma once
#ifndef DATA2_DATABASE_H
#define DATA2_DATABASE_H
#include <iostream>
#include <string>
#include "List.h"


struct Patient
{
    std::string name;
    std::string surname;
    int age;
    bool sex;
    std::string city;
    int visitAmount;
};

class DataBase
{
public:

    List<Patient> patients;
    int currentAmount = 0;


    std::string nameofDataBase;
    void addPatient();

    void findPatient(int currentId);
    void readDataBase(std::string filename);
    void saveDataBase(std::string filename);

};









#endif //DATA2_DATABASE_H
