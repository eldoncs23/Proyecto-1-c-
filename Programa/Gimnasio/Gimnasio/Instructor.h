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

    int cantReportes;
    Reporte** historial;

public:
    Instructor(string c, string n, string t, string co, string fNac,
        string* esp, int cantEsp);
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
    string* getEspecialidades() const { return especialidades; }
    void setEspecialidades(string* esp, int cant); // copia n especialidades


    //manejo de clientes
    void asignarCliente(Cliente* cli);
    void despedirCliente(int index); //eliminar por indice
    Cliente* buscarCliente(const string& ced)const; //buscar cliente por cedula
    Cliente** getClientes() const { return clientes; }

    //manejo de historial (solo el instructor puede modificar)
    void agregarReporteAHistorial(Reporte* r);
    void eliminarReporteHistorial(int index);
    void vaciarHistorial();
    int getCantReportes() const { return cantReportes; }
    Reporte** getHistorial() const { return historial; }

    //manejo de rutinas
    void crearRutina(Cliente* cli, const string& nombreRutina);
    string toString() const;

    // Buscar instructor
    Instructor* buscarInstructor(const string& ced) const;
};

