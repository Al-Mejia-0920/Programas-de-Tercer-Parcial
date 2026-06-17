#ifndef DIGRAFO_H
#define DIGRAFO_H

#include <string>
#include <vector>

struct Ruta {
    char n;
    char nf;
    std::string aC;
    int p;
};

struct Arista {
    char destino;
    std::string nombreArista;
    int peso;
    Arista* siguiente;
};

struct Vertice {
    char id;
    Arista* listaAristas;
    Vertice* siguiente;
};

class DigrafoDinamico {
private:
    Vertice* cabeza;
    std::string nombreArchivo;
    std::vector<std::string> aristasValidas;

    Vertice* buscarVertice(char id);
    bool esAristaValida(std::string nombre);

    char extraerAtributoChar(std::string linea, std::string atributo);
    std::string extraerAtributoString(std::string linea, std::string atributo);

public:
    DigrafoDinamico(std::string archivo);
    ~DigrafoDinamico();

    void insertarVertice(char id);
    void registrarRuta(Ruta r);
    void mostrarDigrafo();
    void cargarConfiguracionXML();
    void dijkstra(char inicio, char fin);
};

#endif

