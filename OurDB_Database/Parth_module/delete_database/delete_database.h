//
// Created by zeel,mihir,parth on 13/04/2021.
//


#include <iostream>
#include <string>

using namespace std;

#ifndef OURDB_DATABASE_DELETE_DATABASE_H
#define OURDB_DATABASE_DELETE_DATABASE_H

string deleteDatabase(string databaseName)
{
        databaseName = "../../OurDB_Database/Databases/" + databaseName;
           if (_rmdir(databaseName.c_str()) == -1) {
                return errorDeletingDatabase[0];
            } else {
                return SuccessDeletingDatabaseMsg;
            }
 }


#endif //OURDB_DATABASE_DELETE_DATABASE_H
