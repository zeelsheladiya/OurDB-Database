//
// Created by Micron on 02/06/2021.
//
#include <iostream>
#include <string>
#include <regex>
#include <filesystem>
#include "../../External_Libraries/json.hpp"

using namespace std;
using json = nlohmann::json;

#ifndef OURDB_DATABASE_DELETE_QUERY_LOGIC_H
#define OURDB_DATABASE_DELETE_QUERY_LOGIC_H

void DeleteColumnFunc(string table_name , int index)
{
    ifstream i("../Databases/" + databaseSelectGlobal + "/" + table_name + ".Ourdb");
    json j;
    i >> j;

    j["table_data"].erase(index);

    ofstream o("../Databases/" + databaseSelectGlobal + "/" + table_name + ".Ourdb");
    o << j << endl;
}

#endif //OURDB_DATABASE_DELETE_QUERY_LOGIC_H