#include <iostream>
using namespace std;

int main(){
    // Declaracion de variables
    int elementos, i;
    int vector[5];

    // Ingreso de cantidad de elementos del vector
    cout << "Ingrese la cantidad de elementos del vector:  ";
    cin >> elementos;

    // Carga de valores enteros en el vector
    cout << "CARGA DE VALORES EN EL VECTOR:" << endl;
    cout << "" << endl;
    for (i = 0; i < elementos; i++) {
        cout << "Ingrese el elemento " << i << ":" << endl;
        cin >> vector[i];
    }
    system("clear");

    // Muestra de los valores cargados en el vector
    cout << "" << endl;
    cout << "LISTA DE LOS VALORES CARGADOS EN EL VECTOR:" << endl;
    cout << "" << endl;
    for (i = 0; i < elementos; i++) {
        cout << "Vector[" << i << "] = " << vector[i] << endl;
    }
    cout << "" << endl;

    return 0;
}