#include "digrafo.h"
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    DigrafoDinamico miDigrafo("red.xml");
    miDigrafo.cargarConfiguracionXML();

    char opcion;
    cout << "      CREACION DINAMICA DE DIGRAFO     " << endl;

    do {
        Ruta nuevaRuta;

        cout << "\nIngrese Nodo Origen (A - F): ";
        cin >> nuevaRuta.n;
        nuevaRuta.n = toupper(nuevaRuta.n);

        cout << "Ingrese Nodo Destino (A - F): ";
        cin >> nuevaRuta.nf;
        nuevaRuta.nf = toupper(nuevaRuta.nf);

        cout << "Ingrese identificador de Arista (a - n): ";
        cin >> nuevaRuta.aC;

        cout << "Ingrese el Peso de la arista: ";
        cin >> nuevaRuta.p;

        miDigrafo.registrarRuta(nuevaRuta);

        cout << "\n¿Desea agregar otra conexion dirigida? (S/N): ";
        cin >> opcion;

    } while (opcion == 'S' || opcion == 's');

    cout << "  ESTRUCTURA FINAL DEL DIGRAFO " << endl;
    miDigrafo.mostrarDigrafo();

    cout << "   CAMINO MAS CORTO   " << endl;

    char nodoInicio, nodoFin;
    cout << "Punto de Partida (Nodo inicial): ";
    cin >> nodoInicio;
    nodoInicio = toupper(nodoInicio);

    cout << "Punto de Destino (Nodo final): ";
    cin >> nodoFin;
    nodoFin = toupper(nodoFin);

    miDigrafo.dijkstra(nodoInicio, nodoFin);

    return 0;
}
