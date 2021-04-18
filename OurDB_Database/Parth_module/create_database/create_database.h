//
// Created by zeel,mihir,parth on 13/04/2021.
//

#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <conio.h>

using namespace std;

#ifndef OURDB_DATABASE_CREATE_DATABASE_H
#define OURDB_DATABASE_CREATE_DATABASE_H

void FileTabel(string nm)
{
    fstream tb;
    tb.open(nm,ios::in | ios::out | ios::trunc );
    if(!tb.is_open())
    {
        cout<<"error while opening file"<<endl;
    }else
    {
        cout<<"success"<<endl;
    }
    tb.close();

}

string createDatabase(string databaseName)
{
       cm = databaseName.front();  //store the first character of string
       unsigned char cn = databaseName.back(); // stores last character of string
      if(cm >= 97 && cm <= 122)   // check whether the first character is between "a to z" or not
       {
          if((cn >= 32 && cn <= 47)  ||(cn >= 58 && cn <= 92) || (cn >= 123 && cn <= 126)) { // check for special character
              return errorSpecialchaDatabase[0];
          }else{
                  databaseName = strPath[0] + databaseName;
                  if (mkdir(databaseName.c_str()) == -1) {
                      return errorCreatingDatabase[0];
                  } else {
                      databaseName = databaseName + "/deafault.Ourdb";
                      FileTabel(databaseName);
                      return SuccessCreatingDatabaseMsg;
                  }
          }
       }
       else if(!(cm >= 97 && cm <= 122))
       {
           return syntaxOfCreateDatabase[0];
       }


}




#endif //OURDB_DATABASE_CREATE_DATABASE_H
