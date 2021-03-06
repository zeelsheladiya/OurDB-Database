//
// this is ourdb database which is created by zeel sheladiya , mihir surati , parth dabheliya , pranav patel
//


//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
#include "query_process.h"
//#include <cctype>
#include "global_functions/global_function.h"
#include "External_Libraries/json.hpp"
#include "mihir_module/return_object/m_to_json.h"
#include "Parth_module/return_object/p_to_stringTable.h"
#include "zeel_module/return_object/z_to_map.h"
#include "Errors/error_variable.h"

using ourdb = nlohmann::json;



#ifndef OURDB_DATABASE_OURDB_DATABASE_H
#define OURDB_DATABASE_OURDB_DATABASE_H

std::string run_query(std::string query)
{
    //query should not be null
    if(query.empty())
    {
        return querySyntaxError[0];
    }

    replace(query.begin(),query.end(),'\n',' ');

    //trim space from string
    trim(query);

    // replace multi space into one space
    std::string::iterator query_string_of_space  = unique(query.begin(), query.end(), BothAreSpaces);
    query.erase(query_string_of_space,query.end());

    //convert whole string into lowercase
    transform(query.begin(),query.end(),query.begin(), [](unsigned char c){ return std::tolower(c); });

    //declaration of variable for string array
    std::vector<std::string> query_string;

    //split using char
    split(query, split_char, query_string);

    //assign size of string to global string variable
    query_size = query_string.size();

    //returning string value from query_process function
    return query_process(query_string);
    //return query;

}

ourdb To_Json(std::string result)
{
    return m_to_json(result);
}

std::string To_StringTable(std::string result)
{
    return p_to_stringTable(result);
}

std::map<std::string,std::vector<std::string>>  To_Map(std::string result)
{
    return z_to_map(result);
}

#endif //OURDB_DATABASE_OURDB_DATABASE_H