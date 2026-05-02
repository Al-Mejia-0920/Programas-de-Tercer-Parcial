#include "abstracta.h"

ColaPunteros::ColaPunteros() {
    frente = nullptr;
    ultimo = nullptr;
    contador = 0;
}

void ColaPunteros::registrar(int id, string nombre) {
    if (contador < MAX) {
        Alumno* nuevoAlumno = new Alumno{id, nombre};
        Nodo* nuevoNodo = new Nodo{nuevoAlumno, nullptr};

        if (frente == nullptr) {
            frente = nuevoNodo;
        } else {
            ultimo->siguiente = nuevoNodo;
        }
        ultimo = nuevoNodo;
        contador++;
        cout << "Registrado: " << nombre << endl;
    } else {
        cout << "Error: Cola llena (Limite: " << MAX << ")" << endl;
    }
}

void ColaPunteros::atender() {
    if (frente != nullptr) {
        Nodo* aux = frente;
        cout << "Atendiendo a: " << frente->alumno->nombre << endl;

        frente = frente->siguiente;

        delete aux->alumno;
        delete aux;

        contador--;
    } else {
        cout << "No hay nadie en la fila." << endl;
    }
}

void ColaPunteros::mostrar() {
    if (frente == nullptr) {
        cout << "Fila vacia." << endl;
    } else {
        Nodo* temporal = frente;
        cout << "FILA ACTUAL: ";
        while (temporal != nullptr) {
            cout << "[" << temporal->alumno->nombre << "] -> ";
            temporal = temporal->siguiente;
        }
        cout << "NULL (" << contador << "/" << MAX << ")" << endl;
    }
}
