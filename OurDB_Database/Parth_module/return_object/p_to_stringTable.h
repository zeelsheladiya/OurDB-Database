//
// Created by Micron on 02/07/2021.
//

#include "../../External_Libraries/TextTable.h"

#ifndef OURDB_DATABASE_P_TO_STRINGTABLE_H
#define OURDB_DATABASE_P_TO_STRINGTABLE_H

string p_to_stringTable(string result)
{
    ourdb myobj;
    if(SyntaxCheckerForResultString(result))
    {
        vector<string> datastring; // for storing string data in vector
        regex r1("\n"); // regex for checking new line
        filterRegexInstring(result,datastring,r1,-1); // gives vector string which does not match with regex(newline separater)
        vector<string> coldata; // for storing string column data
        regex r2(","); // regex for separation with ,
        filterRegexInstring(datastring[0],coldata,r2,-1); // gives the vector string with  , separated data

        nullRomoverFromVectorString(datastring); // it will remove null value from vector..
        nullRomoverFromVectorString(coldata);

        for(int i = 0 ; i < datastring.size() ; i++) // iterate through datastring
        {
            if(datastring[i].empty()) // it will check whether the  element in vector array is empty or not
            {
                datastring.erase(datastring.begin()+i); // if it is empty then it will erase..
            }
        }

        //myobj = datastring;
        //myobj["col_names"] = coldata;

        map<string,vector<string>> tabledata;   //map to store table data

        for(int i=0;i<coldata.size();i++)
        {
            for(int j= 2 + i;j<datastring.size();j+=coldata.size()+1)
            {
                tabledata[coldata[i]].push_back(datastring[j]);
            }
        }

        vector<string> firstVec;
        vector<string> secondVec;
        for(auto itr = tabledata.begin();itr != tabledata.end();itr++)
        {
            firstVec.push_back(itr->first);
            for(auto itrn : itr->second)
            {
                secondVec.push_back(itrn);
            }
        }

        TextTable t( '-', '|', '+' );

        for(int i=0;i<coldata.size();i++)
        {
            t.add(" " + coldata[i] + " ");
        }
        t.endOfRow();

        for(int i = 0 ; i < tabledata[coldata[0]].size() ; i++)
        {
            for(int j = 0 ; j < coldata.size() ; j++)
            {
                t.add(" " + tabledata[coldata[j]][i] + " ");
            }
            t.endOfRow();
        }

        ostringstream ss;
        ss << t;
        return ss.str();
    }
    else
    {
        return "";
    }
}

#endif //OURDB_DATABASE_P_TO_STRINGTABLE_H
