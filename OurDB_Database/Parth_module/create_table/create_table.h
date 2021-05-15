//
// Created by dabhe on 05-May-21.
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

#ifndef OURDB_DATABASE_CREATE_TABLE_H
#define OURDB_DATABASE_CREATE_TABLE_H

string createTable(string tablename ,vector <string> a)
{
    int i;
    int count = 0;

    if(!(databaseSelectGlobal.empty()))
    {
         validate = validation(tablename,errorSpecialchaTable[0],errFirstLetterNumeric[0]);
        // variable for storing string value which is returned by validate function
             if ( validate == "true_true")
             {
                 regex b("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed betwwen letters..
                 if ( regex_match(tablename, b) )
                 {
                     for(i=0;i<a.size();i++)
                     {
                         validate = validation(a[i],errorSpecialchaTable[0],errFirstLetterNumeric[0]);
                         if ( validate == "true_true")
                         {
                             regex c("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed betwwen letters..
                             if (regex_match(tablename, c))
                             {
                                 count++;
                             }
                         }
                     }

                     if(count == a.size())
                     {
                         tbname = databaseSavePath +"/"+ tablename+".Ourdb"; // it adds the selected database path with tablename
                         // and also store in tbname
                         if(!(filesystem::exists(tbname.c_str()))) // if file already exist then return error..
                         {
                             FileTable(tbname); // call the filetable function which is in global_function.h

                             ourdb col;     //json(ourdb) object to add column info
                             col["col_data"]["total_cols"] = a.size();      //storing total cols
                             col["col_data"]["col_names"] = a;      //storing column names
                             ofstream o(tbname);        //
                             o << col << endl;      // writing into table

                             validate = "";
                             return  SuccessCreatingFileMsg[0];
                         }
                         else
                         {
                             return errTableAlreadyExist[0]; // if table already exist then returns the error..
                         }
                     }
                    else
                     {
                        return errNamingColumn[0];
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
        return SelectTheDatabase[0]; // if database is not select then returns the error.
    }
}


#endif //OURDB_DATABASE_CREATE_TABLE_H
