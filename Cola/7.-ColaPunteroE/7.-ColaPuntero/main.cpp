#include "abstracta.h"

int main() {
    ColaPunteros miCola;
    int opc, id;
    string nombre;

    do {
        cout << "\n    Opciones" << endl;
        cout << "1. Registrar Alumno" << endl;
        cout << "2. Atender Alumno" << endl;
        cout << "3. Ver Fila" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
                miCola.registrar(id, nombre);
                break;
            case 2:
                miCola.atender();
                break;
            case 3:
                miCola.mostrar();
                break;
        }
    } while (opc != 4);

    return 0;
}
