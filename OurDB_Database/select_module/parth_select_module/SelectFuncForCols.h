//
// Created by Mihir on 15-06-2021.
//

#include "../../global_functions/globalFunctionForSelectQuery.h"


//using namespace std;
using ourdb = nlohmann::json;
#ifndef OURDB_DATABASE_SELECTFORCOLS_H
#define OURDB_DATABASE_SELECTFORCOLS_H

string SelectFuncForCols(string tablePath,vector <string> beforeat)
{
    ourdb our1; // object of json
    fstream fs(tablePath);  // file pointer points to tablePath
    vector <vector<string>> data; //2d vector array...
    fs >> our1; // data of tablePath to json object..
    if(our1["table_data"].size() > 0)
    {   // check whether there is data in table or not

        if(selectingSameColsMulTimes(beforeat))     //checks if same column is selected more than once
        {
            return ErrSelectSameColName[0];
        }

        for(int k=0 ;k<our1["table_data"].size();k++)
        {  // iterate through every row in [table_data]
            vector<string> newvec;  // create new string vector for storing single row data in it...
            for (int j = 0; j < beforeat.size(); j++)
            {// iterate through beforeat(column name) vector
                for (int i = 0; i < our1["records"]["col_names"].size(); i++)
                { //
                  if (our1["records"]["col_names"][i] == beforeat[j])
                  { // it checks data are same in beforeat and json object
                      string l = to_string(our1["records"]["col_index"][i]); // takes the value from column index ..
                      newvec.insert(newvec.end(), decryption(our1["table_data"][k][l])); //insert decrypted data in newvec
                      break;
                  }
                }
            }
            data.push_back(newvec); // it will push beck data newvec into data vector..
        }

        return SelectQueryStructureCreater(beforeat,data); // it will return string.. function defined in global fun for select
    }
    else
    {
        return ErrNoDataFoundInTable[0];
    }


}

#endif //OURDB_DATABASE_SELECTFORCOLS_H
