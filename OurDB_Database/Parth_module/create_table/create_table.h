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

string createTable(string databasename)
{

    if(!(databaseSelectGlobal == ""))
    {

             if ( validation(databasename,errorSpecialchaTable[0],syntaxOfCreateTable[0]) == "true_true")
             {
                tbname = databaseSavePath +"/"+ databasename+".Ourdb"; // it adds the selected database path with tablename
                // and also store in tbname
                 if(!(filesystem::exists(tbname.c_str()))) // if file already exist then return error..
                 {
                     FileTabel(tbname); // call the filetable function which is in global_function.h

                 } else{
                     return errTableAlreadyExist[0]; // if table already exist then returns the error..
                 }

             }
             else
             {
                 return SysUnRecognizedError[0]; // if validation some how fails this shows.

             }

    }
    else
    {

        return SelectTheDatabase[0]; // if database is not select then returns the error.
    }


}


#endif //OURDB_DATABASE_CREATE_TABLE_H
