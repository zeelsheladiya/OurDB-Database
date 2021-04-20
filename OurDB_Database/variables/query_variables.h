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

 //dummy variable for stroing dbname
inline string storeDatabaseName = "";
//character for splitting the string into string array
inline char split_char = ' ';

//size of query
inline int query_size = 0;

//for storing first letter of database name(for validation purpose);
inline char firstLetterStore;

//create variable
inline string create_query[2] = {"create","make"};

//database variable
inline string database[1] = {"database"};

//table variable
inline string table[1] = {"table"};

//delete variable
inline string delete_query[2] = {"delete","destroy"};

//selecting  database
inline string select_db_query[3] = {"select","choose","pick"};

//path for string...
inline string strPath[1] = {"../../OurDB_Database/Databases/"};

// for storing last letter of database name(for validation purpose);
inline unsigned char lastLetterStore;

#endif //OURDB_DATABASE_QUERY_VARIABLES_H
