package colabiblioteca;
import java.util.Scanner;

public class ColaBiblioteca {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        
        System.out.print("¿De qué tamaño quieres la cola?: ");
        int tam = leer.nextInt();
        leer.nextLine(); 

        interfaz miCola = new ColaBiblioM(tam); 
        
        int opc;
        do {
            System.out.println("\n   Opciones:");
            System.out.println("1. Registrar Alumno");
            System.out.println("2. Atender Siguiente");
            System.out.println("3. Ver Fila");
            System.out.println("4. Salir");
            System.out.print("Opcion: ");
            opc = leer.nextInt();
            leer.nextLine();

            switch (opc) {
                case 1:
                    System.out.print("ID: "); int id = leer.nextInt();
                    leer.nextLine();
                    System.out.print("Nombre: "); String nom = leer.nextLine();
                    System.out.print("Curso: "); String cur = leer.nextLine();
                    
                    miCola.registrar(new Alumno(id, nom, cur));
                    break;

                case 2:
                    Alumno a = miCola.atender();
                    if (a != null) {
                        System.out.println("Atendiendo a: " + a.getNombre());
                    } else {
                        System.out.println("No hay nadie en la fila.");
                    }
                    break;

                case 3:
                    miCola.mostrarCola();
                    break;
            }
        } while (opc != 4);
        
        System.out.println("Fin del programa.");
    }
}