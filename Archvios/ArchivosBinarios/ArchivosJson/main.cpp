#include <iostream>
#include <fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

struct Persona {
    string nombre;
    int edad;
    string dni;
};

void agregarPersona() {
    Persona p;
    cout << "Nombre: ";
    cin >> p.nombre;
    cout << "Edad: ";
    cin >> p.edad;
    cout << "DNI: ";
    cin >> p.dni;

    json datos;
    ifstream entrada("personas.json");
    if (entrada) entrada >> datos;
    entrada.close();

    datos.push_back({{"nombre", p.nombre}, {"edad", p.edad}, {"dni", p.dni}});

    ofstream salida("personas.json");
    salida << datos.dump(4);
    salida.close();

    cout << "✅ Persona agregada.\n";
}

void listarPersonas() {
    ifstream archivo("personas.json");
    if (!archivo) {
        cout << "No hay archivo de personas aún.\n";
        return;
    }
    json datos;
    archivo >> datos;

    cout << "\n--- LISTA DE PERSONAS ---\n";
    for (auto& p : datos)
        cout << "Nombre: " << p["nombre"]
             << ", Edad: " << p["edad"]
             << ", DNI: " << p["dni"] << endl;
    cout << "--------------------------\n";
}

void actualizarPersona() {
    ifstream archivo("personas.json");
    if (!archivo) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    json datos;
    archivo >> datos;
    archivo.close();

    string dniBuscar;
    cout << "Ingrese el DNI a actualizar: ";
    cin >> dniBuscar;

    bool encontrado = false;
    for (auto& p : datos) {
        if (p["dni"] == dniBuscar) {
            cout << "Persona encontrada: " << p["nombre"] << endl;
            cout << "Nuevo nombre: ";
            cin >> p["nombre"];
            cout << "Nueva edad: ";
            cin >> p["edad"];
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró ese DNI.\n";
        return;
    }

    ofstream salida("personas.json");
    salida << datos.dump(4);
    salida.close();

    cout << "✅ Persona actualizada correctamente.\n";
}

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
