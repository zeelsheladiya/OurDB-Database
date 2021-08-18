//
// Created by zeel,pranav on 10/06/2021.
//

#ifndef OURDB_DATABASE_DELETE_COLUMN_QUERY_LOGIC_H
#define OURDB_DATABASE_DELETE_COLUMN_QUERY_LOGIC_H

std::string delete_column_query_logic_1(std::string table_path,std::string column_name,int column_index)
{
    // read .ourdb file
    std::ifstream file(table_path);
    json ourdb;
    file >> ourdb;

    if(ourdb["records"]["col_names"].size() > 1)
    {
        //variable for storing value of column
        int col_key_index = ourdb["records"]["col_index"][column_index];

        //delete the column name
        ourdb["records"]["col_names"].erase(column_index);

        // delete column nidex
        ourdb["records"]["col_index"].erase(column_index);

        // update the total column
        ourdb["records"]["total_cols"] = (int)ourdb["records"]["total_cols"] - 1;

        // loop for reading all values in terms of row
        if(ourdb["table_data"].size() > 0)
        {
            for (int i = 0; i < ourdb["table_data"].size(); i++)
            {
                //delete the value of related column
                ourdb["table_data"][i].erase(std::to_string(col_key_index));
            }
        }

        // writing into .ourdb file
        std::ofstream o(table_path);
        o << ourdb << std::endl;

        // deletion completed
        return SuccessDeleteColumn[0];

    }
    else
    {
        // table has only one column
        return ErrorOnlyOneColumnLeft[0];
    }

}

#endif //OURDB_DATABASE_DELETE_COLUMN_QUERY_LOGIC_H