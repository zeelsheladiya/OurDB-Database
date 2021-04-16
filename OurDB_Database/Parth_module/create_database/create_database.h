//
// Created by zeel,mihir,parth on 13/04/2021.
//

#include <iostream>
#include <string>
#include<bits/stdc++.h>


using namespace std;

#ifndef OURDB_DATABASE_CREATE_DATABASE_H
#define OURDB_DATABASE_CREATE_DATABASE_H

string createDatabase(string databaseName)
{
    
          first_char =  databaseName.front();
            fir += first_char;
       if(regex_match(fir,rg) == 1)
       {
           bool m = regex_match(databaseName,rg);
           cout<<m<<endl;
           return "database created";
       }
       else
       {
           int l = 2;
           cout<<l<<endl;
           return syntaxOfCreateDatabase[0];
       }




}

#endif //OURDB_DATABASE_CREATE_DATABASE_H
