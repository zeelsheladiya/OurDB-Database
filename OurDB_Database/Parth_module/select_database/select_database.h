//
// Created by dabhe on 19-Apr-21.
//
#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
using namespace std;

#ifndef OURDB_DATABASE_SELECT_DATABASE_H
#define OURDB_DATABASE_SELECT_DATABASE_H

// this function helps for validation..


string selectDatabase(string databaseName)
{
 validate = validation(databaseName,errorSpecialchaDatabase[0],errFirstLetterNumeric[0]);
 if(validate == "true_true")
 {
     //the validation function calls and if it returns true_true then goes in these block

     dName = databaseName;  //stores the databasename to dname variable

     databaseName = strPath[0] + databaseName; // concatnat the databasename with path..

     if (filesystem::exists(databaseName.c_str()))  // it checks whether directory exist or not
     {
         if(!(databaseSelectGlobal == dName)) { // check if dummy variable != databaseGlobal then execute these..

             databaseSelectGlobal = dName; // if above condition is right then dummy assigned to databasesSlectGlobal
             databaseSavePath = databaseName;
             return  SuccessDatabaseSelected[0] + dName; //it returns string selected..
         }else
         {
             return databaseAlreadySelected[0]; // it returns error already selected
         }

     } else {

         return errDatabaseNotFound[0]; // if database it not there then returns not found..
     }

 }
 else if(validate!="true_true")
 {
     return validate; // if validation some how fails this shows.
 }
}


#endif //OURDB_DATABASE_SELECT_DATABASE_H
