//
// Created by Micron on 19/06/2021.
//

#include <fstream>
#include <stdio.h>
#include <string>
#include <ostream>
#include <vector>
#include <iostream>
#include <regex>
#include "AfterWhereProcess.h"
#include "global_function.h"

//using namespace std;

#ifndef OURDB_DATABASE_SYNTAXCHECKERFORRESULTSTRING_H
#define OURDB_DATABASE_SYNTAXCHECKERFORRESULTSTRING_H

bool SyntaxCheckerForResultString(string result)
{
    if(result == "")
    {
        return false; // if result will empty it will return false
    }
    else
    {
        vector<string> datastring; // for storing string data in vector
        regex r1("\n"); // regex for checking new line
        filterRegexInstring(result,datastring,r1,-1); // gives vector string which does not match with regex(newline separater)
        vector<string> coldata; // for storing string column data
        regex r2(","); // regex for separation with ,
        filterRegexInstring(datastring[0],coldata,r2,-1); // gives the vector string with  , separated data

        if(datastring.size() < 3) // if datastring  vector array is less than 3
        {
            return false;  // return false
        }

        if(coldata.size() < 0) // if coldata vector less than 0
        {
            return false; // return false
        }

        nullRomoverFromVectorString(datastring); // it will remove null value from vector..
        nullRomoverFromVectorString(coldata);

        for(int i = 0 ; i < datastring.size() ; i++) // iterate through datastring
        {
            if(datastring[i] == "\n") // it will check whether the  element in vector array is empty or not
            {
                datastring.erase(datastring.begin()+i); // if it is empty then it will erase..
            }
        }

        if(coldata.size() > datastring.size()-3) // minimum value comparision with col data
        {
            return false; // return false
        }

        int colcount = coldata.size(); // stores the coldata size in colcount

        if(datastring[1]!=" ") // if datastring of 2nd value is <space> return error
        {
            return false;
        }

        int datacounter = 0;

        for(int i = 2 ; i < datastring.size() ; i++) // iterate through datastring
        {
            if(datacounter == colcount) // if datacounter and colcount matches
            {
                if(datastring[i] != " ") // if datastring of ith value is <space> then return false
                {
                    return false; // return false
                }
                datacounter = 0; // initialize the datacounter with zero
                continue; // if above condition matches then skip the loop
            }

            if(datacounter != colcount) // if datacounter is not equal to colcount
            {
                datacounter++; // datacounter increment
            }

        }

        return true; // return true

    }
}

#endif //OURDB_DATABASE_SYNTAXCHECKERFORRESULTSTRING_H
