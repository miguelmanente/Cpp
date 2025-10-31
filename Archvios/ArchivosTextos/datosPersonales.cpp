#include <iostream>
#include <fstream>   // Para manejar archivos
#include <string>    // Para usar strings

using namespace std;

int main() {
    // Variables para guardar los datos personales
    string nombre, apellido, dni, fechaNacimiento, direccion, telefono, email;

    // Pedimos los datos por teclado
    cout << "=== CARGA DE DATOS PERSONALES ===" << endl;
    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Apellido: ";
    getline(cin, apellido);

    cout << "DNI: ";
    getline(cin, dni);

    cout << "Fecha de nacimiento (DD/MM/AAAA): ";
    getline(cin, fechaNacimiento);

    cout << "Direccion: ";
    getline(cin, direccion);

    cout << "Telefono: ";
    getline(cin, telefono);

    cout << "Email: ";
    getline(cin, email);

    // Creamos y abrimos el archivo de texto
    ofstream archivo("persona.txt");

    // Verificamos si se pudo abrir correctamente
    if (!archivo) {
        cout << "Error: no se pudo crear el archivo." << endl;
        return 1;  // Salir con error
    }

    // Escribimos los datos en el archivo
    archivo << "=== DATOS PERSONALES ===" << endl;
    archivo << "Nombre: " << nombre << endl;
    archivo << "Apellido: " << apellido << endl;
    archivo << "DNI: " << dni << endl;
    archivo << "Fecha de Nacimiento: " << fechaNacimiento << endl;
    archivo << "Direccion: " << direccion << endl;
    archivo << "Telefono: " << telefono << endl;
    archivo << "Email: " << email << endl;

    // Cerramos el archivo
    archivo.close();

    cout << "\nLos datos se guardaron correctamente en 'persona.txt'." << endl;

    return 0;
}
