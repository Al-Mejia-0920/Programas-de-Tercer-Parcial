#ifndef ABSTRACTA_H_INCLUDED
#define ABSTRACTA_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Nodo
{
    int numero;
    Nodo* siguiente;
};

class dadlista
{
public:
    Nodo* inicio;
    int i;

    dadlista()
    {
        inicio = NULL;
    }

    void agregar(int n){}
    void quitar(){}
    void mostrar(){}
    void tam(){}
};

#endif // ABSTRACTA_H_INCLUDED
