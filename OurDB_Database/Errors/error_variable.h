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
inline string inSufficientWordInCreateSyntax[2] = {"Error index := 3 , Error := there are insufficient words and invalid world in create syntax","3"};

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
inline string syntaxErrShowList[2] = {"Error index := 21 ,Error := Syntax of displaying database/table list is wrong..\n \tSyntax : show/view/display all database/table ","21"};

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
inline string ExtraWordInRenameSyntax[2] = {"Error index := 31 ,Error := There is/are some extra words in rename query..","31"};

// error in syntax of rename Table
inline string syntaxErrRenameTable[2] = {"Error index := 32 ,Error := syntax of rename table is wrong.. \n\t Syntax : rename table old_name new_name ","32"};

// not allowing to rename the default.Ourdb file
inline string errRenamingDefaultTable[2] = {"Error index := 33 ,Error := You cannot rename default table!!","33"};

// when you try to rename the old table with same new name table.
inline string sameNameTableErr[2]= {"Error index := 34 ,Error := Same name of old and new table.." ,"34"};

// Table renaming unknown error
inline string errRenameTable[2] = {"Error index := 35 ,Error := Error renaming table! Same name table might exist already!! ","35"};

// When user tries to rename table that doesnt exist in the database
inline string errNoSuchTableExist[2] = {"Error index := 36 ,Error := No such table exists in the database!! ","36"};

//error occur when table can not be deleted
inline string errorDeletingTable[2] = {"Error index := 37 , Error := unable to delete table. ","37"};

// not allowing to delete the default.Ourdb file
inline string errDeletingDefaultTable[2] = {"Error index := 38 ,Error := You cannot delete default table!!","38"};

// error while naming columns win table
inline string errNamingColumn[2] = {"Error index := 39 ,Error := Invalid name for column!!","39"};

//insufficient words in insert query syntax
inline string inSufficientWordIninsertSyntax[2] = {"Error index := 40 , Error := there are insufficient words and invalid world in insert syntax","40"};

// wrong syntax of insert query
inline string ErrSyntaxInsertQuery[2] = {"Error index := 41 , Error := Wrong syntax of insert data query!\n\t Correct syntax : insert into <table_name> @ '<col1_value>' '<col2_value>' ...","41"};

// invalid no of data while inserting i.e. data not matching no. of columns
inline string ErrDataNotEqualToNoOfCols[2] = {"Error index := 42 , Error := No. of data entered does not equals to no. of columns in the table!","42"};

// error if column data is insufficient or data irregularity
inline string ErrImproperData[2] = {"Error index := 43 , Error := Improper or No data insertion!!","43"};

// error if two columns have same name (while creating the table and specifying col names)
inline string ErrSameColName[2] = {"Error index := 44 , Error := Column name invalid! Another column with same name already exists!!","44"};

// occurs  error in syntax of delete query...
inline string ErrdeleteQuerySyntax[2] = {"Error index := 45 , Error := error in syntax of delete query.. delete @ <table_name> where <column_name> (=/!) <column_value>  (&/|) <column_name1> (=/!) <column_value1>","45"};

// column(key) and value are not same..
inline string ErrInsufficientColumnValue[2] = {"Error index := 46 ,Error := insufficient condition with column","46"};

//  conditions are not in order..
inline string  ErrorConditionNotInAppropriateOrder[2] = {"Error index : 47 , Error := conditions are not in appropriate order","47"};

// missing some operator in the query string..
inline string  ErrorDontHaveEnoughOperator[2] = {"Error index : 48 , Error := value don't have sufficient oprator","48"};

// column does not exists...
inline string  ErrColumnDoesNotExists[2] = {"Error index : 49, Error := columns are not exist into table","49"};

// insufficient word in update query suntax
inline string insufficientWordInUpdateSyntax[2] = {"Error index := 50 , Error := there are insufficient words and invalid world in update syntax","50"};

// error in update query syntx
inline string ErrUpdateQuerySyntax[2] = {"Error index := 51 , Error := Error in update query syntax .. update into <table_name> @ set/put <table_field> <field_value> where <table_field1>(=/|)<field_value1> ","51"};

// table does not exists error
inline string tableDoesNotExist[2] = {"Error index := 52 , Error := table does not exists  ","52"};

//insufficient words in update query syntax
inline string inSufficientWordInUpdateSyntax[2] = {"Error index := 53 , Error := there are insufficient words or invalid world in update syntax","53"};

// when user tries to insert/retrieve data to/from default table
inline string  ErrDataManipulationInDefault[2] = {"Error index : 54, Error := Cannot add or retrieve data from default table!!","54"};

// error where keyword is not at its right place as per syntax
inline string ErrWhereKeyword[2] = {"Error index : 55 Error := where keyword is not at its right place as per syntax","55"};

//error that you cant delete anything from default table
inline string ErrDeleteDefult[2] = {"Error index : 56 Error := can not perform any delete opration on default table","56"};

//table does not have data to delete
inline string ErrNoDataForDeleteInTable[2] = {"Error index : 57 := table does not have any data to perform delete operation","57"};

//table does not have data to delete
inline string ErrNoDataForUpdateInTable[2] = {"Error index : 58 := table does not have any data to perform update operation","58"};

//column does not have right syntax
inline string ErrorDeleteColumnSyntax[2] = {"Error index : 59 := syntax error in delete column query \n Syntax := delete column/col from <table_name> @ <col_name>","59"};

//column does not exist
inline string ErrorColumnNotExist[2] = {"Error index : 60 := column does not exist into table ","60"};

#endif //OURDB_DATABASE_ERROR_VARIABLE_H
