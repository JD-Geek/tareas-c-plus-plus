#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombreDispositivo;
    float potencia, horasDiarias, dias, precioKwh;
    float consumoKwh, costoTotal;

    cout << "=== SISTEMA DE CALCULO DE CONSUMO ELECTRICO ===" << endl;
    cout << "Ingrese el nombre del dispositivo: ";
    cin >> nombreDispositivo;

    // Validación de valores positivos
    do {
        cout << "Ingrese la potencia en watts (W) (> 0): ";
        cin >> potencia;
        if (potencia <= 0) cout << "Error: Debe ser un valor positivo.\n";
    } while (potencia <= 0);

    do {
        cout << "Ingrese las horas de uso diario (0 a 24): ";
        cin >> horasDiarias;
        if (horasDiarias <= 0 || horasDiarias > 24) cout << "Error: Rango invalido.\n";
    } while (horasDiarias <= 0 || horasDiarias > 24);

    do {
        cout << "Ingrese la cantidad de dias utilizados (> 0): ";
        cin >> dias;
        if (dias <= 0) cout << "Error: Debe ser un valor positivo.\n";
    } while (dias <= 0);

    do {
        cout << "Ingrese el costo de cada kWh en colones (> 0): ";
        cin >> precioKwh;
        if (precioKwh <= 0) cout << "Error: Debe ser un valor positivo.\n";
    } while (precioKwh <= 0);

    // Cálculos según la fórmula del examen
    consumoKwh = (potencia * horasDiarias * dias) / 1000.0f;
    costoTotal = consumoKwh * precioKwh;

    // Presentación y clasificación
    cout << "\n--- RESUMEN DE CONSUMO ---" << endl;
    cout << "Dispositivo: " << nombreDispositivo << endl;
    cout << "Consumo total: " << consumoKwh << " kWh" << endl;
    cout << "Costo total: " << costoTotal << " colones" << endl;
    cout << "Clasificacion: ";

    if (consumoKwh < 10.0f) {
        cout << "Bajo" << endl;
    } else if (consumoKwh >= 10.0f && consumoKwh < 50.0f) {
        cout << "Moderado" << endl;
    } else {
        cout << "Alto" << endl;
    }

    return 0;
}
