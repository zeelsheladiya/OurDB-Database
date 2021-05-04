//
// Created by dabhe on 29-Apr-21.
//
#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"
using namespace std;

#ifndef OURDB_DATABASE_RENAME_DATABASE_H
#define OURDB_DATABASE_RENAME_DATABASE_H

string renameDatabase(string databaseName)
{
    if(!(databaseSelectGlobal.empty()))
    {
        firstLetterStore = databaseName.front();  //store the first character of string
        lastLetterStore = databaseName.back(); // stores last character of string
        if(firstLetterStore >= 97 && firstLetterStore <= 122)   // check whether the first character is between "a to z" or not
        {
                if((lastLetterStore >= 32 && lastLetterStore <= 47)  ||(lastLetterStore >= 58 && lastLetterStore <= 92) || (lastLetterStore >= 123 && lastLetterStore <= 126)) // check for special character
                {
                    return errorSpecialchaDatabase[0]; // defined in Errors/error_variable.h
                }else{
                    databaseName = strPath[0] + databaseName; //strpath[0]="path" defined in  variables/query_variables.h
                    if(!(databaseSavePath==databaseName))
                    {
                        if (!(rename(databaseSavePath.c_str(), databaseName.c_str()) == 0)) // rename the directory
                        {

                            return errrenameDatabase[0]; // defined in Errors/error_variable.h

                        } else {
                            databaseSelectGlobal = ""; // after renaming it has to be empty.. sp again have to select in order to rename
                            return SuccessRenamingDatabaseMsg[0]; // Success_Messages/Success_Msg.h
                        }
                    }else
                    {
                        return sameNameDatabaseErr[0];
                    }
                }
        }
        else if(!(firstLetterStore >= 97 && firstLetterStore <= 122)) // check if character is not between "a to z"...
        {
            return syntaxOfCreateDatabase[0]; // defined in Errors/error_variable.h
        }

    }else{

        return SelectTheDatabase[0]; // if database is not selected before renaming then it gives error..
    }



}



#endif //OURDB_DATABASE_RENAME_DATABASE_H
