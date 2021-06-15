//
// Created by Mihir on 15-06-2021.
//

//#include "query_process.h"

#ifndef OURDB_DATABASE_SELECT_MODULE_H
#define OURDB_DATABASE_SELECT_MODULE_H

string SelectQuery(vector <string> query)
{
    if(!(databaseSelectGlobal.empty()))
    {
        bool iswherepresent;
        int frompos=0;
        for(auto &i : query)
        {
            if(i == "where")
            {
                iswherepresent = true;
            }
        }

        if(iswherepresent)
        {
            //code for select query w/o where
            if(query[1] == "*")
            {
                if(query[2] == from[0])
                {
                    string tbl = query[3];
                }
            }
            else
            {
                for(auto &i : query)
                {
                    frompos++;
                    if(i == from[0])
                    {
                        break;
                    }
                }

                if(frompos==query.size())
                {
                    //error :- no from found in query
                }
                else
                {
                    return "";
                }
            }
        }
        else
        {
            return "";
            //code for select query with 'where'
        }
    }
    else
    {
        return SelectTheDatabase[0];        //select database error if database isnt selected
    }
}


#endif //OURDB_DATABASE_SELECT_MODULE_H
