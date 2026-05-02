/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package colabiblioteca;
import java.util.LinkedList;
import java.util.Queue;

public class ColaBiblioM implements interfaz {
    private Queue<Alumno> cola = new LinkedList<>();
    private int lM;

    public ColaBiblioM(int tamaño) {
        this.lM = tamaño;
    }

    @Override
    public void registrar(Alumno nuevo) {
        if (!estaLlena()) {
            cola.add(nuevo); 
            System.out.println("[Libreria] Registrado: " + nuevo.getNombre());
        } else {
            System.out.println("Error: La cola esta llena (Limite: " + lM + ")");
        }
    }

    @Override
    public Alumno atender() {
        return cola.poll(); 
    }

    @Override
    public void mostrarCola() {
        if (estaVacia()) {
            System.out.println("La fila esta vacia");
        } else {
            System.out.println("FILA");
            for (Alumno a : cola) {
                System.out.print("[" + a.getNombre() + "] ");
            }
            System.out.println("\nCupo: " + cola.size() + " / " + lM);
        }
    }

    @Override
    public boolean estaVacia() {
        return cola.isEmpty();
    }

    @Override
    public boolean estaLlena() {
        return cola.size() >= lM;
    }
}