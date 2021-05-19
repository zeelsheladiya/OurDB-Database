//
// Created by zeel,mihir,parth,pranav on 17/05/2021.
//

#include <iostream>
#include <ostream>
#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
#include "../../External_Libraries/json.hpp"
#include "../../global_functions/encryption.h"
#include "../../global_functions/decryption.h"

using namespace std;
using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_INSERT_INTO_TABLE_H
#define OURDB_DATABASE_INSERT_INTO_TABLE_H

string insertIntoTable(string tbname,vector<string> a)
{
    if(!(databaseSelectGlobal.empty()))
    {
        validate = validation(tbname,errorSpecialchaTable[0],errFirstLetterNumeric[0]);
        // variable for storing string value which is returned by validate function
        if ( validate == "true_true")
        {
            regex b("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed between letters..
            if ( regex_match(tbname, b) )
            {
                string path = databaseSavePath +"/"+ tbname+".Ourdb";       //path where table is stored
                ifstream in(path);

                ourdb coldata;
                ourdb tbdata;

                in>>coldata;

                if(a.size() == coldata["records"]["total_cols"])       //checks if no. of data inserted is equals to no. of columns in the table
                {

                    string tmp;
                    for(int i=0;i< a.size();i++)
                    {
                        tmp = coldata["records"]["col_names"][i];      //temporary variable to store column related data
                        tbdata["table_data"][tmp] = encryption(a[i]);       //data encrypted and added to tbdata

                    }
                    coldata["table_data"] += tbdata["table_data"];      //data appended to table from tbdata
                    ofstream o(path);
                    o<<coldata<<endl;
                    return SuccessInsertDataTableMsg[0];       //successfully inserted data into table
                }
                else
                {
                    return ErrDataNotEqualToNoOfCols[0];        //error if no. of cols isnt equal to no. of data inserted
                }
            }
            else
            {
                return errorSpecialchaTable[0]; // error for special character found..
            }
        }
        else if(validate!="true_true")
        {
            return validate; // if validation some how fails this shows.
        }

    }
    else
    {
        return SelectTheDatabase[0];        //select database error if database isnt selected
    }
}

#endif //OURDB_DATABASE_INSERT_INTO_TABLE_H
