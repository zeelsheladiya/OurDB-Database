//
// Created by dabhe on 02-Jun-21.
//
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<regex>
#include<fstream>
#include "Errors/error_variable.h"
#include "Parth_module/update_into_table/ForUpdate.h"
#include "decryption.h"
#include "External_Libraries/json.hpp"
using namespace std;
using json = nlohmann::json;
#ifndef OURDB_DATABASE_AFTERWHEREPROCESS_H
#define OURDB_DATABASE_AFTERWHEREPROCESS_H


bool isColumnAvailable(string colname , string tablename)
{
    json jason;
    fstream fs1(tablename);
    fs1 >> jason;
    int counter = 0;
    for(int i=0;i<jason["records"]["col_names"].size();i++)
    {
        if(jason["records"]["col_names"][i] == colname)
        {
            counter = 1;
            break;
        }else
        {
            counter = 0;
        }
    }

    if(counter == 0)
    {
        return false;

    }else
    {
        return true;
    }

}

//checks whether operator are in order or not
bool isOpeatorsAreInOrder(vector<string> value)
{
    int n = 0;
    if(value[0] == "!" || value[0] == "=") // first value should be of comparision operator
    {
        n++;  // it will increment the variable n
    }
    else
    {
        return false;
    }

    if(value.size() > 1) {
        for (int i = 1; i < value.size() - 1; i++) {
            if (i % 2 == 0) // at even position there should be (! =) comparision operator
            {
                if (value[i] == "!" || value[i] == "=") {
                    n++; //increment n
                } else {
                    return false;
                }
            }

            if (i % 2 == 1)  //at odd position there should be (& |) logical operator
            {
                if (value[i] == "&" || value[i] == "|") {
                    n++; //increment n
                } else {
                    return false;
                }
            }
        }


        if (value[value.size() - 1] == "!" ||
            value[value.size() - 1] == "=") //at last position there should be (!=) comparision operator
        {
            n++;
        } else {
            return false;
        }
    }

    if(n == value.size()) // vector <string> value and variable n should be same
    {
        return true;
    }
    else
    {
        return false;
    }
}

// count the matches in regex..
int countMatchInRegex(string s, string re)
{
    regex words_regex(re);
    auto words_begin = sregex_iterator(
            s.begin(), s.end(), words_regex);
    auto words_end = sregex_iterator();
    // it will return count (matches in string) using regex.
    return distance(words_begin, words_end);
}

// it will trim a string from the left(remove space from left) using regex
string l_regextrim(const string &s) {
    return regex_replace(s, regex("^\\s+"), string(""));
}

// it will trim a string from the right(remove space from right) using regex
string r_regextrim(const std::string &s) {
    return regex_replace(s, regex("\\s+$"), string(""));
}

// it will filter with the help of regex and stores it into a vector string from string..
void filterRegexInstring(string h , vector<string> &op , regex r , int filter)
{
    sregex_token_iterator iter1(h.begin(),h.end(),r,filter);
    sregex_token_iterator end1;
    for ( ; iter1 != end1; ++iter1)
    {
        op.insert(op.end(),*iter1);
    }
}

string  globalFuncForWhereClouse(string h , string table_name , map<string,string> set_data,int mode)
{

    regex regexForOperation("[&!=|]"); // regex  defined for operator..
    vector<string> operation; // vector string for storing operator.
    vector<string> values; // vector string for storing actual value (column name and value as vector array).
    filterRegexInstring(h,values,regexForOperation,-1); //it will call the above defined function...

    for(int i = 0 ; i < values.size() ; i++)
    {
        if(values[i].empty()) // it will check whether the  element in vector array is empty or not
        {
            values.erase(values.begin()+i); // if it is empty then it will erase..
        }
    }

    for (int i = 0 ; i < values.size() ; i++)
    {
        values[i] = l_regextrim(values[i]);//remove extra space from the left(trim from left)
        values[i] = r_regextrim(values[i]);//remove extra space from the right(trim from right)
    }

    filterRegexInstring(h,operation,regexForOperation,0); // defined in above function.

    string opstring; // store the value which are converted from vector to string
    for (auto const& s : operation) { opstring += s; } //it will convert vector string to string.
    int op1 = countMatchInRegex(opstring,"[|&]"); // it will count the logical operator in 'opstring'
    int op2 = countMatchInRegex(opstring,"[!=]"); // it will count the comparision operator in 'opstring'
    if(values.size()%2 == 0) // check the given vector sting is even is or not(column : value)
    {
        if(isOpeatorsAreInOrder(operation)) // defined above function check the order of operator
        {
            if(op1+1 == op2) // op2 should  op1+1
            {
                if(values.size() == op2 * 2) // vector <string> value should be multiple of 2(op2)
                {
                    int tempCheckForColumn = 0; // temp variable to count of available column
                    for(int i = 0; i < values.size() ; i+=2)
                    {
                        if(isColumnAvailable(values[i],table_name)) //check the column available in table or not
                        {
                            tempCheckForColumn++;
                        }
                    }

                    if(values.size()/2 == tempCheckForColumn) // column from json should match with column from string
                    {
                        string strOperation; // stores the value from vector to string.

                        for (const auto &piece : operation) {strOperation += piece;}

                        vector<string> compareOp; // stores the comparision operator.
                        vector<string> logicalOp; // stores the logical operator.

                        regex reg("[&|]"); // regex

                        filterRegexInstring(strOperation,compareOp,reg,-1); //  filter regex in string defined in above string

                        vector<bool> boolStr; // stores the boolean value

                        int tempForValue = 0; // tempForVale for the index value of vector string
                        int tempForLogicalOp = 0;// tempForLogicalOp for the index value of vector string
                        int counterLogicalOp = 0;// counterLogicalOp for the index value of vector string

                        json jason;
                        fstream  fs(table_name);
                        fs >> jason;

                        // this will iterate through json["table_data"]
                        for(int i = 0 ; i < jason["table_data"].size() ; i++)
                        {

                            for(int j = 0 ; j < compareOp.size() ; j++) // iterate through vector <string> compareOp
                            {

                                if(compareOp[j] == "=") // compare (=) operator with the compareOp
                                {

                                    string l ="";
                                        for(int k=0;k<jason["records"]["col_names"].size();k++)
                                        {
                                            if(values[tempForValue] == jason["records"]["col_names"][k])
                                            {
                                                l = to_string((k+1));
                                            }
                                        }

                                    if(decryption(jason["table_data"][i][l]) == values[ tempForValue + 1 ])
                                    {
                                        boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                    }
                                    else
                                    {
                                        boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                    }
                                }

                                if(compareOp[j]=="!") // compare (!) operator with the compareOp
                                {

                                    string l ="";
                                    for(int m=0;m<jason["records"]["col_names"].size();m++)
                                    {
                                        if(values[tempForValue] != jason["records"]["col_names"][m])
                                        {

                                            l = to_string(m+1);
                                        }
                                    }
                                    if(decryption(jason["table_data"][i][l]) == values[tempForValue + 1])
                                    {

                                        boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                    }
                                    else
                                    {
                                        boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                    }
                                }

                                tempForValue += 2; //temp value counter by 2
                            }

                            for(int j = 0 ; j < logicalOp.size() ; j++) // for iterate through logicalOp.
                            {

                                if(logicalOp[j].compare("&")) // compare (&) operator with the logicalop
                                {
                                    if( boolStr[tempForLogicalOp] && boolStr[tempForLogicalOp + 1]) // it will check both the bool value are true then counterLogicalOp
                                    {

                                        counterLogicalOp++; // counterLogicalOp increment
                                    }
                                }

                                if(logicalOp[j].compare("|")) // compare (|) operator with the logicalop
                                {
                                    if( boolStr[tempForLogicalOp] || boolStr[tempForLogicalOp + 1]) // it will check both the bool value are true then counterLogicalOp
                                    {
                                        counterLogicalOp++; //counterLogicalOP increment
                                    }
                                }

                                tempForLogicalOp+=2; //temp value counter by 2

                            }

                            if(counterLogicalOp == logicalOp.size())
                            {
                                switch(mode)
                                {
                                    case 1:
                                        ForUpdate(i,set_data,table_name);
                                        break;

                                    default:
                                      break;
                                }
                            }

                        }
                        return "success";

                    }
                    else
                    {
                        return  ErrColumnDoesNotExists[0];
                    }
                }
                else
                {
                    return ErrInsufficientColumnValue[0];
                }
            }
            else
            {
                return ErrorDontHaveEnoughOperator[0];
            }
        }
        else
        {
            return ErrorConditionNotInAppropriateOrder[0];
        }
    }
    else
    {
        return ErrInsufficientColumnValue[0];
    }


}

string globalFuncForWhereClouse(string h , string table_name ,int mode)
{

    regex regexForOperation("[&!=|]"); // regex  defined for operator..
    vector<string> operation; // vector string for storing operator.
    vector<string> values; // vector string for storing actual value (column name and value as vector array).
    filterRegexInstring(h,values,regexForOperation,-1); //it will call the above defined function...

    for(int i = 0 ; i < values.size() ; i++)
    {
        if(values[i].empty()) // it will check whether the  element in vector array is empty or not
        {
            values.erase(values.begin()+i); // if it is empty then it will erase..
        }
    }


    for (int i = 0 ; i < values.size() ; i++)
    {
        values[i] = l_regextrim(values[i]);//remove extra space from the left(trim from left)
        values[i] = r_regextrim(values[i]);//remove extra space from the right(trim from right)
    }

    filterRegexInstring(h,operation,regexForOperation,0); // defined in above function.

    string opstring; // store the value which are converted from vector to string
    for (auto const& s : operation) { opstring += s; } //it will convert vector string to string.
    int op1 = countMatchInRegex(opstring,"[|&]"); // it will count the logical operator in 'opstring'
    int op2 = countMatchInRegex(opstring,"[!=]"); // it will count the comparision operator in 'opstring'

    if(values.size()%2 == 0) // check the given vector sting is even is or not(column : value)
    {
        if(isOpeatorsAreInOrder(operation)) // defined above function check the order of operator
        {
            if(op1+1 == op2) // op2 should  op1+1
            {
                if(values.size() == op2 * 2) // vector <string> value should be multiple of 2(op2)
                {
                    int tempCheckForColumn = 0; // temp variable to count of available column
                    for(int i = 0; i < values.size() ; i+=2)
                    {
                        if(isColumnAvailable(values[i],table_name)) //check the column available in table or not
                        {
                            tempCheckForColumn++;
                        }
                    }

                    if(values.size()/2 == tempCheckForColumn) // column from json should match with column from string
                    {
                        string strOperation; // stores the value from vector to string.

                        for (const auto &piece : operation) {strOperation += piece;}

                        vector<string> compareOp; // stores the comparision operator.
                        vector<string> logicalOp; // stores the logical operator.

                        regex reg("[&|]"); // regex

                        filterRegexInstring(strOperation,compareOp,reg,-1); //  filter regex in string defined in above string

                        vector<bool> boolStr; // stores the boolean value

                        int tempForValue = 0; // tempForVale for the index value of vector string
                        int tempForLogicalOp = 0;// tempForLogicalOp for the index value of vector string
                        int counterLogicalOp = 0;// counterLogicalOp for the index value of vector string

                        json jason;
                        fstream  fs(table_name);
                        fs >> jason;


                        for(int i = 0 ; i < jason["table_data"].size();i++)
                        {
                            for(int j = 0 ; j < compareOp.size() ; j++) // iterate through vector <string> compareOp
                            {
                                if(compareOp[j].compare("=")) // compare (=) operator with the compareOp
                                {
                                    string l ="";
                                    for(int k=0;k<jason["records"]["col_names"].size();k++)
                                    {
                                        if(values[tempForValue] == jason["records"]["col_names"][k])
                                        {
                                            l = to_string((k+1));
                                        }
                                    }

                                    if(decryption(jason["table_data"][i][l]) == values[ tempForValue + 1 ])
                                    {
                                        boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                    }
                                    else
                                    {
                                        boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                    }
                                }

                                if(compareOp[j].compare("!")) // compare (!) operator with the compareOp
                                {
                                    string l ="";
                                    for(int m=0;m<jason["records"]["col_names"].size();m++)
                                    {
                                        if(values[tempForValue] != jason["records"]["col_names"][m])
                                        {

                                            l = to_string(m+1);
                                        }
                                    }
                                    if(decryption(jason["table_data"][i][l]) == values[tempForValue + 1])
                                    {

                                        boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                    }
                                    else
                                    {
                                        boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                    }
                                }

                                tempForValue += 2; //temp value counter by 2
                            }

                            for(int j = 0 ; j < logicalOp.size() ; j++) // for iterate through logicalOp.
                            {
                                if(logicalOp[j].compare("&")) // compare (&) operator with the logicalop
                                {
                                    if( boolStr[tempForLogicalOp] && boolStr[tempForLogicalOp + 1]) // it will check both the bool value are true then counterLogicalOp
                                    {

                                        counterLogicalOp++; // counterLogicalOp increment
                                    }
                                }

                                if(logicalOp[j].compare("|")) // compare (|) operator with the logicalop
                                {
                                    if( boolStr[tempForLogicalOp] || boolStr[tempForLogicalOp + 1]) // it will check both the bool value are true then counterLogicalOp
                                    {
                                        counterLogicalOp++; //counterLogicalOP increment
                                    }
                                }

                                tempForLogicalOp+=2; //temp value counter by 2

                            }

                            if(counterLogicalOp == logicalOp.size())
                            {
                                switch(mode)
                                {
                                    case 1:

                                        break;

                                    default:
                                        break;
                                }
                            }

                        }

                    }
                    else
                    {
                        return  ErrColumnDoesNotExists[0];
                    }
                }
                else
                {
                    return ErrInsufficientColumnValue[0];
                }
            }
            else
            {
                return ErrorDontHaveEnoughOperator[0];
            }
        }
        else
        {
            return ErrorConditionNotInAppropriateOrder[0];
        }
    }
    else
    {
        return ErrInsufficientColumnValue[0];
    }

}
#endif //OURDB_DATABASE_AFTERWHEREPROCESS_H
