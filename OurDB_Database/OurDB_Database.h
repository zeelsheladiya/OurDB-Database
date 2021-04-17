//
// this is ourdb database which is created by zeel sheladiya , mihir surati , parth dabheliya
//


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "query_process.h"
#include <cctype>

using namespace std;

#ifndef OURDB_DATABASE_OURDB_DATABASE_H
#define OURDB_DATABASE_OURDB_DATABASE_H

//function for trimming string from front
string& ltrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

//function for trimming string from end
string& rtrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

//function for trimming string from the both side
string& trim(string& str, const string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}

// function for replace all space form string into one space
bool BothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }

// split function for string into string array
void split(string const &str, const char delim,vector<string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

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