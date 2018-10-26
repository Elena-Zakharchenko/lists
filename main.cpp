#include <stdio.h>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include "datastorage.cpp"


///Users/elenazaharcenko/CLionProjects/data2
/*
 *
 *
 *
 *
 *
 */


int main()
{
    Datastorage STORE;
    int p = 1;


    while(p != 0)
    {
        std::cout << "To add patient push 1 and write nameOfDatabase" << std::endl;
        std::cout << "To find out the information about the patient push 2 and write nameOfDatabase" << std::endl;
        std::cout << "To quit the program push 0" << std::endl;
        std::cout << "To create a new DataBase push 3" << std::endl;
        std::cout << "To read DataBase push 4 and write name of file" << std::endl;
        std::cout << "To save DataBase push 5 and write name of file" << std::endl;
        std::cout << "To copy DataBase push 6" << std::endl;
        std::cin >> p;
        int currentId = 0;
        switch(p)
        {
            case 1:
            {
                std::string name;
                std::cin >> name;
                STORE.addPatient(name);
                continue;
            }
            case 2:
            {
                std::string name;
                std::cin >> name;
                int index = STORE.findDataBase(name);
                std::cout << "Enter ID of the patient" << std::endl;
                std::cin >> currentId;
                STORE.storage[index].findPatient(currentId);
                continue;
            }
            case 0:
                break;


            case 3:
            {
                std::string name;
                std::cin>>name;
                STORE.createDataBase(name);
                continue;
            }
            case 4:
            {
                std::string name;
                std::cin>>name;
                STORE.readDataBase(name);
                continue;
            }
            case 5:
            {
                std::string name;
                std::cin>>name;
                STORE.saveDataBase(name);
                continue;
            }
            case 6:
            {
                std::cout << "Write the name of source DataBase\n";
                std::string source;
                std::cin>>source;
                std::cout<<"Write down the name of new DataBase\n";
                std::string newname;
                std::cin>>newname;
                STORE.copyDataBase(source, newname);
                continue;
            }



            default:
                break;
        }
    }
    return 0;
}
