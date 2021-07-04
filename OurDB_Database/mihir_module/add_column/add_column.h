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
            int samecol = 0;
            int colaldthere = 0;
            int keycheck = 0;

            string path = databaseSavePath + "/" + tablename + ".Ourdb";       //path where table is stored

            if(filesystem::exists(path))        //checks if table exists or not
            {
                ifstream in(path);

                ourdb coldata;      //var to store json data

                in >> coldata;      //taking json data from table into coldata variable
                for(int i=0;i<a.size();i++)
                {
                    if(keywords_checker(a[i]))
                    {
                        keycheck++;     //increments if banned keyword found in col name
                    }
                    for(auto & newcol : coldata["records"]["col_names"])
                    {
                        if(newcol == a[i])
                        {
                            colaldthere++;      //increments if col already there in table
                        }
                    }
                    for(int j=i+1;j<a.size();j++)
                    {
                        if(a[i] == a[j])
                        {
                            samecol++;      //increments if tries to add same col name
                        }
                    }
                }

                if(samecol==0 && colaldthere==0 && keycheck==0)
                {
                    int tc = coldata["records"]["total_cols"];      //var to store total cols in table
                    int lastind = coldata["records"]["last_col_index"];
                    int tlast = lastind;

                    for (auto &newcol : a)      //loop to add the new column/s name in table
                    {
                        coldata["records"]["col_names"] += newcol;
                        coldata["records"]["col_index"] += ++tlast;
                    }

                    for (auto &i : coldata["table_data"])       //looping the data already present in table
                    {
                        for (int j = 1; j <= a.size(); j++)        //loop to check how many new column/s data we need to add
                        {
                            i[to_string(j + lastind)] = encryption("null");        //setting the newly added column/s data as NULL
                        }
                    }

                    tc += a.size();        //changing the total column number as new cols are added
                    lastind += a.size();

                    coldata["records"]["total_cols"] = tc;
                    coldata["records"]["last_col_index"] = lastind;

                    ofstream o(path);
                    o << coldata;       //parsing the json data to table

                    return SuccessAddColumnMsg[0];      //column added successfully
                }
                else if(samecol!=0)
                {
                    return ErrAddingSameColName[0];        //error adding same column name
                }
                else if(keycheck!=0)
                {
                    return ErrorBannedKeywords[0];      //error adding banned keywords as column name
                }
                else
                {
                    return ErrSameColName[0];       //error column already there in table
                }
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