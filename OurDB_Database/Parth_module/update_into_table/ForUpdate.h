//
// Created by dabhe on 02-Jun-21.
//
#include <iostream>
#include <string>
#include <stdio.h>
#include <ostream>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
#include "../../External_Libraries/json.hpp"

using namespace std;
using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_FORUPDATE_H
#define OURDB_DATABASE_FORUPDATE_H

void ForUpdate(int index,map<string,string>set_data,string table_name)
{
  ourdb odb;
  fstream fs1(table_name);
  fs1 >> odb;

  map<string, string>::iterator itr;
  for( itr = set_data.begin(); itr != set_data.end(); ++itr) {
      for(int i=0;i<odb["records"]["total_cols"];i++)
      {
          if(odb["records"]["col_names"][i] == itr->first)
          {
              string l = to_string(i+1);
              odb["table_data"][index][l] = encryption(itr->second);

          }

      }

    }

   ofstream fsm(table_name);
    fsm << odb;

}
#endif //OURDB_DATABASE_FORUPDATE_H
