#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Espera en segundos (simulacion)
void esperar(int segundos) {
    cout << "Esperando " << segundos << " segundos...\n";
    this_thread::sleep_for(chrono::seconds(segundos));
}

// Acciones de la lavadora
void luz(string estado) {
    cout << "Luz: " << estado << endl;
}

void bomba(string direccion) {
    cout << "Bomba: " << direccion << endl;
}

void girar() {
    cout << "Girando tambor...\n";
}

// Ciclo de lavado
void lavar(string plan) {
    cout << "\nEncendiendo lavadora... Estado: IDLE\n";

    // Validar plan
    if (plan != "regular" && plan != "delicate" && plan != "super") {
        cout << "Plan no valido. Usa: regular, delicate o super\n";
        return;
    }

    // SOAK
    cout << "\nEstado: SOAK (Remojo)\n";
    luz("Remojando");
    bomba("Entrada de agua");
    esperar(3);  // Simula 30 segundos

    // RINSE
    cout << "\nEstado: RINSE (Enjuague)\n";
    luz("Enjuague");
    girar();
    esperar(3);  // Simula 30 minutos

    // DRAIN
    cout << "\nEstado: DRAIN (Drenar)\n";
    luz("Drenaje");
    bomba("Salida de agua");
    esperar(2);  // Simula 5 minutos

    // SUPER: espera antes de secar
    if (plan == "super") {
        cout << "\n(SUPER DELICATE) Esperando antes de secar...\n";
        luz("Apagada");
        esperar(2);  // Simula 5 minutos
    }

    // DRY
    if (plan != "super") {
        cout << "\nEstado: DRY (Secado)\n";
        luz("Secado");
        girar();
        esperar(3);  // Simula 20 minutos
    }

    cout << "\nCiclo completado. Estado final: IDLE\n";
}

int main() {
    string plan;
    char continuar;

    do {
        cout << "\nSimulador de Lavadora\n";
        cout << "Planes disponibles: regular / delicate / super\n";
        cout << "Selecciona un plan: ";
        cin >> plan;

        lavar(plan);

        cout << "\nDeseas lavar otra vez? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "\nPrograma terminado. Hasta luego.\n";
    return 0;
}