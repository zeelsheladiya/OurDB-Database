//
// Created by zeel,mihir,parth on 05-May-21.
//

#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <conio.h>
#include <filesystem>
#include <numeric>
#include <algorithm>
#include "Errors/error_variable.h"

//using namespace std;
#ifndef OURDB_DATABASE_GLOBAL_FUNCTION_H
#define OURDB_DATABASE_GLOBAL_FUNCTION_H

// functions in this header file ----------------------------------------------------------------
// validation function
// filetable function for create table
// ltrim function to trim left side
// rtrim function to trim right side
// trim function to trim both side
// botharespacies function to check multiple spaces in string
// split function for string into string array
// function for remove null values into vector string

//---------------------------------------------------------------------------------------------

// check word with global word variable
template<class Element, class Container>
bool syntaxCompare(const Element & keyvalue ,const Container & variablearray)
{
    return find(begin(variablearray), end(variablearray), keyvalue) != end(variablearray);
}

// string validation in terms of name
inline std::string validation(std::string dbname,std::string ferror,std::string serror)
{
    firstLetterStore = dbname.front();  //store the first character of string
    lastLetterStore = dbname.back(); // stores last character of string
    if(firstLetterStore >= 97 && firstLetterStore <= 122)   // check whether the first character is between "a to z" or not
    {
        if((lastLetterStore >= 32 && lastLetterStore <= 47)  ||(lastLetterStore >= 58 && lastLetterStore <= 92) || (lastLetterStore >= 123 && lastLetterStore <= 126)) // check for special character
        {
            return ferror; // returns ferror variable i.e. no spl char allowed in db/table name

        }else{

            return "true_true"; // return true_true for execution of these block
        }
    }
    else if((firstLetterStore >= 48 && firstLetterStore <= 57)) // check if character is not between "a to z"...
    {
        return serror; // returns serror variable i.e. first letter cant be a numeric value

    }else if(!(firstLetterStore >= 97 && firstLetterStore <= 122)){

      return ferror;  // returns ferror variable i.e. no spl char allowed in db/table name
    }

}

// create file in terms of table
inline std::string FileTable(std::string nm)
{
    std::fstream tb; // creats the object of class "fstream"...   here "tb" obj is created
    tb.open(nm,std::ios::in | std::ios::out | std::ios::trunc ); // in for writing , out for writing and trunc
    if(!tb.is_open()) // is_open is defined in "fstream" which check file is created or not if created then open it
    {
        return errorCreatingFile[0]; // defined in Errors/error_variable.h
    }
    tb.close(); // closes the file

   return SuccessCreatingFileMsg[0];
}

//function for trimming string from front
inline std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

//function for trimming string from end
inline std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

//function for trimming string from the both side
inline std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}

// function for replace all space form string into one space
inline bool BothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }

// split function for string into string array
inline void split(std::string const &str, const char delim,std::vector<std::string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

//separate the query after specific position (after '@' to be precise)
std::vector <std::string> InputStringSeparation(std::vector <std::string> arr)
{
    if(!(databaseSelectGlobal.empty()))
    {
        std::string tbname = arr[2];       //var to store table name and check if it exists or not!
        std::string path = databaseSavePath + "/" + tbname + ".Ourdb";       //path where table is stored

        if(std::filesystem::exists(path.c_str()))        //checks if the path is valid i.e. if table exists or not
        {
            std::string temp;        //string to store vector string array

            for(int i=0;i<arr.size();i++)
            {
                temp += arr[i] + " ";       //stores data into string after separating them by space
            }

            temp = regex_replace(temp,std::regex("' "),"'"); // trim the left side of the space into single quote
            temp = regex_replace(temp,std::regex(" '"),"'"); // trim the right side of the space into single quote

            float count = std::count(temp.begin(), temp.end(), '\'');     //counts the number of occurrence of ' for separating data that is to be inserted

            std::vector <std::string> data;       //vector string to return inserted data

            std::regex words_regex("'(.*?)'");       //regex to remove ' ' from the data

            for(std::sregex_iterator it = std::sregex_iterator(
                    temp.begin(), temp.end(), words_regex);
                it != std::sregex_iterator(); it++)
            {
                std::smatch match = *it;
                std::string match_str = match.str(1);
                data.insert(data.end(),match_str);      //data inserted after separating into vector string
            }

            if(data.size() == count/2)    //checks if the data is equal to no. of data inserted by user
            {
                return data;        //returning vector string that contains records for inserting
            }
            else
            {
                std::vector <std::string> error;
                error.insert(error.end(),ErrImproperData[0]);   //error if improper insertion of data

                return error;    //return error
            }
        }
        else
        {
            std::vector <std::string> error;
            error.insert(error.end(),errNoSuchTableExist[0]);   //error if table doesnt exists

            return error;    //return error
        }
    }
    else
    {
        std::vector <std::string> error;
        error.insert(error.end(),SelectTheDatabase[0]);   //error if database not selected

        return error;    //return error
    }
}

std::string string_quote_cutter(std::string strx)
{
    strx.erase(std::remove(strx.begin(),strx.end(),'\''),strx.end());
    return strx;
}

std::string string_quote_cutter(std::string strx, char cut)
{
    strx.erase(std::remove(strx.begin(),strx.end(),cut),strx.end());
    return strx;
}

void nullRomoverFromVectorString(std::vector<std::string> &vec)
{
    if(vec.size() > 0)
    {
        for(int i = 0 ; i < vec.size() ; i++)
        {
            if(vec[i].empty()) // it will check whether the  element in vector array is empty or not
            {
                vec.erase(vec.begin()+i); // if it is empty then it will erase..
            }
        }
    }
}


#endif //OURDB_DATABASE_GLOBAL_FUNCTION_H
