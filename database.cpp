#include <stdio.h>
#include <math.h>
#include <fstream> // работа с файлами
#include <iomanip> // манипуляторы ввода/вывода
#include <cstring>
#include <vector>           // std::(vector)
#include <sstream>          // std::(istringstream)
#include <algorithm>
#include "database.h"







inline void DataBase::addPatient()
{
    int currentId = currentAmount;
    currentAmount ++;
    Patient patient;
    std::cout << "name:" << std::endl;
    std::cin >> patient.name;
    std::cout << "surname:" << std::endl;
    std::cin >> patient.surname;
    /*std::cout << "age:" << std::endl;
    std::cin >> this -> patients[currentId] -> age;
    std::cout << "sex (female = 1, male = 0):" << std::endl;
    std::cin >> this -> patients[currentId] -> sex;
    std::cout << "city:" << std::endl;
    std::cin >> this -> patients[currentId] -> city;
    std::cout << "amount of visiting:" << std::endl;
    std::cin >> this -> patients[currentId] -> visitAmount;
    std::cout << "ID:" << currentId << std::endl;*/
    patients.push_back(patient);


}

inline void DataBase::findPatient(int currentId)
{
    if (currentId > patients.size-1)
    {
        std::cout << "Error ID" << std::endl;
    }
    else
    {



        Node<Patient>* current = patients.head;
        for (int i = 0; i < currentId; i++)
        {
            current = current->pnext;
        }




        std::cout << "name:" <<current->value.name << std::endl;
        std::cout << "surname:" << current->value.surname  << std::endl;

        /*std::cout << "sex:";1
        if (this -> patients[currentId] -> sex)
        {
            std::cout << "female" << std::endl;
        }
        else
        {
            std::cout << "male" << std::endl;
        }
        std::cout << "city:" << this -> patients[currentId] -> city << std::endl;
        std::cout << "amount of visiting:" << this -> patients[currentId] -> visitAmount << std::endl;*/
    }
}

inline void split(const std::string &s, char delim, std::vector<std::string> &elems)
{

    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}
//
//
inline std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


inline void DataBase::readDataBase(std::string filename)
{
    std::ifstream tmpDataBase(filename);
    while(tmpDataBase)
    {
        std::string buffer;
        std::getline(tmpDataBase, buffer);
        if (buffer != "")
        {
            std::vector<std::string> info;
            Patient patient;
            info = split(buffer, ' ');
            patient.name = info[0];
            patient.surname = info[1];
            patients.push_back(patient);

        }

    }
}

inline void DataBase::saveDataBase(std::string filename)
{
    std::ofstream newDataBase(filename);
    Node<Patient>* current = patients.head;
    for (int i = 0; i < patients.size; i++)
    {
        newDataBase<<current->value.name <<' '<<current->value.surname<<std::endl;
        current = current -> pnext;
    }
    newDataBase.close();
}
