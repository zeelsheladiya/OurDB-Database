//
// Created by zeel,mihir,parth,pranav on 13/04/2021.
//


#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"
using namespace std;

#ifndef OURDB_DATABASE_DELETE_DATABASE_H
#define OURDB_DATABASE_DELETE_DATABASE_H

/*
string deleteDatabase(string databaseName)
{

    firstLetterStore = databaseName.front();  //store the first character of string
    lastLetterStore = databaseName.back(); // stores last character of string


    if(firstLetterStore >= 97 && firstLetterStore <= 122)   // check whether the first character is between "a to z" or not
    {
        if((lastLetterStore >= 32 && lastLetterStore <= 47)  ||(lastLetterStore >= 58 && lastLetterStore <= 92) || (lastLetterStore >= 123 && lastLetterStore <= 126)) { // check for special character

            return errorSpecialchaDatabase[0]; // defined in Errors/error_variable.h

        }else{

            databaseName = strPath[0] + databaseName; //strpath[0]="path" defined in  variables/query_variables.h
         if(filesystem::exists(databaseName.c_str())) {
             if (!(filesystem::remove_all(databaseName)))  //from the filesystem function to remove directory
             {

                 return errorDeletingDatabase[0]; // errorDeletingDatabase[0] defined in   Errors/error_variable.h

             } else {
                 databaseSelectGlobal = ""; // reset the global variable in ,defined in variables/query_variables.h
                 databaseSavePath = " "; // reset the databaseSave path...
                 return SuccessDeletingDatabaseMsg[0]; // SuccessDeletingDatabaseMsg defined in Success_Messages/Success_Msg.h

             }
         }
         else
         {
             return errDatabaseListIsEmpty[0];
         }
        }
    }
    else if(!(firstLetterStore >= 97 && firstLetterStore <= 122)) // check if character is not between "a to z"...
    {
        return syntaxOfCreateDatabase[0]; // defined in Errors/error_variable.h
    }
 }
*/

string deleteDatabase(string databaseName)
{
    validate = validation(databaseName,errLastCharName[0],errStartWithDbName[0]);
    if( validate == "true_true")
    {
        regex l("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed betwwen letters..
        if ( regex_match(databaseName, l) ) {
            databaseName = strPath[0] + databaseName; //strpath[0]="path" defined in  variables/query_variables.h
            if(filesystem::exists(databaseName.c_str())) {
                if (!(filesystem::remove_all(databaseName)))  //from the filesystem function to remove directory
                {
                    return errorDeletingDatabase[0]; // errorDeletingDatabase[0] defined in   Errors/error_variable.h
                } else {
                    databaseSelectGlobal = ""; // reset the global variable in ,defined in variables/query_variables.h
                    databaseSavePath = " "; // reset the databaseSave path...
                    return SuccessDeletingDatabaseMsg[0]; // SuccessDeletingDatabaseMsg defined in Success_Messages/Success_Msg.h

                }
            }
            else
            {
                return errDatabaseListIsEmpty[0];
            }
        }
        else
        {
            return  errorSpecialchaDatabase[0];
        }
    }else if(validate != "true_true")
    {
        return  validate;
    }
}
#endif //OURDB_DATABASE_DELETE_DATABASE_H
