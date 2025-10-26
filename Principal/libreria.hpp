#ifndef LIBRERIA_HPP
#define LIBRERIA_HPP

#include <iostream>
using namespace std;

//VARIABLES GLOBALES
int opcion;
int sentido;
string listaRutas[5] = {"A101", "A102", "T102", "X102", "X103"};

struct Rutas {
    string A102[11];
    string X102[6];
    string T102[6];
    string T100E[6];
    string A105[6];
    string X103[6];
};

void bienvenida() {
    cout << "=====================================\n";
    cout << "       Bienvenido a EscalApp\n";
    cout << "=====================================\n\n";
}

void seleccionarRuta() {
    cout << "===== Que ruta tomaras hoy? =====" << endl << endl;

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << listaRutas[i] << endl;
    }
    cout << "\nSelecciona una opcion (1-5): ";
    cin >> opcion;

    if (opcion < 1 or opcion > 5) {
        cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 5." << endl;
    } 
    else {
        cout << "Has seleccionado la ruta: " << listaRutas[opcion - 1] << endl << endl;
    }
}

void seleccionarSentido() {
    cout << "1. IDA\n" << "2. VUELTA\n" << "SELECCIONE EL SENTIDO: ";
    cin >> sentido;
}

#endif