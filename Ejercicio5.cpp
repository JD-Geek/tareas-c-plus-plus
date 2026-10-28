#include <iostream>

using namespace std;

// Función para clasificar y mostrar el estado de una temperatura
void clasificarTemperatura(float temp) {
    if (temp < 30.0f) {
        cout << "Clasificacion: Normal" << endl;
    } else if (temp >= 30.0f && temp <= 45.0f) {
        cout << "Clasificacion: Advertencia" << endl;
    } else {
        cout << "Clasificacion: Critico" << endl;
    }
}

// Función 1: Registrar temperatura y actualizar estadísticas mediante referencias (&)
void registrarTemperatura(int &cantidad, float &suma, float &maxima, float &minima, float &ultima) {
    cout << "Ingrese la temperatura a registrar (C): ";
    cin >> ultima;

    if (cantidad == 0) {
        maxima = ultima;
        minima = ultima;
    } else {
        if (ultima > maxima) maxima = ultima;
        if (ultima < minima) minima = ultima;
    }

    suma += ultima;
    cantidad++;

    cout << "¡Temperatura registrada con exito!" << endl;
    clasificarTemperatura(ultima);
}

// Función 2: Mostrar estadísticas acumuladas
void mostrarEstadisticas(int cantidad, float suma, float maxima, float minima) {
    if (cantidad == 0) {
        cout << "Error: No se han registrado mediciones aun." << endl;
        return;
    }

    float promedio = suma / cantidad;
    cout << "\n--- ESTADISTICAS DEL DISPOSITIVO ---" << endl;
    cout << "Total de mediciones: " << cantidad << endl;
    cout << "Temperatura maxima: " << maxima << " C" << endl;
    cout << "Temperatura minima: " << minima << " C" << endl;
    cout << "Temperatura promedio: " << promedio << " C" << endl;
}

// Función 3: Reiniciar todas las estadísticas a cero
void reiniciarMediciones(int &cantidad, float &suma, float &maxima, float &minima, float &ultima) {
    cantidad = 0;
    suma = 0.0f;
    maxima = 0.0f;
    minima = 0.0f;
    ultima = 0.0f;
    cout << "Todas las estadisticas han sido reiniciadas." << endl;
}

int main() {
    int opcion;
    // Variables locales solicitadas por las restricciones
    int cantidad = 0;
    float suma = 0.0f;
    float maxima = 0.0f;
    float minima = 0.0f;
    float ultima = 0.0f;

    // Bucle do-while para mantener activo el menú principal
    do {
        cout << "\n=====================================" << endl;
        cout << "         SISTEMA DE MONITOREO        " << endl;
        cout << "=====================================" << endl;
        cout << "1. Registrar temperatura" << endl;
        cout << "2. Consultar estado" << endl;
        cout << "3. Mostrar estadisticas" << endl;
        cout << "4. Reiniciar mediciones" << endl;
        cout << "5. Salir" << endl;
        cout << "=====================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarTemperatura(cantidad, suma, maxima, minima, ultima);
                break;

            case 2:
                if (cantidad == 0) {
                    cout << "Error: No hay registros previos de temperatura." << endl;
                } else {
                    cout << "\n--- ESTADO ACTUAL ---" << endl;
                    cout << "Ultima temperatura registrada: " << ultima << " C" << endl;
                    clasificarTemperatura(ultima);
                }
                break;

            case 3:
                mostrarEstadisticas(cantidad, suma, maxima, minima);
                break;

            case 4:
                reiniciarMediciones(cantidad, suma, maxima, minima, ultima);
                break;

            case 5:
                cout << "Saliendo del sistema de monitoreo. ¡Hasta luego!" << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    } while (opcion != 5);

    return 0;
}
