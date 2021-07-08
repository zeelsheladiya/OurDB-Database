//
// Created by Mihir on 15-05-2021.
//

#include <iostream>
#include <ostream>
#include <iostream>
#include <string>
#include <filesystem>
#include "../variables/query_variables.h"
#include "../global_functions/global_function.h"
#include "../External_Libraries/json.hpp"

using namespace std;
using ourdb = nlohmann::json;

#ifndef OURDB_DATABASE_ENCRYPTION_H
#define OURDB_DATABASE_ENCRYPTION_H

string encryption(string data) // code for encryption
{
    //here goes encryption code..
    enc_dec=""; // variable in variable.h file

    for(char c : data)
    {
        //logic of encryption...
        enc_dec += c ^ 69;

    }
  //return the encrypt data
    return enc_dec;
}

#endif //OURDB_DATABASE_ENCRYPTION_H
