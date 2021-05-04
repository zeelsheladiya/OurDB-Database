//
// Created by Mihir on 04-05-2021.
//

#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"

using namespace std;

#ifndef OURDB_DATABASE_DATABASE_LIST_H
#define OURDB_DATABASE_DATABASE_LIST_H

string databaseList()
{
    string path = strPath[0];   //path where all our databases are created and stored

    if(!filesystem::is_empty(path))     //checks if the current path to database is empty or not
    {
        cout << "Databases are : \n";
        for (auto &i : filesystem::directory_iterator(path))    //increments the existing folders(databases) at given path
        {
            cout << i.path().filename().string()<< endl;   //displays name of the folders(databases) that are found at that given path in string format
        }
        return "";
    }
    else
        return errDatabaseListIsEmpty[0];
}



#endif //OURDB_DATABASE_DATABASE_LIST_H
