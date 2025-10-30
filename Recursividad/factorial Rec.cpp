#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) {
        cout << "factorial(" << n << ") = 1  ← (caso base)" << endl;
        return 1;
    } else {
        cout << "factorial(" << n << ") = " << n << " * factorial(" << n - 1 << ")" << endl;
        return n * factorial(n - 1);
    }
}

int main() {
    int numero;
    cout << "Ingrese un número: ";
    cin >> numero;

    if (numero < 0) {
        cout << "El factorial no está definido para números negativos." << endl;
    } else {
        int resultado = factorial(numero);
        cout << "Resultado final: " << resultado << endl;
    }

    return 0;
}
