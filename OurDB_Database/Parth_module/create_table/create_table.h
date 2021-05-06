//
// Created by dabhe on 05-May-21.
//
#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
using namespace std;
#ifndef OURDB_DATABASE_CREATE_TABLE_H
#define OURDB_DATABASE_CREATE_TABLE_H

string createTable(string tablename)
{

    if(!(databaseSelectGlobal == ""))
    {
         validate = validation(tablename,syntaxOfCreateTable[0],errorSpecialchaTable[0]);
        // variable for storing string value which is returned by validate function
             if ( validate == "true_true")
             {
                tbname = databaseSavePath +"/"+ tablename+".Ourdb"; // it adds the selected database path with tablename
                // and also store in tbname
                 if(!(filesystem::exists(tbname.c_str()))) // if file already exist then return error..
                 {
                     FileTable(tbname); // call the filetable function which is in global_function.h
                     return  SuccessCreatingFileMsg[0];
                 } else{
                     return errTableAlreadyExist[0]; // if table already exist then returns the error..
                 }

             }
             else if(validate!="true_true")
             {
                 return validate; // if validation some how fails this shows.

             }

    }
    else
    {

        return SelectTheDatabase[0]; // if database is not select then returns the error.
    }


}


#endif //OURDB_DATABASE_CREATE_TABLE_H
