#include<iostream>
using namespace std;

int main(){ 
    // Declaracion de variables
    int elementos, i=0;
    int vector[6];

    // Ingreso de cantidad de elementos del vector
    cout << "Ingrese la cantidad de elementos del vector:  ";
    cin >> elementos;

    // Carga de valores enteros en el vector
    while (i < 6){
        vector[i] = 1 + rand() % 100;
        i++;
    }

    // Muestra de los valores cargados en el vector
    cout << "" << endl;
    cout << "LISTA DE LOS VALORES CARGADOS EN EL VECTOR:" << endl;
    cout << "" << endl;
    for (i = 0; i < elementos; i++) {
        cout << vector[i] << "  ";
    }
    cout << "\n" << endl;

    return 0;
}