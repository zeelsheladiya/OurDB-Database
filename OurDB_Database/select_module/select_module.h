//
// Created by Mihir on 15-06-2021.
//

#include "zeel_select_module/SelectFuncForAllWithWhere.h"
#include "zeel_select_module/SelectFuncForColsWithWhere.h"
#include "zeel_select_module/SelectFuncForAllWithWhereWithAdditionalFunc.h"
#include "zeel_select_module/SelectFuncForColsWithWhereWithAdditionalFunc.h"
#include "mihir_select_module/SelectFuncForAll.h"
#include "parth_select_module/SelectFuncForCols.h"
#include "parth_select_module/SelectFuncForColWithAdditionalFunc.h"
#include "mihir_select_module/SelectFuncForAllWithAdditionalFunc.h"

#ifndef OURDB_DATABASE_SELECT_MODULE_H
#define OURDB_DATABASE_SELECT_MODULE_H

// function for allocating select query
string SelectQuery(vector <string> query)
{
    // check whether database is selected or not
    if(!(databaseSelectGlobal.empty()))
    {
        // string for after @ symbol
        string afterselect = "";

        // check for @ symbol
        if(query[1]==colSymbol[0])
        {
            return ErrAtSymbol[0];
        }

        // regex for separation using @
        regex regexforat("^[^@]*@[^@]*$");

        // add space in after select word
        for(int i=1;i<query.size();i++)
        {
            afterselect += query[i] + " ";
        }

        // check if regex is matched or not
        if(!regex_match(afterselect,regexforat))
        {
            return ErrInUpdateSyntaxForAt[0];
        }

        //variables
        vector <string> beforeafterat;       //vector string to return inserted data
        regex regexat("@");

        // will return unmatched vector string array
        filterRegexInstring(afterselect,beforeafterat,regexat,-1);

        // check before @ size
        if(beforeafterat.size()!=2)
        {
            return ErrSyntaxInSelectQuery[0];
        }

        // variable allocation for after and before @
        vector <string> afterat;
        vector <string> beforeat;

        regex regexspaceforat(" ");

        // will return unmatched values in terms of vector string array
        filterRegexInstring(beforeafterat[0],beforeat,regexspaceforat,-1);
        filterRegexInstring(beforeafterat[1],afterat,regexspaceforat,-1);

        // filter it out null values into vector string array
        for(int i=0;i<beforeat.size();i++)
        {
            if(beforeat[i].empty())
            {
                beforeat.erase(beforeat.begin()+i);
            }
        }

        // same as above
        for(int i=0;i<afterat.size();i++)
        {
            if(afterat[i].empty())
            {
                afterat.erase(afterat.begin()+i);
            }
        }

        // path for table
        string tablename = databaseSavePath +"/"+ afterat[0] +".Ourdb";

        // check table is exist or not
        if(filesystem::exists(tablename))
        {
            // table reading
            ifstream file(tablename);
            json ourdb;
            file >> ourdb;
            int countforcolcheck = 0;       //counter to check if select column name is present in table

            // regex for additional functions alt + 24 = ↑ and alt + 25 = ↓
            regex regexForConditionalOperation("[↑↓]");

            // allocation of select query
            if(beforeat[0] == var_for_func_inselect[0] && beforeat.size()==1)
            {
                if(afterat.size()==1)
                {
                    //select query for all data w/o where
                    return SelectFuncForAll(tablename);
                }
                else if(afterat.size()==2)
                {
                    if(regex_match(afterat[1],regexForConditionalOperation))
                    {
                        //select query with where condition and function with additional function
                        return SelectFuncForAllwithAdditionalFunc(tablename,afterat[1]);
                    }
                    else
                    {
                        return ErrSyntaxInSelectQuery[0];
                    }
                }
                else if(afterat.size()>2)
                {
                    if(syntaxCompare(afterat[1],where))
                    {
                        //select query for all data with where
                        return SelectFuncForAllWithWhere(tablename,afterat);
                    }
                    else if(regex_match(afterat[1],regexForConditionalOperation) && syntaxCompare(afterat[1],where))
                    {
                        //select query with where condition and function with additional function
                        return SelectFuncForAllWithWhereWithAdditionalFunc(tablename,afterat[1],afterat);
                    }
                    else
                    {
                        return ErrSyntaxInSelectQuery[0];
                    }
                }
                else
                {
                    return ErrSyntaxInSelectQuery[0];
                }

            }       //write code here in else-if statement to add more select statement functionalities
            else
            {
                // check columns into table
                for(auto &j : beforeat)
                {
                    for(auto &i : ourdb["records"]["col_names"])
                    {
                        if(j == i)
                        {
                            countforcolcheck++;
                        }
                    }
                }
                if(countforcolcheck == beforeat.size())
                {
                    if(afterat.size()==1)
                    {
                        //select query for cols data w/o where
                        return SelectFuncForCols(tablename,beforeat);
                    }
                    else if(afterat.size()==2)
                    {
                        if(regex_match(afterat[1],regexForConditionalOperation))
                        {
                            //select query with where condition and function with additional function
                            return SelectFuncForColswithAdditionalFunc(tablename,afterat[1],beforeat);
                        }
                        else
                        {
                            return ErrSyntaxInSelectQuery[0];
                        }
                    }
                    else if(afterat.size()>2)
                    {
                        if(syntaxCompare(afterat[1],where))
                        {
                            //select query for cols data with where
                            return SelectFuncForColsWithWhere(tablename,beforeat,afterat);
                        }
                        else if(regex_match(afterat[1],regexForConditionalOperation) && syntaxCompare(afterat[1],where))
                        {
                            //select query with where condition and function with additional function
                            return SelectFuncForColsWithWhereWithAdditionalFunc(tablename,afterat[1],beforeat,afterat);
                        }
                        else
                        {
                            return ErrSyntaxInSelectQuery[0];
                        }
                    }
                    else
                    {
                        return ErrSyntaxInSelectQuery[0];
                    }
                }
                else
                    return ErrorColumnDoesNotMatchFromTable[0];
            }

        }
        else
        {
            return tableDoesNotExist[0];
        }


    }
    else
    {
        return SelectTheDatabase[0];        //select database error if database isn't selected
    }
}


#endif //OURDB_DATABASE_SELECT_MODULE_H
