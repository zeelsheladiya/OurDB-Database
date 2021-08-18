//
// Created by dabhe on 29-Apr-21.
//
//#include <iostream>
//#include <string>
//#include <filesystem>
#include "../../variables/query_variables.h"
//using namespace std;

#ifndef OURDB_DATABASE_RENAME_DATABASE_H
#define OURDB_DATABASE_RENAME_DATABASE_H

std::string renameDatabase(std::string databaseName)
{
    if(!(databaseSelectGlobal.empty()))
    {
        validate = validation(databaseName,errorSpecialchaDatabase[0],errFirstLetterNumeric[0]);
        if(validate == "true_true")
        {
            std::regex l("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed between letters..
            if ( regex_match(databaseName, l) )
            {
                databaseName = strPath[0] + databaseName; //strpath[0]="path" defined in  variables/query_variables.h
                if (!(databaseSavePath == databaseName))
                {
                    if (rename(databaseSavePath.c_str(), databaseName.c_str()) != 0) // rename the directory
                    {
                        return errrenameDatabase[0]; // defined in Errors/error_variable.h
                    }
                    else
                    {
                        databaseSelectGlobal = ""; // after renaming it has to be empty.. sp again have to select in order to rename
                        return SuccessRenamingDatabaseMsg[0]; // Success_Messages/Success_Msg.h
                    }
                }
                else
                {
                    return sameNameDatabaseErr[0];
                }
            }
            else
            {
                return  errorSpecialchaDatabase[0];
            }
        }
        else if(validate != "true_true")
            return validate;
    }
    else
    {
        return SelectTheDatabase[0]; // if database is not selected before renaming then it gives error..
    }
}

#endif //OURDB_DATABASE_RENAME_DATABASE_H
