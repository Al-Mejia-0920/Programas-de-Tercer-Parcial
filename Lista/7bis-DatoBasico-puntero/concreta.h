#ifndef CONCRETA_H_INCLUDED
#define CONCRETA_H_INCLUDED

#include "abstracta.h"

class Lista : public dadlista
{
public:
    Lista(){
        inicio = NULL;
        i = 0;
    }
    void agregar(int n)
    {
        Nodo* nuevo = new Nodo();
        nuevo->numero = n;
        nuevo->siguiente = inicio;
        inicio = nuevo;
        i++;
        cout<<"\n"<<n<<" ...Agregado correctamente";
    }

    void quitar()
    {
        if(inicio != NULL)
        {
            Nodo* aux = inicio;
            inicio = inicio->siguiente;
            delete aux;
            i--;
            cout<<"Se ha eliminado....";
        } else
        {
            cout<<"No hay nada que borrar....";
        }
    }

    void mostrar()
    {
        Nodo* aux = inicio;
        if(aux == NULL)
        {
            cout<<"Lista vacia...";
        }
        while (aux != NULL)
        {
            cout<<"\nNumero : "<<aux->numero;
            aux = aux->siguiente;
        }
    }

    void tam()
    {
        cout <<"\nHay "<<i<<" Personas en la lista";
    }
};


#endif // CONCRETA_H_INCLUDED
