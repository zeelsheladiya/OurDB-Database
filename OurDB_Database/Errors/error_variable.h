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

#endif //OURDB_DATABASE_ERROR_VARIABLE_H
