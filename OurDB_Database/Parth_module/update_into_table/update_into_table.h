//
// Created by dabhe on 02-Jun-21.
//
#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
#include "../../global_functions/AfterWhereProcess.h"
#include "../../External_Libraries/json.hpp"

using namespace std;
using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_UPDATE_INTO_TABLE_H
#define OURDB_DATABASE_UPDATE_INTO_TABLE_H

string updateTable(string table_name,map<string,string> vc,string storedStringAfterWhere)
{
    if(!(databaseSelectGlobal.empty()))
    {
        validate = validation(table_name,errorSpecialchaTable[0],errFirstLetterNumeric[0]);

        if(validate == "true_true")
        {
            regex nl("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed betwwen letters..
           if(regex_match(table_name,nl))
           {
               tbname = "";
               tbname = databaseSavePath  + "/" + table_name + ".Ourdb";
               if(filesystem::exists(tbname.c_str()))
               {
                   if( table_name == "default")
                   {
                       return "default table can't be created";
                   }else {
                       return globalFuncForWhereClouse(storedStringAfterWhere, tbname, vc, 1);
                   }
               }
               else
               {
                   return tableDoesNotExist[0];
               }

           }
           else
           {
               return errorSpecialchaTable[0]; // error for special character found..
           }
        }else
        {
            return validate;
        }
    }else
    {
        return SelectTheDatabase[0];
    }

}


#endif //OURDB_DATABASE_UPDATE_INTO_TABLE_H
