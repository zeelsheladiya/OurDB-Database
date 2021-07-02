//
// Created by Micron on 18/06/2021.
//

#ifndef OURDB_DATABASE_SELECTFUNCFORALLWITHADDITIONALFUNC_H
#define OURDB_DATABASE_SELECTFUNCFORALLWITHADDITIONALFUNC_H

#include "../../global_functions/globalFunctionForSelectQuery.h"

using namespace std;
using ourdb = nlohmann::json;

string SelectFuncForAllwithAdditionalFunc(string tablepath , string additionalFunc)
{

    ifstream in(tablepath);

    ourdb coldata;

    in >> coldata;

    if(coldata["table_data"].size()>0)
    {
        vector<string> colname;     //vector string for col names
        vector<vector<string>> data;    //vector of vector string for table data

        for (auto& x : coldata["records"]["col_names"].items())
        {
            colname.insert(colname.end(), string_quote_cutter(to_string(x.value()),'\"'));    //col name inserted to vector colname
        }

        for(int i=0; i < coldata["table_data"].size();i++)
        {
            vector<string> jval;    //temporary vector to store value to add into vector of vector 'data'
            for(auto &j : coldata["table_data"][i].items())
            {
                jval.push_back(decryption(j.value()));      //value pushed to vector of vector string 'data'
            }
            data.push_back(jval);
        }


        if(additionalFunc == "<")
        {
            ascending_sort(data);
        }
        else if(additionalFunc == ">")
        {
            descending_sort(data);
        }

        return SelectQueryStructureCreater(colname,data);
    }
    else
        return ErrNoDataFoundInTable[0];
}

#endif //OURDB_DATABASE_SELECTFUNCFORALLWITHADDITIONALFUNC_H
