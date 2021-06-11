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
    int count = 0;
    int samecol = 0;  //var to check if there is a col with same name as another col

    if(!(databaseSelectGlobal.empty()))
    {
         validate = validation(tablename,errorSpecialchaTable[0],errFirstLetterNumeric[0]);
        // variable for storing string value which is returned by validate function
             if ( validate == "true_true")
             {
                 regex b("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed betwwen letters..
                 if ( regex_match(tablename, b) )
                 {
                     for(int i=0;i<a.size();i++)
                     {
                         validate = validation(a[i],errorSpecialchaTable[0],errFirstLetterNumeric[0]);
                         if ( validate == "true_true")
                         {
                             regex c("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed between letters..
                             if (regex_match(a[i], c))
                             {
                                 for(int j=i+1;j<a.size();j++)
                                 {
                                     if(a[i] == a[j])
                                     {
                                         samecol++;
                                     }
                                 }
                                 if(samecol==0)
                                 {
                                     count++;
                                 }
                             }
                         }
                     }

                     if(count == a.size())
                     {
                         int cnt = 0;
                         tbname = databaseSavePath +"/"+ tablename+".Ourdb"; // it adds the selected database path with tablename
                         // and also store in tbname
                         if(!(filesystem::exists(tbname.c_str()))) // if file already exist then return error..
                         {
                             FileTable(tbname); // call the filetable function which is in global_function.h

                             ourdb col;     //json(ourdb) object to add column info

                             col["records"]["total_cols"] = a.size();      //storing total cols
                             col["records"]["col_names"] = a;      //storing column names

                             for(auto &i : col["records"]["col_names"])
                             {
                                 cnt++;
                                 col["records"]["col_index"] += cnt;
                             }

                             col["records"]["last_col_index"] = cnt;

                             ofstream o(tbname);
                             o << col << endl;      // writing col data into table

                             validate = "";
                             return  SuccessCreatingFileMsg[0];     //successfully created table
                         }
                         else
                         {
                             return errTableAlreadyExist[0]; // if table already exist then returns the error..
                         }
                     }
                     else if(samecol!=0)
                     {
                         return ErrSameColName[0];      // error if 2 or more cols have same name
                     }
                     else
                     {
                        return errNamingColumn[0];      //error naming the columns
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
