#include <iostream>
#include <fstream>
#include <cstring>  // para strcpy y strlen

using namespace std;

// Estructura que guarda los datos personales
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

    cout << "=== CARGA DE DATOS PERSONALES ===" << endl;

    cout << "Nombre: ";
    cin.getline(p.nombre, 50);

    cout << "Apellido: ";
    cin.getline(p.apellido, 50);

    cout << "DNI: ";
    cin.getline(p.dni, 15);

    cout << "Fecha de nacimiento (DD/MM/AAAA): ";
    cin.getline(p.fechaNacimiento, 15);

    cout << "Direccion: ";
    cin.getline(p.direccion, 100);

    cout << "Telefono: ";
    cin.getline(p.telefono, 20);

    cout << "Email: ";
    cin.getline(p.email, 50);

    // Abrimos el archivo binario para escribir (crea o sobreescribe)
    ofstream archivo("persona.dat", ios::binary);

    if (!archivo) {
        cout << "Error al abrir el archivo para escritura." << endl;
        return 1;
    }

    // Escribimos la estructura completa en el archivo
    archivo.write(reinterpret_cast<char*>(&p), sizeof(Persona));

    archivo.close();

    cout << "\nDatos guardados correctamente en archivo binario 'persona.dat'." << endl;

    return 0;
}
