#include <iostream>

using namespace std;

// 3. Funciones separadas que reciben parámetros y devuelven el resultado con return
float sumar(float a, float b) {
    return a + b;
}

float restar(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    return a / b;
}

float calcularPotencia(float base, int exponente) {
    float resultado = 1.0f;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}

int main() {
    int opcion;
    float num1, num2;
    int exponente;

    // 1. do-while para mantener activo el menú hasta que se elija salir (opción 6)
    do {
        cout << "\n=====================================" << endl;
        cout << "          CALCULADORA BASICA         " << endl;
        cout << "=====================================" << endl;
        cout << "1. Sumar" << endl;
        cout << "2. Restar" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Calcular potencia" << endl;
        cout << "6. Salir" << endl;
        cout << "=====================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // 2. switch para seleccionar la operación
        switch (opcion) {
            case 1:
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                cout << "Ingrese el segundo numero: ";
                cin >> num2;
                cout << "Resultado: " << sumar(num1, num2) << endl;
                break;

            case 2:
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                cout << "Ingrese el segundo numero: ";
                cin >> num2;
                cout << "Resultado: " << restar(num1, num2) << endl;
                break;

            case 3:
                cout << "Ingrese el primer numero: ";
                cin >> num1;
                cout << "Ingrese el segundo numero: ";
                cin >> num2;
                cout << "Resultado: " << multiplicar(num1, num2) << endl;
                break;

            case 4:
                cout << "Ingrese el numerador: ";
                cin >> num1;
                cout << "Ingrese el denominador: ";
                cin >> num2;
                // 6. Evitar dividir entre cero
                if (num2 == 0) {
                    cout << "Error: No se puede dividir entre cero." << endl;
                } else {
                    cout << "Resultado: " << dividir(num1, num2) << endl;
                }
                break;

            case 5:
                cout << "Ingrese la base: ";
                cin >> num1;
                do {
                    cout << "Ingrese el exponente entero no negativo: ";
                    cin >> exponente;
                    if (exponente < 0) {
                        cout << "Error: El exponente debe ser mayor o igual a 0.\n";
                    }
                } while (exponente < 0);

                // 7. Cálculo de potencia mediante un ciclo (sin usar pow())
                cout << "Resultado: " << calcularPotencia(num1, exponente) << endl;
                break;

            case 6:
                cout << "Saliendo del programa. Hasta luego!" << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    } while (opcion != 6); // 8. Termina únicamente al seleccionar la opción 6

    return 0;
}
