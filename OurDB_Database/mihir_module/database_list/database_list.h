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
    filesystem::path path(strPath[0]);   //path where all our databases are created and stored
    string list;   //string to store the list of databases
    
    if(!filesystem::is_empty(path))     //checks if the current path to database is empty or not
    {
        list += "Databases are : \n";
        for (auto &i : filesystem::directory_iterator(path))    //increments the existing folders(databases) at given path
        {
            if(i.is_directory())
            {
                list += i.path().filename().string() + "\n";   //store the names of all the folders(databases) in list string
            }
        }
        return list;    //returns the list string which has all the database's name
    }
    else
        return errDatabaseListIsEmpty[0];   //error to be displayed if there is no database at given path
}



#endif //OURDB_DATABASE_DATABASE_LIST_H
