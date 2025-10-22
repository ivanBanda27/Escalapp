#ifndef LIBRERIA_HPP
#define LIBRERIA_HPP

#include <iostream>
using namespace std;

string listaRutas[6] = {"A102", "A105", "T102", "T100E", "X102", "X103"};

struct Rutas {
    string A102[6] = {"Colegio Castillo", "U.San Buenaventura", "C.C. San Fernando", "Entrada Simon Bolivar", "Tenaris", "UTB"};
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
int opcion;

void seleccionarRuta() {
    cout << "===== Que ruta tomaras hoy? =====" << endl << endl;

    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ". " << listaRutas[i] << endl;
    }
    cout << "\nSelecciona una opcion (1-6): ";
    cin >> opcion;

    if (opcion < 1 or opcion > 6) {
        cout << "Opcion invalida. Por favor, selecciona una opcion entre 1 y 6." << endl;
    } 
    else {
        cout << "Has seleccionado la ruta: " << listaRutas[opcion - 1] << endl << endl;
    }
}

#endif