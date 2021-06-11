//
// Created by Mihir on 10-06-2021.
//

#include <iostream>
#include <ostream>
#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
#include "../../External_Libraries/json.hpp"

using namespace std;
using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_ADD_COLUMN_H
#define OURDB_DATABASE_ADD_COLUMN_H

string addColumn(string tablename,vector<string> a)
{
    if(!(databaseSelectGlobal.empty()))
    {
        if(tablename == "default")
        {
            return ErrDataManipulationInDefault[0];       //error if user tries to insert into default table
        }
        else
        {
            string path = databaseSavePath + "/" + tablename + ".Ourdb";       //path where table is stored

            if(filesystem::exists(path))        //checks if table exists or not
            {
                ifstream in(path);

                ourdb coldata;      //var to store json data

                in >> coldata;      //taking json data from table into coldata variable

                int tc = coldata["records"]["total_cols"];      //var to store total cols in table

                for(auto & newcol : a)      //loop to add the new column/s name in table
                {
                    coldata["records"]["col_names"] += newcol;
                }

                for(auto & i : coldata["table_data"])       //looping the data already present in table
                {
                    for(int j=1;j<=a.size();j++)        //loop to check how many new column/s data we need to add
                    {
                        i[to_string(j+tc)] = "";        //setting the newly added column/s data ad NULL
                    }
                }

                tc += a.size();        //changing the total column number as new cols are added
                coldata["records"]["total_cols"] = tc;

                ofstream o(path);
                o << coldata;       //parsing the json data to table

                return "Column added successfully!!!";
            }
            else
            {
                return errNoSuchTableExist[0];      //error if table doesnt exist
            }
        }
    }
    else
    {
        return SelectTheDatabase[0];        //select database error if database isn't selected
    }
}

#endif //OURDB_DATABASE_ADD_COLUMN_H