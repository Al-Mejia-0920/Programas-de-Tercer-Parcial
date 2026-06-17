#include <iostream>
#include "Arboles.h"

int main() {
    ArbolBinario arbolXML;
    arbolXML.cargarXML("datos_arbol.xml");

    std::cout << "--- Arbol en formato XML ---\n";
    arbolXML.mostrarEstructura();

    std::cout << "\nPreorden: ";
    arbolXML.preorden();
        std::cout << "\n\n";


    std::cout << "\nInorden:  ";
    arbolXML.inorden();
        std::cout << "\n\n";


    std::cout << "\nPostorden: ";
    arbolXML.postorden();
    std::cout << "\n\n";

    ArbolBinario arbolJSON;
    arbolJSON.cargarJSON("datos_arbol.json");

    std::cout << "--- Arbol en formato JSON ---\n";
    arbolXML.mostrarEstructura();
    std::cout << "\n\n";

    std::cout << "Preorden:  ";
    arbolJSON.preorden();
    std::cout << "\n\n";

    std::cout << "\nInorden:   ";
    arbolJSON.inorden();
    std::cout << "\n\n";

    std::cout << "\nPostorden: ";
    arbolJSON.postorden();
    std::cout << "\n\n";

    return 0;
}