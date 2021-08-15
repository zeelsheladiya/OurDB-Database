![OurDB Database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/logo.png?raw=true)



# OurDB Database 

light weight Database. Created using c++ for every type of machine. Scalable as well as easy to use Database. 




## Authors

 - [Zeel Sheladiya](https://github.com/zeelsheladiya)
 - [Mihir Surati](https://github.com/mihirsurati)
 - [Parth Dabheliya](https://github.com/Parth-Dab)

  
## 🔗 Social Media Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://in.linkedin.com/in/zeel-sheladiya-772513176)

[![github](https://img.shields.io/badge/github-5000AD?style=for-the-badge&logo=github&logoColor=white)](https://github.com/zeelsheladiya)

  
## Documentation

[Documentation](https://github.com/zeelsheladiya/OurDB-Database/blob/main/OurDB_Database_Documentation.pdf)

## Video Tutorial

 - You can watch the video of how to use ourdb database on ourdb youtube channel.
 - here is the link :- [click here](https://www.youtube.com/watch?v=2e2Mfs0TdUI)

## Other Syantax related help
 - you can check ourdb_database/syntax.txt where you can find all updated syntax.

## Features

- Light weight (size less than 2mb)
- scalable
- Can run cross platform (Windows ,Mac ,Linux)
- Dynamically made database. Any developer can easily made changes
- Files with own encryption and own extension .Ourdb
- Even low end device like Arduino , raspberry pi can also run it.
- It requires minimum c++ 17 standard compiler or above to run on any system
- It is combination (NoSQL + SQL) because it doesn’t have schema for storing table but it has perfect syntax for creating query like SQL


  ## Run Locally

Clone the project

```bash
  git clone https://github.com/zeelsheladiya/OurDB-Database.git
```

  
## Usage/Examples

-> Add Database to your project

- Add or include OurDB_Database.h in your colnsole or gui program file

```javascript
#include "OurDB_Database.h"
```

## How To Use OurDB Database

[comment]: <> (create database ------------------------------------------------)

## Create database:
- First step to enter in the database system is to create database. A physical storage area where all table resides.
- Syntax : create/make database/db <database_name>

```javascript
create database zeel
``` 

![Create Database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_101.jpg?raw=true)

- Even you can change the (create) keyword in the code(instruction for developer) its dynamic add or remove keyword etc.

[comment]: <> (select database ------------------------------------------------)

## Select database:
- select the database among the existing databases else returns the error.
- Syntax : select/choose database/db <database_name>
- After creating database you have to compulsory select the database in order to create table and perform some action/operations.

```javascript
select database zeel
``` 

![select Database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_102.jpg?raw=true)

- database is so flexible that developer can change any keyword.

[comment]: <> (create table ------------------------------------------------)

## Create Table:
- Creates table in the database along with the column in it.
- Syntax : create/make table <table_name> @ <column1_name> <column2_name>…
- After creating database you have to compulsory select the database in order to create table and perform some action/operations.

```javascript
create table mark @ id name age 
``` 

![create table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_104.jpg?raw=true)

- with this simple syntax we can easily create the table in database.

[comment]: <> (Current database ------------------------------------------------)

## Current database:
- it will show the selected database/the database you are in right now.
- Syntax : current/present database/db

```javascript
current database
``` 

![current database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_105.jpg?raw=true)

- this query used when you don’t know what database you are in right now.

[comment]: <> (Rename database ------------------------------------------------)

## Rename database:
- It will rename the database in the system.
- first you have to select the database then and then you can perform rename query.and after renaming you have to again select the database to perform the operation.
- Syntax : rename database <database_name>

```javascript
select database parth
``` 

```javascript
rename database parthx
``` 

![Rename database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_106.jpg?raw=true)

- we have given this facility who wants to change the name of the database but it is not good practice to do so..

[comment]: <> (Show databases ------------------------------------------------)

## Show databases:
- It will show all the database resides in the system.
- Syntax : show/display/view all db/database

```javascript
show all db
``` 

![Show databases](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_107.jpg?raw=true)

- it is advisable to run query prior to any other query so that you can see all the database exists in the system

[comment]: <> (Show tables ------------------------------------------------)

## Show tables:
- It will show all the tables resides in the selected database.
- first we have to select the database so that we can see the table resides in it.
- Syntax : show/display/view all table

```javascript
show all table
``` 

![Show tables](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_108.jpg?raw=true)

[comment]: <> (Show column in table ------------------------------------------------)

## Show column in table:
- It will list out all the column which is present in the table
- After selecting database , create table and then you will be able to use this feature.
- Syntax : show all col @ <table_name>

```javascript
show all col @ tb1
``` 

![Show column in table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_109.jpg?raw=true)

- show column in table never return null value because column in the table decide at the creation of table.

[comment]: <> (Rename table in database ------------------------------------------------)

## Rename table in database:
- This command will rename the table exist in the particular database.
- make sure that table must exist before renaming the table.
- Syntax : rename table <old_table_name> <new_table_name>

```javascript
reaname table tbn tb1
``` 

![Rename table in database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_110.jpg?raw=true)

[comment]: <> (Rename column in table ------------------------------------------------)

## Rename column in table:
- This command will rename the column in the particular table
- make sure to check that column exist in the table by show all column @ table.
- Syntax :rename column/col from <table_name> @ <old_col_name> <new_col_name>

```javascript
rename col from tb1 @ age agex
``` 

![Rename column in table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_111.jpg?raw=true)

- this feature looks so simple but most important while working with the database.

[comment]: <> (Insert data in to the table ------------------------------------------------)

## Insert data in to the table:
- Insert query is used to enter the data in the empty column which was created with the table during creation of table
- make sure in which table you are going to insert the data ,that must be created before insertion of data.
- insert or add both will be accepted but not simultaneously.
- Syntax : insert into <table_name> @ '<col1_value>' '<col2_value>' ...

```javascript
insert into mark @ '1' 'zeel' '20' 
``` 

![Insert data in to the table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_112.jpg?raw=true)

- you can see the data in the table by select command we will look for it later on.
- Single quote is necessary for inserting the value in to the table.

[comment]: <> (Adding new column in the table ------------------------------------------------)

## Adding new column in the table:
- This command will add a new column in the existing table.
- make sure in which table you are going to insert the column ,that must be created before insertion of column.
- insert or add both will be accepted but not simultaneously.
- Syntax : insert/add col/column into <table_name> @ <col_name>

```javascript
insert col into mark @ gender
``` 

![Adding new column in the table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_113.jpg?raw=true)

[comment]: <> (Updating a data in to the table ------------------------------------------------)

## Updating a data in to the table:
- It used to update a data in to the table.
- Here after where table field and value connected with the = operator. Or !(not equal) operator.
- And for more than one condition you can concatenation condition with either &(and) or |(or)
- It's also support < , > , <= , >= operators.
- Syntax : update @ <table_name> set/put <table_field> '<field_value>' where <table_field1>(=|!)<field_value1> & <table_field2>(=|!)<field_value2>

```javascript
update @ mark set gender 'female' where id=1 & name=zeel
``` 

![Updating a data in to the table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_114.jpg?raw=true)

[comment]: <> (Delete the database ------------------------------------------------)

## Delete the database:
- It will delete the database from the system.
- delete or destroy both are accepted but not simultaneously
- Syntax : delete/destroy database <database_name>

```javascript
delete db dbn
``` 

![Delete the database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_115.jpg?raw=true)

- Before deleting the database always make sure that your all the tables are deleted or you may loss important data.

[comment]: <> (Delete the table ------------------------------------------------)

## Delete the table:
- Delete the table from the database.
- make sure to select the database before deleting table.
- Syntax : delete table <table_name>

```javascript
delete table tb
``` 

![Delete the table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_116.jpg?raw=true)

[comment]: <> (Delete the particular table data ------------------------------------------------)

## Delete the particular table data:
- Delete the data from the table at particular row/rows.
- make sure to select the database before deleting table.
- Here at particular row/rows you can delete a data.
- Here after where table field and value connected with the = operator. Or !(not equal) operator.
- And for more than one condition you can concatenation condition with either &(and) or |(or)
- It's also support < , > , <= , >= operators.
- Syntax : delete/destroy @ <table_name> where <column_name> (=/!) <column_value> (&/|) <column_name1> (=/!) <column_value1>

```javascript
delete @ tb1 where id=4
``` 

![Delete the particular table data](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_117.jpg?raw=true)

[comment]: <> (Delete the column ------------------------------------------------)

## Delete the column:
- This will delete the column from the table.
- make sure in which table you are going to insert the column ,that must be created before insertion of column.
- Syntax : delete/destroy column/col from <table_name> @ <col_name>

```javascript
delete col from tb1 @ pass
``` 

![Delete the column](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_118.jpg?raw=true)

[comment]: <> (Select data from table ------------------------------------------------)

## Select data from table:
- It will select and display the the data into the table format.
- Syntax : select/choose col1 col2 @ <table_name> where <column_name> (=/!) <column_value> (&/|) <column_name1> (=/!) <column_value1>

```javascript
select * @ tb
``` 

![Select data from table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_119.jpg?raw=true)

## Other updates will be added after new commits...

## Examples of console app with ourdb database

- this example's code also can be seen in OurDB_Database/console.cpp.

```javascript
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
``` 

## Contact

- If you need any help regarding this project feel free to contact us on our social media link and github account.
