//
// Created by dabhe on 10-Jun-21.
//
#include <iostream>
#include <ostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
#include "../../External_Libraries/json.hpp"
#include "../../global_functions/encryption.h"
#include "../../global_functions/decryption.h"
#include "../../global_functions/keywords_checker.h"

//using namespace std;
using ourdb = nlohmann::json;
#ifndef OURDB_DATABASE_UPDATE_COLUMNS_H
#define OURDB_DATABASE_UPDATE_COLUMNS_H

string rename_column(string table_name,vector<string>key)
{
    if(!(databaseSelectGlobal.empty()))
    {
        int keycheck = 0;

        for(int i=1; i<key.size();i+=2)
        {
            if(keywords_checker(key[i]))
            {
                keycheck++;     //keyword var incremented if banned keyword found
            }
        }

        if(keycheck!=0)
        {
            return ErrorBannedKeywords[0];     //error for checking rename column with banned keywords
        }

        validate = validation(table_name,errorSpecialchaTable[0],errFirstLetterNumeric[0]);

        if(validate == "true_true")
        {

            regex nl("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed betwwen letters..
            if(regex_match(table_name,nl))
            {
                tbname = "";
                tbname = databaseSavePath  + "/" + table_name + ".Ourdb"; // table path where it exists..
                tname = "";
                tname=table_name; // tablename

               if(filesystem::exists(tbname))  // if filesystem exists then goes into the
               {
                   ourdb odb;  //json object..
                   fstream fs(tbname);  // filpointer points to file
                   fs >> odb; // fs data into the json object odb
                   int cunt = 0;
                   int cuntx = 0; //
                   for(int i=0;i<odb["records"]["col_names"].size();i++) //iterate through col_names in file
                   {
                       for (int j = 0; j < key.size(); j=j+2) {
                           if(key[j+1]==odb["records"]["col_names"][i]) //checks the column in the key with the column in  the file
                           {
                               cuntx++; // increment the counter if matches..
                           }
                       }
                   }

                   if(cuntx == 0) {
                       for (int i = 0; i < odb["records"]["col_names"].size(); i++) {
                           for (int j = 0; j < key.size(); j = j + 2) {
                               if (odb["records"]["col_names"][i] == key[j]) {
                                   odb["records"]["col_names"][i] = key[j + 1];
                                   cunt++;
                               }
                           }
                       }
                   }else
                   {
                       return ErrSameColumnNameExit[0]; // gives error when same name of column in tabble
                   }

                      ofstream fsm(tbname); //ofstream object
                      fsm << odb; // fsm data into the fsm

                       if(cunt > 0) {
                           return SuccessInRenamingColumn[0]; // success in renaming column
                       }else
                       {
                         return ErrorInRenameOp[0]; // renaming operation error;
                       }

               }
               else
               {
                  return tableDoesNotExist[0]; // gives error if table does not exists
               }
            }
            else
            {
                
                return errorSpecialchaTable[0]; // error for special character found..
            }
        }else
        {
            return validate;
        }
    }else
    {
        return SelectTheDatabase[0];
    }
}







#endif //OURDB_DATABASE_UPDATE_COLUMNS_H
