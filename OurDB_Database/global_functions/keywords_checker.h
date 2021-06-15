//
// Created by Mihir on 15-06-2021.
//

#ifndef OURDB_DATABASE_KEYWORDS_CHECKER_H
#define OURDB_DATABASE_KEYWORDS_CHECKER_H

bool keywords_checker(string s)
{
    if(syntaxCompare(s,bannedkeywords))
    {
        return 1;
    }
    else
        return 0;
}

#endif //OURDB_DATABASE_KEYWORDS_CHECKER_H
