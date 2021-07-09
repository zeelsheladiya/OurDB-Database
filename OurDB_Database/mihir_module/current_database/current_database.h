//
// Created by Mihir on 04-05-2021.
//

#include <iostream>
#include <string>
#include "../../variables/query_variables.h"

#ifndef CONSOLE_CPP_CURRENT_DATABASE_H
#define CONSOLE_CPP_CURRENT_DATABASE_H

string currentDatabase()
{
    string a = databaseSelectGlobal;

    if(a == "")
    {
        return errDatabaseNotSelected[0];
    }
    else
        return "Your currently selected database is \n\t" + a;
}

#endif //CONSOLE_CPP_CURRENT_DATABASE_H
