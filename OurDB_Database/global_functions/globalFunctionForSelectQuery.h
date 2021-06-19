//
// Created by dabhe on 19-Jun-21.
//

#ifndef OURDB_DATABASE_GLOBALFUNCTIONFORSELECTQUERY_H
#define OURDB_DATABASE_GLOBALFUNCTIONFORSELECTQUERY_H

string SelectQueryStructureCreater(vector<string> vect,vector<vector<string>>vectl)
{
    string ml="";
    for(int i=0;i<vect.size();i++)
    {
        if(i == vect.size()-1)
        {
            ml += vect[i];
        }
        else
        {
            ml += vect[i] + ",";
        }
    }
    ml += "\n*";
    ml += "\n";
    for (int i = 0; i < vectl.size(); i++)
    {
        for (int j = 0; j < vectl[i].size(); j++)
        {
            ml += vectl[i][j] + "\n";
        }

        ml += "*\n";

    }

    return ml;
}
#endif //OURDB_DATABASE_GLOBALFUNCTIONFORSELECTQUERY_H
