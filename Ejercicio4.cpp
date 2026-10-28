#include <iostream>

using namespace std;

// 1, 2, 3, 4, 7. Función recursiva (sin ciclos adentro)
int sumaRecursiva(int n) {
    // 3. Caso base: cuando llega a 1, devuelve 1
    if (n <= 1) {
        return 1;
    }
    // 4. Caso recursivo: suma el número actual y llama a la función con n - 1
    return n + sumaRecursiva(n - 1);
}

int main() {
    int numero;

    // 6. Validar que el número ingresado esté estrictamente entre 1 y 100
    do {
        cout << "Ingrese un numero (entre 1 y 100): ";
        cin >> numero;
        if (numero < 1 || numero > 100) {
            cout << "Error: El numero debe estar entre 1 y 100.\n";
        }
    } while (numero < 1 || numero > 100);

    // Presentación visual de la suma (imitando el ejemplo del profesor)
    cout << "\nSuma:" << endl;
    for (int i = numero; i >= 1; i--) {
        cout << i;
        if (i > 1) {
            cout << " + ";
        }
    }

    // 5. Mostrar el resultado llamando a la función recursiva desde main()
    int resultado = sumaRecursiva(numero);
    cout << " = " << resultado << endl;

    return 0;
}
