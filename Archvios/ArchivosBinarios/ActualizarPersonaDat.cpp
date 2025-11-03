#include <iostream>
#include <fstream>
#include <cstring>  // Para strcmp y strcpy
using namespace std;

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
    char dniBuscado[15];
    bool encontrado = false;

    cout << "=== ACTUALIZAR REGISTRO EN persona.dat ===" << endl;
    cout << "Ingrese el DNI de la persona que desea modificar: ";
    cin.getline(dniBuscado, 15);

    // Abrimos el archivo en modo lectura/escritura binaria
    fstream archivo("persona.dat", ios::in | ios::out | ios::binary);
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    // Buscar el registro por DNI
    while (archivo.read(reinterpret_cast<char*>(&p), sizeof(Persona))) {
        if (strcmp(p.dni, dniBuscado) == 0) {
            encontrado = true;

            cout << "\nRegistro encontrado:\n";
            cout << "Nombre actual: " << p.nombre << endl;
            cout << "Apellido actual: " << p.apellido << endl;
            cout << "DNI: " << p.dni << endl;
            cout << "Fecha de nacimiento: " << p.fechaNacimiento << endl;
            cout << "Direccion actual: " << p.direccion << endl;
            cout << "Telefono actual: " << p.telefono << endl;
            cout << "Email actual: " << p.email << endl;

            cout << "\n--- Ingrese los nuevos datos ---\n";
            cout << "Nuevo nombre: ";
            cin.getline(p.nombre, 50);
            cout << "Nuevo apellido: ";
            cin.getline(p.apellido, 50);
            cout << "Nueva direccion: ";
            cin.getline(p.direccion, 100);
            cout << "Nuevo telefono: ";
            cin.getline(p.telefono, 20);
            cout << "Nuevo email: ";
            cin.getline(p.email, 50);

            // Retrocedemos el puntero del archivo al inicio del registro que queremos sobrescribir
            long posicion = -1 * static_cast<long>(sizeof(Persona));
            archivo.seekp(posicion, ios::cur);

            // Sobrescribimos el registro actualizado
            archivo.write(reinterpret_cast<char*>(&p), sizeof(Persona));

            cout << "\nRegistro actualizado correctamente.\n";
            break;
        }
    }

    if (!encontrado)
        cout << "\nNo se encontró ninguna persona con ese DNI.\n";

    archivo.close();
    return 0;
}
