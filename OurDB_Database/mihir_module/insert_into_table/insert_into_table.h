//
// Created by zeel,mihir,parth,pranav on 17/05/2021.
//

#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
#include "../../External_Libraries/json.hpp"
#include "../../global_functions/encryption.h"
#include "../../global_functions/decryption.h"

using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_INSERT_INTO_TABLE_H
#define OURDB_DATABASE_INSERT_INTO_TABLE_H

std::string insertIntoTable(std::string tbname,std::vector<std::string> a)
{
    if(!(databaseSelectGlobal.empty()))
    {
        if(tbname == "default")
        {
            return ErrDataManipulationInDefault[0];       //error if user tries to insert into default table
        }
        else
        {
            std::string path = databaseSavePath + "/" + tbname + ".Ourdb";       //path where table is stored

            std::ifstream in(path);

            ourdb coldata;
            ourdb tbdata;

            in >> coldata;

            if (a.size() == coldata["records"]["total_cols"])       //checks if no. of data inserted is equals to no. of columns in the table
            {
                std::string tmp;
                std::vector <std::string> st;

                for (auto& x : coldata["records"]["col_index"].items())
                    st.insert(st.end(), to_string(x.value()));

                if(!coldata["records"]["primary_key"].empty())      //checks if primary key is set on table or not
                {
                    std::string primarykey = coldata["records"]["primary_key"];

                    int prcount=0;        //counter for index of column_name
                    for(auto & i : coldata["records"]["col_names"])
                    {
                        if(i == primarykey)
                        {
                            break;
                        }
                        prcount++;
                    }

                    if(a[prcount].empty())    //if user tries to insert null data in primary key
                    {
                        return ErrPrimaryKeyConstraintViolation[0];     //primary key constraint violated
                    }

                    int colindex = coldata["records"]["col_index"][prcount];      //to store column index of the primary key column
                    std::string colindexstr = std::to_string(colindex);     //converting it to string

                    for(auto & i : coldata["table_data"])
                    {
                        if(a[prcount] == decryption(i[colindexstr]))      //checks if duplicate data is being added to the primary key
                        {
                            return ErrPrimaryKeyConstraintViolation[0];     //primary key constraint violated
                        }
                    }
                }

                if(!coldata["records"]["foreign_key"].empty())      //checks if foreign key is set on table or not
                {
                    for(auto & i : coldata["records"]["foreign_key"])
                    {
                        std::string foreignkey = i[0];      //stores foreign key for checking
                        std::string prtbname = i[1];
                        ourdb prtabledata;

                        std::string prtbpath = strPath[0] + databaseSelectGlobal + "/" + prtbname + ".Ourdb";

                        if(!std::filesystem::exists(prtbpath.c_str()))
                        {
                            return errNoSuchTableExist[0];
                        }

                        std::ifstream prin(prtbpath);

                        prin >> prtabledata;

                        int frcount=0;        //counter for index of foreign key column_name
                        for(auto & j : coldata["records"]["col_names"])
                        {
                            if(j == foreignkey)
                            {
                                break;
                            }
                            frcount++;
                        }

                        std::string prtbprimarykey = prtabledata["records"]["primary_key"];     //primary table's primary key

                        int prcount=0;        //counter for index of primary column_name
                        for(auto & j : prtabledata["records"]["col_names"])
                        {
                            if(j == prtbprimarykey)
                            {
                                break;
                            }
                            prcount++;
                        }

                        int frcolindex = coldata["records"]["col_index"][frcount];      //to store column index of the foreign key column
                        std::string frcolindexstr = std::to_string(frcolindex);     //converting it to string

                        int prcolindex = prtabledata["records"]["col_index"][prcount];      //to store column index of the primary key column
                        std::string prcolindexstr = std::to_string(prcolindex);     //converting it to string

                        int frdatachecker = 0;

                        for(auto & k : prtabledata["table_data"])
                        {
                            if(a[frcount] == decryption(k[prcolindexstr]))      //checks if duplicate data is being added to the primary key
                            {
                                break;
                            }
                            frdatachecker++;
                        }

                        if(frdatachecker == prtabledata["table_data"].size())
                        {
                            return ErrForeignKeyConstraintViolated[0];      //if data in foreign key is not found in the primary key it is asociated with
                        }
                    }
                }

                for (int i = 0; i < a.size(); i++)
                {
                    //tbdata["table_data"][to_string(i+1)] = encryption(a[i]);       //data encrypted and added to tbdata
                    if(a[i].empty())
                    {
                        a[i] = "null";
                    }
                    tbdata["table_data"][st[i]] = encryption(a[i]);       //data encrypted and added to tbdata
                }

                coldata["table_data"] += tbdata["table_data"];      //data appended to table from tbdata
                std::ofstream o(path);
                o << coldata << std::endl;

                return SuccessInsertDataTableMsg[0];       //successfully inserted data into table
            }
            else
            {
                return ErrDataNotEqualToNoOfCols[0];        //error if no. of cols isnt equal to no. of data inserted
            }

        }
    }
    else
    {
        return SelectTheDatabase[0];        //select database error if database isnt selected
    }
}

#endif //OURDB_DATABASE_INSERT_INTO_TABLE_H