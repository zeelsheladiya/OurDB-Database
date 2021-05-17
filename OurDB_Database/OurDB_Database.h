//
// this is ourdb database which is created by zeel sheladiya , mihir surati , parth dabheliya , pranav patel
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "query_process.h"
#include <cctype>
#include "global_functions/global_function.h"

using namespace std;

#ifndef OURDB_DATABASE_OURDB_DATABASE_H
#define OURDB_DATABASE_OURDB_DATABASE_H

string run_query(string query)
{
    //trim space from string
    trim(query);

    // replace multi space into one space
    string::iterator query_string_of_space  = unique(query.begin(), query.end(), BothAreSpaces);
    query.erase(query_string_of_space,query.end());

    //convert whole string into lowercase
    transform(query.begin(),query.end(),query.begin(), [](unsigned char c){ return std::tolower(c); });

    //declaration of variable for string array
    vector<string> query_string;

    //split using char
    split(query, split_char, query_string);

    //assign size of string to global string variable
    query_size = query_string.size();

    //returning string value from query_process function
    return query_process(query_string);
    //return query;

}


#endif //OURDB_DATABASE_OURDB_DATABASE_H