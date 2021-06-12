//
// Created by dabhe on 10-Jun-21.
//
#include <iostream>
#include <string>

using namespace std;
#ifndef OURDB_DATABASE_PARTH_ERRORS_H
#define OURDB_DATABASE_PARTH_ERRORS_H

// syntax error in renaming query..
inline string ErrorInRenameQuery[2] = {"Error index := P.1 , Error := Rename column Syntax is not right\n rename column/col from <table_name> @ <old_col_name> <new_col_name> ","P.1"};

//renaming operation failed..
inline string ErrorInRenameOp[2] = {"Error index := P.2 , Error := Renaming column operation failed .. insertted column name pr order may be wrong ","P.2"};

//wrong column name...
inline string ErrorInColumnName[2] = {"Error index := P.2 , Error := Wrong column name or insertion syntax wrong\n update @ <table_name> @ set/put <table_field> '<field_value>' where <table_field1>(=/|)<field_value1>","P.3"};


#endif //OURDB_DATABASE_PARTH_ERRORS_H
