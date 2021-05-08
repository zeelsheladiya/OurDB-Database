//
// Created by zeel,mihir,parth,pranav on 13/04/2021.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef OURDB_DATABASE_ERROR_VARIABLE_H
#define OURDB_DATABASE_ERROR_VARIABLE_H

//first word of syntax is wrong
inline string querySyntaxError[2] = {"Error index := 1 , Error := your initial query syntax is wrong","1"};

//secend word of syntax is wrong
inline string syntaxOfCreateError[2] = {"Error index := 2 , Error := invalid word in create query syntax","2"};

//extra words in create query syntax
inline string ExtraWordInCreateSyntax[2] = {"Error index := 3 , Error := there are some extra words and invalid world in create syntax","3"};

//extra words in delete query syntax
inline string ExtraWordInDeleteSyntax[2] = {"Error index := 4 , Error := there are some extra words and invalid world in delete syntax","4"};

// secend word of syntax is wrong
inline string syntaxOfDeleteError[2] = {"Error index := 5 , Error := invalid word in create query syntax","5"};

//error occur due to input wrong name type by user
inline string syntaxOfCreateDatabase[2] = {"Error index := 6 , Error := invalid name for creating database ","6"};

//error occur during creating database directory
inline string errorCreatingDatabase[2] = {"Error index := 7 , Error := database creation failed. ","7"};

//error occur when database can not be deleted
inline string errorDeletingDatabase[2] = {"Error index := 8 , Error := unable to delete database. ","8"};

//error occur when database name is not valid
inline string errorSpecialchaDatabase[2] = {"Error index := 9 , Error := special character not allowed in database name. ","9"};

//error occur when file (table) can not be created in database folder
inline string errorCreatingFile[2] = {"Error index := 10 , Error := unable to create file ","10"};

//error occur id that named database is already exist
inline string errorDatatbaseExists[2] = {"Error index := 11 , Error := database already exist ","11"};

// error selecting database
inline string errorSelectingDatabase[2] = {"Error index := 12 , Error := error selecting database ","12"};

// extrawords in database syntax..
inline string ExtraWordInselectDatabaseSyntax[2] = {"Error index := 13 , Error := there are some extra words and invalid world in select database syntax","13"};

// error when database is not there
inline string errDatabaseNotFound[2] = {"Error index := 14 , Error := database not found","14"};

// when database already and you try to create with same name
inline string databaseAlreadySelected[2] = {"Error index := 15 , Error := database already selected","15"};

// it is unknown error
inline string SysUnRecognizedError[2] = {"Error index := 16 , Error := system unrecognized error","16"};

// error in syntax of rename database
inline string syntaxErrRenameDatabase[2] = {"Error index := 17 ,Error := syntax of rename database is wrong.. \n\t Syntax : rename database new_db_name ","17"};

// giving wrong name to database
inline string errrenameDatabase[2] = {"Error index := 18 ,Error :=  Renaming database error! Same name database might exist!! ","18"};

// when someone rename the database he new to select the database for further process..
inline string SelectTheDatabase[2] = {"Error index := 19 ,Error :=  First select the database ","19"};

// when you try to rename the old database with same new name database.
inline string sameNameDatabaseErr[2]= {"Error index := 20 ,Error :=  Same name of old and new database.." ,"20"};

// error in syntax of show all database
inline string syntaxErrShowList[2] = {"Error index := 21 ,Error := Syntax of displaying database list is wrong..\n \tSyntax : show/view/display all database ","21"};

//extra words in delete query syntax
inline string errExtraWordInShowListSyntax[2] = {"Error index := 22 , Error := there are some extra words or invalid word in show database list syntax","22"};

//if no database exist and the list is empty
inline string errDatabaseListIsEmpty[2] = {"Error index := 23 ,Error := No database exists!! Please create a database and then try again..","23"};

// when user tries to ask what is current selected database but no database has been selected
inline string errDatabaseNotSelected[2] = {"Error index := 24 ,Error := No database selected!! Please select a database first..","24"};

// error in syntax of current database
inline string syntaxErrCurrentDatabase[2] = {"Error index := 25 ,Error := Syntax of current database is wrong..\n \tSyntax : current/present database ","25"};

// error in special character in table while creating
inline string errorSpecialchaTable[2] = {"Error index := 26 , Error := special character not allowed in table name. ","26"};

// table creation failed
inline string syntaxOfCreateTable[2] = {"Error index := 27 , Error := syntax of creating table is wrong. ","27"};

// if table already exists then it will gives error..
inline string errTableAlreadyExist[2] = {"Error index := 28 , Error := table already exists.", "28"};

//database name cant start with the numeric value
inline string errFirstLetterNumeric[2] = {"Error index := 29 , Error := Name cannot start with numeric value! Only alphabets allowed.","29"};

//if no table exist in current database and the list is empty
inline string errTableListIsEmpty[2] = {"Error index := 30 ,Error := No tables exists in current database!! Please create a table or select another database..","30"};

//extra word in rename table/database syntax
inline string ExtraWordInRenameSyntax[2] = {"Error index := 30 ,Error := There is/are some extra words in rename query..","31"};

// error in syntax of rename Table
inline string syntaxErrRenameTable[2] = {"Error index := 31 ,Error := syntax of rename table is wrong.. \n\t Syntax : rename table old_name new_name ","32"};

// not allowing to rename the default.Ourdb file
inline string errRenamingDefaultTable[2] = {"Error index := 32 ,Error := You cannot rename default table!!","32"};

// when you try to rename the old table with same new name table.
inline string sameNameTableErr[2]= {"Error index := 33 ,Error := Same name of old and new table.." ,"33"};

// Table renaming unknown error
inline string errRenameTable[2] = {"Error index := 34 ,Error := Error renaming table! Same name table might exist already!! ","34"};

// When user tries to rename table that doesnt exist in the database
inline string errNoSuchTableExist[2] = {"Error index := 35 ,Error := No such table exist in the database!! ","35"};

//error occur when table can not be deleted
inline string errorDeletingTable[2] = {"Error index := 36 , Error := unable to delete table. ","36"};

// not allowing to delete the default.Ourdb file
inline string errDeletingDefaultTable[2] = {"Error index := 37 ,Error := You cannot delete default table!!","37"};

#endif //OURDB_DATABASE_ERROR_VARIABLE_H
