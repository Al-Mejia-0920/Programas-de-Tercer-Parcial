#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>

// Tipo de dato solicitado para registrar conexiones en el programa
struct Ruta {
    char n;             // Nodo inicial
    char nf;            // Nodo final
    std::string aC;     // Arista escogida
    int p;              // Peso
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

class GrafoDinamico {
private:
    Vertice* cabeza;
    std::string nombreArchivo;
    std::vector<std::string> aristasValidas; // Almacena el pool 'a'-'n' del XML

    Vertice* buscarVertice(char id);
    bool esAristaValida(std::string nombre);

    // Auxiliares para procesar las etiquetas del XML
    char extraerAtributoChar(std::string linea, std::string atributo);
    std::string extraerAtributoString(std::string linea, std::string atributo);

public:
    GrafoDinamico(std::string archivo);
    ~GrafoDinamico();

    void insertarVertice(char id);
    void registrarRuta(Ruta r); // Aquí es donde tú conectas los nodos en el programa
    void mostrarGrafo();
    void cargarConfiguracionXML(); // Carga el catálogo maestro
    void dijkstra(char inicio, char fin);
};

#endif
