#include <iostream>
using namespace std;

int main(){
    // Declaracion de variables
    int elementos, i, j, aux;
    int vector[5];

    // Ingreso de cantidad de elementos del vector
    cout << "Ingrese la cantidad de elementos del vector:  ";
    cin >> elementos;

    // Carga de valores enteros en el vector
    cout << "" << endl;
    cout << "CARGA DE VALORES EN EL VECTOR:" << endl;
    cout << "" << endl;
    for (i = 0; i < elementos; i++) {
        cout << "Ingrese el elemento " << i << ":" << endl;
        cin >> vector[i];
    }
    
    system("clear");
    
    // Muestra de los valores cargados en el vector
    cout << "" << endl;
    cout << "LISTA DE LOS VALORES DESORDENADOS:" << endl;
    cout << "" << endl;
    for (i = 0; i < elementos; i++) {
        cout << vector[i] << "  ";
    }
    cout << "" << endl;

    // Ordenamiento de los valores cargados en el vector (Metodo Burbuja)
    for (i = 0; i < elementos - 1; i++) {
        for (j = 0; j < elementos - 1 - i; j++) {
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
 
    // Muestra de los valores ordenados en el vector
    cout << "" << endl;
    cout << "LISTA DE LOS VALORES ORDENADOS EN EL VECTOR:" << endl;
    cout << "" << endl;
    for (i = 0; i < elementos; i++) {
        cout << vector[i] << "  ";
    }
    cout << "" << endl;
    return 0;
}