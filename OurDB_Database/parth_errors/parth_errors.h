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

//
inline string ErrorInRenameOp[2] = {"Error index := P.2 , Error := Renaming column operation failed .. insertted column name pr order may be wrong ","P.2"};
#endif //OURDB_DATABASE_PARTH_ERRORS_H
