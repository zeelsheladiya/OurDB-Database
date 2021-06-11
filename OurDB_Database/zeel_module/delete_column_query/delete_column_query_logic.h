//
// Created by zeel,pranav on 10/06/2021.
//

#ifndef OURDB_DATABASE_DELETE_COLUMN_QUERY_LOGIC_H
#define OURDB_DATABASE_DELETE_COLUMN_QUERY_LOGIC_H

string delete_column_query_logic_1(string table_path,int column_index)
{
    // read .ourdb file
    ifstream file(table_path);
    json ourdb;
    file >> ourdb;

    return "yoyo";

}

#endif //OURDB_DATABASE_DELETE_COLUMN_QUERY_LOGIC_H