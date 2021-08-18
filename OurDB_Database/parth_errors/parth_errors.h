//
// Created by dabhe on 10-Jun-21.
//
//#include <string>
//using namespace std;
#ifndef OURDB_DATABASE_PARTH_ERRORS_H
#define OURDB_DATABASE_PARTH_ERRORS_H

// syntax error in renaming query..
inline std::string ErrorInRenameQuery[2] = {"Error index := P.1 , Error := Rename column Syntax is not right\n rename column/col from <table_name> @ <old_col_name> <new_col_name> ","P.1"};

//renaming operation failed..
inline std::string ErrorInRenameOp[2] = {"Error index := P.2 , Error := Renaming column operation failed .. inserted column name pr order may be wrong ","P.2"};

//wrong column name...
inline std::string ErrorInColumnName[2] = {"Error index := P.3 , Error := Wrong column name or insertion syntax wrong\n update @ <table_name> @ set/put <table_field> '<field_value>' where <table_field1>(=/|)<field_value1>","P.3"};

// same column name already exist...
inline std::string ErrSameColumnNameExit[2]={"Error index := P.4 , Error := Same column name already exist in other column\n update @ <table_name> @ set/put <table_field> '<field_value>' where <table_field1>(=/|)<field_value1>","P.4"};
#endif //OURDB_DATABASE_PARTH_ERRORS_H
