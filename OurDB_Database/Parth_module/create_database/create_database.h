//
// Created by zeel,mihir,parth,pranav on 13/04/2021.
//

#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <conio.h>
#include <filesystem>

using namespace std;

#ifndef OURDB_DATABASE_CREATE_DATABASE_H
#define OURDB_DATABASE_CREATE_DATABASE_H

/*void FileTabel(string nm)
{
    fstream tb; // creats the object of class "fstream"...   here "tb" obj is created
    tb.open(nm,ios::in | ios::out | ios::trunc ); // in for writing , out for writing and trunc
    if(!tb.is_open()) // is_open is defined in "fstream" which check file is created or not if created then open it
    {
        cout<<errorCreatingFile[0]<<endl; // defined in Errors/error_variable.h
    }else
    {
        cout<<SuccessCreatingFileMsg[0]<<endl; // defined in "Success_Messages/Success_Msg.h"..
    }
    tb.close(); // closes the file

}
*/


string createDatabase(string databaseName)
{
       cm = databaseName.front();  //store the first character of string
       cn = databaseName.back(); // stores last character of string
      if(cm >= 97 && cm <= 122)   // check whether the first character is between "a to z" or not
       {
          if((cn >= 32 && cn <= 47)  ||(cn >= 58 && cn <= 92) || (cn >= 123 && cn <= 126)) // check for special character
          {

              return errorSpecialchaDatabase[0]; // defined in Errors/error_variable.h

          }else{
                   databaseName = strPath[0] + databaseName; //strpath[0]="path" defined in  variables/query_variables.h
                   if(!(filesystem::exists(databaseName.c_str()))) // checks for database that has already been created
                   {

                       if(mkdir(databaseName.c_str()) ==-1)  // cretae directory, mkdir function defined in direct.h header file
                       {

                           return errorCreatingDatabase[0]; // defined in Errors/error_variable.h

                       } else{
                          // databaseName = databaseName +
                                          "/deafault.Ourdb"; //it takes file path from above and add the path to file
                           //  FileTabel(databaseName); //creats file called default.Ourdb from above defined function

                           return SuccessCreatingDatabaseMsg[0]; // Success_Messages/Success_Msg.h
                       }

                   }else{
                        return errorDatatbaseExists[0];// defined in error.h
                   }
          }
       }
       else if(!(cm >= 97 && cm <= 122)) // check if character is not between "a to z"...
       {
           return syntaxOfCreateDatabase[0]; // defined in Errors/error_variable.h
       }

}




#endif //OURDB_DATABASE_CREATE_DATABASE_H
