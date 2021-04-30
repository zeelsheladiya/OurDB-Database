//
// Created by zeel,mihir,parth,pranav on 13/04/2021.
//
#include <iostream>
#include <string>
#include <regex>

using namespace std;

#ifndef OURDB_DATABASE_QUERY_VARIABLES_H
#define OURDB_DATABASE_QUERY_VARIABLES_H

//global variable for selecting database
 string databaseSelectGlobal = "";

 // whole database path gets value while renaming, made for renameing only....
string databaseSavePath = "";

 //dName variable for stroing dbname
 string dName = "";
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

//selecting  database
string select_db_query[3] = {"select","choose","pick"};

//rename database
string rename_database_query[2] = {"rename","retitle"};

//path for string...
string strPath[1] = {"../../OurDB_Database/Databases/"};

// for validation
unsigned char cn;

#endif //OURDB_DATABASE_QUERY_VARIABLES_H
