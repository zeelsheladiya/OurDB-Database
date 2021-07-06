#include "OurDB_Database.h"
#include <iostream>
#include <string>
#include "variables/query_variables.h"
#include "global_functions/global_function.h"
#include "global_functions/SyntaxCheckerForResultString.h"

using namespace std;

template<class Element, class Container>
bool selectChecker(const Element & s ,const Container & s1)
{
    for(string i : s1)
    {
        //cout << i << endl << s.find(i) << endl;
        if(s.find(i) != -1)
        {
            return true;
        }
    }

    return false;
}


int main() {

    string s;

    while(true) {

        cout << "Enter Your query :  ";
        getline(cin, s);

        if(selectChecker(s,select_db_query))
        {
            if(selectChecker(s,colSymbol))
            {
                string check = run_query(s);

                if(SyntaxCheckerForResultString(check))
                {
                    cout << endl << To_StringTable(run_query(s)) << endl;
                }
                else
                    cout << endl << run_query(s) << endl;
            }
            else
            {
                cout << endl << run_query(s) << endl;
            }
        }
        else
        {
            cout << endl << run_query(s) << endl;
        }
    }

    return 0;
}
