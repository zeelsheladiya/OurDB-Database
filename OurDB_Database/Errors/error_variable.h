//
// Created by zeel,mihir,parth,pranav on 13/04/2021.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef OURDB_DATABASE_ERROR_VARIABLE_H
#define OURDB_DATABASE_ERROR_VARIABLE_H

//first word of syntax is wrong
string querySyntaxError[2] = {"Error index := 1 , Error := your initial query syntax is wrong","1"};

//secend word of syntax is wrong
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

//error occur when database can not be created
string errorDeletingDatabase[2] = {"Error index := 8 , Error := unable to delete database. ","8"};

//error occur when database name is not valid
string errorSpecialchaDatabase[2] = {"Error index := 9 , Error := special character not allowed. ","9"};

//error occur when file (table) can not be created in database folder
string errorCreatingFile[2] = {"Error index := 10 , Error := unable to create file ","10"};

//error occur id that named database is already exist
string errorDatatbaseExists[2] = {"Error index := 11 , Error := database already exist ","11"};

// error selecting database
string errorSelectingDatabase[2] = {"Error index := 12 , Error := error selecting database ","12"};

// extrawords in database syntax..
string ExtraWordInselectDatabaseSyntax[2] = {"Error index := 13 , Error := there are some extra words and invalid world in select database syntax","13"};

// error when database is not there
string errDatabaseNotFound[2] = {"Error index := 14 , Error := database not found","14"};

// when database already and you try to create with same name
string databaseAlreadySelected[2] = {"Error index := 15 , Error := database already selected","15"};

// it is unknown error
string SysUnRecognizedError[2] = {"Error index := 16 , Error := system unrecognized error","16"};

// error in syntax of rename database
string syntaxErrRenameDatabase[2] = {"Error index := 17 ,Error := syntax of rename database is wrong.. ","17"};

// giving wrong name to database
string errrenameDatabase[2] = {"Error index := 18 ,Error :=  renaming database error ","18"};

// when someone rename the database he new to select the database for further process..
string SelectTheDatabase[2] = {"Error index := 19 ,Error :=  First select the database ","19"};

// when you try to rename the old database with same new name database.
string sameNameDatabaseErr[2]= {"Error index := 20 ,Error :=  Same name of old and new database.. \",\"19\""};
#endif //OURDB_DATABASE_ERROR_VARIABLE_H
