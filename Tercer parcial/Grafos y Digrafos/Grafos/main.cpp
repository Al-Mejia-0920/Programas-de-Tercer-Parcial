#include "grafo.h"
#include <iostream>
#include <cctype>

using namespace std;

int main() {
    GrafoDinamico miMapa("red.xml");
    miMapa.cargarConfiguracionXML();

    char opcion;
    cout <<    "RUTAS"    << endl;

    do {
        Ruta nuevaRuta;

        cout << "\nIngrese el Nodo de Origen (Ej. A-F): ";
        cin >> nuevaRuta.n;
        nuevaRuta.n = toupper(nuevaRuta.n);

        cout << "Ingrese el Nodo de Destino (Ej. A-F): ";
        cin >> nuevaRuta.nf;
        nuevaRuta.nf = toupper(nuevaRuta.nf);

        cout << "Ingrese el nombre de la Arista (Ej. a-n): ";
        cin >> nuevaRuta.aC;

        cout << "Ingrese el Peso/Costo de esta conexion: ";
        cin >> nuevaRuta.p;

        miMapa.registrarRuta(nuevaRuta);

        cout << "\n¿Desea registrar otra ruta? (S/N): ";
        cin >> opcion;

    } while (opcion == 'S' || opcion == 's');

    cout << "      MAPA DEL GRAFO " << endl;
    miMapa.mostrarGrafo();

    cout << "    CAMINO MAS CORTO   " << endl;

    char nodoInicio, nodoFin;
    cout << "Ingrese desde que Nodo desea partir: ";
    cin >> nodoInicio;
    nodoInicio = toupper(nodoInicio);

    cout << "Ingrese hacia que Nodo desea llegar: ";
    cin >> nodoFin;
    nodoFin = toupper(nodoFin);

    miMapa.dijkstra(nodoInicio, nodoFin);

    return 0;
}
