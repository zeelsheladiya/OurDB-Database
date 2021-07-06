//
// Created by dabhe on 19-Jun-21.
//

#ifndef OURDB_DATABASE_GLOBALFUNCTIONFORSELECTQUERY_H
#define OURDB_DATABASE_GLOBALFUNCTIONFORSELECTQUERY_H

string SelectQueryStructureCreater(vector<string> vect,vector<vector<string>>vectl)
{
    string ml=""; // string which will strings
    for(int i=0;i<vect.size();i++) // iterate  through the string vect
    {
        if(i == vect.size()-1)   // last value of vector string
        {
            ml += vect[i]; // adds the last column name (data in vector) of vector to the string
        }
        else
        {
            ml += vect[i] + ","; // adds the column name (data in vector) of vector to the string except last
        }
    }
    ml += "\n "; // adds space to the new line
    ml += "\n"; // adds newline
    for (int i = 0; i < vectl.size(); i++)  // iterate through whole 2d vector
    {
        for (int j = 0; j < vectl[i].size(); j++) // iterate through 1d vector which is in the 1d vector
        {
            ml += vectl[i][j] + "\n"; // add the value of column
        }

        ml += " \n"; // adds the space,newline after every 1d string vector..

    }

    return ml; // return the string..

    // it will return string like ......
    // col1_name,col2_name,co3_name
    // <space>
    // col1_value\ncol2_value\nco3_value
    // <space>
    // col1_value\ncol2_value\nco3_value
    // <space>
    // col1_value\ncol2_value\nco3_value
    // <space>

}

void ascending_sort(vector<vector<string>> &data)
{
    sort(data.begin(),data.end());
}

void descending_sort(vector<vector<string>> &data)
{
    sort(data.begin(),data.end(),greater <>());
}

bool selectingSameColsMulTimes(vector <string> beforeat)
{
    int colcounter = 0;

    for(int i=0;i<beforeat.size()-1;i++)
    {
        for(int j=i+1;j<beforeat.size();j++)
        {
            if(beforeat[i] == beforeat[j])
            {
                colcounter++;
            }
        }
    }

    if(colcounter==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

#endif //OURDB_DATABASE_GLOBALFUNCTIONFORSELECTQUERY_H
