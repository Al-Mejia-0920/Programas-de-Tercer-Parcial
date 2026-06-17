#include "Arboles.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

NodoArbol::NodoArbol(int valor) {
    dato = valor;
    izq = nullptr;
    der = nullptr;
}

ArbolBinario::ArbolBinario() {
    raiz = nullptr;
}

NodoArbol* ArbolBinario::insertarNodo(NodoArbol* nodo, int dato) {
    if (nodo == nullptr) {
        return new NodoArbol(dato);
    }
    if (dato < nodo->dato) {
        nodo->izq = insertarNodo(nodo->izq, dato);
    } else if (dato > nodo->dato) {
        nodo->der = insertarNodo(nodo->der, dato);
    }
    return nodo;
}

void ArbolBinario::insertar(int dato) {
    raiz = insertarNodo(raiz, dato);
}

void ArbolBinario::mostrarEstructuraRecursivo(NodoArbol* nodo, int espacio) {
    if (nodo == nullptr) {
        return;
    }

    espacio += 5;

    mostrarEstructuraRecursivo(nodo->der, espacio);

    std::cout << '\n';
    for (int i = 5; i < espacio; i++) {
        std::cout << " ";
    }
    std::cout << nodo->dato << "\n";

    mostrarEstructuraRecursivo(nodo->izq, espacio);
}

void ArbolBinario::mostrarEstructura() {
    std::cout << "\n-- Estructura de un arbol binario --\n";
    mostrarEstructuraRecursivo(raiz, 0);
}



void ArbolBinario::preordenRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->dato << "-";
        preordenRecursivo(nodo->izq);
        preordenRecursivo(nodo->der);
    }
}

void ArbolBinario::inordenRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        inordenRecursivo(nodo->izq);
        std::cout << nodo->dato << "-";
        inordenRecursivo(nodo->der);
    }
}

void ArbolBinario::postordenRecursivo(NodoArbol* nodo) {
    if (nodo != nullptr) {
        postordenRecursivo(nodo->izq);
        postordenRecursivo(nodo->der);
        std::cout << nodo->dato << "-";
    }
}

void ArbolBinario::preorden() {
    preordenRecursivo(raiz);
}

void ArbolBinario::inorden() {
    inordenRecursivo(raiz);
}

void ArbolBinario::postorden() {
    postordenRecursivo(raiz);
}

void ArbolBinario::cargarXML(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return;

    std::string linea;
    while (std::getline(archivo, linea)) {
        size_t inicio = linea.find("<Numero>");
        size_t fin = linea.find("</Numero>");
        if (inicio != std::string::npos && fin != std::string::npos) {
            inicio += 8;
            std::string valorStr = linea.substr(inicio, fin - inicio);
            insertar(std::stoi(valorStr));
        }
    }
    archivo.close();
}

void ArbolBinario::cargarJSON(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) return;

    char c;
    std::string numeroStr = "";
    while (archivo.get(c)) {
        if (std::isdigit(c) || c == '-') {
            numeroStr += c;
        } else {
            if (!numeroStr.empty()) {
                insertar(std::stoi(numeroStr));
                numeroStr = "";
            }
        }
    }
    if (!numeroStr.empty()) {
        insertar(std::stoi(numeroStr));
    }
    archivo.close();
}
