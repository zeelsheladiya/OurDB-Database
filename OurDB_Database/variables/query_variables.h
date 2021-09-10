//
// Created by zeel,mihir,parth,pranav on 13/04/2021.
//
//#include <iostream>
//#include <string>
#include <filesystem>

//using namespace std;

#ifndef OURDB_DATABASE_QUERY_VARIABLES_H
#define OURDB_DATABASE_QUERY_VARIABLES_H

//Note : make sure to empty it before use..
//for storing temperory std::string in queryprocess.
inline std::string StoreTempString="";

//global variable for selecting database
inline std::string databaseSelectGlobal = "";

// whole database path gets value while renaming, made for renameing only....
inline std::string databaseSavePath = "";

//dName variable for stroing dbname
inline std::string dName = "";

//tbname variable stroing the table name
inline std::string tbname = "";

//character for splitting the std::string into std::string array
inline char split_char = ' ';

//variable for storing std::string value which is returned by validate function
inline std::string validate = "";

//size of query
inline int query_size = 0;

//for storing first letter of database name;
inline char firstLetterStore;

//create variable
inline std::string create_query[2] = {"create","make"};

//insert variable
inline std::string insert_query[2] = {"insert","add"};

//into variable
inline std::string into[1] = {"into"};

//variable for encryption and decryption
inline std::string enc_dec = "";

//database variable
inline std::string database[2] = {"database","db"};

//table variable
inline std::string table[2] = {"table","tb"};

//column variable
inline std::string column[2] = {"column","col"};

//delete variable
inline std::string delete_query[2] = {"delete","destroy"};

//selecting  database
inline std::string select_db_query[3] = {"select","choose","pick"};

//rename database/table
inline std::string rename_query[1] = {"rename"};

//displaying all databases
inline std::string list_query[3] = {"view","show","display"};

//'all' variable to check all keyword in displaying all database/table syntax
inline std::string all[1] = {"all"};

//'current' variable to check if user ask to view their current/present database or table
inline std::string current[2] = {"current","present"};

// symbol to check for columns in create table syntax
inline std::string colSymbol[1] = {"@"};

// update table query
inline std::string update[1] = {"update"};

//path for std::string...
inline std::string strPath[1] = {""+ std::filesystem::current_path().parent_path().generic_string() + "/Databases/"};

// set for the update query purpose..
inline std::string setx[2] = {"set","put"};

//for storing last letter of database name;
inline unsigned char lastLetterStore;

//temporary storing table name
inline std::string tname ="";

//it will stores the value which is returned by FileTable
inline std::string filetbReturnValue = "";

//'from' variable (in syntax) to check from which table we want to manipulate the column/s
inline std::string from[1] = {"from"};

//banned keywords
inline std::string bannedkeywords[20] = {"database","table","db","where","column","col","set","put","into","default"};

//'where' variable (in syntax) of select
inline std::string where[1] = {"where"};

//variable for all in select query
inline std::string var_for_func_inselect[1] = {"*"};

//variable for symbol for primary key
inline std::string pkey[1] = {"$"};

#endif //OURDB_DATABASE_QUERY_VARIABLES_H
