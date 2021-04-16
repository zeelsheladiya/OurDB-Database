#include "OurDB_Database.h"
#include <iostream>
#include <string>


using namespace std;

int main() {

    string s;

    while(true) {

        cout << "Enter Your query :  ";
        getline(cin, s);
        cout << run_query(s) << endl;

    }

    return 0;
}
