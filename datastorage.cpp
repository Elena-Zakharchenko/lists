#include"datastorage.h"
#include<iostream>
#include<string>

inline void Datastorage::createDataBase(std::string nameOfDataBase)
{
    DataBase newDataBase;
    newDataBase.nameofDataBase = nameOfDataBase;
    storage.push_back(newDataBase);

}
inline int Datastorage::findDataBase(std::string nameOfDataBase)
{
    int index = -777;
    for (int i = 0; i < storage.size(); i++)
    {
        if (storage[i].nameofDataBase == nameOfDataBase)
        {
            index = i;

        }

    }
    if (index == -777)
    {
        std::cout << "error" <<std::endl;
        return index;
    }
    else
    {
        return index;
    }

}
inline void Datastorage::readDataBase(std::string nameOfDataBase)
{
    std::string filename;
    int index = findDataBase(nameOfDataBase);
    if (index != -777)
    {
        std::cin >> filename;
        storage[index].readDataBase(filename);
    }
    else
    {
        std::cout<< "error" << std::endl;
    }

}
inline void Datastorage::saveDataBase(std::string nameOfDataBase)
{
    std::string filename;
    int index = findDataBase(nameOfDataBase);
    if (index != -777)
    {
        std::cout<< "Write name of the file, that you want to save:" <<std::endl;
        std::cin >> filename;
        storage[index].saveDataBase(filename);
    }
    else
    {
        std::cout<< "error" << std::endl;
    }

}
inline void Datastorage::copyDataBase(std::string sourceDataBase, std::string newDataBase)
{
    int sourceindex = findDataBase(sourceDataBase);
    DataBase database;
    database.nameofDataBase = newDataBase;
    Node<Patient>* current = storage[sourceindex].patients.head;
    for (int i=0; i < storage[sourceindex].patients.size; i++)
    {
        Patient patient;
        patient.name = current -> value.name;
        patient.surname = current -> value.surname;
        database.patients.push_back(patient);
        current = current -> pnext;
    }
    storage.push_back(database);
}



inline void Datastorage::addPatient(std::string nameOfDataBase)
{
    int index = findDataBase(nameOfDataBase);
    if (index != -777)
    {
        storage[index].addPatient();

    }else

    {
       std::cout<< "error\n";
    }
}
