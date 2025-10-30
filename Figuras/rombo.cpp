#include <iostream>
using namespace std;

void drawDiamond(int n) {
    // Si el usuario pasa un n par, lo ajustamos al siguiente impar
    if (n % 2 == 0) {
        n++;
    }

    int mid = n / 2; // índice de la fila central (0-based)

    for (int i = 0; i < n; ++i) {
        int stars;
        if (i <= mid) {
            // filas desde la punta superior hasta la central
            stars = 2 * i + 1;
        } else {
            // filas desde la central hacia la punta inferior
            stars = 2 * (n - 1 - i) + 1;
        }
        int spaces = (n - stars) / 2;

        // imprimir espacios
        for (int s = 0; s < spaces; ++s) cout << ' ';
        // imprimir asteriscos
        for (int a = 0; a < stars; ++a) cout << '*';
        cout << '\n';
    }
}

int main() {
    int n;
    cout << "Ingrese la altura del rombo (se ajusta a impar si ingresa un número par): ";
    cin >> n;

    if (n <= 0) {
        cout << "Ingrese un número mayor que 0.\n";
        return 1;
    }

    drawDiamond(n);
    return 0;
}
