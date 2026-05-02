#include "abstracta.h"

ColaPunteros::ColaPunteros(int tam) {
    frente = nullptr;
    ultimo = nullptr;
    contador = 0;
    limite = tam;
}

void ColaPunteros::registrar(int id, string nombre) {
    if (contador < limite) {
        Alumno* nuevoAlumno = new Alumno{id, nombre};
        Nodo* nuevoNodo = new Nodo{nuevoAlumno, nullptr};

        if (frente == nullptr) {
            frente = nuevoNodo;
        } else {
            ultimo->siguiente = nuevoNodo;
        }
        ultimo = nuevoNodo;
        contador++;
        cout << ">> Registrado: " << nombre << endl;
    } else {
        cout << "!! Error: Cola llena. Limite de " << limite << " alcanzado." << endl;
    }
}

void ColaPunteros::atender() {
    if (frente != nullptr) {
        Nodo* aux = frente;
        cout << ">>> Atendiendo a: " << frente->alumno->nombre << endl;
        frente = frente->siguiente;

        delete aux->alumno;
        delete aux;
        contador--;
    } else {
        cout << "!!! Fila vacia." << endl;
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
        cout << "NULL (" << contador << "/" << limite << ")" << endl;
    }
}
