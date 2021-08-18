//
// Created by zeel on 02/07/2021.
//

#ifndef OURDB_DATABASE_M_TO_JSON_H
#define OURDB_DATABASE_M_TO_JSON_H

#include "../../global_functions/SyntaxCheckerForResultString.h"

ourdb m_to_json(std::string result)
{
    ourdb myobj;
    if(SyntaxCheckerForResultString(result))
    {
        std::vector<std::string> datastring; // for storing string data in vector
        std::regex r1("\n"); // regex for checking new line
        filterRegexInstring(result,datastring,r1,-1); // gives vector string which does not match with regex(newline separater)
        std::vector<std::string> coldata; // for storing string column data
        std::regex r2(","); // regex for separation with ,
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

        std::map<std::string,std::vector<std::string>> tabledata;   //map to store table data

        for(int i=0;i<coldata.size();i++)
        {
            for(int j= 2 + i;j<datastring.size();j+=coldata.size()+1)
            {
                tabledata[coldata[i]].push_back(datastring[j]);
            }
        }


        for(auto itr = tabledata.begin();itr != tabledata.end();itr++)
        {
            //cout << itr->first << "\t";
            for(auto &j : itr->second)
            {
                myobj[itr->first] += j;
            }
            std::cout << std::endl;
        }

        return myobj;
    }
    else
    {
        return myobj;
    }
}

#endif //OURDB_DATABASE_M_TO_JSON_H
