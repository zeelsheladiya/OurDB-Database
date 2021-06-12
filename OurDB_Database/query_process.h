//
// Created by zeel,mihir,parth,pranav on 13/04/2021.
//
#include <iostream>
#include <string>
#include <regex>
#include <vector>
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

using namespace std;

#ifndef OURDB_DATABASE_QUERY_PROCESS_H
#define OURDB_DATABASE_QUERY_PROCESS_H

// check world with global world variable
template<class Element, class Container>
bool syntaxCompare(const Element & keyvalue ,const Container & variablearray)
{
    return find(begin(variablearray), end(variablearray), keyvalue) != end(variablearray);
}

// function for query process
string query_process(vector<string> query)
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
                    vector <string> a;
                    int j = 4;

                    for(int i=0;i<query_size - 4;i++)
                    {
                        a.insert(a.end(),query[j]);
                        j++;
                    }
                    //cout << a[0];

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
                    StoreTempString += query[i];
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
        if(query_size == 3) {

            if (syntaxCompare(query[1], database))//check for database's word
            {
                return selectDatabase(query[2]);

            } else {

                return errorSelectingDatabase[0];
            }
        }
        else{
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
                        vector <string> vc;
                        regex fb("[a-z0-9_]{0,}");
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
                    vector <string> a = InputStringSeparation(query); //vector string separated by ''
                    if(a.empty() || a[0] == ErrImproperData[0])
                    {
                        return ErrImproperData[0];    //error if there is improper data insertion
                    }
                    else if(a[0] == errNoSuchTableExist[0])
                    {
                        return errNoSuchTableExist[0];
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
                        vector <string> a;

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
                         map <string,string> mx;
                         StoreTempString = "";
                         int j = 4;
                         regex fb("[a-z0-9_']{0,}");

                         vector <string> strsep;
                         int l = 0;
                         while(query[j] != "where")
                         {
                           if(regex_match(query[j].c_str(),fb))
                           {
                               l++;
                               j++;

                           }else
                           {
                               return ErrUpdateQuerySyntax[0];
                           }

                         }
                         j = 4;
                         while(query[j] != "where")
                         {
                             strsep.insert(strsep.end(),query[j]);
                             j++;
                         }

                         regex rl("[a-z0-9_]{0,}");
                         regex rf("'([^']*)'");
                         int cntf=0,cntl=0;
                         for(int i=0;i<strsep.size();i++)
                         {
                             if(i % 2 == 0)
                             {
                                 if(regex_match(strsep[i].c_str(),rl))
                                 {
                                     cntf++;
                                 }else
                                 {
                                     return ErrorInColumnName[0];
                                 }
                             }else if(i % 2 != 0)
                             {
                                 if(regex_match(strsep[i].c_str(),rf))
                                 {
                                     cntl++;
                                 }else
                                 {
                                     return ErrUpdateQuerySyntax[0];
                                 }
                             }
                         }
                         if(strsep.size() == (cntl + cntf)) {
                             for (int i = 0; i < strsep.size(); i = i + 2) {
                                 mx.insert(pair<string, string>(strsep[i], string_quote_cutter(strsep[i + 1])));
                             }
                         }
                         else
                         {
                             return ErrUpdateQuerySyntax[0];;
                         }
                          j++;
                         for(int i = j; i<query_size;i++)
                         {
                             StoreTempString += query[i];
                         }

                             return updateTable(query[2], mx, StoreTempString);

                     }
                     else
                     {
                         return ErrUpdateQuerySyntax[0];
                     }



             }else
             {
                return ErrUpdateQuerySyntax[0];
             }

         }else
         {
            return inSufficientWordInUpdateSyntax[0];
         }
    }
    else
    {
        return querySyntaxError[0];
    }
}

#endif //OURDB_DATABASE_QUERY_PROCESS_H
