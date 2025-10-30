#include <iostream>
using namespace std;

int Potencia(int base, int exponente) {
    if (exponente == 0) {
        cout << "Potencia(" << base << ", " << exponente << ") -> 1  ← (caso base)" << endl;
        return 1;
    } else {
        cout << "Potencia(" << base << ", " << exponente << ") -> "
             << base << " * Potencia(" << base << ", " << (exponente - 1) << ")" << endl;
        return base * Potencia(base, exponente - 1);
    }
}

int main() {
    int base = 2, exponente = 4;
    cout << "Resultado final: " << Potencia(base, exponente) << endl;
    return 0;
}
