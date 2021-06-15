//
// Created by Mihir on 15-06-2021.
//

#include "zeel_select_module/SelectFuncForAllWithWhere.h"
#include "zeel_select_module/SelectFuncForColsWithWhere.h"
#include "mihir_select_module/SelectFuncForAll.h"
#include "parth_select_module/SelectFuncForCols.h"

#ifndef OURDB_DATABASE_SELECT_MODULE_H
#define OURDB_DATABASE_SELECT_MODULE_H

string SelectQuery(vector <string> query)
{
    if(!(databaseSelectGlobal.empty()))
    {
        string afterselect = "";

        if(query[1]==colSymbol[0])
        {
            return "@ error!";
        }

        regex regexforat("^[^@]*@[^@]*$");

        for(int i=1;i<query.size();i++)
        {
            afterselect += query[i] + " ";
        }

        if(!regex_match(afterselect,regexforat))
        {
            return "Mul or none @ error!!";
        }

        vector <string> beforeafterat;       //vector string to return inserted data
        regex regexat("@");

        filterRegexInstring(afterselect,beforeafterat,regexat,-1);

        if(beforeafterat.size()!=2)
        {
            return "Syntax error select!!!";
        }

        vector <string> afterat;
        vector <string> beforeat;

        regex regexspaceforat(" ");

        filterRegexInstring(beforeafterat[0],beforeat,regexspaceforat,-1);
        filterRegexInstring(beforeafterat[1],afterat,regexspaceforat,-1);

        for(int i=0;i<beforeat.size();i++)
        {
            if(beforeat[i].empty())
            {
                beforeat.erase(beforeat.begin()+i);
            }
        }

        for(int i=0;i<afterat.size();i++)
        {
            if(afterat[i].empty())
            {
                afterat.erase(afterat.begin()+i);
            }
        }

        string tablename = databaseSavePath +"/"+ afterat[0] +".Ourdb";

        if(filesystem::exists(tablename))
        {
            ifstream file(tablename);
            json ourdb;
            file >> ourdb;
            int countforcolcheck = 0;       //counter to check if select column name is present in table

            if(beforeat[0] == var_for_func_inselect[0] && beforeat.size()==1)
            {
                if(afterat.size()==1)
                {
                    //select query for all data w/o where
                    return SelectFuncForAll(tablename);
                }
                else if(afterat.size()>2)
                {
                    if(afterat[1]==where[0])
                    {
                        //select query for all data with where
                        return SelectFuncForAllWithWhere(tablename,afterat);
                    }
                    else
                    {
                        return "Syntax error!";
                    }
                }
                else
                {
                    return "Syntax error!";
                }

            }       //write code here in else-if statement to add more select statement functionalities
            else
            {
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
                    else if(afterat.size()>2)
                    {
                        if(afterat[1]==where[0])
                        {
                            //select query for cols data with where
                            return SelectFuncForColsWithWhere(tablename,beforeat,afterat);
                        }
                        else
                        {
                            return "Syntax error!";
                        }
                    }
                    else
                    {
                        return "Syntax error!";
                    }
                }
                else
                    cout <<"ERROR!";
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
