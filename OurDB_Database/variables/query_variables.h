//
// Created by zeel,mihir,parth on 13/04/2021.
//
#include <iostream>
#include <string>
#include <regex>

using namespace std;

#ifndef OURDB_DATABASE_QUERY_VARIABLES_H
#define OURDB_DATABASE_QUERY_VARIABLES_H

//character for splitting the string into string array
char split_char = ' ';
//size of query
int query_size = 0;

//for storing first letter of database name;
char cm;
//create variable
string create_query[2] = {"create","make"};

//database variable
string database[1] = {"database"};

//table variable
string table[1] = {"table"};

//delete variable
string delete_query[2] = {"delete","destroy"};

#endif //OURDB_DATABASE_QUERY_VARIABLES_H
