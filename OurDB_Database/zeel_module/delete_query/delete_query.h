//
// Created by dabhe on 02-Jun-21.
//
//#include <iostream>
//#include <string>
//#include <regex>
//#include <filesystem>
#include "../../global_functions/AfterWhereProcess.h"



#ifndef OURDB_DATABASE_DELETE_QUERY_H
#define OURDB_DATABASE_DELETE_QUERY_H

std::string DeleteQuery(std::string table_name ,std::string whereKeyword ,std::string afterWherestr)
{
    //check whether database is selected or not
    if(databaseSelectGlobal != "") {

        if(table_name != "default") {
            std::string table = databaseSavePath + "/" + table_name + ".Ourdb";

            if (std::filesystem::exists(table.c_str())) {

                if (syntaxCompare(whereKeyword,where))
                {
                    return globalFuncForWhereClouse(afterWherestr,table_name,1);

                } else {
                    //err where name is not exsist at right place as its syntax
                    return ErrWhereKeyword[0];
                }
            } else {
                //err the table is not exist
                return errNoSuchTableExist[0];
            }
        }
        else
        {
            //err that you cant delete anything from default table
            return ErrDeleteDefult[0];
        }

    }
    else {
        // err of select the database
        return SelectTheDatabase[0];
    }
}

#endif //OURDB_DATABASE_DELETE_QUERY_H