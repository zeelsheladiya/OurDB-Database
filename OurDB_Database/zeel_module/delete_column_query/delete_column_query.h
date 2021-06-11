//
// Created by zeel,pranav on 10/06/2021.
//
#include <iostream>
#include <string>
#include <regex>
#include <filesystem>
#include "delete_column_query_logic.h"

#ifndef OURDB_DATABASE_DELETE_COLUMN_QUERY_H
#define OURDB_DATABASE_DELETE_COLUMN_QUERY_H

string DeleteColumnQuery(string table_name,string column_name)
{
    if(databaseSelectGlobal != "") // check, is datebase selected or not
    {
        if(table_name != "default") // check, table should not be default
        {
            // table path into string
            string table_path = "../Databases/" + databaseSelectGlobal + "/" + table_name + ".Ourdb";

            // check whether file is exist or not
            if (filesystem::exists(table_path.c_str()))
            {
                // read .ourdb file
                ifstream file(table_path);
                json j;
                file >> j;

                // variable for storing index of column
                int column_index = 0;

                // loop for getting index number of matched column and for checking whether column exist into table or not
                for(int i = 0 ; i < j["records"]["col_names"].size() ; i++ )
                {
                    if(j["records"]["col_names"][i] == column_name)
                    {
                        column_index = i + 1;
                        break;
                    }
                }

                if(column_index > 0)
                {
                    // column exist so process toward the delete column from the table
                    return delete_column_query_logic_1(table_path,column_index);
                }
                else
                {
                    // column does not exist into the table
                    return ErrorColumnNotExist[0];
                }

            }
            else
            {
                //err the table is not exist
                return errNoSuchTableExist[0];
            }

        }
        else
        {
            // default table can not be deleted
            return ErrDeleteDefult[0];
        }
    }
    else
    {
        // database should be selected
        return SelectTheDatabase[0];
    }
}

#endif //OURDB_DATABASE_DELETE_COLUMN_QUERY_H