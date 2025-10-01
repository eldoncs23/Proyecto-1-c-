#pragma once
#define INSTRUCTOR_H
#include <iostream>
#include "Cliente.h"
#include "Historial.h"
using namespace std;

class Instructor {
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNacimiento;

    int* especialidades; // ids de especialidades
    int cantidadEspecialidades;

    Cliente** clientesAsignados;
    int cantidadClientes;
    int maxClientes;

public:
    // Constructor y destructor
    Instructor(string nombre, string cedula, string telefono, string correo, string fechaNacimiento,
        int* especialidades, int cantidadEspecialidades);
    ~Instructor();

    // Getters
    string getNombre() const;
    string getCedula() const;
    int getCantEspecialidades() const;
    int getEspecialidad(int index) const;

    // Setters
    void setNombre(string nombre);
    void setCedula(string cedula);
    void setTelefono(string telefono);
    void setCorreo(string correo);
    void setFechaNacimiento(string fecha);
    void setEspecialidades(int* especialidades, int cantEsp);

    // Métodos
    bool tieneEspecialidad(int idEsp);
    // crear reporte (el instructor pide datos por consola)
    void crearReporteParaCliente(Cliente* c);
    //void asignarRutina(Cliente* cli, string rutinaActual);// rutinas
    void crearRutinaParaCliente(Cliente* c);
    void modificarRutinaDeCliente(Cliente* c);
    // gestión clientes
    bool asignarCliente(Cliente* c);
    // mostrar
    void mostrar() const;
};