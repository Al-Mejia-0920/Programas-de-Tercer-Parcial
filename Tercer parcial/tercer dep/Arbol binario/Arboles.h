#ifndef ARBOLES_H
#define ARBOLES_H

#include <string>

struct NodoArbol {
    int dato;
    NodoArbol* izq;
    NodoArbol* der;

    NodoArbol(int valor);
};

class ArbolBinario {
private:
    NodoArbol* raiz;

    NodoArbol* insertarNodo(NodoArbol* nodo, int dato);
    void preordenRecursivo(NodoArbol* nodo);
    void inordenRecursivo(NodoArbol* nodo);
    void postordenRecursivo(NodoArbol* nodo);
    void mostrarEstructuraRecursivo(NodoArbol* nodo, int espacio);


public:
    ArbolBinario();
    void insertar(int dato);
    void preorden();
    void inorden();
    void postorden();
    void cargarXML(const std::string& nombreArchivo);
    void cargarJSON(const std::string& nombreArchivo);

    void mostrarEstructura();
};

#endif