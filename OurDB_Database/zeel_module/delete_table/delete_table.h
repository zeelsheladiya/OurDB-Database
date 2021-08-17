//
// Created by  zeel,mihir,parth,pranav on 08/05/2021.
//

#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"

//using namespace std;


#ifndef OURDB_DATABASE_DELETE_TABLE_H
#define OURDB_DATABASE_DELETE_TABLE_H

string deleteTable(string tableName)
{
    if(!(databaseSelectGlobal.empty())) // database selected or not
    {
        if(tableName == "default")
        {
            return errDeletingDefaultTable[0];      //doesnt allow user to delete the default.Ourdb file(table)
        }

        dName = databaseSelectGlobal;      //to store current database name

        validate = validation(tableName,errorSpecialchaTable[0],errFirstLetterNumeric[0]);    //validating old table name
        if(validate == "true_true")
        {
            regex l("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed between letters..
            if ( regex_match(tableName, l) )
            {

                validate = validation(tableName,errorSpecialchaTable[0],errFirstLetterNumeric[0]);    //validating new table name
                if(validate == "true_true")
                {
                    tableName = strPath[0] + databaseSelectGlobal + "/" + tableName + ".Ourdb";
                    if(filesystem::exists(tableName.c_str()))     // checks if file already exist or not
                    {
                        //delete table logic
                        if (!(filesystem::remove_all(tableName)))  //from the filesystem function to remove directory
                        {
                            return errorDeletingTable[0]; // errorDeletingDatabase[0] defined in   Errors/error_variable.h
                        } else {
                            return SuccessDeletingTableMsg[0]; // SuccessDeletingTableMsg defined in Success_Messages/Success_Msg.h
                        }
                    }
                    else {
                        return errNoSuchTableExist[0]; // check table exist or not
                    }

                }
                else if(validate != "true_true") // global function for validation
                    return validate;
            }
            else
            {
                return  errorSpecialchaTable[0];
            }
        }
        else if(validate != "true_true") // global function
            return validate;
    }
    else
    {
        return SelectTheDatabase[0]; // if database is not selected before renaming then it gives error..
    }
}

#endif //OURDB_DATABASE_DELETE_TABLE_H
