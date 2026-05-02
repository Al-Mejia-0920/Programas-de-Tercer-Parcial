#include "concreta.h"
#include <iostream>

using namespace std;

int main() {
   Lista L;
   int op, num, cantidad;

   do {
      cout << "\n--- MENU ORDENAMIENTO INDIRECTO ---\n";
      cout << "1. Ingresar numeros\n";
      cout << "2. Ordenar \n";
      cout << "3. Mostrar \n";
      cout << "4. Salir\n";
      cout << "Seleccione una opcion :";
      cin >> op;
      switch (op) {
      case 1:
        cout << "Cuantos numeros quieres ingresar : ";
        cin >> cantidad;
          for(int z = 0; z < cantidad ; z++) {
              cout << "Ingrese el valor " << z + 1 << " : ";
              cin >> num;
              L.agregar(num);
          }
        break;

      case 2:
        L.ordenar();
        break;

      case 3:
        L.mostrar();
        break;

      case 4:
        cout << "Saliendo del programa....";
        break;

      default:
        cout << "Opcion no valida";
        break;
      }
   } while (op != 4);

    return 0;
}