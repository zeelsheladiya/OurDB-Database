//
// Created by Micron on 18/06/2021.
//

#ifndef OURDB_DATABASE_SELECTFUNCFORCOLWITHADDITIONALFUNC_H
#define OURDB_DATABASE_SELECTFUNCFORCOLWITHADDITIONALFUNC_H

string SelectFuncForColswithAdditionalFunc(string tablename , string AdditionalFunc ,vector <string> beforeat)
{
    ourdb our1; // object of json
    fstream fs(tablename);  // file pointer points to tablePath
    vector <vector<string>> data; //2d vector array...
    fs >> our1; // data of tablePath to json object..
    if(our1["table_data"].size() > 0)
    {   // check whether there is data in table or not

        for(int k=0 ;k<our1["table_data"].size();k++)
        {  // iterate through every row in [table_data]
            vector<string> newvec;  // create new string vector for storing single row data in it...
            for (int j = 0; j < beforeat.size(); j++)
            { // iterate through beforeat(column name) vector
                for (int i = 0; i < our1["records"]["col_names"].size(); i++)
                { //

                    if(selectingSameColsMulTimes(beforeat))     //checks if same column is selected more than once
                    {
                        return ErrSelectSameColName[0];
                    }

                    if (our1["records"]["col_names"][i] == beforeat[j])
                    { // it checks data are same in beforeat and json object
                        string l = to_string(our1["records"]["col_index"][i]); // takes the value from column index ..
                        newvec.insert(newvec.end(), decryption(our1["table_data"][k][l])); //insert decrypted data in newvec
                    }
                }

            }
            data.push_back(newvec); // it will push beck data newvec into data vector..
        }

        if(AdditionalFunc == "<")
        {
            ascending_sort(data);
        }else if(AdditionalFunc == ">")
        {
            descending_sort(data);
        }
        return SelectQueryStructureCreater(beforeat,data); // it will return string.. function defined in global fun for select
    }
    else
    {
        return ErrNoDataFoundInTable[0];
    }

}

#endif //OURDB_DATABASE_SELECTFUNCFORCOLWITHADDITIONALFUNC_H
