//
// Created by Mihir on 05-05-2021.
//

#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"

#ifndef OURDB_DATABASE_TABLE_LIST_H
#define OURDB_DATABASE_TABLE_LIST_H

string tableList()
{
    if(databaseSelectGlobal == "")
    {
        return errDatabaseNotSelected[0];
    }
    else
    {
        string path = strPath[0] + databaseSelectGlobal + "./";   //path to current database where our tables are created and stored
        string list = "";   //string to store the list of tables

        if (!filesystem::is_empty(path))     //checks if the current path to table is empty or not
        {
            cout << "Tables are : \n";
            for (auto &i : filesystem::directory_iterator(path))    //increments the existing files(tables) at given path
            {
                list += i.path().filename().stem().string() + "\n";   //store the names of all the files(tables) in list string without extension
            }
            return list;    //returns the list string which has all the tables's name
        }
        else
            return errTableListIsEmpty[0];	//error to be displayed if there is no table present at selected database
    }
}

#endif //OURDB_DATABASE_TABLE_LIST_H
