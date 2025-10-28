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
int nueva_opcion;
string parada;
string linea;
string listaRutas[5] = {"A101", "A102", "T102", "X102", "X103"};


//FUNCIONES
void bienvenida() { //FUNCION DE BIENVENIDA Y PARA INICIAR LA APLICACION
    cout << "=====================================\n";
    cout << "       Bienvenido a EscalApp\n";
    cout << "=====================================\n\n";
}

void barraCarga() { //FUNCION DE ANIMACION DE CARGA
    cout << "\nIniciando aplicacion";
    for (int i = 0; i < 5; i++) {
        cout << ".";
        Sleep(400);
    }
    cout << "\nAplicacion iniciada!\n" << endl;
}

void seleccionarRuta() { // función para seleccionar la ruta que el usuario tomará
        cout << "===== Que ruta tomaras hoy? =====" << endl << endl;

        for (int i = 0; i < 5; i++) {
            cout << i + 1 << ". " << listaRutas[i] << endl;
        }
        cout << "\nSelecciona una opcion (1-5): ";
        cin >> opcion;
        
        if (opcion >= 1 and opcion <= 5) {
            cout << "Has seleccionado la ruta: " << listaRutas[opcion - 1] << endl << endl;
        } else {
            cout << "Opcion invalida. Ingrese un valor entre 1 y 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            seleccionarRuta();
            
        }

    
}

void seleccionarSentido() { // función para seleccionar el sentido de la ruta, si es de ida o vuelta
    cout << "1. IDA\n" << "2. VUELTA\n" << "SELECCIONE EL SENTIDO: ";
    cin >> sentido;

    if (sentido < 1 || sentido > 2) {
        cout << "Opcion invalida. Por favor seleccione 1 o 2." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        seleccionarSentido();
    }
}

void seleccionarParada() { // función para saber en que parada se bajará el usuario
    cout << "Selecciona en que escalon te bajaras: ";
    cin >> parada;

}

bool verificarParadaEnArchivo(const string& archivo_ruta, const string& paradaBuscada) { // función para verificar si la parada que ingresó el usuario existe en el archivo de la ruta
    ifstream archivo(archivo_ruta);
    if (!archivo.is_open()) {
        cerr << "Error: no se pudo abrir el archivo " << archivo_ruta << endl;
        return false;
    }

    
    int numeroLinea = 0; // para saber en qué línea está la parada
    bool encontrada = false;

    while (getline(archivo, linea)) {
        numeroLinea++;

        // limpia espacios al inicio y final de la línea
        linea.erase(remove(linea.begin(), linea.end(), '\r'), linea.end());
        linea.erase(remove(linea.begin(), linea.end(), '\n'), linea.end());
        while (!linea.empty() && isspace(linea.front())) linea.erase(linea.begin());
        while (!linea.empty() && isspace(linea.back())) linea.pop_back();

        if (linea.empty()) continue; // esto es para ignorar las líneas vacías

        // para intentar comparar como número si es posible
        try {
            int valorArchivo = stoi(linea);
            int valorUsuario = stoi(paradaBuscada);

            if (valorArchivo == valorUsuario) {
                cout << "\n Parada seleccionada: " << linea << "\n" << endl;
                encontrada = true;
                break;
            }
        } catch (...) {
            // si no es número, comparamos como texto
            if (linea == paradaBuscada) {
                cout << "\n Parada seleccionada: " << linea << "\n" << endl;
                encontrada = true;
                break;
            }
        }
    }

    archivo.close();

    if (!encontrada) {
        return false;
    }

    return true;
}


void procesarRuta(const string& codigoRuta) { // función para procesar la ruta seleccionada, el sentido y mostrar las paradas
    seleccionarSentido();

    string direccion = (sentido == 1) ? "Ida" : "Vuelta";
    string archivo_ruta = "rutas/" + codigoRuta + "-" + direccion + ".txt";

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
        procesarRuta(codigoRuta);
    }
}

void nuevaOpcion() { // función en caso de que el usuario quiera reiniciar el proceso o salir de la app
    cout << "Que desea hacer?\n" << "1. Reiniciar el proceso.\n" << "2. Salir de EscalApp.\n";    
    cin >> nueva_opcion;    
}

void visualizarSolicitud() { // función para mostrar un resumen de la solicitud del usuario y pueda ver si está correcta
    cout << "===== VISUALIZACION DE SOLICITUD =====\n" << endl;
    cout << "Ruta seleccionada: " << listaRutas[opcion - 1] << endl;
    cout << "Sentido: " << ((sentido == 1) ? "IDA" : "VUELTA") << endl;
    cout << "Parada seleccionada: " << linea << endl;
}

void confirmarSolicitud() { // función para que el usuario confirme o cancele la solicitud
    char confirmacion;
    cout << "Ingrese 'C' para confirmar o 'N' para cancelar: ";
    cin >> confirmacion;

    switch (confirmacion) {
        case 'C':
        case 'c':
            cout << "\nSolicitud confirmada y enviada a tu conductor.\nGracias por usar EscalApp!\n" << endl;
            break;
        case 'N':
        case 'n':
            cout << "Solicitud cancelada." << endl;
            nuevaOpcion();
            switch (nueva_opcion) {
                case 1:
                    seleccionarRuta();
                    procesarRuta(listaRutas[opcion - 1]);
                    confirmarSolicitud();
                break;
                case 2:
                    cout << "Gracias por usar EscalApp. Hasta luego!" << endl;
                    break;
                default:
                cout << "Opcion invalida. Por favor, intente de nuevo." << endl;
                nuevaOpcion();
            }
            break;
        default:
            cout << "\nOpcion invalida. Por favor ingrese 'C' o 'N'.\n" << endl;
            confirmarSolicitud();
            break;
    }
}


#endif