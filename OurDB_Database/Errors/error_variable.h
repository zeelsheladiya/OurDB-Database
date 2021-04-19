//
// Created by zeel,mihir,parth on 13/04/2021.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef OURDB_DATABASE_ERROR_VARIABLE_H
#define OURDB_DATABASE_ERROR_VARIABLE_H

// first word of syntax is wrong
string querySyntaxError[2] = {"Error index := 1 , Error := your initial query syntax is wrong","1"};

// secend word of syntax is wrong
string syntaxOfCreateError[2] = {"Error index := 2 , Error := invalid word in create query syntax","2"};

//extra words in create query syntax
string ExtraWordInCreateSyntax[2] = {"Error index := 3 , Error := there are some extra words and invalid world in create syntax","3"};

//extra words in delete query syntax
string ExtraWordInDeleteSyntax[2] = {"Error index := 4 , Error := there are some extra words and invalid world in delete syntax","4"};

// secend word of syntax is wrong
string syntaxOfDeleteError[2] = {"Error index := 5 , Error := invalid word in create query syntax","5"};

//error occur due to input wrong name type by user
string syntaxOfCreateDatabase[2] = {"Error index := 6 , Error := invalid name for creating database ","6"};

//error occur during creating database directory
string errorCreatingDatabase[2] = {"Error index := 7 , Error := database creation failed. ","7"};

string errorDeletingDatabase[2] = {"Error index := 8 , Error := unable to delete database. ","8"};

string errorSpecialchaDatabase[2] = {"Error index := 9 , Error := special character not allowed. ","9"};

string errorCreatingFile[2] = {"Error index := 10 , Error := unable to create file ","10"};

string errorDatatbaseExists[2] = {"Error index := 11 , Error := database already exist ","11"};
#endif //OURDB_DATABASE_ERROR_VARIABLE_H
