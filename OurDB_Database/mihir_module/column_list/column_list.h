//
// Created by Mihir on 04-07-2021.
//

#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../External_Libraries/json.hpp"

//using namespace std;
using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_COLUMN_LIST_H
#define OURDB_DATABASE_COLUMN_LIST_H

string columnList(string tablename)
{
    if(!(databaseSelectGlobal.empty()))
    {
        string path = databaseSavePath + "/" + tablename + ".Ourdb";       //path where table is stored

        if(filesystem::exists(path))
        {
            if(tablename == "default")
            {
                return "Can't access default table!!";
            }
            else
            {
                string collist;
                ifstream in(path);

                ourdb coldata;      //var to store json data

                in >> coldata;      //taking json data from table into coldata variable

                if(coldata["records"]["col_names"].empty())
                {
                    return ErrNoDataFoundInTable[0];
                }

                collist += "Columns in table " + tablename + " are :\n\t";

                for(auto &i : coldata["records"]["col_names"])
                {
                    collist += i;
                    collist += "\n\t";
                }

                return collist;
            }
        }
        else
        {
            return tableDoesNotExist[0];
        }
    }
    else
    {
        return SelectTheDatabase[0];        //select database error if database isn't selected
    }
}

#endif //OURDB_DATABASE_COLUMN_LIST_H
