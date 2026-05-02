package pkg4.colaarreglo;

import java.util.Scanner;

public class ColaArreglo {

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        interfaz miCola = new ColaArregloM();
        int opc;

        do {
            System.out.println("\n--- REGISTRO DE ALUMNOS ---");
            System.out.println("1. Registrar Alumno");
            System.out.println("2. Atender Siguiente");
            System.out.println("3. Salir");
            System.out.print("Opcion: ");
            opc = leer.nextInt();
            leer.nextLine();

            switch (opc) {
                case 1:
                    System.out.print("Ingrese ID: ");
                    int id = leer.nextInt();
                    leer.nextLine();
                    System.out.print("Ingrese Nombre: ");
                    String nom = leer.nextLine();
                    System.out.print("Ingrese Curso: ");
                    String cur = leer.nextLine();

                  
                    miCola.registrar(new Alumno(id, nom, cur));
                    miCola.mostrarCola();
                    break;

                case 2:
                    Alumno atendido = miCola.atender();
                    if (atendido != null) {
                        System.out.println(">>> SE ATENDIO A: " + atendido.getNombre());
                    } else {
                        System.out.println("!!! No hay nadie a quien atender.");
                    }
                    miCola.mostrarCola();
                    break;

                case 3:
                    break;

                default:
                    System.out.println("Opcion no valida, intenta de nuevo.");
                    break;
            }
        } while (opc != 3);
        
        leer.close();
    }
}