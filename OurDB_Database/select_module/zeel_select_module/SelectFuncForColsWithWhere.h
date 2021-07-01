//
// Created by Mihir,zeel on 15-06-2021.
//

#ifndef OURDB_DATABASE_SELECTFUNCFORCOLSWITHWHERE_H
#define OURDB_DATABASE_SELECTFUNCFORCOLSWITHWHERE_H

string SelectFuncForColsWithWhere(string tablename,vector <string> beforeat,vector <string> afterat)
{
    //string for where condition
    string whereConditionString;

    // convert vector into string
    for(int i = 2 ; i < afterat.size(); i++ )
    {
        whereConditionString += afterat[i];
    }

    // string of index where condition mathed
    string indexies = globalFuncForWhereClouse(whereConditionString,tablename,2);

    // regex for onliy number
    regex regexForOnlyInt("[0-9]{0,}");


    if(regex_match(indexies,regexForOnlyInt))
    {

        string tablepath = databaseSavePath +"/"+ tablename +".Ourdb";

        ourdb our1;
        fstream fs(tablepath);
        vector <vector<string>> data;
        string ml;
        fs >> our1;

        vector<string> ind;

        for(auto zeel : indexies)
        {
            ind.insert(ind.end(),to_string(zeel-48));
        }

        for(int k=0 ;k<ind.size();k++)      //loop for data that satisfies after where condition
        {
            vector<string> newvec;
            for (int i = 0; i < our1["records"]["col_names"].size(); i++)   //loop for checking col names with col indexes
            {
                for (int j = 0; j < beforeat.size(); j++)   //loop for checking cols that are specified by user before '@'
                {
                    if (our1["records"]["col_names"][i] == beforeat[j])     //checks user specified col with col in table
                    {
                        string l = to_string(our1["records"]["col_index"][i]); // takes the value from column index ..
                        newvec.insert(newvec.end(), decryption(our1["table_data"][stoi(ind[k])][l]));
                    }
                }

            }
            data.push_back(newvec);     //inserting vector 'newvec' into vector of vector 'data'
        }

        return SelectQueryStructureCreater(beforeat,data);
    }
    else if (indexies == "")
    {
        // error no data found
        return ErrNoDataFoundInTable[0];
    }
    else
    {
        // it will give you an error
        return indexies;
    }

}

#endif //OURDB_DATABASE_SELECTFUNCFORCOLSWITHWHERE_H
