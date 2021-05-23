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

using namespace std;
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

//---------------------------------------------------------------------------------------------


// string validation in terms of name
inline string validation(string dbname,string ferror,string serror)
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
inline string FileTable(string nm)
{
    fstream tb; // creats the object of class "fstream"...   here "tb" obj is created
    tb.open(nm,ios::in | ios::out | ios::trunc ); // in for writing , out for writing and trunc
    if(!tb.is_open()) // is_open is defined in "fstream" which check file is created or not if created then open it
    {
        return errorCreatingFile[0]; // defined in Errors/error_variable.h
    }
    tb.close(); // closes the file

   return SuccessCreatingFileMsg[0];
}

//function for trimming string from front
inline string& ltrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

//function for trimming string from end
inline string& rtrim(string& str, const string& chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

//function for trimming string from the both side
inline string& trim(string& str, const string& chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}

// function for replace all space form string into one space
inline bool BothAreSpaces(char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }

// split function for string into string array
inline void split(string const &str, const char delim,vector<string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
}

//separate the query after specific position (after '@' to be precise)
vector <string> InputStringSeparation(vector <string> arr,int pos)
{
    string temp;        //string to store vector string array

    for(int i=0;i<arr.size();i++)
    {
        temp += arr[i] + " ";       //stores data into string after separating them by space
    }

    int count = std::count(temp.begin(), temp.end(), '\'');     //counts the number of occurrence of ' for separating data that is to be inserted

    vector <string> data;       //vector string to return inserted data

    regex words_regex("'(.*?)'");       //regex to remove ' ' from the data

    for(sregex_iterator it = sregex_iterator(
            temp.begin(), temp.end(), words_regex);
        it != sregex_iterator(); it++)
    {
        smatch match = *it;
        string match_str = match.str(1);
        data.insert(data.end(),match_str);      //data inserted after separating into vector string
    }

    if(data.size() == (count/2))    //checks if the data is equal to no. of data inserted by user
    {
        return data;        //returning vector string that contains records for inserting
    }
    else
    {
        vector <string> error;
        error.insert(error.end(),ErrImproperData[0]);   //error if improper insertion of data

        return error;    //return error
    }


}

#endif //OURDB_DATABASE_GLOBAL_FUNCTION_H
