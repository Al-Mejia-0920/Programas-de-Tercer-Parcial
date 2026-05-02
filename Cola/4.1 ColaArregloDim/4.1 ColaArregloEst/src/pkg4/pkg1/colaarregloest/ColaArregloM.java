package pkg4.pkg1.colaarregloest;

public class ColaArregloM implements interfaz {
    private Nodo frente;
    private Nodo ultimo;
    private int contador;
    private int limite;

    public ColaArregloM(int tam) {
        this.frente = null;
        this.ultimo = null;
        this.contador = 0;
        this.limite = tam;
    }

    @Override
    public void registrar(Alumno nuevo) {
        if (!estaLlena()) {
            Nodo nuevoNodo = new Nodo(nuevo);
            if (estaVacia()) {
                frente = nuevoNodo;
            } else {
                ultimo.siguiente = nuevoNodo;
            }
            ultimo = nuevoNodo;
            contador++;
            System.out.println("Registrado: " + nuevo.getNombre());
        } else {
            System.out.println("Error: Cupo lleno (" + limite + ")");
        }
    }

    @Override
    public Alumno atender() {
        if (!estaVacia()) {
            Alumno atendido = frente.alumno;
            frente = frente.siguiente;
            if (frente == null) {
                ultimo = null;
            }
            contador--;
            return atendido;
        }
        return null;
    }

    @Override
    public void mostrarCola() {
        if (estaVacia()) {
            System.out.println("La fila esta vacia");
        } else {
            System.out.print("Fila actual: ");
            Nodo actual = frente;
            while (actual != null) {
                System.out.print("[" + actual.alumno.getNombre() + "] -> ");
                actual = actual.siguiente;
            }
            System.out.println("Cupo: " + contador + " / " + limite);
        }
    }

    @Override
    public boolean estaLlena() {
        return contador >= limite;
    }

    @Override
    public boolean estaVacia() {
        return frente == null;
    }
}