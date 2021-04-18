//
// Created by zeel,mihir,parth on 13/04/2021.
//


#include <iostream>
#include <string>
#include <filesystem>
using namespace std;

#ifndef OURDB_DATABASE_DELETE_DATABASE_H
#define OURDB_DATABASE_DELETE_DATABASE_H

string deleteDatabase(string databaseName)
{
         databaseName = strPath[0] + databaseName; // strPath[0] is path to database folder where database stored..
         // strpath[0] is stored in variables/query_variable.h
           if (!(filesystem::remove_all(databaseName))) { //from the filesystem function to remove directory
                return errorDeletingDatabase[0]; // errorDeletingDatabase[0] defined in   Errors/error_variable.h
            } else {
                return SuccessDeletingDatabaseMsg; // SuccessDeletingDatabaseMsg defined in Success_Messages/Success_Msg.h
            }
 }


#endif //OURDB_DATABASE_DELETE_DATABASE_H
