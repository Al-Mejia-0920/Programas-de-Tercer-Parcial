#include "abstracta.h"

int main() {
    int tamMax;
    cout << "Indique el tamaño maximo de la cola: ";
    cin >> tamMax;

    ColaPunteros miCola(tamMax);
    int opc, id;
    string nombre;

    do {
        cout << "\n1. Registrar  2. Atender  3. Ver  4. Salir" << endl;
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
