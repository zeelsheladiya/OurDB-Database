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
                return ErrNoColsFoundInTable[0];
            }

            if(coldata["records"]["primary_key"] == colname)
            {
                return "This col is already a primary key!!";
            }

            for(auto & i : coldata["records"]["col_names"])
            {
                if(i == colname)
                {
                    break;
                }
                count++;
            }

            if(count >= coldata["records"]["col_names"].size())
            {
                return ErrColumnDoesNotExists[0];
            }
            else
            {
                //std::cout <<count << std::endl;
                if(!coldata["table_data"].empty())
                {
                    //std::cout << "2"<< std::endl;
                    int countforduplicatedata = 0;

                    int colindex = coldata["records"]["col_index"][count];
                    std::string colindexstr = std::to_string(colindex);

                    for(int i=0;i<coldata["table_data"].size()-1;i++)
                    {
                        for(int j=i+1;j<coldata["table_data"].size();j++)
                        {
                            if(decryption(coldata["table_data"][i][colindexstr]) == decryption(coldata["table_data"][j][colindexstr]) )
                            {
                                //std::cout << "mul data found!"<< std::endl;
                                if(decryption(coldata["table_data"][i][colindexstr]) != "null")
                                {
                                    countforduplicatedata++;
                                }
                            }
                        }
                    }

                    if(countforduplicatedata==0)
                    {
                        coldata["records"]["primary_key"] = colname;
                    }
                    else
                    {
                        return ErrPrimaryKeyDuplData[0];
                    }
                }
                else
                {
                    coldata["records"]["primary_key"] = colname;
                }

                std::ofstream o(tbname);
                o << coldata << std::endl;

                return SuccessPrimaryKey[0];
            }
        }
        else
        {
            return errNoSuchTableExist[0];
        }
    }
    else
    {
        return SelectTheDatabase[0]; // if database is not selected before renaming then it gives error..
    }

}

#endif //CONSOLE_CPP_ADD_PRIMARY_KEY_H
