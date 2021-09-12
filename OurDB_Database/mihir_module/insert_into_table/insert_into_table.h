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

                    int count=0;        //counter for index of column_name
                    for(auto & i : coldata["records"]["col_names"])
                    {
                        if(i == primarykey)
                        {
                            break;
                        }
                        count++;
                    }

                    if(a[count].empty())    //if user tries to insert null data in primary key
                    {
                        return ErrPrimaryKeyConstraintViolation[0];     //primary key constraint violated
                    }

                    int colindex = coldata["records"]["col_index"][count];      //to store column index of the primary key column
                    std::string colindexstr = std::to_string(colindex);     //converting it to string

                    for(auto & i : coldata["table_data"])
                    {
                        if(a[count] == decryption(i[colindexstr]))      //checks if duplicate data is being added to the primary key
                        {
                            return ErrPrimaryKeyConstraintViolation[0];     //primary key constraint violated
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