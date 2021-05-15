//
// Created by Mihir on 15-05-2021.
//

#include <iostream>
#include <ostream>
#include <iostream>
#include <string>
#include <filesystem>
#include "../../variables/query_variables.h"
#include "../../global_functions/global_function.h"
#include "../../External_Libraries/json.hpp"

using namespace std;
using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_ENCRYPTION_H
#define OURDB_DATABASE_ENCRYPTION_H

string encryption(string data)
{
    //here goes encryption code..
    return data;
}

#endif //OURDB_DATABASE_ENCRYPTION_H
