/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package colabiblioteca;

public class Alumno {
    private int id;
    private String nombre;
    private String curso;

    public Alumno(int id, String nombre, String curso) {
        this.id = id;
        this.nombre = nombre;
        this.curso = curso;
    }

    public String getNombre() { return nombre; }
    public String getCurso() { return curso; }
    public int getId() { return id; }
}

