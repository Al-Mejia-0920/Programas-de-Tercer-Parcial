from abstracta import dadlista

class Persona :
    def __init__(self,nombre,edad,peso):
        self.nombre = nombre
        self.edad = edad
        self.peso = peso


class lista(dadlista):
    def agregar(self,n,p,e):
        if self.i < 10:
            NPersona = Persona(n,e,p)
            self.arreglo[self.i] = NPersona
            self.i +=1
            print(f" {n} a sido guardado")
        else: 
            print("----La lista esta llena----")



    def quitar(self):
          
        if self. i > 0:
            eliminado = self.arreglo[self.i - 1]
            self.arreglo[self.i - 1] = None
            self.i -= 1
            print("Eliminado....",eliminado.nombre)
        else:
            print("No hay nadie para eliminar...")
            

    def mostrar(self):

        if self.i == 0:
            print("Lista vacia... ")
        
        else:
            for j in range(self.i) :
              p = self.arreglo[j]
              print("\nNombre : ",p.nombre)
              print("\nEdad : ",p.edad)
              print("\nPeso : ",p.peso)

        
    def vacia(self):
        return self.i == 0
    
    def tamaño(self):
        return self.i
    
    def llena(self):
        return self.i == 10