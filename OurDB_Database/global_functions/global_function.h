//
// Created by dabhe on 05-May-21.
//

#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <conio.h>
#include <filesystem>
using namespace std;
#ifndef OURDB_DATABASE_GLOBAL_FUNCTION_H
#define OURDB_DATABASE_GLOBAL_FUNCTION_H

inline string validation(string dbname,string ferror,string serror)
{
    firstLetterStore = dbname.front();  //store the first character of string
    lastLetterStore = dbname.back(); // stores last character of string
    if(firstLetterStore >= 97 && firstLetterStore <= 122)   // check whether the first character is between "a to z" or not
    {
        if((lastLetterStore >= 32 && lastLetterStore <= 47)  ||(lastLetterStore >= 58 && lastLetterStore <= 92) || (lastLetterStore >= 123 && lastLetterStore <= 126)) // check for special character
        {
            return ferror; // returns ferror variable

        }else{

            return "true_true"; // return true_true for execution of these block
        }
    }
    else if((firstLetterStore >= 48 && firstLetterStore <= 57)) // check if character is not between "a to z"...
    {
        return serror; // returns serror variable

    }else if(!(firstLetterStore >= 97 && firstLetterStore <= 122)){

      return errorSpecialchaDatabase[0];
    }

}

inline void FileTable(string nm)
{
    fstream tb; // creats the object of class "fstream"...   here "tb" obj is created
    tb.open(nm,ios::in | ios::out | ios::trunc ); // in for writing , out for writing and trunc
    if(!tb.is_open()) // is_open is defined in "fstream" which check file is created or not if created then open it
    {
        cout<<errorCreatingFile[0]<<endl; // defined in Errors/error_variable.h
    }
    tb.close(); // closes the file

}

#endif //OURDB_DATABASE_GLOBAL_FUNCTION_H
