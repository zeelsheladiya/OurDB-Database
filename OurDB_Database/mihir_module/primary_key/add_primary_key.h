//
// Created by Mihir on 19-08-2021.
//

#include "../../External_Libraries/json.hpp"
#include "../../global_functions/decryption.h"

using ourdb = nlohmann::json;

#ifndef CONSOLE_CPP_ADD_PRIMARY_KEY_H
#define CONSOLE_CPP_ADD_PRIMARY_KEY_H

std::string addPrimaryKey(std::string colname , std::string tbname)
{
    if(!(databaseSelectGlobal.empty()))
    {
        if(tbname == "default")
        {
            return errUpdatingDefaultTable[0];      //doesnt allow user to update the default.Ourdb file(table)
        }

        tbname = strPath[0] + databaseSelectGlobal + "/" + tbname + ".Ourdb";
        if(std::filesystem::exists(tbname.c_str()))     // checks if file exists or not
        {
            std::ifstream in(tbname);

            ourdb coldata;
            int count = 0;      //counter for checking if column exists or not

            in >> coldata;

            if(coldata["records"]["col_names"].empty())
            {
                return ErrNoColsFoundInTable[0];        //no columns exist in the table
            }

            if(coldata["records"]["primary_key"] == colname)
            {
                return ErrAlreadyAPrimaryKey[0];       //if the column is already the primary key
            }

            for(auto & i : coldata["records"]["col_names"])
            {
                if(i == colname)
                {
                    break;
                }
                count++;        //to store position of the column
            }

            if(count >= coldata["records"]["col_names"].size())
            {
                return ErrColumnDoesNotExists[0];   //if column doesnt exist in the table
            }
            else
            {
                if(!coldata["table_data"].empty())
                {
                    int countforduplicatedata = 0;
                    int countfornulldata = 0;

                    int colindex = coldata["records"]["col_index"][count];      //to store column index of the primary key column
                    std::string colindexstr = std::to_string(colindex);     //converting it to string

                    for(int i=0;i<coldata["table_data"].size();i++)
                    {
                        if(decryption(coldata["table_data"][i][colindexstr])=="null")
                        {
                            countfornulldata++;     //if it contains null data
                        }

                        for(int j=i+1;j<coldata["table_data"].size();j++)
                        {
                            if(decryption(coldata["table_data"][i][colindexstr]) == decryption(coldata["table_data"][j][colindexstr]) )
                            //if the column contains duplicate data
                            {
                                countforduplicatedata++;
                            }
                        }
                    }

                    if(countforduplicatedata==0 && countfornulldata==0)
                    {
                        coldata["records"]["primary_key"] = colname;    //sets the column as primary key
                    }
                    else if(countforduplicatedata!=0)
                    {
                        return ErrPrimaryKeyDuplData[0];        //error duplicate data exists in the column
                    }
                    else
                    {
                        return ErrPrimaryKeyNullData[0];        //error NULL data exists in the column
                    }
                }
                else
                {
                    coldata["records"]["primary_key"] = colname;        //sets the column as primary key
                }

                std::ofstream o(tbname);
                o << coldata << std::endl;

                return SuccessPrimaryKey[0];    //succesfully added primary key
            }
        }
        else
        {
            return errNoSuchTableExist[0];      //if table doesnt exists
        }
    }
    else
    {
        return SelectTheDatabase[0]; // if database is not selected before renaming then it gives error..
    }

}

#endif //CONSOLE_CPP_ADD_PRIMARY_KEY_H
