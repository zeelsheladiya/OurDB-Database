//
// Created by dabhe on 19-Apr-21.
//
#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"
using namespace std;

#ifndef OURDB_DATABASE_SELECT_DATABASE_H
#define OURDB_DATABASE_SELECT_DATABASE_H

// this function helps for validation..
string validation(string dbname,string ferror,string serror)
{
    cm = dbname.front();  //store the first character of string
    cn = dbname.back(); // stores last character of string
    if(cm >= 97 && cm <= 122)   // check whether the first character is between "a to z" or not
    {
        if((cn >= 32 && cn <= 47)  ||(cn >= 58 && cn <= 92) || (cn >= 123 && cn <= 126)) // check for special character
        {
            return ferror; // returns ferror variable

        }else{

            return "true_true"; // return true_true for execution of these block
        }
    }
    else if(!(cm >= 97 && cm <= 122)) // check if character is not between "a to z"...
    {
        return serror; // returns serror variable
    }

}

string selectDatabase(string databaseName)
{

 if(validation("databaseName",errorSpecialchaDatabase[0],syntaxOfCreateDatabase[0])=="true_true") {
     //the validation function calls and if it returns true_true then goes in these block

     dummy = databaseName;  //stores the databasename to dummy variable

     databaseName = strPath[0] + databaseName; // concatnat the databasename with path..

     if (filesystem::exists(databaseName.c_str())) { // it checks whether directory exist or not

         if(!(databaseSelectGlobal == dummy)) { // check if dummy variable != databaseGlobal then execute these..

             databaseSelectGlobal = dummy; // if above condition is right then dummy assigned to databasesSlectGlobal

             return  SuccessDatabaseSelected[0] + dummy; //it returns string selected..
         }else
         {
             return databaseAlreadySelected[0]; // it returns error already selected
         }

     } else {

         return errDatabaseNotFound[0]; // if database it not there then returns not found..
     }

 }
 else
 {
     return SysUnRecognizedError[0]; // if validation some how fails this shows.
 }
}


#endif //OURDB_DATABASE_SELECT_DATABASE_H
