#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <limits>
#include "libreria.hpp"
#include <string>
using namespace std;

int main() {
  
    char tecla;

    bienvenida();
    cout << "Presione la tecla 's' para iniciar..." << endl;

    do {
      tecla = getch();
    } while (tecla != 'S' && tecla != 's');

    barraCarga();

      
    seleccionarRuta();
    

      switch (opcion) {
        case 1:
            cout << "RUTA A101" << endl;
            procesarRuta("A101");
            break;
        case 2:
            cout << "RUTA A102" << endl;
            procesarRuta("A102");
            break;
        case 3:
            cout << "RUTA T102" << endl;
            procesarRuta("T102");
            break;
        case 4:
            cout << "RUTA X102" << endl;
            procesarRuta("X102");
            break;
        case 5: 
            cout << "RUTA X103" << endl;
            procesarRuta("X103");
            break;
        default:
          cout << "Opcion invalida. Ingrese un valor entre 1 y 5.\n";
          seleccionarRuta();
          break;
        }

  
    visualizarSolicitud();
    confirmarSolicitud();
  
  cout << "holaaa";


  

    return 0;
}
