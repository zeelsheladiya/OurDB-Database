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
inline string databaseSelectGlobal = "";

// whole database path gets value while renaming, made for renameing only....
inline string databaseSavePath = "";

//dName variable for stroing dbname
inline string dName = "";

//character for splitting the string into string array
inline char split_char = ' ';

//size of query
inline int query_size = 0;

//for storing first letter of database name;
inline char firstLetterStore;

//create variable
inline string create_query[2] = {"create","make"};

//database variable
inline string database[2] = {"database","db"};

//table variable
inline string table[1] = {"table"};

//delete variable
inline string delete_query[2] = {"delete","destroy"};

//selecting  database
inline string select_db_query[3] = {"select","choose","pick"};

//rename database
inline string rename_database_query[2] = {"rename","retitle"};

//displaying all databases
inline string database_list_query[3] = {"view","show","display"};

//'all' variable to check all keyword in displaying all database/table syntax
inline string all[1] = {"all"};

//'current' variable to check if user ask to view their current/present database or table
inline string current[2] = {"current","present"};

//path for string...
inline string strPath[1] = {"../../OurDB_Database/Databases/"};

//for storing last letter of database name;
inline unsigned char lastLetterStore;

#endif //OURDB_DATABASE_QUERY_VARIABLES_H
