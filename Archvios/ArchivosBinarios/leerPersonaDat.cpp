#include <iostream>
#include <fstream>
using namespace std;

// Estructura igual a la usada al guardar
struct Persona {
    char nombre[50];
    char apellido[50];
    char dni[15];
    char fechaNacimiento[15];
    char direccion[100];
    char telefono[20];
    char email[50];
};

int main() {
    Persona p;

    ifstream archivo("persona.dat", ios::binary); // Abrimos en modo binario
    if (!archivo) {
        cout << "Error: no se pudo abrir el archivo persona.dat" << endl;
        return 1;
    }

    cout << "=== LECTURA DE DATOS DESDE ARCHIVO BINARIO ===" << endl << endl;

    // Mientras haya datos por leer...
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Persona))) {
        cout << "Nombre: " << p.nombre << endl;
        cout << "Apellido: " << p.apellido << endl;
        cout << "DNI: " << p.dni << endl;
        cout << "Fecha de nacimiento: " << p.fechaNacimiento << endl;
        cout << "Direccion: " << p.direccion << endl;
        cout << "Telefono: " << p.telefono << endl;
        cout << "Email: " << p.email << endl;
        cout << "----------------------------------------" << endl;
    }

    archivo.close();

    cout << "Fin de la lectura del archivo." << endl;

    return 0;
}
