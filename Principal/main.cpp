#include <iostream>
#include <fstream>
#include "libreria.hpp"
using namespace std;

int main() {
  
  bienvenida();

  seleccionarRuta();

  Rutas ra102;
  

  if (opcion == 1) {
    cout << "Ruta A102:" << endl;
        for (int i = 0; i < 6; i++) {
    cout << " > Parada " << i + 1 << ": " << ra102.A102[i] << endl; 
  }
    }


  return 0;
}
