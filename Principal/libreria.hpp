#ifndef LIBRERIA_HPP
#define LIBRERIA_HPP

#include <iostream>
#include <windows.h>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

//VARIABLES GLOBALES
int opcion;
int sentido;
string parada;
string listaRutas[5] = {"A101", "A102", "T102", "X102", "X103"};

void bienvenida() {
    cout << "=====================================\n";
    cout << "       Bienvenido a EscalApp\n";
    cout << "=====================================\n\n";
}

void barraCarga() {
    cout << "\nIniciando aplicacion";
    for (int i = 0; i < 5; i++) {
        cout << ".";
        Sleep(400);
    }
    cout << "\nAplicacion iniciada!\n" << endl;
}

void seleccionarRuta() {
    cout << "===== Que ruta tomaras hoy? =====" << endl << endl;

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << listaRutas[i] << endl;
    }
    cout << "\nSelecciona una opcion (1-5): ";
    cin >> opcion;

    cout << "Has seleccionado la ruta: " << listaRutas[opcion - 1] << endl << endl;
}

void seleccionarSentido() {
    cout << "1. IDA\n" << "2. VUELTA\n" << "SELECCIONE EL SENTIDO: ";
    cin >> sentido;
}

void seleccionarParada() {
    cout << "Selecciona en que escalon te bajaras: ";
    cin >> parada;

}

bool verificarParadaEnArchivo(const string& archivo_ruta, const string& paradaBuscada) {
    ifstream archivo(archivo_ruta);
    if (!archivo.is_open()) {
        cerr << "Error: no se pudo abrir el archivo " << archivo_ruta << endl;
        return false;
    }

    string linea;
    int numeroLinea = 0; // para saber en qué línea está la parada
    bool encontrada = false;

    while (getline(archivo, linea)) {
        numeroLinea++;

        // limpia espacios al inicio y final de la línea
        linea.erase(remove(linea.begin(), linea.end(), '\r'), linea.end());
        linea.erase(remove(linea.begin(), linea.end(), '\n'), linea.end());
        while (!linea.empty() && isspace(linea.front())) linea.erase(linea.begin());
        while (!linea.empty() && isspace(linea.back())) linea.pop_back();

        if (linea.empty()) continue; // ignora líneas vacías

        // intentamos comparar como número si es posible
        try {
            int valorArchivo = stoi(linea);
            int valorUsuario = stoi(paradaBuscada);

            if (valorArchivo == valorUsuario) {
                cout << "\n Parada seleccionada: " << linea << "\n" << endl;
                encontrada = true;
                break;
            }
        } catch (...) {
            // si no es número, comparamos texto
            if (linea == paradaBuscada) {
                cout << "\n Parada seleccionada: " << linea << "\n" << endl;
                encontrada = true;
                break;
            }
        }
    }

    archivo.close();

    if (!encontrada) {
        cout << "\n La parada '" << paradaBuscada << "' no se encontró en este archivo.\n";
        return false;
    }

    return true;
}


void procesarRuta(const string& codigoRuta) {
    seleccionarSentido();

    string direccion = (sentido == 1) ? "Ida" : "Vuelta";
    string archivo_ruta = "../Rutas/rutas/" + codigoRuta + "-" + direccion + ".txt";

    cout << "\nCargando paradas de la ruta " << codigoRuta << " (" << direccion << "):\n\n";

    ifstream archivo(archivo_ruta);
    if (!archivo.is_open()) {
        cerr << "Error: no se pudo abrir el archivo " << archivo_ruta << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();

    seleccionarParada();

    if (!verificarParadaEnArchivo(archivo_ruta, parada)) {
        cout << "\n La parada '" << parada << "' no existe en esta ruta.\n";
    }
}

void confirmarSolicitud() {
    char confirmacion;
    cout << "===== CONFIRMACION DE SOLICITUD =====\n" << endl;
    cout << "Ruta seleccionada: " << listaRutas[opcion - 1] << endl;
    cout << "Sentido: " << ((sentido == 1) ? "IDA" : "VUELTA") << endl;
    cout << "Parada seleccionada: " << parada << endl;
    cout << "Ingrese 'C' para confirmar o 'N' para cancelar: ";
    cin >> confirmacion;

    switch (confirmacion) {
        case 'C':
        case 'c':
            cout << "Solicitud confirmada y enviada a tu conductor. Gracias por usar EscalApp!" << endl;
            break;
        case 'N':
        case 'n':
            cout << "Solicitud cancelada. Puede reiniciar el proceso si lo desea." << endl;
            break;
        default:
            cout << "Opcion invalida. Por favor ingrese 'C' o 'N'." << endl;
            break;
    }
}

#endif