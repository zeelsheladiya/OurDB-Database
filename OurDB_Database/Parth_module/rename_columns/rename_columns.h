//
// Created by dabhe on 10-Jun-21.
//
#include <iostream>
#include <ostream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
#include "../../External_Libraries/json.hpp"
#include "../../global_functions/encryption.h"
#include "../../global_functions/decryption.h"

using namespace std;
using ourdb = nlohmann::json;
#ifndef OURDB_DATABASE_UPDATE_COLUMNS_H
#define OURDB_DATABASE_UPDATE_COLUMNS_H

string rename_column(string table_name,vector<string>key)
{
    if(!(databaseSelectGlobal.empty()))
    {
        validate = validation(table_name,errorSpecialchaTable[0],errFirstLetterNumeric[0]);

        if(validate == "true_true")
        {
            regex nl("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed betwwen letters..
            if(regex_match(table_name,nl))
            {
                tbname = "";
                tbname = databaseSavePath  + "/" + table_name + ".Ourdb";
                tname = "";
                tname=table_name;

               if(filesystem::exists(tbname))
               {
                   ourdb odb;
                   fstream fs(tbname);
                   fs >> odb;
                   remove(tbname.c_str());
                   string svPth1 =  databaseSavePath  + "/" + tname + ".Ourdb";
                   int cunt = 0;
                  for(int i=0;i<odb["records"]["col_names"].size();i++)
                  {
                      for (int j = 0; j < key.size(); j=j+2) {
                          if(odb["records"]["col_names"][i] == key[j])
                          {
                              odb["records"]["col_names"][i] = key[j+1];
                              cunt++;
                          }
                      }
                  }
                  fstream fsm(svPth1);
                  odb >> fsm;

                   if(cunt > 0) {
                       return SuccessInRenamingColumn[0];
                   }else
                   {
                     return ErrorInRenameOp[0];
                   }

               }
               else
               {
                  return tableDoesNotExist[0];
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