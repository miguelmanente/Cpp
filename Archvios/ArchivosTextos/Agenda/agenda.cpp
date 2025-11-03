#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <limits>
using namespace std;

struct Persona {
    string nombre;
    int edad;
    string dni;
};

// 🔹 Cargar una persona en el archivo CSV
void agregarPersona() {
    ofstream archivo("personas.csv", ios::app);
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Persona p;
    char op;
    do {
        cout << "Nombre: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar buffer
        getline(cin, p.nombre);

        cout << "Edad: ";
        cin >> p.edad;
        cin.ignore();

        cout << "DNI: ";
        getline(cin, p.dni);

        archivo << p.nombre << "," << p.edad << "," << p.dni << endl;
        cout << "✅ Persona guardada correctamente.\n";

        cout << "\n¿Desea agregar otra persona? (s/n): ";
        cin >> op;
    } while (op == 's' || op == 'S');

    archivo.close();
}

// 🔹 Leer todas las personas del archivo
void listarPersonas() {
    ifstream archivo("personas.csv");
    if (!archivo) {
        cout << "No hay archivo de personas aún.\n";
        return;
    }

    string linea;
    cout << "\n--- LISTA DE PERSONAS ---\n";
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string nombre, edad, dni;
        getline(ss, nombre, ',');
        getline(ss, edad, ',');
        getline(ss, dni, ',');

        cout << "Nombre: " << nombre << ", Edad: " << edad << ", DNI: " << dni << endl;
    }
    cout << "--------------------------\n";
}

// 🔹 Actualizar persona (por DNI)
void actualizarPersona() {
    ifstream entrada("personas.csv");
    if (!entrada) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    vector<Persona> personas;
    string linea;
    while (getline(entrada, linea)) {
        stringstream ss(linea);
        Persona p;
        string edadStr;
        getline(ss, p.nombre, ',');
        getline(ss, edadStr, ',');
        getline(ss, p.dni, ',');
        p.edad = stoi(edadStr);
        personas.push_back(p);
    }
    entrada.close();

    string dniBuscar;
    cout << "Ingrese el DNI de la persona a actualizar: ";
    cin >> dniBuscar;

    bool encontrado = false;
    for (auto& p : personas) {
        if (p.dni == dniBuscar) {
            cout << "Persona encontrada: " << p.nombre << ", edad " << p.edad << endl;
            cout << "Ingrese nuevo nombre: ";
            cin >> p.nombre;
            cout << "Ingrese nueva edad: ";
            cin >> p.edad;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró una persona con ese DNI.\n";
        return;
    }

    ofstream salida("personas.csv", ios::trunc);
    for (auto& p : personas)
        salida << p.nombre << "," << p.edad << "," << p.dni << endl;
    salida.close();

    cout << "✅ Persona actualizada correctamente.\n";
}

// 🔹 Menú principal
int main() {
    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar persona\n";
        cout << "2. Listar personas\n";
        cout << "3. Actualizar persona\n";
        cout << "0. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;
        system("pause");
        switch (opcion) {
            case 1: agregarPersona(); break;
            case 2: listarPersonas(); break;
            case 3: actualizarPersona(); break;
            case 0: cout << "Saliendo...\n"; break;
            default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);

    return 0;
}
