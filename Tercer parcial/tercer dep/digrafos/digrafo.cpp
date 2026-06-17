#include "digrafo.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

DigrafoDinamico::DigrafoDinamico(string archivo) {
    cabeza = nullptr;
    nombreArchivo = archivo;
}

DigrafoDinamico::~DigrafoDinamico() {
    Vertice* actV = cabeza;
    while (actV != nullptr) {
        Arista* actA = actV->listaAristas;
        while (actA != nullptr) {
            Arista* auxA = actA;
            actA = actA->siguiente;
            delete auxA;
        }
        Vertice* auxV = actV;
        actV = actV->siguiente;
        delete auxV;
    }
}

Vertice* DigrafoDinamico::buscarVertice(char id) {
    Vertice* aux = cabeza;
    while (aux != nullptr) {
        if (aux->id == id) return aux;
        aux = aux->siguiente;
    }
    return nullptr;
}

bool DigrafoDinamico::esAristaValida(string nombre) {
    for (size_t i = 0; i < aristasValidas.size(); i++) {
        if (aristasValidas[i] == nombre) return true;
    }
    return false;
}

void DigrafoDinamico::insertarVertice(char id) {
    if (buscarVertice(id) != nullptr) return;
    Vertice* nuevo = new Vertice{id, nullptr, cabeza};
    cabeza = nuevo;
}

void DigrafoDinamico::cargarConfiguracionXML() {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "[!] Error: No se pudo abrir el archivo XML." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (linea.find("<nodo") != string::npos) {
            char id = extraerAtributoChar(linea, "id");
            if (id != ' ') insertarVertice(id);
        }
        else if (linea.find("<arista") != string::npos) {
            string idArista = extraerAtributoString(linea, "id");
            if (!idArista.empty()) aristasValidas.push_back(idArista);
        }
    }
    archivo.close();
    cout << "[OK] Catalogos maestros leidos desde el XML con exito." << endl;
}

void DigrafoDinamico::registrarRuta(Ruta r) {
    Vertice* vOrigen = buscarVertice(r.n);
    Vertice* vDestino = buscarVertice(r.nf);

    if (vOrigen == nullptr || vDestino == nullptr) {
        cout << "[!] Error: El nodo origen o destino no existen en el catálogo XML." << endl;
        return;
    }
    if (!esAristaValida(r.aC)) {
        cout << "[!] Error: La arista '" << r.aC << "' no esta permitida por el XML." << endl;
        return;
    }

    Arista* nueva = new Arista{r.nf, r.aC, r.p, vOrigen->listaAristas};
    vOrigen->listaAristas = nueva;
}

void DigrafoDinamico::mostrarDigrafo() {
    Vertice* actV = cabeza;
    while (actV != nullptr) {
        cout << "Nodo [" << actV->id << "] apunta a: ";
        Arista* actA = actV->listaAristas;
        while (actA != nullptr) {
            cout << "--(" << actA->nombreArista << ", p:" << actA->peso << ")--> [" << actA->destino << "] | ";
            actA = actA->siguiente;
        }
        cout << "NULL" << endl;
        actV = actV->siguiente;
    }
}

char DigrafoDinamico::extraerAtributoChar(string linea, string atributo) {
    string token = atributo + "=\"";
    size_t pos = linea.find(token);
    if (pos != string::npos) return linea[pos + token.length()];
    return ' ';
}

string DigrafoDinamico::extraerAtributoString(string linea, string atributo) {
    string token = atributo + "=\"";
    size_t pos = linea.find(token);
    if (pos != string::npos) {
        size_t inicio = pos + token.length();
        size_t fin = linea.find("\"", inicio);
        return linea.substr(inicio, fin - inicio);
    }
    return "";
}

void DigrafoDinamico::dijkstra(char inicio, char fin) {
    int dist[26];
    char previo[26];
    bool visitado[26];
    string aristaPrevio[26];

    for (int i = 0; i < 26; i++) {
        dist[i] = 999999;
        previo[i] = ' ';
        visitado[i] = false;
    }

    dist[inicio - 'A'] = 0;

    for (int count = 0; count < 26; count++) {
        int min = 999999, u = -1;
        for (int i = 0; i < 26; i++) {
            if (!visitado[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1 || (u + 'A') == fin) break;

        visitado[u] = true;
        char nodoU = u + 'A';
        Vertice* vU = buscarVertice(nodoU);

        if (vU != nullptr) {
            Arista* act = vU->listaAristas;
            while (act != nullptr) {
                int v = act->destino - 'A';
                if (!visitado[v] && dist[u] != 999999 && dist[u] + act->peso < dist[v]) {
                    dist[v] = dist[u] + act->peso;
                    previo[v] = nodoU;
                    aristaPrevio[v] = act->nombreArista;
                }
                act = act->siguiente;
            }
        }
    }

    if (dist[fin - 'A'] == 999999) {
        cout << "\nNo existe ninguna ruta dirigida transitable desde " << inicio << " hasta " << fin << "." << endl;
        return;
    }

    cout << "\n[Dijkstra Unidireccional] Ruta mas corta desde " << inicio << " hasta " << fin << " | Peso Total: " << dist[fin - 'A'] << endl;
    vector<string> camino;
    char actual = fin;
    while (actual != inicio) {
        char p = previo[actual - 'A'];
        string ar = aristaPrevio[actual - 'A'];
        camino.insert(camino.begin(), string(1, p) + " --(" + ar + ")--> " + string(1, actual));
        actual = p;
    }
    for (size_t i = 0; i < camino.size(); i++) cout << camino[i] << endl;
}
