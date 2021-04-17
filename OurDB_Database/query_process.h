//
// Created by zeel,mihir,parth on 13/04/2021.
//
#include <iostream>
#include <string>
#include "Errors/error_variable.h"
#include "variables/query_variables.h"
#include "Success_Messages/Success_Msg.h"
#include "Parth_module/create_database/create_database.h"
#include "Parth_module/delete_database/delete_database.h"

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

            } else if (syntaxCompare(query[1], table)) {
                //for create table
            } else {
                // else part of create query
                return syntaxOfCreateError[0];
            }
        }
        else{
            return ExtraWordInCreateSyntax[0];
        }

    } else if (syntaxCompare(query[0],delete_query)) {
        // all delete queries
        if(query_size == 3) {

            if (syntaxCompare(query[1], database))//check for database's word
            {   //for delete database
                return deleteDatabase(query[2]); // parth's part

            } else if (syntaxCompare(query[1], table)) {
                //for delete table
            } else {
                // else part of delete queries
                return syntaxOfDeleteError[0];
            }
        }
        else{
            return ExtraWordInDeleteSyntax[0];
        }

    }
    else
    {
        return querySyntaxError[0];
    }
}

#endif //OURDB_DATABASE_QUERY_PROCESS_H
