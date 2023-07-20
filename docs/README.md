<!-- markdownlint-configure-file {
  "MD013": {
    "code_blocks": false,
    "tables": false
  },
  "MD033": false,
  "MD041": false
} -->

# Oikos database

[<img src="../img/logo.png" align="center" width="100">](https://github.com/zeelsheladiya/OurDB-Database)

<br/>

# 1. Overview Of The Project
This is documentation to [Oikos-db](https://github.com/zeelsheladiya/OurDB-Database) which is created and licensed by [Zeel Sheladiya](https://github.com/zeelsheladiya), [Mihir Surati](https://github.com/mihirsurati), [Parth Dabheliya](https://github.com/Parth-Dab), Pranav patel and contributors.

## 1.1 Scope Of The Project
Database Management systems are widely used by companies and organizations to maintain and manage their knowledge and information resources. After completing a database management course, students might work in any number of industries including: 
- Automotive
- Banking
- Education
- Legal
- Insurance,
- Government
- Pharmaceutical
- Retail
- Data Science
- NGO etc.

## 2. Overview Of The Existing Systems And Technologies

## 2.1 Types of Database Management Systems
There are several types of database management systems. Here is a list of seven  common database management systems: 
- Hierarchical databases
- Network databases
- Relational databases
- Object-oriented databases
- Graph databases
- ER model databases
- Document databases
- NoSQL databases etc.

## 2.2 Database Management Software
There are several types of database management softwares. Here is a list of seven common database management softwares: 
- SolarWinds Database Performance Analyzer
- DbVisualizer
- ManageEngine Application Manager
- Altibase
- Oracle RDBMS
- IBM DB2
- Microsoft SQL Server
- SAP Sybase ASE
- Teradata
- ADABAS
- MySQL
- FileMaker
- Microsoft Access
- Informix
- SQLite
- PostgresSQL
- AmazonRDS
- MongoDB
- Redis
- CouchDB
- Neo4j
- OrientDB
- Couchbase
- phpMyAdmin
- SQL Developer
- MariaDB etc.

# 3. Architecture Of OurDB

## 3.1 Process Flow Of OurDB
In this Database management system , after connecting the database with your application.  Whenever you use run_query() , through this function your query will be gone for process via 
OurDB_Database.h to query_process.h. 

In the query processor your query gets some operation  on it and through these operations, it will be selected by three main modules. After the module operation if there is data for insertion or updation, it will write in encrypted form into the physical storage area. 

However , if there is data for viewing purpose then the module will perform operation on actual data and then present you in the form of string.

## 3.2 Objectives Of The Project
- You don’t need to install this database to use. It’s make this database super portable.
- You can make your own query syntax very easily . it’s make your query code super protected.
- It has all data files in encrypted format.
- You can connect this database with your application with just one line of code.
- This database works in both application console and GUI.
- Database import and export is super easy.
- You can make a shared database without any connection string or any extra connection.
- You can add your own module in the database for the query process.
- It’s very lite in terms of size.
- To run this database you don’t need any extra speciﬁcation requirement in your system. So it can work smoothly in low specs machines.

# 4. Feasibility Study

## 4.1. Financial Feasibility
It is too light weight and it doesn't need any high end requirements to run. So it can be too cheap or very affordable for all kinds of developers.

## 4.2. Technical feasibility
OurDB is a completely data operation based application. The main  technologies and tools that are associated with OurDB are ,

- C++ Compiler

This technology is freely available and technical skills required are manageable. From These it’s clear that the project OurDB is technically feasible.

## 4.3. Resource and Time Feasibility
Resource that are required for the OurDB project includes, C++ compiler, Space in physical disk to record the data, C and C++ supported environment

## 5. Consideration
1.	Performance
2.	Security
3.	Usability and ease of use
4.	Capacity and Scalability
5.	Availability
6.	Maintainability

## 6. GETTING STARTED
This will tell you about the OurDB database. And how to use it.Its so simple to use this database system you don’t need to install whole database  system like any other. But just add some database files not more than(under 1.5	MB) and need to install c++17 compiler(minimum requirement).

## 6.1 We need to follow some step to get started with database..
1. You have to include Ourdb_Database.h header file to your application so that you can use database.
2. Then you have to create a database.
3. After creating database, you can create table and do all table related operation.
4. Then you can insert into the the table.
5. Even you can perform update and delete operation with & and | operators.

## 6.2 Additional functionality:
a) We have added functionality for the developer to convert data to json object.

b) Convert the data to stringTable(represent data in table format in console application)

c) Convert the data to map

	Developer can easily change the filter to convert to the above three format, by default it is string.


## 7. Syntax and uses

## 7.1 Create database:
First step to enter in the database system is to create database. A physical storage area where all table resides.

> Above example shows that it is very simple to create a database..

Even you can change the (create) keyword in the code(instruction for developer). its  dynamic add or remove keyword etc.


## Select database :
select the database among the existing databases else returns the error.


> After creating database you have to compulsory select the database in order to create table and perform some action/operations.

Note : database is so flexible that developer can change any keyword..



	Create table :
Creates table in the database along with the column in it.

Keyword : create or make


   NOTE : After creating database you have to compulsory select the database 
in order to create table and perform some action/operations.




NOTE : with this simple syntax we can easily create the table in database.






	Current database :
it will show the selected database/the database you are in right now.





Note: this query used when you don’t know what database you are in right now.




	Rename database :
It will rename the database in the system..

    NOTE : first you have to select the database then and then you can perform rename 
query.and after renaming you have to again select the database to perform the operation.




  Note: we have given this facility who wants to change the name of the 
database but it is not good practice to do so..




	Show databases :
It will show all the database resides in the system.



NOTE : it is advisable to run query prior to any other query so that you can see all the 
database exists in the system






	Show tables :
It will show all the tables resides in the selected database.

 Note : first we have to select the database so that we can see the table 
resides in it.








	Show column in table :
It will list out all the column which is present in the table

 Note : After selecting database , create table and then you will be able to use 
this feature.



Note: show column in table never return null value because column in the 
table decide at the creation of table.







	Rename table in database :
This command will rename the table exist in the particular database.

Note : make sure that table must exist before renaming the table.









	Rename column in table :
This command will rename the column in the particular table

 Note : make sure to check that column exist in the table by show all column 
@ table.

Keyword : column/col both will be accepted but not simultaneously.




Note : this feature looks so simple but most important while working with the 
database .



	Insert data in to the  table :

Insert query is used to enter the data in the empty column which was created 
with the table during creation of table.

 Note : make sure in which table you are going to insert the data ,that must be 
created before insertion of data.

Keyword :insert or add both will be accepted but not simultaneously.





Note : you can see the data in the table by select command we will look for it 
later on.

Single quote is necessary for inserting the value in to the table.



	Adding new column in the table :

This command will add a new column in the existing table.

 Note : make sure in which table you are going to insert the column ,that must 
be created before insertion of column.

Keyword :insert or add both will be accepted but not simultaneously.





	Updating a data in to the table :
It used to update a data in to the table ..

Here at particular row/rows you can update a data.

Here after where table field and value connected with the = 
operator.
Or !(not equal) operator.

And for more than one condition you can concatenation condition 
with either &(and) or |(or)








	Delete the database :
It will delete the database from the system.

Keyword : delete or destroy both are accepted but not 
simultaneously



NOTE : Before deleting the database always make sure that your all the tables are deleted 
or you may loss important data.




	Delete the table :
Delete the table from the database.

Note: make sure to select the database before deleting table.




## Delete the particular table data :
Delete the data from the table at particular row/rows . Note: make sure to select the database before deleting table.

> Here at particular row/rows you can delete a data.
> Here after where table field and value connected with the =  operator.
> Or !(not equal) operator.

And for more than one condition you can concatenation condition  with either &(and) or |(or)

Syntax : delete/destroy @ <table_name> where <column_name>
(=/!) <column_value> (&/|) <column_name1> (=/!)

<column_value1>









## Delete the column
This will delete the column from the table. Note : make sure in which table you are going to insert the column ,that must be created before insertion of column.

## Select data from table:
It will select and display the the data into the table format.

## Syntax 
```
: select/choose col1 col2 @ <table_name> where
<column_name> (=/!) <column_value> (&/|) <column_name1>
(=/!) <column_value1>```

## Encryption And Decryption
The data stored in the database should be secure and can’t be read by  the user or any other ,While they are stored in the database. So that we created our own encryption and decryption method to encrypt and  decrypt data respectively.

The encryption and decryption use in this we gave name as 69Cryption. This 69Cryption method encrypt the data before stored in the json format  And decrypt the data after user ask to retrieve it. So that user can see the  encrypted data.

## How actually data stored in the table
The Encrypted data are stored in to the <file_name>.Ourdb (here Ourdb extension is especially for our database system). While user run query “create table” , the <file_name>.Ourdb is stored in specified database. Which was previously selected by the user. While user uses “insert into” query, the data stored in the file as Json  format.

## Future Enhancement
We have code in our github directory.we will put  directory as public so every one will be able to take advantage of  database and also then can add more feature . we have created in such a way that , changes can be easily made. So that we want to create a big community which can enhance the  code.



# OurDB Database <img src="nwse.png" width="150px">
Light weight Database. Created using c++ for every type of machine. Scalable as well as easy to use Database. 

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

```c++
#include "OurDB_Database.h"
```

## How To Use OurDB Database

[comment]: <> (create database ------------------------------------------------)

## Create database:
- First step to enter in the database system is to create database. A physical storage area where all table resides.
- Syntax : create/make database/db <database_name>

```c++
create database zeel
``` 

![Create Database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_101.jpg?raw=true)

- Even you can change the (create) keyword in the code(instruction for developer) its dynamic add or remove keyword etc.

[comment]: <> (select database ------------------------------------------------)

## Select database:
- select the database among the existing databases else returns the error.
- Syntax : select/choose database/db <database_name>
- After creating database you have to compulsory select the database in order to create table and perform some action/operations.

```c++
select database zeel
``` 

![select Database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_102.jpg?raw=true)

- database is so flexible that developer can change any keyword.

[comment]: <> (create table ------------------------------------------------)

## Create Table:
- Creates table in the database along with the column in it.
- Syntax : create/make table <table_name> @ <column1_name> <column2_name>…
- After creating database you have to compulsory select the database in order to create table and perform some action/operations.

```c++
create table mark @ id name age 
``` 

![create table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_104.jpg?raw=true)

- with this simple syntax we can easily create the table in database.

[comment]: <> (Current database ------------------------------------------------)

## Current database:
- it will show the selected database/the database you are in right now.
- Syntax : current/present database/db

```c++
current database
``` 

![current database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_105.jpg?raw=true)

- this query used when you don’t know what database you are in right now.

[comment]: <> (Rename database ------------------------------------------------)

## Rename database:
- It will rename the database in the system.
- first you have to select the database then and then you can perform rename query.and after renaming you have to again select the database to perform the operation.
- Syntax : rename database <database_name>

```c++
select database parth
``` 

```c++
rename database parthx
``` 

![Rename database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_106.jpg?raw=true)

- we have given this facility who wants to change the name of the database but it is not good practice to do so..

[comment]: <> (Show databases ------------------------------------------------)

## Show databases:
- It will show all the database resides in the system.
- Syntax : show/display/view all db/database

```c++
show all db
``` 

![Show databases](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_107.jpg?raw=true)

- it is advisable to run query prior to any other query so that you can see all the database exists in the system

[comment]: <> (Show tables ------------------------------------------------)

## Show tables:
- It will show all the tables resides in the selected database.
- first we have to select the database so that we can see the table resides in it.
- Syntax : show/display/view all table

```c++
show all table
``` 

![Show tables](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_108.jpg?raw=true)

[comment]: <> (Show column in table ------------------------------------------------)

## Show column in table:
- It will list out all the column which is present in the table
- After selecting database , create table and then you will be able to use this feature.
- Syntax : show all col @ <table_name>

```c++
show all col @ tb1
``` 

![Show column in table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_109.jpg?raw=true)

- show column in table never return null value because column in the table decide at the creation of table.

[comment]: <> (Rename table in database ------------------------------------------------)

## Rename table in database:
- This command will rename the table exist in the particular database.
- make sure that table must exist before renaming the table.
- Syntax : rename table <old_table_name> <new_table_name>

```c++
reaname table tbn tb1
``` 

![Rename table in database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_110.jpg?raw=true)

[comment]: <> (Rename column in table ------------------------------------------------)

## Rename column in table:
- This command will rename the column in the particular table
- make sure to check that column exist in the table by show all column @ table.
- Syntax :rename column/col from <table_name> @ <old_col_name> <new_col_name>

```c++
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

```c++
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

```c++
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

```c++
update @ mark set gender 'female' where id=1 & name=zeel
``` 

![Updating a data in to the table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_114.jpg?raw=true)

[comment]: <> (Delete the database ------------------------------------------------)

## Delete the database:
- It will delete the database from the system.
- delete or destroy both are accepted but not simultaneously
- Syntax : delete/destroy database <database_name>

```c++
delete db dbn
``` 

![Delete the database](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_115.jpg?raw=true)

- Before deleting the database always make sure that your all the tables are deleted or you may loss important data.

[comment]: <> (Delete the table ------------------------------------------------)

## Delete the table:
- Delete the table from the database.
- make sure to select the database before deleting table.
- Syntax : delete table <table_name>

```c++
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

```c++
delete @ tb1 where id=4
``` 

![Delete the particular table data](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_117.jpg?raw=true)

[comment]: <> (Delete the column ------------------------------------------------)

## Delete the column:
- This will delete the column from the table.
- make sure in which table you are going to insert the column ,that must be created before insertion of column.
- Syntax : delete/destroy column/col from <table_name> @ <col_name>

```c++
delete col from tb1 @ pass
``` 

![Delete the column](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_118.jpg?raw=true)

[comment]: <> (Select data from table ------------------------------------------------)

## Select data from table:
- It will select and display the the data into the table format.
- Syntax : select/choose col1 col2 @ <table_name> where <column_name> (=/!) <column_value> (&/|) <column_name1> (=/!) <column_value1>

```c++
select * @ tb
``` 

![Select data from table](https://github.com/zeelsheladiya/OurDB-Database/blob/main/images/PrtScr%20capture_119.jpg?raw=true)

[comment]: <> (primery key to table ------------------------------------------------)

## To set primary and foreign key:
- Now ourdb has schema such as primary key nad foreign key.
- Syntax [primary key] : set $ <col_name> @ <table_name>
- Syntax [foreign key] : set # <col_name> @ <table_name> $ <primary_table_name>

```c++
// to set primary key
set $ id @ testTable
``` 

```c++
// to set foreign key
set # id @ testTable $ mainTable
``` 

## Functions for output:
- there are mainly three functions to get better formatted output such as output as a string , map , json.
- Syntax [ output as a table string for console app ] : To_StringTable(run_query("your query"))
- Syntax [ output as a map object ] : To_Map(run_query("your query"))
- Syntax [ output as a json object ] : To_Json(run_query("your query"))

```c++
// to get table string
To_StringTable(run_query("select * @ testTable"))
``` 

```c++
// to get map object
To_Map(run_query("select * @ testTable"))
``` 

```c++
// to get json object
To_Json(run_query("select * @ testTable"))
``` 

## Other updates will be added after new commits...

## Examples of console app with ourdb database

- this example's code also can be seen in OurDB_Database/console.cpp.

```c++
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
