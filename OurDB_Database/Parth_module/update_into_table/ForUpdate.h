//
// Created by dabhe on 02-Jun-21.
//
//#include <iostream>
//#include <string>
//#include <ostream>
#include "../../variables/query_variables.h"
#include "../../Errors/error_variable.h"
#include "../../global_functions/global_function.h"
#include "../../External_Libraries/json.hpp"

//using namespace std;
using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_FORUPDATE_H
#define OURDB_DATABASE_FORUPDATE_H

void ForUpdate(int index,std::map<std::string,std::string>set_data,std::string table_name,std::vector <std::string>strsep3)
{
  ourdb odb;
  std::fstream fs1(table_name);
  fs1 >> odb;
   int countl=0;


    for (auto itr : set_data) {  // iterate through map vale in set_data
        for (int i = 0; i < odb["records"]["col_names"].size(); i++)  //iterate through col_names in json
        {
            if (to_string(odb["records"]["col_names"][i]) ==
                ('"' + itr.first + '"').c_str()) // matches the column in map with the column in json
            {

                std::string l = to_string(odb["records"]["col_index"][i]); // takes the value from column index ..
                odb["table_data"][index][l] = encryption(
                        itr.second); // insert the new value in the particular filed..

            }

        }


    }

    std::ofstream fsm(table_name);
    fsm << odb;  // print updated value in file from json object.

}
#endif //OURDB_DATABASE_FORUPDATE_H
