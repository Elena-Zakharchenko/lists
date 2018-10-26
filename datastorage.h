#include<vector>
#include<string>
#include"database.cpp"
#ifndef DATA2_DATASTORAGE_H
#define DATA2_DATASTORAGE_H




class Datastorage
{
public:
    std::vector<DataBase> storage;
    void createDataBase(std::string nameOfDataBase);
    int findDataBase(std::string nameOfDataBase);
    void readDataBase(std::string nameOfDataBase);
    void saveDataBase(std::string nameOfDataBase);
    void copyDataBase(std::string sourceDataBase, std::string newDataBase);
    void addPatient(std::string nameOfDataBase);

};







#endif //DATA2_DATASTORAGE_H
