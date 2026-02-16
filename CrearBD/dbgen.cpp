#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Column {
    string name;
    string type;
    bool primaryKey;
    bool autoIncrement;
};

struct Table {
    string name;
    vector<Column> columns;
    vector<vector<string>> rows;
};

int main() {
    string dbName;
    int tableCount;

    cout << "Nombre de la base de datos: ";
    cin >> dbName;

    cout << "Cantidad de tablas: ";
    cin >> tableCount;

    vector<Table> tables;

    for (int t = 0; t < tableCount; t++) {
        Table table;
        int colCount;

        cout << "\nNombre de la tabla: ";
        cin >> table.name;

        cout << "Cantidad de columnas: ";
        cin >> colCount;

        for (int c = 0; c < colCount; c++) {
            Column col;

            cout << "Nombre columna: ";
            cin >> col.name;

            cout << "Tipo SQL (INT, VARCHAR(50), etc): ";
            cin >> col.type;

            cout << "Es PRIMARY KEY? (1=si 0=no): ";
            cin >> col.primaryKey;

            cout << "Es AUTO_INCREMENT? (1=si 0=no): ";
            cin >> col.autoIncrement;

            table.columns.push_back(col);
        }

        int rowCount;
        cout << "\nCantidad de registros iniciales:    ";
        cin >> rowCount;

        for (int r = 0; r < rowCount; r++) {
            vector<string> row;
            cout << "\nRegistro " << r + 1 << ":\n";

            for (const auto& col : table.columns) {
                string value;
                cout << col.name << ": ";
                cin >> value;
                row.push_back(value);
            }

            table.rows.push_back(row);
        }

        tables.push_back(table);
    }

    ofstream sql(dbName + ".sql");

    sql << "CREATE DATABASE IF NOT EXISTS " << dbName << ";\n";
    sql << "USE " << dbName << ";\n\n";

    for (const auto& table : tables) {
        sql << "CREATE TABLE " << table.name << " (\n";

        for (size_t i = 0; i < table.columns.size(); i++) {
            const auto& col = table.columns[i];

            sql << "    " << col.name << " " << col.type;

            if (col.autoIncrement)
                sql << " AUTO_INCREMENT";

            if (i < table.columns.size() - 1 || col.primaryKey)
                sql << ",";

            sql << "\n";
        }

        for (const auto& col : table.columns) {
            if (col.primaryKey) {
                sql << "    PRIMARY KEY (" << col.name << ")\n";
            }
        }

        sql << ");\n\n";

        for (const auto& row : table.rows) {
            sql << "INSERT INTO " << table.name << " VALUES (";

            for (size_t i = 0; i < row.size(); i++) {
                sql << "'" << row[i] << "'";
                if (i < row.size() - 1)
                    sql << ",";
            }

            sql << ");\n";
        }

        sql << "\n";
    }

    sql.close();

    cout << "\nArchivo " << dbName << "\n.sql generado correctamente\n";
    return 0;
}
