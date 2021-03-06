//
// Created by dabhe on 02-Jun-21.
//
//#include <iostream>
//#include <string>
//#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
#include "../../global_functions/AfterWhereProcess.h"
#include "../../External_Libraries/json.hpp"

//using namespace std;
using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_UPDATE_INTO_TABLE_H
#define OURDB_DATABASE_UPDATE_INTO_TABLE_H

std::string updateTable(std::string table_name,std::map<std::string,std::string> vc,std::string storedStringAfterWhere,std::vector<std::string>strsep3)
{
    if(!(databaseSelectGlobal.empty())) // checks whether database is selected or not
    {
        validate = validation(table_name,errorSpecialchaTable[0],errFirstLetterNumeric[0]); // validates the function

        if(validate == "true_true")
        {
            std::regex nl("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed between letters..
           if(regex_match(table_name,nl))
           {
               tbname = "";
               tbname = databaseSavePath  + "/" + table_name + ".Ourdb"; //saved table path
                  tname = "";
                  tname=table_name; // table name
               if(std::filesystem::exists(tbname.c_str()))
               {
                   if( table_name == "default") // user can't perform the action in default table
                   {
                       return errUpdatingDefaultTable[0];
                   }else
                   {
                       int CounterForCol = 0; // counter for column
                       ourdb odb; // json object
                       std::ifstream fs1(tbname);
                       fs1 >> odb;

                       for(auto lkey : vc) // iterate through map
                       {
                           for (auto key : odb["records"]["col_names"]) // iterate through col_names in json
                           {
                               if(to_string(key) == '"'+lkey.first+'"')  // if map value and value in column matches
                               {
                                   CounterForCol++; // increment the counter
                               }
                           }
                       }

                       if(CounterForCol == vc.size()) // i
                       {
                              return globalFuncForWhereClouse(storedStringAfterWhere, tbname, vc, 1, strsep3);
                       }
                       else
                       {
                           return ErrorDoestNotExistInSetCondition[0]; // column doest not exist...
                       }
                   }
               }
               else
               {
                   return tableDoesNotExist[0]; // table does not exist
               }

           }
           else
           {
               return errorSpecialchaTable[0]; // error for special character found..
           }
        }else
        {
            return validate; // if the error from validate function..
        }
    }else
    {
        return SelectTheDatabase[0]; // select database error.
    }

}

#endif //OURDB_DATABASE_UPDATE_INTO_TABLE_H
