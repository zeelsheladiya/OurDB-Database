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
#include "../zeel_module/delete_query/delete_query_logic.h"
#include "decryption.h"
#include "External_Libraries/json.hpp"
//using namespace std;
using json = nlohmann::json;
#ifndef OURDB_DATABASE_AFTERWHEREPROCESS_H
#define OURDB_DATABASE_AFTERWHEREPROCESS_H


// this function is check that, is given column name available or not in given table path
bool isColumnAvailable(std::string colname ,std::string tablepath)
{
    json jason;
    std::fstream fs1(tablepath);
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
bool isOpeatorsAreInOrder(std::vector<std::string> value)
{
    int n = 0;
    if(value[0] == "!" || value[0] == "=" || value[0] == ">" || value[0] == "<"  || value[0] == ">=" || value[0] == "<=") // first value should be of comparision operator
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
                if (value[i] == "!" || value[i] == "=" || value[i] == ">" || value[i] == "<"  || value[i] == ">=" || value[i] == "<=") {
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


        if (value[value.size() - 1] == "!" || value[value.size() - 1] == "=" || value[value.size() - 1] == "<" || value[value.size() - 1] == ">" || value[value.size() - 1] == ">=" || value[value.size() - 1] == "<=") //at last position there should be (!=) comparision operator
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
int countMatchInRegex(std::string s, std::string re)
{
    std::regex words_regex(re);
    auto words_begin = std::sregex_iterator(
            s.begin(), s.end(), words_regex);
    auto words_end = std::sregex_iterator();
    // it will return count (matches in string) using regex.
    return distance(words_begin, words_end);
}

// it will trim a string from the left(remove space from left) using regex
std::string l_regextrim(const std::string &s) {
    return regex_replace(s, std::regex("^\\s+"), std::string(""));
}

// it will trim a string from the right(remove space from right) using regex
std::string r_regextrim(const std::string &s) {
    return regex_replace(s, std::regex("\\s+$"), std::string(""));
}

// it will filter with the help of regex and stores it into a vector string from string..
void filterRegexInstring(std::string h , std::vector<std::string> &op , std::regex r , int filter)
{
    std::sregex_token_iterator iter1{h.begin(),h.end(),r,filter} , end1;
    for ( ; iter1 != end1; ++iter1)
    {
        op.insert(op.end(),*iter1);
    }
}

// where function for process where condition in string
// note :- here table_path parameter means table's path and h is a string after the where keyword and mode for switch statement
// note :- this function search from the front to the backward
std::string  globalFuncForWhereClouse(std::string h ,std::string table_path , std::map<std::string,std::string> set_data,int mode,std::vector <std::string> strsep3)
{

    std::regex regexForOperation("[&!=|]|<=|>=|>|<"); // regex  defined for operator..
    std::vector<std::string> operation; // vector string for storing operator.
    std::vector<std::string> values; // vector string for storing actual value (column name and value as vector array).
    filterRegexInstring(h,values,regexForOperation,-1); //it will call the above defined function...
    std::regex regexForInteger("[0-9]{0,}"); // regex for integer
    std::regex regexForFloat("[0-9]*\\.?[0-9]{1,}");// regex for Float

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

    std::string opstring; // store the value which are converted from vector to string
    for (auto const& s : operation) { opstring += s; } //it will convert vector string to string.
    int op1 = countMatchInRegex(opstring,"[|&]"); // it will count the logical operator in 'opstring'
    int op2 = countMatchInRegex(opstring,"[!=]|<=|>=|>|<"); // it will count the comparision operator in 'opstring'

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
                        if(isColumnAvailable(values[i],table_path)) //check the column available in table or not
                        {
                            tempCheckForColumn++; // counter for available column
                        }
                    }

                    if(values.size()/2 == tempCheckForColumn) // column from json should match with column from string
                    {
                        std::string strOperation; // stores the value from vector to string.

                        for (const auto &piece : operation) {strOperation += piece;} // conversation vector string into string

                        std::vector<std::string> compareOp; // stores the comparision operator.
                        std::vector<std::string> logicalOp; // stores the logical operator.

                        std::regex reg("[&|]"); // regex

                        filterRegexInstring(strOperation,compareOp,reg,-1); //  filter regex in string defined in above string

                        filterRegexInstring(strOperation,logicalOp,reg,0); //  filter regex in string defined in above string

                        std::vector<bool> boolStr; // stores the boolean value

                        int tempForValue = 0; // tempForVale for the index value of vector string
                        int tempForLogicalOp = 0;// tempForLogicalOp for the index value of vector string
                        int counterLogicalOp = 0;// counter for the logicalOp variable
                        int counterCompareOp = 0;// counter for the compareOp variable

                        json jason; // json object
                        std::fstream  fs(table_path); // read the file
                        fs >> jason; // inport file data into json object

                        int processCounter = 0; // counter for process

                        if(jason["table_data"].size() > 0) {
                            // this will iterate through json["table_data"]
                            for (int i = 0; i < jason["table_data"].size(); i++) {
                                if (compareOp.size() > 0) {
                                    for (int j = 0;
                                         j < compareOp.size(); j++) // iterate through vector <string> compareOp
                                    {
                                        if (compareOp[j] == "=") // compare (=) operator with the compareOp
                                        {
                                            std::string l = "";
                                            for (int k = 0; k < jason["records"]["col_names"].size(); k++) {
                                                // compare column name from json file to query string
                                                if (values[tempForValue] == jason["records"]["col_names"][k]) {
                                                    l = to_string(jason["records"]["col_index"][k]);
                                                    break;
                                                }
                                            }

                                            // compare data with decryption
                                            if (decryption(jason["table_data"][i][l]) == values[tempForValue + 1]) {
                                                counterCompareOp++;
                                                boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                            } else {
                                                boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                            }
                                        }

                                        if (compareOp[j] == "!") // compare (!) operator with the compareOp
                                        {

                                            std::string l = "";
                                            for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                            {
                                                // compare column name from json file to query string
                                                if (values[tempForValue] == jason["records"]["col_names"][m])
                                                {
                                                    l = to_string(jason["records"]["col_index"][m]);
                                                    break;
                                                }
                                            }
                                            if (decryption(jason["table_data"][i][l]) != values[tempForValue + 1])
                                            {
                                                counterCompareOp++;
                                                boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                            } else {
                                                boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                            }
                                        }

                                        if (compareOp[j] == ">") // compare (!) operator with the compareOp
                                        {

                                            std::string l = "";
                                            for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                            {
                                                // compare column name from json file to query string
                                                if (values[tempForValue] == jason["records"]["col_names"][m])
                                                {
                                                    l = to_string(jason["records"]["col_index"][m]);
                                                    break;
                                                }
                                            }

                                            //check if value is integer
                                            if(regex_match(decryption(jason["table_data"][i][l]),regexForFloat) && regex_match(values[tempForValue + 1],regexForFloat))
                                            {
                                                if (stof(decryption(jason["table_data"][i][l])) > stof(values[tempForValue + 1]))
                                                {
                                                    counterCompareOp++;
                                                    boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                } else {
                                                    boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                }
                                            }
                                            else
                                            {
                                                return ErrorShouldBeInt[0];
                                            }
                                        }

                                        if (compareOp[j] == "<") // compare (!) operator with the compareOp
                                        {

                                            std::string l = "";
                                            for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                            {
                                                // compare column name from json file to query string
                                                if (values[tempForValue] == jason["records"]["col_names"][m])
                                                {
                                                    l = to_string(jason["records"]["col_index"][m]);
                                                    break;
                                                }
                                            }

                                            //check if value is integer
                                            if(regex_match(decryption(jason["table_data"][i][l]),regexForFloat) && regex_match(values[tempForValue + 1],regexForFloat))
                                            {
                                                if (stof(decryption(jason["table_data"][i][l])) < stof(values[tempForValue + 1]))
                                                {
                                                    counterCompareOp++;
                                                    boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                } else {
                                                    boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                }
                                            }
                                            else
                                            {
                                                return ErrorShouldBeInt[0];
                                            }
                                        }

                                        if (compareOp[j] == ">=") // compare (!) operator with the compareOp
                                        {

                                            std::string l = "";
                                            for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                            {
                                                // compare column name from json file to query string
                                                if (values[tempForValue] == jason["records"]["col_names"][m])
                                                {
                                                    l = to_string(jason["records"]["col_index"][m]);
                                                    break;
                                                }
                                            }

                                            //check if value is integer
                                            if(regex_match(decryption(jason["table_data"][i][l]),regexForFloat) && regex_match(values[tempForValue + 1],regexForFloat))
                                            {
                                                if (stof(decryption(jason["table_data"][i][l])) >= stof(values[tempForValue + 1]))
                                                {
                                                    counterCompareOp++;
                                                    boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                } else {
                                                    boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                }
                                            }
                                            else
                                            {
                                                return ErrorShouldBeInt[0];
                                            }
                                        }

                                        if (compareOp[j] == "<=") // compare (!) operator with the compareOp
                                        {

                                            std::string l = "";
                                            for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                            {
                                                // compare column name from json file to query string
                                                if (values[tempForValue] == jason["records"]["col_names"][m])
                                                {
                                                    l = to_string(jason["records"]["col_index"][m]);
                                                    break;
                                                }
                                            }

                                            //check if value is integer
                                            if(regex_match(decryption(jason["table_data"][i][l]),regexForFloat) && regex_match(values[tempForValue + 1],regexForFloat))
                                            {
                                                if (stof(decryption(jason["table_data"][i][l])) <= stof(values[tempForValue + 1]))
                                                {
                                                    counterCompareOp++;
                                                    boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                } else {
                                                    boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                }
                                            }
                                            else
                                            {
                                                return ErrorShouldBeInt[0];
                                            }
                                        }


                                        tempForValue += 2; //temp value counter by 2
                                    }

                                }

                                if (logicalOp.size() > 0) {
                                    for (int j = 0; j < logicalOp.size(); j++) // for iterate through logicalOp.
                                    {

                                        if (logicalOp[j] =="&") // compare (&) operator with the logicalop
                                        {
                                            if (boolStr[tempForLogicalOp] && boolStr[tempForLogicalOp +1]) // it will check both the bool value are true then counterLogicalOp
                                            {
                                                counterLogicalOp++; // counterLogicalOp increment
                                            }
                                        }

                                        if (logicalOp[j] == "|") // compare (|) operator with the logicalop
                                        {
                                            if (boolStr[tempForLogicalOp] || boolStr[tempForLogicalOp +1]) // it will check both the bool value are true then counterLogicalOp
                                            {
                                                counterLogicalOp++; //counterLogicalOP increment
                                            }
                                        }

                                        tempForLogicalOp += 1; //temp value counter by 1

                                    }
                                }

                                if(counterCompareOp > 0)
                                {
                                    if (counterLogicalOp == logicalOp.size()) {
                                        switch (mode)
                                        {
                                            case 1:

                                                // update query function
                                                ForUpdate(i, set_data, table_path,strsep3);
                                                processCounter++;
                                                break;

                                            default:

                                                break;
                                        }
                                    }
                                }

                                boolStr.clear(); // clear the vector bool array
                                tempForValue = 0; // tempForVale for the index value of vector string
                                tempForLogicalOp = 0;// tempForLogicalOp for the index value of vector string
                                counterLogicalOp = 0;// counter for the logicalOp variable
                                counterCompareOp = 0;// counter for the compareOp variable

                            }
                        }
                        else
                        {
                            //error that table does not have any data
                            return ErrNoDataForUpdateInTable[0];
                        }

                        if (processCounter > 0)
                        {
                            //success process massage with rows are affected
                            return SuccessUpdateDataTableMsg[0] + " " + std::to_string(processCounter) +" Rows are affected !";
                        } else
                        {
                            //success process massage without rows are affected
                            return SuccessUpdateDataTableMsg[0] + " " + std::to_string(processCounter) +" Row affected !";
                        }
                    }
                    else
                    {
                        // error column does not exist
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

// where function for process where condition in string
// note :- here table_name is name of the table and h is a string after the where keyword and mode for switch statement
// note :- this function search from the backward to the front
std::string globalFuncForWhereClouse(std::string h , std::string table_name ,int mode)
{

    std::regex regexForOperation("[&!=|]|<=|>=|>|<"); // regex  defined for operator..
    std::vector<std::string> operation; // vector string for storing operator.
    std::vector<std::string> values; // vector string for storing actual value (column name and value as vector array).
    filterRegexInstring(h,values,regexForOperation,-1); //it will call the above defined function...
    std::regex regexForInteger("[0-9]{0,}"); // regex for integer
    std::regex regexForFloat("[0-9]*\\.?[0-9]{1,}");// regex for Float

    std::string stringOfIndexies = "";

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

    std::string opstring; // store the value which are converted from vector to string
    for (auto const& s : operation) { opstring += s; } //it will convert vector string to string.
    int op1 = countMatchInRegex(opstring,"[|&]"); // it will count the logical operator in 'opstring'
    int op2 = countMatchInRegex(opstring,"[!=]|<=|>=|>|<"); // it will count the comparision operator in 'opstring'

    if(values.size()%2 == 0) // check the given vector sting is even is or not(column : value)
    {
        if(isOpeatorsAreInOrder(operation)) // defined above function check the order of operator
        {
            if(op1+1 == op2) // op2 should  op1+1
            {
                if(values.size() == op2 * 2) // vector <string> value should be multiple of 2(op2)
                {
                        int tempCheckForColumn = 0; // temp variable to count of available column

                    std::string tablepath = databaseSavePath + "/" + table_name + ".Ourdb";  // path of the table

                        for(int i = 0; i < values.size() ; i+=2)
                        {
                            if(isColumnAvailable(values[i],tablepath)) //check the column available in table or not
                            {
                                tempCheckForColumn++; // counter for available column
                            }
                        }

                        if(values.size()/2 == tempCheckForColumn) // column from json should match with column from string
                        {
                            std::string strOperation; // stores the value from vector to string.

                            for (const auto &piece : operation) {strOperation += piece;} // conversation vector string into string

                            std::vector<std::string> compareOp; // stores the comparision operator.
                            std::vector<std::string> logicalOp; // stores the logical operator.

                            std::regex reg("[&|]"); // regex

                            filterRegexInstring(strOperation,compareOp,reg,-1); //  filter regex in string defined in above string

                            filterRegexInstring(strOperation,logicalOp,reg,0); //  filter regex in string defined in above string

                            std::vector<bool> boolStr; // stores the boolean value

                            int tempForValue = 0; // tempForVale for the index value of vector string
                            int tempForLogicalOp = 0;// tempForLogicalOp for the index value of vector string
                            int counterLogicalOp = 0;// counter for the logicalOp variable
                            int counterCompareOp = 0;// counter for the compareOp variable

                            json jason; // json object
                            std::fstream  fs(tablepath); // read the file
                            fs >> jason; // inport file data into json object

                            int processCounter = 0; // counter for process

                            if(jason["table_data"].size() > 0)
                            {
                                for (int i = jason["table_data"].size() - 1; i > -1; i--)
                                {
                                    if(compareOp.size() > 0 )
                                    {
                                        for (int j = 0 ; j < compareOp.size(); j++) // iterate through vector <string> compareOp
                                        {
                                            if (compareOp[j] == "=") // compare (=) operator with the compareOp
                                            {
                                                std::string l = "";
                                                for (int k = 0; k < jason["records"]["total_cols"]; k++)
                                                {
                                                    // compare column name from json file to query string
                                                    if (values[tempForValue] == jason["records"]["col_names"][k])
                                                    {
                                                        l = to_string(jason["records"]["col_index"][k]);
                                                        break;
                                                    }
                                                }

                                                // compare data with decryption
                                                if (decryption(jason["table_data"][i][l]) == values[tempForValue + 1])
                                                {
                                                    counterCompareOp++;
                                                    boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                } else {
                                                    boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                }
                                            }

                                            if (compareOp[j] == "!") // compare (!) operator with the compareOp
                                            {
                                                std::string l = "";
                                                for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                                {
                                                    // compare column name from json file to query string
                                                    if (values[tempForValue] == jason["records"]["col_names"][m])
                                                    {
                                                        l = to_string(jason["records"]["col_index"][m]);
                                                        break;
                                                    }
                                                }

                                                // compare data with decryption
                                                if (decryption(jason["table_data"][i][l]) != values[tempForValue + 1])
                                                {
                                                    counterCompareOp++;
                                                    boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                } else {
                                                    boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                }
                                            }


                                            if (compareOp[j] == ">") // compare (!) operator with the compareOp
                                            {

                                                std::string l = "";
                                                for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                                {
                                                    // compare column name from json file to query string
                                                    if (values[tempForValue] == jason["records"]["col_names"][m])
                                                    {
                                                        l = to_string(jason["records"]["col_index"][m]);
                                                        break;
                                                    }
                                                }

                                                //check if value is integer
                                                if(regex_match(decryption(jason["table_data"][i][l]),regexForFloat) && regex_match(values[tempForValue + 1],regexForFloat))
                                                {
                                                    if (stof(decryption(jason["table_data"][i][l])) > stof(values[tempForValue + 1]))
                                                    {
                                                        counterCompareOp++;
                                                        boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                    } else {
                                                        boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                    }
                                                }
                                                else
                                                {
                                                    return ErrorShouldBeInt[0];
                                                }
                                            }

                                            if (compareOp[j] == "<") // compare (!) operator with the compareOp
                                            {

                                                std::string l = "";
                                                for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                                {
                                                    // compare column name from json file to query string
                                                    if (values[tempForValue] == jason["records"]["col_names"][m])
                                                    {
                                                        l = to_string(jason["records"]["col_index"][m]);
                                                        break;
                                                    }
                                                }

                                                //check if value is integer
                                                if(regex_match(decryption(jason["table_data"][i][l]),regexForFloat) && regex_match(values[tempForValue + 1],regexForFloat))
                                                {
                                                    if (stof(decryption(jason["table_data"][i][l])) < stof(values[tempForValue + 1]))
                                                    {
                                                        counterCompareOp++;
                                                        boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                    } else {
                                                        boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                    }
                                                }
                                                else
                                                {
                                                    return ErrorShouldBeInt[0];
                                                }
                                            }


                                            if (compareOp[j] == ">=") // compare (!) operator with the compareOp
                                            {

                                                std::string l = "";
                                                for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                                {
                                                    // compare column name from json file to query string
                                                    if (values[tempForValue] == jason["records"]["col_names"][m])
                                                    {
                                                        l = to_string(jason["records"]["col_index"][m]);
                                                        break;
                                                    }
                                                }

                                                //check if value is integer
                                                if(regex_match(decryption(jason["table_data"][i][l]),regexForFloat) && regex_match(values[tempForValue + 1],regexForFloat))
                                                {
                                                    if (stof(decryption(jason["table_data"][i][l])) >= stof(values[tempForValue + 1]))
                                                    {
                                                        counterCompareOp++;
                                                        boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                    } else {
                                                        boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                    }
                                                }
                                                else
                                                {
                                                    return ErrorShouldBeInt[0];
                                                }
                                            }

                                            if (compareOp[j] == "<=") // compare (!) operator with the compareOp
                                            {

                                                std::string l = "";
                                                for (int m = 0; m < jason["records"]["col_names"].size(); m++)
                                                {
                                                    // compare column name from json file to query string
                                                    if (values[tempForValue] == jason["records"]["col_names"][m])
                                                    {
                                                        l = to_string(jason["records"]["col_index"][m]);
                                                        break;
                                                    }
                                                }

                                                //check if value is integer
                                                if(regex_match(decryption(jason["table_data"][i][l]),regexForFloat) && regex_match(values[tempForValue + 1],regexForFloat))
                                                {
                                                    if (stof(decryption(jason["table_data"][i][l])) <= stof(values[tempForValue + 1]))
                                                    {
                                                        counterCompareOp++;
                                                        boolStr.insert(boolStr.end(),true); // insert boolean value(true) in vector<bool>
                                                    } else {
                                                        boolStr.insert(boolStr.end(),false); // insert boolean value(false) in vector<bool>
                                                    }
                                                }
                                                else
                                                {
                                                    return ErrorShouldBeInt[0];
                                                }
                                            }

                                            tempForValue += 2; //temp value counter by 2
                                        }
                                    }

                                    if (logicalOp.size() > 0) {
                                        for (int j = 0; j < logicalOp.size(); j++) // for iterate through logicalOp.
                                        {
                                            if (logicalOp[j] == "&") // compare (&) operator with the logicalop
                                            {
                                                if (boolStr[tempForLogicalOp] && boolStr[tempForLogicalOp + 1]) // it will check both the bool value are true then counterLogicalOp
                                                {
                                                    counterLogicalOp++; // counterLogicalOp increment
                                                }
                                            }

                                            if (logicalOp[j] == "|") // compare (|) operator with the logicalop
                                            {
                                                if (boolStr[tempForLogicalOp] || boolStr[tempForLogicalOp + 1]) // it will check both the bool value are true then counterLogicalOp
                                                {
                                                    counterLogicalOp++; //counterLogicalOP increment
                                                }
                                            }

                                            tempForLogicalOp += 1; //temp value counter by 1
                                        }
                                    }

                                    if (counterCompareOp > 0)
                                    {
                                        if (counterLogicalOp == logicalOp.size())
                                        {
                                            switch (mode)
                                            {
                                                case 1:

                                                    // delete query function
                                                    DeleteColumnFunc(table_name, i);
                                                    processCounter++;
                                                    break;

                                                case 2:

                                                    // get indexies which will going to have fill the given condition
                                                    stringOfIndexies += std::to_string(i);
                                                    processCounter++;
                                                    break;

                                                default:

                                                    break;
                                            }

                                        }
                                    }

                                    boolStr.clear(); // clear the vector bool array
                                    tempForValue = 0; // tempForVale for the index value of vector string
                                    tempForLogicalOp = 0;// tempForLogicalOp for the index value of vector string
                                    counterLogicalOp = 0;// counter for the logicalOp variable
                                    counterCompareOp = 0;// counter for the compareOp variable

                                }
                            }
                            else
                            {
                                //error that table does not have any data
                                return ErrNoDataForDeleteInTable[0];
                            }

                            if(processCounter > 0)
                            {
                                if(mode == 2)
                                {
                                    return stringOfIndexies;
                                }
                                //success process massage with rows are affected
                                return SuccessDeleteDataTableMsg[0] + " " + std::to_string(processCounter) + " Rows are affected !";
                            }
                            else
                            {
                                if(mode == 2)
                                {
                                    return stringOfIndexies;
                                }
                                //success process massage without rows are affected
                                return SuccessDeleteDataTableMsg[0] + " " + std::to_string(processCounter) + " Row affected !";
                            }

                        }
                        else
                        {
                            // error column does not exist
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
