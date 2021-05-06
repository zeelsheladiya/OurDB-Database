//
// Created by zeel,mihir,parth,pranav on 13/04/2021.
//

#include <iostream>
#include <string>
#include <fstream>
#include <direct.h>
#include <conio.h>
#include <filesystem>
#include "../../global_functions/global_function.h"

using namespace std;

#ifndef OURDB_DATABASE_CREATE_DATABASE_H
#define OURDB_DATABASE_CREATE_DATABASE_H
/*
string createDatabase(string databaseName)
{
    firstLetterStore = databaseName.front();  //store the first character of string
    lastLetterStore = databaseName.back(); // stores last character of string
      if(firstLetterStore >= 97 && firstLetterStore <= 122)   // check whether the first character is between "a to z" or not
       {
          if((lastLetterStore >= 32 && lastLetterStore <= 47)  ||(lastLetterStore >= 58 && lastLetterStore <= 92) || (lastLetterStore >= 123 && lastLetterStore <= 126)) // check for special character
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
                          databaseName = databaseName +
                                          "/default.Ourdb"; //it takes file path from above and add the path to file
                            FileTable(databaseName); //creats file called default.Ourdb from above defined function

                           return SuccessCreatingDatabaseMsg[0]; // Success_Messages/Success_Msg.h
                       }

                   }else{
                        return errorDatatbaseExists[0];// defined in error.h
                   }
          }
       }
       else if(!(firstLetterStore >= 97 && firstLetterStore <= 122)) // check if character is not between "a to z"...
       {
           return syntaxOfCreateDatabase[0]; // defined in Errors/error_variable.h
       }

}
*/
string createDatabase(string databaseName)
{
    validate = validation(databaseName,syntaxOfCreateDatabase[0],errorSpecialchaDatabase[0]);
     if( validate == "true_true")
     {
         regex l("[a-zA-Z0-9_]{0,}"); // alphabet numeric and _ allowed betwwen letters..
         if ( regex_match(databaseName, l) ) {
             databaseName = strPath[0] + databaseName; //strpath[0]="path" defined in  variables/query_variables.h
             if (!(filesystem::exists(databaseName.c_str()))) // checks for database that has already been created
             {

                 if (mkdir(databaseName.c_str()) ==-1)  // cretae directory, mkdir function defined in direct.h header file
                 {

                     return errorCreatingDatabase[0]; // defined in Errors/error_variable.h

                 } else {
                     databaseName = databaseName +
                                    "/default.Ourdb"; //it takes file path from above and add the path to file
                     FileTable(databaseName); //creats file called default.Ourdb from above defined function

                     return SuccessCreatingDatabaseMsg[0]; // Success_Messages/Success_Msg.h
                 }

             } else {
                 return errorDatatbaseExists[0];// defined in error.h
             }
         }
         else
         {
            return  errorSpecialchaDatabase[0];
         }
     }else if(validate != "true_true")
     {
         return  errorSpecialchaDatabase[0];
     }
}
#endif //OURDB_DATABASE_CREATE_DATABASE_H
