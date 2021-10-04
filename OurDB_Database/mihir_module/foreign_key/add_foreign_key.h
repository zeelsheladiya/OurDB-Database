//
// Created by Mihir on 01-10-2021.
//

#include "../../External_Libraries/json.hpp"
#include "../../global_functions/decryption.h"
#include <algorithm>

using ourdb = nlohmann::json;

#ifndef CONSOLE_CPP_ADD_FOREIGN_KEY_H
#define CONSOLE_CPP_ADD_FOREIGN_KEY_H

std::string addForeignKey(std::string frcolname,std::string frtbname,std::string prtbname)
{
    if(!(databaseSelectGlobal.empty()))
    {
        if(frtbname == "default" || prtbname == "default")
        {
            return errUpdatingDefaultTable[0];      //doesnt allow user to update the default.Ourdb file(table)
        }

        std::string frtb = strPath[0] + databaseSelectGlobal + "/" + frtbname + ".Ourdb";   //path of foreign key's table
        std::string prtb = strPath[0] + databaseSelectGlobal + "/" + prtbname + ".Ourdb";   //path of primary table

        if(std::filesystem::exists(frtb.c_str()) && std::filesystem::exists(prtb.c_str()))     // checks if file exists or not
        {
            std::ifstream infr(frtb);
            std::ifstream inpr(prtb);

            ourdb prcoldata;
            ourdb frcoldata;
            ourdb frdatafinal;      //temp var to store foreign key and add it to foreign key table

            infr >> frcoldata;
            inpr >> prcoldata;

            if(prcoldata["records"]["col_names"].empty() || frcoldata["records"]["col_names"].empty())
            {
                return ErrNoColsFoundInTable[0];        //if no columns exist in the table
            }
            if(prcoldata["records"]["primary_key"].empty())
            {
                return ErrNoPrimaryKeyFound[0];     //if there is no primary key in primary table
            }

            if(!frcoldata["records"]["foreign_key"].empty())
            {
                for(auto & i : frcoldata["records"]["foreign_key"])
                {
                    if(i[0] == frcolname)
                    {
                        return ErrAlreadyAForeignKey[0];    //if you try to add a foreign key that is already a foreign key to another or same primary table
                    }
                }
            }

            std::string prkeycol = prcoldata["records"]["primary_key"];     //primary key of primary table

            int countforpkey = 0;   //to count primary key's index in primary table
            int countforfkey = 0;   //to count foreign key's index in its table

            for(auto & i : prcoldata["records"]["col_names"])
            {
                if(i == prkeycol)
                {
                    break;
                }
                countforpkey++;
            }

            for(auto & i : frcoldata["records"]["col_names"])
            {
                if(i == frcolname)
                {
                    break;
                }
                countforfkey++;
            }

            if(countforfkey >= frcoldata["records"]["col_names"].size())
            {
                return ErrColumnDoesNotExists[0];   //if column doesnt exist in the table
            }

            if(frcoldata["table_data"].empty())
            {
                frdatafinal["records"]["foreign_key"] = {frcolname,prtbname};   //sets foreign key col data in pair of column_name and primary_table_name

                frcoldata["records"]["foreign_key"] += frdatafinal["records"]["foreign_key"];    //adds it to table's column data

                std::ofstream ofr(frtb);    //writes on the table (file)
                ofr << frcoldata << std::endl;

                return SuccessForeignKey[0];    //succesfully added foreign key!
            }
            else if(prcoldata["table_data"].empty() && !(frcoldata["table_data"].empty()))
            {
                return ErrForeignKeyConstraintViolated[0];      //if theres no data in primary table's primary key column
            }
            else
            {
                int prcolindex = prcoldata["records"]["col_index"][countforpkey];      //to store column index of the primary key column
                std::string prcolindexstr = std::to_string(prcolindex);     //converting it to string

                int frcolindex = frcoldata["records"]["col_index"][countforfkey];       //to store column index of the primary key column
                std::string frcolindexstr = std::to_string(frcolindex);     //converting it to string

                std::vector<std::string> arrprdata;     //to store primary columns data

                for(auto & i : prcoldata["table_data"])
                {
                    arrprdata.insert(arrprdata.end(), decryption(i[prcolindexstr]));    //inserting primary col's data into a vector<string>
                }

                int countforfrdatacheck = 0;       //to check if foreign key col's data is valid acc to primary key's data or not

                for(auto& i : frcoldata["table_data"])
                {
                    std::string frdata = decryption(i[frcolindexstr]);

                    if(std::count(arrprdata.begin(),arrprdata.end(), frdata))
                    {
                        countforfrdatacheck++;      //increases if data is found and so is valid
                    }
                }

                if(countforfrdatacheck == frcoldata["table_data"].size())       //if all of the data are valid
                {
                    frdatafinal["records"]["foreign_key"] = {frcolname,prtbname};   //sets foreign key col data in pair of column_name and primary_table_name

                    frcoldata["records"]["foreign_key"] += frdatafinal["records"]["foreign_key"];   //adds it to table's column data

                    std::ofstream ofr(frtb);    //writes on the table (file)
                    ofr << frcoldata << std::endl;

                    return SuccessForeignKey[0];    //succesfully added foreign key!
                }
                else
                {
                    return ErrCantAddForeignKey[0];     //if data isnt valid acc to primary col's data
                }
            }
        }
        else
        {
            return tableDoesNotExist[0];    //if either of the tables doesnt exist
        }
    }
    else
    {
        return SelectTheDatabase[0];    //if database is not selected
    }
}

#endif //CONSOLE_CPP_ADD_FOREIGN_KEY_H
