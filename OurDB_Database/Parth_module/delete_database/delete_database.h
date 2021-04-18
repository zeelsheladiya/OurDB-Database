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
         databaseName = strPath[0] + databaseName;
           if (!(filesystem::remove_all(databaseName))) {
               cout<<databaseName.c_str()<<endl;
                return errorDeletingDatabase[0];
            } else {
                return SuccessDeletingDatabaseMsg;
            }
 }


#endif //OURDB_DATABASE_DELETE_DATABASE_H
