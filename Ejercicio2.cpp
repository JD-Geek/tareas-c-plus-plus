#include <iostream>

using namespace std;

int main() {
    int cantidadMediciones;

    // Validación de cantidad de mediciones entre 3 y 20
    do {
        cout << "Ingrese la cantidad de mediciones (entre 3 y 20): ";
        cin >> cantidadMediciones;
        if (cantidadMediciones < 3 || cantidadMediciones > 20) {
            cout << "Error: La cantidad debe estar entre 3 y 20.\n";
        }
    } while (cantidadMediciones < 3 || cantidadMediciones > 20);

    float sumaTemp = 0;
    float tempMayor = -9999.0f;
    float tempMenor = 9999.0f;
    int mayoresA35 = 0;
    bool alertaCritica = false;

    for (int i = 1; i <= cantidadMediciones; i++) {
        float temp;
        cout << "Temperatura " << i << ": ";
        cin >> temp;

        sumaTemp += temp;

        if (temp > tempMayor) tempMayor = temp;
        if (temp < tempMenor) tempMenor = temp;
        if (temp > 35.0f) mayoresA35++;
        if (temp > 50.0f) alertaCritica = true;
    }

    float promedio = sumaTemp / cantidadMediciones;

    cout << "\n--- RESULTADOS DE TEMPERATURA ---" << endl;
    cout << "Promedio: " << promedio << " C" << endl;
    cout << "Mayor: " << tempMayor << " C" << endl;
    cout << "Menor: " << tempMenor << " C" << endl;
    cout << "Temperaturas mayores a 35 C: " << mayoresA35 << endl;

    if (alertaCritica) {
        cout << "ADVERTENCIA: Temperatura critica detectada (> 50 C)." << endl;
    }

    return 0;
}
