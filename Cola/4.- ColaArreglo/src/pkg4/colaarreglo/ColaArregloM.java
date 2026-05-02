/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pkg4.colaarreglo;

public class ColaArregloM implements interfaz {
    private final int MAX = 5;
    private Alumno[] datos = new Alumno[MAX];
    private int frente = 0;
    private int ultimo = -1;
    private int contador = 0;

    @Override
    public void registrar(Alumno nuevo) {
        if (!estaLlena()) {
            ultimo = (ultimo + 1) % MAX;
            datos[ultimo] = nuevo;
            contador++;
            System.out.println(">> Registrado: " + nuevo.getNombre());
        } else {
            System.out.println("!! Error: Cola llena.");
        }
    }

    @Override
    public Alumno atender() {
        if (!estaVacia()) {
            Alumno atendido = datos[frente];
            frente = (frente + 1) % MAX;
            contador--;
            return atendido;
        }
        return null;
    }

    @Override public boolean estaLlena() { return contador == MAX; }
    @Override public boolean estaVacia() { return contador == 0; }
    
    @Override
    public void mostrarCola() {
        if (estaVacia()) {
            System.out.println("--- La fila esta vacia ---");
        } else {
            System.out.print("Fila actual: ");
            int aux = frente;
            for (int i = 0; i < contador; i++) {
                System.out.print("[" + datos[aux].getNombre() + "] ");
                aux = (aux + 1) % MAX;
        }
        System.out.println("\n(Alumnos en espera: " + contador + ")");
    }
}
}