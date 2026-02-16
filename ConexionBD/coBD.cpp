// Instalar en Linux Mint estas librerías 
// sudo apt update
// sudo apt install libmysqlcppconn-dev  o
// sudo apt install libmysql++-dev

// Usa la librería estándar de C++ para entrada/salida por consola. 
// Proporciona std::cout, std::cerr, std::endl, etc.
#include <iostream>
using namespace std;
// Incluye definiciones de excepciones estándar por ejemplo std::runtime_error. 
// En este código no se usa explícitamente, así que no es necesario, pero no hace daño incluirlo.
#include <stdexcept>

// mysql_driver.h — declara sql::mysql::get_mysql_driver_instance y la clase del driver MySQL.
#include <mysql-cppconn/jdbc/mysql_driver.h>

// mysql_connection.h — define la clase sql::Connection.
#include <mysql-cppconn/jdbc/mysql_connection.h>

// mysql_statement.h — declara sql::Statement.
#include <mysql-cppconn/jdbc/cppconn/statement.h>
#include <mysql-cppconn/jdbc/cppconn/prepared_statement.h>

// exception.h — declara sql::SQLException.
#include <mysql-cppconn/jdbc/cppconn/exception.h>

// cppconn/resultset.h — declara sql::ResultSet.
#include <mysql-cppconn/jdbc/cppconn/resultset.h>

// incluye los punteros inteligentes de C++ y utilidades relacionadas con la gestión automática de recursos.
#include <memory>

int main(){
    // Inicio de un bloque try para capturar excepciones (luego hay un catch para sql::SQLException). 
    // Si ocurre una excepción dentro del try, se salta al catch.
    try {
        //Obtiene el driver de MySQL. get_mysql_driver_instance() suele devolver un singleton 
        //(puntero a la instancia del driver). driver se usa para crear conexiones.
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();

        // Conexión al servidor MySQL de XAMPP
        //driver->connect(...) abre una conexión al servidor MySQL en la dirección dada: 
        //protocolo TCP, 127.0.0.1 puerto 3306. También se pasan usuario "root" y contraseña "Mibero606487".
        //El resultado es un puntero sql::Connection*. Se envuelve en std::unique_ptr<sql::Connection> 
        //para gestionar automáticamente la memoria y cerrar la conexión al salir del bloque.
        unique_ptr<sql::Connection> con(
            driver->connect("tcp://127.0.0.1:3306", "root", "Mibero606487")
        );

        //Muestra por consola un mensaje indicando que la conexión fue exitosa.
        cout << "Conectado a MySQL!" << endl;

        //Selecciona la base de datos (schema) agenda para la conexión. Equivalente a hacer USE agenda; en SQL.
        con->setSchema("agenda"); // BD que creaste

        //Crea un objeto Statement a partir de la conexión (con->createStatement() devuelve sql::Statement*)
        //y lo envuelve en std::unique_ptr para gestión RAII. stmt permite ejecutar consultas SQL que no requieren parámetros.
        unique_ptr<sql::Statement> stmt(con->createStatement());
        
        //Ejecuta la consulta SELECT * FROM personas y guarda el resultado en un sql::ResultSet. También envuelto en unique_ptr. res
        //contendrá todas las filas devueltas por la consulta.
        unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM personas"));

        while (res->next()) {
            cout << "ID: " << res->getInt("id")
                      << " Nombre: " << res->getString("nombre")
                      << " Tel: " << res->getString("telefono") 
                      <<endl;
        }
    }
    //Bloque catch que captura excepciones del tipo sql::SQLException (lanzadas por el conector si hay problemas de conexión,
    //consulta, credenciales, etc.).
    //imprime el mensaje de error en std::cerr y devuelve 1 indicando fallo.
    catch (sql::SQLException& e) {
        cerr << "Error MySQL: " << e.what() << endl;
        return 1;
    }
}

