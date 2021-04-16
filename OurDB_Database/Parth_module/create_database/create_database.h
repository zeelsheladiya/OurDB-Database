//
// Created by zeel,mihir,parth on 13/04/2021.
//

#include <iostream>
#include <string>
#include<bits/stdc++.h>
#include <iostream>
#include <direct.h>

using namespace std;

#ifndef OURDB_DATABASE_CREATE_DATABASE_H
#define OURDB_DATABASE_CREATE_DATABASE_H

string createDatabase(string databaseName)
{

       first_char =  databaseName.front();
       fir += first_char;
       if((regex_match(fir,rg) == 1) || databaseName!="con")
       {
         if(mkdir(databaseName.c_str()) == 1)
           return "database created";
       }
       else
       {
           return syntaxOfCreateDatabase[0];
       }




}

#endif //OURDB_DATABASE_CREATE_DATABASE_H
