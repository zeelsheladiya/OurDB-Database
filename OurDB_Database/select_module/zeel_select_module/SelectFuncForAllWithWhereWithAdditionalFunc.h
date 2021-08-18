//
// Created by Micron on 18/06/2021.
//

#ifndef OURDB_DATABASE_SELECTFUNCFORALLWITHWHEREWITHADDITIONALFUNC_H
#define OURDB_DATABASE_SELECTFUNCFORALLWITHWHEREWITHADDITIONALFUNC_H

std::string SelectFuncForAllWithWhereWithAdditionalFunc(std::string tablename,std::string additionalFunc ,std::vector<std::string> afterat)
{
    //string for where condition
    std::string whereConditionString;

    // convert vector into string
    for(int i = 3 ; i < afterat.size(); i++ )
    {
        whereConditionString += afterat[i];
    }

    // string of index where condition mathed
    std::string indexies = globalFuncForWhereClouse(whereConditionString,tablename,2);

    // regex for onliy number
    std::regex regexForOnlyInt("[0-9]{1,}");


    if(regex_match(indexies,regexForOnlyInt))
    {
        //main logic

        std::string tablepath = databaseSavePath +"/"+ tablename +".Ourdb";

        std::ifstream in(tablepath);

        ourdb coldata;

        in >> coldata;

        std::vector<std::string> ind;

        for(auto zeel : indexies)
        {
            ind.insert(ind.end(),std::to_string(zeel-48));
        }

        std::vector<std::string> colname;     //vector string for col names
        std::vector<std::vector<std::string>> data;    //vector of vector string for table data

        for (auto& x : coldata["records"]["col_names"].items())
        {
            colname.insert(colname.end(), string_quote_cutter(to_string(x.value()),'\"'));    //col name inserted to vector colname
        }

        for(int i=0; i < ind.size();i++)
        {
            std::vector<std::string> jval;    //temporary vector to store value to add into vector of vector 'data'
            for(auto &j : coldata["table_data"][stoi(ind[i])].items())
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

        return SelectQueryStructureCreater(colname,data);         //global func for select query
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

#endif //OURDB_DATABASE_SELECTFUNCFORALLWITHWHEREWITHADDITIONALFUNC_H
