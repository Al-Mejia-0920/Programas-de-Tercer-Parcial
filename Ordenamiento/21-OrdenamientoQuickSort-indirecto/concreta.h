#ifndef CONCRETA_H_INCLUDED
#define CONCRETA_H_INCLUDED
#include "abstracta.h"
#include <iostream>

using namespace std;

class Lista : public dadlista {
public:
    void agregar(int n) {
        if(i < 20) {
            arreglo[i] = n;
            punteros[i] = &arreglo[i]; 
            i++;
            cout << "Numero guardado" << endl;
        } else {
            cout << "Lista llena" << endl;
        }
    }

    
    void mostrar() {
        for (int j = 0; j < i; j++) {
            cout << *punteros[j] << " "; 
        }
        cout << endl;
    }

    void ordenar() {
        if(i > 1) {
            quicksortIndirecto(0, i - 1);
            cout << "Lista Ordenada Indirectamente" << endl;
        }
    }

private:
    void quicksortIndirecto(int bajo, int alto) {
        if (bajo < alto) {
            int pivote = *punteros[alto];
            int k = (bajo - 1);

            for(int j = bajo; j < alto; j++) {
                if (*punteros[j] < pivote) { 
                    k++;
                   
                    int* temp = punteros[k];
                    punteros[k] = punteros[j];
                    punteros[j] = temp;
                }
            }
            int* temp = punteros[k + 1];
            punteros[k + 1] = punteros[alto];
            punteros[alto] = temp;

            int pi = k + 1;
            quicksortIndirecto(bajo, pi - 1);
            quicksortIndirecto(pi + 1, alto);
        }
    }
};
#endif