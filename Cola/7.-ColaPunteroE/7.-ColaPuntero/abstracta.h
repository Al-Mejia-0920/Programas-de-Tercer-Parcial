#ifndef ABSTRACTA_H
#define ABSTRACTA_H

#include <iostream>
#include <string>

using namespace std;

struct Alumno {
    int id;
    string nombre;
};

struct Nodo {
    Alumno* alumno;
    Nodo* siguiente;
};

class ColaPunteros {
private:
    Nodo* frente;
    Nodo* ultimo;
    int contador;
    const int MAX = 5;

public:
    ColaPunteros();
    void registrar(int id, string nombre);
    void atender();
    void mostrar();
};

#endif
