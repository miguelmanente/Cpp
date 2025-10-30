#include<iostream>
using namespace std;

int main(){ 
    // Declaracion de variables
    int filas, columnas, i, j;
    int matriz[5][5];

    // Ingreso de cantidad de filas y columnas de la matriz
    cout << "Ingrese la cantidad de filas de la matriz:  ";
    cin >> filas;
    cout << "Ingrese la cantidad de columnas de la matriz:  ";
    cin >> columnas;

    // Carga de valores enteros en la matriz
    cout << "CARGA DE VALORES EN LA MATRIZ:" << endl;
    cout << "" << endl;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            cout << "Ingrese el elemento [" << i << "][" << j << "] :" << endl;
            cin >> matriz[i][j];
        }
    }
   // system("clear");

    // Muestra de los valores cargados en la matriz
    cout << "" << endl;
    cout << "LISTA DE LOS VALORES CARGADOS EN LA MATRIZ:" << endl;
    cout << "" << endl;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "  ";
        }
        cout << "\n" << endl;
    }

    return 0;
}
