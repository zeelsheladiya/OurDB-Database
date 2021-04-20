//
// Created by dabhe on 19-Apr-21.
//
#include <iostream>
#include <string>
#include <filesystem>
using namespace std;

#ifndef OURDB_DATABASE_SELECT_DATABASE_H
#define OURDB_DATABASE_SELECT_DATABASE_H


string validation(string dbname,string ferror,string serror)
{
    cm = dbname.front();  //store the first character of string
    cn = dbname.back(); // stores last character of string
    if(cm >= 97 && cm <= 122)   // check whether the first character is between "a to z" or not
    {
        if((cn >= 32 && cn <= 47)  ||(cn >= 58 && cn <= 92) || (cn >= 123 && cn <= 126)) // check for special character
        {
            return ferror; // defined in Errors/error_variable.h

        }else{

            return "true_true";
        }
    }
    else if(!(cm >= 97 && cm <= 122)) // check if character is not between "a to z"...
    {
        return serror; // defined in Errors/error_variable.h
    }

}

string selectDatabase(string databaseName)
{

 if(validation("databaseName",errorSpecialchaDatabase[0],syntaxOfCreateDatabase[0])=="true_true") {
     databaseName = strPath[0] + databaseName;
     if (filesystem::exists(databaseName.c_str())) {
         if(!(databaseSelectGlobal == databaseName)) {
             databaseSelectGlobal = databaseName;
             return databaseSelectGlobal + " selected..";
         }else
         {
             return databaseAlreadySelected[0];
         }

     } else {
         databaseSelectGlobal = "";
         return errDatabaseNotFound[0];
     }

 }
 else
 {
     return "error";
 }
}


#endif //OURDB_DATABASE_SELECT_DATABASE_H
