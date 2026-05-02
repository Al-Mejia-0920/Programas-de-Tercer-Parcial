package colabiblioteca;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */

public interface interfaz {
    void registrar(Alumno alumno);
    Alumno atender();
    boolean estaLlena();
    boolean estaVacia();
    void mostrarCola();
}