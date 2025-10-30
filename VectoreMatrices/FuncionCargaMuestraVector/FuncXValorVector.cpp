//carga y muestra de un vector usando funciones con pasaje de parámetros por valor

#include <iostream>
using namespace std;

// Prototipos de funciones
void cargaVector(int vector[], int nroelementos);
void muestraVector(int vector[], int nroelementos);

int main(){
    // Declaracion de variables
    int nroelementos;
    int vector[10];

    // Ingreso de cantidad de elementos del vector
    cout << "Ingrese la cantidad de elementos del vector:  ";
    cin >> nroelementos;

    // Llamado a la funcion para cargar el vector   
    cargaVector(vector, nroelementos);
    system("clear");
    
    // Llamado a la funcion para mostrar el vector
    muestraVector(vector, nroelementos);

    return 0;
}

// Definicion de la funcion para cargar el vector
void cargaVector(int vector[], int nroelementos){
    cout << "CARGA DE VALORES EN EL VECTOR:" << endl;
    cout << "" << endl;
    for (int i = 0; i < nroelementos; i++) {
        cout << "Ingrese el elemento " << i << ":" << endl;
        cin >> vector[i];
    }
}       

// Definicion de la funcion para mostrar el vector
void muestraVector(int vector[], int nroelementos){
    cout << "" << endl;
    cout << "LISTA DE LOS VALORES CARGADOS EN EL VECTOR:" << endl;
    cout << "" << endl;
    for (int i = 0; i < nroelementos; i++) {
        cout << "Vector[" << i << "] = " << vector[i] << endl;
    }
    cout << "" << endl;
}   