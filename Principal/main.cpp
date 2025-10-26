#include <iostream>
#include <fstream>
#include "libreria.hpp"
#include <string>
using namespace std;

int main() {
  
  bienvenida();

  seleccionarRuta();

  Rutas ra102;
  


  

  switch (opcion) {
    case 1:
        cout << "RUTA A101" << endl;
        seleccionarSentido();

        if (sentido == 1) {
          cout << endl;
          ifstream a101_ida("../Rutas/rutas/A101-Ida.txt");
          string linea;
          while (getline(a101_ida, linea)) {
            cout << linea << endl;
          } a101_ida.close();
          
        }
        if (sentido == 2) {
          cout << endl;
          ifstream a101_vuelta("../Rutas/rutas/A101-vuelta.txt");
          string linea;
          while (getline(a101_vuelta, linea)) {
            cout << linea << endl;
          } a101_vuelta.close();
        }
    case 2:
        cout << "RUTA A102" << endl;
        seleccionarSentido();

        if (sentido == 1) {
          cout << endl;
          ifstream a102_ida("../Rutas/rutas/A102-Ida.txt");
          string linea;
          while (getline(a102_ida, linea)) {
            cout << linea << endl;
          } a102_ida.close();
        }
        if (sentido == 2) {
          cout << endl;
          ifstream a102_vuelta("../Rutas/rutas/A102-vuelta.txt");
          string linea;
          while (getline(a102_vuelta, linea)) {
            cout << linea << endl;
          } a102_vuelta.close();
        }
    case 3:
        cout << "RUTA T102" << endl;
        seleccionarSentido();

        if (sentido == 1) {
          cout << endl;
          ifstream t102_ida("../Rutas/rutas/T102-Ida.txt");
          string linea;
          while (getline(t102_ida, linea)) {
            cout << linea << endl;
          } t102_ida.close();
        }
        if (sentido == 2) {
          cout << endl;
          ifstream t102_vuelta("../Rutas/rutas/T102-vuelta.txt");
          string linea;
          while (getline(t102_vuelta, linea)) {
            cout << linea << endl;
          } t102_vuelta.close();
        }
    case 4:
        cout << "RUTA X102" << endl;
        seleccionarSentido();

        if (sentido == 1) {
          cout << endl;
          ifstream x102_ida("../Rutas/rutas/X102-Ida.txt");
          string linea;
          while (getline(x102_ida, linea)) {
            cout << linea << endl;
          } x102_ida.close();
        }
        if (sentido == 2) {
          cout << endl;
          ifstream x102_vuelta("../Rutas/rutas/X102-vuelta.txt");
          string linea;
          while (getline(x102_vuelta, linea)) {
            cout << linea << endl;
          } x102_vuelta.close();
        }
    case 5: 
        cout << "RUTA X103" << endl;
        seleccionarSentido();

        if (sentido == 1) {
          cout << endl;
          ifstream x103_ida("../Rutas/rutas/X103-Ida.txt");
          string linea;
          while (getline(x103_ida, linea)) {
            cout << linea << endl;
          } x103_ida.close();
        }
        if (sentido == 2) {
          cout << endl;
          ifstream x103_vuelta("../Rutas/rutas/X103-vuelta.txt");
          string linea;
          while (getline(x103_vuelta, linea)) {
            cout << linea << endl;
          } x103_vuelta.close();
        }
    }


  return 0;
}
