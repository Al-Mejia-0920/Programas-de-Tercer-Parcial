from concreta import lista

def main():
    L = lista()

    while True:
        print("----MENU----\n1.Agregar(Maximo 10)\n2.Quitar\n3.Mostrar lista\n4.Verificar si esta vacia\n5.Tamaño de la lista\n6.Salir")
        
        opcion = input("Elige una opcion : ")

        match opcion:
            case "1":
                name = input("Ingresa un nombre : ")
                eda = input("Ingresa la edad : ")
                pes = input("Ingresa el peso : ")
                L.agregar(name,eda,pes)
            
            case "2":
                L.quitar()
            
            case "3":
                L.mostrar()
            
            case "4":
                print("Esta vacia...",L.vacia())
            
            case "5":
                if L.llena():
                  print("La lista ya esta llena...")
                else: 
                    print("Tamaño : ",L.tamaño())

            case "6":
                print("Adioooooos")
                break

            case _:
                print("Opcion no valida")

    L.mostrar()


main()
