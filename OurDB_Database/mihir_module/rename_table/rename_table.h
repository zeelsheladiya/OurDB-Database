//
// Created by Mihir on 07-05-2021.
//

#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"

#ifndef OURDB_DATABASE_RENAME_TABLE_H
#define OURDB_DATABASE_RENAME_TABLE_H

string renameTable(string oldName, string newName)
{
    if(!(databaseSelectGlobal.empty()))
    {
        if(oldName == "default")
        {
            return errRenamingDefaultTable[0];      //doesnt allow user to rename the default.Ourdb file(table)
        }

        dName = databaseSelectGlobal;      //to store current database name

        validate = validation(oldName,errorSpecialchaTable[0],errFirstLetterNumeric[0]);    //validating old table name
        if(validate == "true_true")
        {
            regex l("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed between letters..
            if ( regex_match(oldName, l) )
            {

                validate = validation(newName,errorSpecialchaTable[0],errFirstLetterNumeric[0]);    //validating new table name
                if(validate == "true_true")
                {
                    oldName = strPath[0] + databaseSelectGlobal + "/" + oldName + ".Ourdb";
                    if(filesystem::exists(oldName.c_str()))     // checks if file already exist or not
                    {
                        regex l("[a-zA-Z0-9_]{0,}");    // alphabet numeric and _ allowed between letters..
                        if (regex_match(newName, l))
                        {
                            newName = strPath[0] + databaseSelectGlobal + "/" + newName + ".Ourdb";

                            if(oldName == newName)      //if both old and new name are same then return error
                            {
                                return sameNameTableErr[0];        //same old and new name error
                            }
                            else
                            {
                                if(rename(oldName.c_str(),newName.c_str()) != 0)        //if rename function doesnt work then return error
                                {
                                    return errRenameTable[0];       //renaming table error
                                }
                                else
                                {
                                    return SuccessRenamingTableMsg[0];        //success msg if the table is renamed successfully!
                                }
                            }
                        }
                        else
                        {
                            return  errorSpecialchaTable[0];
                        }
                    }
                    else
                        return errNoSuchTableExist[0];

                }
                else if(validate != "true_true")
                    return validate;
            }
            else
            {
                return  errorSpecialchaTable[0];
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

#endif //OURDB_DATABASE_RENAME_TABLE_H
