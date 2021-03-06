//
// Created by zeel,mihir,parth,pranav on 13/04/2021.
//
//#include <iostream>
//#include <string>
#include <regex>
//#include <vector>
#include "Errors/error_variable.h"
#include "parth_errors/parth_errors.h"
#include "variables/query_variables.h"
#include "Success_Messages/Success_Msg.h"
#include "Parth_module/create_database/create_database.h"
#include "Parth_module/delete_database/delete_database.h"
#include "Parth_module/select_database/select_database.h"
#include "mihir_module/rename_database/rename_database.h"
#include "mihir_module/database_list/database_list.h"
#include "mihir_module/current_database/current_database.h"
#include "Parth_module/create_table/create_table.h"
#include "mihir_module/table_list/table_list.h"
#include "mihir_module/rename_table/rename_table.h"
#include "zeel_module/delete_table/delete_table.h"
#include "mihir_module/insert_into_table/insert_into_table.h"
#include "Parth_module/update_into_table/update_into_table.h"
#include "Parth_module/update_into_table/ForUpdate.h"
#include "zeel_module/delete_query/delete_query.h"
#include "Parth_module/rename_columns/rename_columns.h"
#include "zeel_module/delete_column_query/delete_column_query.h"
#include "mihir_module/add_column/add_column.h"
#include "select_module/select_module.h"
#include "mihir_module/column_list/column_list.h"
#include "mihir_module/primary_key/add_primary_key.h"
#include "mihir_module/foreign_key/add_foreign_key.h"

//using namespace std;

#ifndef OURDB_DATABASE_QUERY_PROCESS_H
#define OURDB_DATABASE_QUERY_PROCESS_H

// function for query process
std::string query_process(std::vector<std::string> query)
{
    //check for create's queries
    if(syntaxCompare(query[0],create_query))
    {
        // all create queries
        if(query_size == 3) {

            if (syntaxCompare(query[1], database))//check for database's word
            { //for create database
                return createDatabase(query[2]); // parth's part
            }
            else
            {
                // else part of create query
                return syntaxOfCreateError[0];
            }
        }
        if(query_size > 3)
        {
            if (syntaxCompare(query[1], table))
            { //check for table name

                if(syntaxCompare(query[3],colSymbol))
                {
                    std::vector <std::string> a;
                    int j = 4;

                    for(int i=0;i<query_size - 4;i++)
                    {
                        a.insert(a.end(),query[j]);
                        j++;
                    }


                    return createTable(query[2],a); // return table creation
                }
                else
                {
                    // else part of create query
                    return syntaxOfCreateError[0];
                }

            }
            else
            {
                // else part of create query
                return syntaxOfCreateError[0];
            }
        }
        else{
            return inSufficientWordInCreateSyntax[0];
        }

    } else if (syntaxCompare(query[0],delete_query)) {
        // all delete queries
        if(query_size == 3) {

            if (syntaxCompare(query[1], database))//check for database's word
            {   //for delete database
                return deleteDatabase(query[2]); // parth's part

            } else if (syntaxCompare(query[1], table)) {
                //for delete table
                return deleteTable(query[2]);

            } else {
                // else part of delete queries
                return syntaxOfDeleteError[0];
            }
        }
        else if(query_size >= 4)
        {
            if(syntaxCompare(query[1],colSymbol))
            {
                StoreTempString = "";
                for(int i=4;i<query_size;i++)
                {
                    StoreTempString += query[i] + " ";
                }

                return DeleteQuery(query[2],query[3],StoreTempString);

            }
            else if(syntaxCompare(query[1],column))        //checks fro column's word
            {
                if(query_size == 6)
                {
                    if (syntaxCompare(query[2], from))        //checks for 'from' word
                    {
                        if (syntaxCompare(query[4], colSymbol))       //checks for colsymbol
                        {
                            //return delete column/columns function
                            return DeleteColumnQuery(query[3],query[5]);
                        }
                        else
                        {
                            return ErrorDeleteColumnSyntax[0];
                        }
                    }
                    else
                    {
                        return ErrorDeleteColumnSyntax[0];
                    }
                }
                else
                {
                    return ErrorDeleteColumnSyntax[0];
                }
            }
            else
            {
                 return ErrdeleteQuerySyntax[0];
            }

        }
        else{
            return ExtraWordInDeleteSyntax[0];
        }

    }
    else if(syntaxCompare(query[0],select_db_query))
    {
        // select database query
        if (syntaxCompare(query[1], database))//check for database's word
        {
            if(query_size == 3)
            {
                return selectDatabase(query[2]);
            }
            else
            {
                return ExtraWordInselectDatabaseSyntax[0];
            }
        }
        else if(query_size > 3)
        {
            return SelectQuery(query);
        }
        else
        {
            return ExtraWordInselectDatabaseSyntax[0];
        }

    }
    else if(syntaxCompare(query[0],rename_query))
    {
        // for rename the database
        if(query_size == 3)
        {
            if (syntaxCompare(query[1], database))      //check for database's word
            {
                return renameDatabase(query[2]);
            }
            else
            {
                return syntaxErrRenameDatabase[0];
            }
        }
        else if(query_size == 4)
        {
            if (syntaxCompare(query[1], table))     //check for table's word
            {
                return renameTable(query[2],query[3]);
            }
            else
            {
                return syntaxErrRenameTable[0];
            }
        }
        else if(query_size > 5)
        {
            if (syntaxCompare(query[1], column))     //check for column's word
            {
                if(syntaxCompare(query[2],from))        //checks for 'from' word
                {
                    if(syntaxCompare(query[4],colSymbol))       //checks for colsymbol
                    {
                        std::vector <std::string> vc;
                        std::regex fb("[a-z0-9_]{0,}");
                        for(int i = 5;i<query_size;i++)
                        {
                            if(regex_match(query[i].c_str(),fb)) {
                                vc.insert(vc.end(), query[i]);
                            }else
                            {
                                return ErrorInRenameQuery[0];
                            }
                        }
                       if(vc.size()%2==0) {

                           return rename_column(query[3], vc);
                       }
                       else
                       {
                           return ErrorInRenameQuery[0];
                       }
                    }else{
                        return ErrorInRenameQuery[0];
                    }
                }else{
                    return ErrorInRenameQuery[0];
                }
            }else{
                return ErrorInRenameQuery[0];
            }
        }
        else
        {
            return ExtraWordInRenameSyntax[0];
        }

    }
    else if(syntaxCompare(query[0],list_query))
    {
        // for list of database
        if(query_size == 3)     //checks query length (must be 3)
        {
            if(syntaxCompare(query[1],all))     //checks if second word in query is 'all'
            {
                if(syntaxCompare(query[2],database))    //checks if user wants to display all databases
                {
                    return databaseList();
                }
                else if(syntaxCompare(query[2],table))    //checks if user wants to display all tables
                {
                    return tableList();
                }
                else
                {
                    return syntaxErrShowList[0];
                }
            }
            else
            {
                return syntaxErrShowList[0];
            }
        }
        else if(query_size == 5)
        {
            if(syntaxCompare(query[1],all))     //checks if second word in query is 'all'
            {
                if(syntaxCompare(query[2],column))    //checks if third word in query is 'col'/'column'
                {
                    if(syntaxCompare(query[3],colSymbol))    //checks if 4th word is colSymbol
                    {
                        return columnList(query[4]);    //returns columnList() func
                    }
                    else
                    {
                        return syntaxErrShowCols[0];    //syntax error in column list
                    }
                }
                else
                {
                    return syntaxErrShowCols[0];    //syntax error in column list
                }
            }
            else
            {
                return syntaxErrShowCols[0];
            }
        }
        else
        {
              return errExtraWordInShowListSyntax[0];
        }
    }
    else if(syntaxCompare(query[0],current))
    {
        // query for see the current database
        if(query_size == 2)     //checks query length (must be 2)
        {
            if(syntaxCompare(query[1],database))    //checks if user wants to check current database
            {
                return currentDatabase();
            }
            else
                return syntaxErrCurrentDatabase[0];
        }
        else
            return syntaxErrCurrentDatabase[0];
    }
    else if(syntaxCompare(query[0],insert_query))
    {
        if(query_size > 3)
        {
            if(syntaxCompare(query[1],into))
            {
                if(syntaxCompare(query[3],colSymbol))
                {
                    std::vector <std::string> a = InputStringSeparation(query); //vector string separated by ''
                    if(a.empty() || a[0] == ErrImproperData[0])
                    {
                        return ErrImproperData[0];    //error if there is improper data insertion
                    }
                    else if(a[0] == errNoSuchTableExist[0] || a[0] == SelectTheDatabase[0])
                    {
                        return a[0];    //error if table doesnt exist or database not selected
                    }
                    else
                    {
                        return insertIntoTable(query[2],a); // return table creation
                    }
                }
                else
                {
                    // else part of insert query
                    return ErrSyntaxInsertQuery[0];
                }
            }
            else if(syntaxCompare(query[1],column))
            {
                //add col/column into <table_name> @ <col_name>
                if(syntaxCompare(query[2],into))
                {
                    if(syntaxCompare(query[4],colSymbol))
                    {
                        std::vector <std::string> a;

                        for(int i=5;i < query_size;i++)
                        {
                            a.insert(a.end(),query[i]);
                        }

                        return addColumn(query[3],a);
                    }
                    else
                    {
                        return ErrSyntaxAddColumn[0];
                    }
                }
                else
                {
                    return ErrSyntaxAddColumn[0];
                }
            }
            else
            {
                // else part of create query
                return ErrSyntaxInsertQuery[0];
            }
        }
        else
        {
            return inSufficientWordIninsertSyntax[0];
        }
    }
    else if(syntaxCompare(query[0],update))
    {
         if(query_size > 6)
         {
             if(syntaxCompare(query[1],colSymbol))
             {
                     if(syntaxCompare(query[3],setx))
                     {
                         std::map <std::string,std::string> mx;
                         StoreTempString = ""; // it will store the value for after where process
                         //int j = 4; // index for after set keyword...
                         std::regex fb("[a-z0-9_']{0,}");
                         std::regex rl("[a-z0-9_ ]{1,}"); // regex for checking alphanumericals values
                         std::regex rf("'[^']*'"); // checking the value which resides in  ''

                         std::string setString;
                         std::vector <std::string> strsep1;
                         std::vector <std::string> strsep2;
                         std::vector <std::string> strsep3;
                         std::vector <std::string> strsep;
                         
                         int j = 4; // again set the j=4 for operation
                         while(!syntaxCompare(query[j],where))
                         {
                             setString += query[j] + " "; // stores the value in the string  set .......... where
                             j++; // increment j for the further process for getting index of j
                         }

                         filterRegexInstring(setString,strsep1,rf,-1); // it will filter with the regex and stores the value in the vector string
                         filterRegexInstring(setString,strsep2,rf,0); // it will filter with the regex and stores the value in the vector string
                         filterRegexInstring(setString,strsep3,rf,-1); // it will filter ' ' and gives the vector array without it
                         nullRomoverFromVectorString(strsep1); // removes the null value from the vector
                         nullRomoverFromVectorString(strsep2);
                         nullRomoverFromVectorString(strsep3);

                         for(auto & i : strsep1)
                         {
                             trim(i," ");
                         }

                         if(strsep1.size() >= strsep2.size())
                         {
                             for(int i=0 ; i<strsep2.size() ; i++) // iterate through strsep2
                             {
                                 strsep.insert(strsep.end(),strsep1[i]); // insert the strsep1(column name) in strsep vector.
                                 strsep.insert(strsep.end(),strsep2[i]); // insert the strsep2(column value) in strsep vector.
                             }
                         }
                         else
                         {
                             for(int i = 0 ; i < strsep1.size() ; i++)
                             {
                                 strsep.insert(strsep.end(),strsep1[i]); // insert the strsep1(column name) in strsep vector.
                                 strsep.insert(strsep.end(),strsep2[i]); // insert the strsep2(column value) in strsep vector.
                             }
                         }

                         int cntf=0,cntl=0;

                         for(int i=0;i<strsep.size();i++) // iterate through strsep
                         {
                             if(i % 2 == 0) // check for the index at even value
                             {
                                 if(regex_match(strsep[i].c_str(),rl)) // matches the regex
                                 {
                                     cntf++;
                                 }else
                                 {
                                     return ErrorInColumnName[0]; // error in giving column name
                                 }
                             }else if(i % 2 != 0)
                             {
                                 if(regex_match(strsep[i].c_str(),rf)) //matches the regex
                                 {
                                     cntl++;
                                 }else {
                                     return ErrUpdateQuerySyntax[0]; // error in update query syntax
                                 }
                             }
                         }

                         if(strsep.size() == (cntl + cntf)) { // strsep size should match (cntl+cntf)
                             for (int i = 0; i < strsep1.size() & i < strsep2.size(); i++) {
                                 mx.insert(std::pair<std::string, std::string>(strsep1[i], string_quote_cutter(strsep2[i]))); // string_quote_cutter removes the quote from the string
                              // stores the vector in the map
                             }
                         }
                         else
                         {
                             return ErrUpdateQuerySyntax[0]; //error in update query syntax
                         }

                          j++; // increment to pass the 'where' into the query.
                         for(int i = j; i<query_size;i++)
                         {
                             StoreTempString += query[i] + " "; // stores the string for the after where process
                         }

                             return updateTable(query[2], mx, StoreTempString,strsep3);
                           // return the string  from the function updateTable
                     }
                     else
                     {
                         return ErrUpdateQuerySyntax[0]; //error in update query syntax
                     }
             }else
             {
                return ErrUpdateQuerySyntax[0]; // error in update query syntax
             }

         }else
         {
            return inSufficientWordInUpdateSyntax[0]; //less word in the update syntax
         }
    }
    else if(syntaxCompare(query[0],setx))       // checks for set/put keyword
    {
        if(syntaxCompare(query[1],pkey))    //checks for primary key symbol '$'
        {
            if(query_size == 5)
            {
                if(syntaxCompare(query[3],colSymbol))       //checks for '@'
                {
                    return addPrimaryKey(query[2],query[4]);
                }
                else
                {
                    return ErrSyntaxPrimaryKey[0];      //primary key syntax error
                }
            }
            else
            {
                return ErrSyntaxPrimaryKey[0];      //primary key syntax error
            }
        }
        if(syntaxCompare(query[1],frkey))    //checks for foreign key symbol '#'
        {
            //set # <col_name> @ <table_name> $ <primary_table_name>
            if(query_size == 7)
            {
                if(syntaxCompare(query[3],colSymbol))   //checks syntax for colsymbol '@'
                {
                    if(syntaxCompare(query[5],pkey))    //checks syntax for primary key symbol '$'
                    {
                        return addForeignKey(query[2],query[4],query[6]);   //calls addForeignKey method that takes column_name, table_name & primary_table_name
                    }
                    else
                    {
                        return ErrSyntaxForeignKey[0];  //foreign key syntax error
                    }
                }
                else
                {
                    return ErrSyntaxForeignKey[0];  //foreign key syntax error
                }
            }
            else
            {
                return ErrSyntaxForeignKey[0];  //foreign key syntax error
            }
        }
        else
        {
            return querySyntaxError[0];      // syntax error
        }
    }
    else
    {
        return querySyntaxError[0]; // syntax error
    }
}

#endif //OURDB_DATABASE_QUERY_PROCESS_H
