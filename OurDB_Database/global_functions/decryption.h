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

#ifndef OURDB_DATABASE_DECRYPTION_H
#define OURDB_DATABASE_DECRYPTION_H

string decryption(string data) // code for decryption
{
    //here goes decryption code..
    enc_dec=""; // variable resides in variable.h
    for(char c : data)
    {
        // logic for decryption
        enc_dec += c ^ 69;
    }

    return enc_dec;//return the decrypted data
}

#endif //OURDB_DATABASE_DECRYPTION_H
