#include <iostream>
#include "concreta.h"

using namespace std;

int main()
{
    Lista L;
    int op,num;

    L.agregar(10);
    L.agregar(20);
    L.agregar(30);
    L.agregar(40);
    L.agregar(50);

   do
    {
        cout<<"\n----MENU---\n";
        cout<<"\n1.Agregar numero\n";
        cout<<"\n2.Quitar numero\n";
        cout<<"\n3.Mostrar lista\n";
        cout<<"\n4.Ver tamano de la lista\n";
        cout<<"\n5.Salir\n";
        cout<<"Opcion : ";
        cin >>op;

        switch(op)
        {
        case 1:
            cout <<"Ingresa un numero : ";cin>>num;

            L.agregar(num);
            break;

        case 2:
            L.quitar();
            break;

        case 3:
            L.mostrar();
            break;

        case 4:
            L.tam();
            break;

        case 5:
            cout <<"Saliendo del programa...";
            break;

        default:
            cout <<"Opcion no valida";
        }

    } while(op != 5);
    return 0;
}
