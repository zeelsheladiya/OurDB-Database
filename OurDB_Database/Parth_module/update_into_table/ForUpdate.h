//
// Created by dabhe on 02-Jun-21.
//
#include <iostream>
#include <string>
#include <stdio.h>
#include <ostream>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../Errors/error_variable.h"
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

  for( auto itr : set_data) {  // iterate through map vale in set_data
      for(int i=0;i<odb["records"]["col_names"].size();i++)  //iterate through col_names in json
      {
          if(to_string(odb["records"]["col_names"][i]) == ('"' + itr.first + '"').c_str()) // matches the column in map with the column in json
          {
              string l = to_string(odb["records"]["col_index"][i]); // takes the value from column index ..
              odb["table_data"][index][l] = encryption(itr.second); // insert the new value in the particular filed..
          }

      }

    }

  ofstream fsm(table_name);
  fsm << odb;  // print updated value in file from json object.

}
#endif //OURDB_DATABASE_FORUPDATE_H
