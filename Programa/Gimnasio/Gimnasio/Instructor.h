#pragma once
#define INSTRUCTOR_H

#include "Cliente.h"
#include "Reporte.h"
#include <string>
using namespace std;

class Instructor {
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNacimiento;
    string* especialidades; //arreglo dinamico de strings
    int cantEspecialidades;
    Cliente** clientes;
    int cantClientes;
    int tamClientes; //el maximo de clientes
public:
    Instructor(string c, string n);
    ~Instructor();

    void mostrar() const;

    //gets
    string getCedula() const { return cedula; }
    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }
    string getCorreo() const { return correo; }
    string getFechaNacimiento() const { return fechaNacimiento; }
    int getCantClientes() const { return cantClientes; }

    //sets
    void setNombre(const string& n) { nombre = n; }
    void setTelefono(const string& t) { telefono = t; }
    void setCorreo(const string& e) { correo = e; }
    void setFechaNacimiento(const string& f) { fechaNacimiento = f; }

    //manejo de especialidades
    void setEspecialidades(const string* arr, int n); // copia n especialidades
    void agregarEspecialidad(const string& esp);
    void listarEspecialidades() const;

    //manejo de clientes
    void asignarCliente(Cliente* cli);
    void despedirCliente(int index); //eliminar por indice
    Cliente* buscarCliente(string cedula); //buscar cliente por cedula
 

    //manejo de historial (solo el instructor puede modificar)
    void agregarReporteAHistorial(Cliente* cli, Reporte* r);
    void eliminarReporteDeHistorial(Cliente* cli, int index);
    void vaciarHistorialCliente(Cliente* cli);

    void crearRutina(Cliente* cli, string rutina);
    string toString() const;
};

