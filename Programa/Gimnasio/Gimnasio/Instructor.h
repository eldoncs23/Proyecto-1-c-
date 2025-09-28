#pragma once
#define INSTRUCTOR_H

#include "Cliente.h"
#include "Reporte.h"
#include <string>
using namespace std;

class Instructor {
private:
    string nombre;
    string cedula;
    string telefono;
    string correo;
    string fechaNacimiento;
    string* especialidades;
    int cantEspecialidades;

    // Clientes asignados (solo punteros, no los destruye)
    Cliente** clientesAsignados;
    int cantClientes;

public:
    Instructor(string nom, string ced, string tel, string corr, string fecha,
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

    //manejo de clientes asignados
    void asignarCliente(Cliente* cli);
    Cliente* buscarCliente(const string& ced) const;
    Cliente** getClientesAsignados() const { return clientesAsignados; }

    //manejo de historial (solo el instructor puede modificar)
    void agregarReporteAHistorial(Cliente* cli, Reporte* rep);
    void eliminarReporteHistorial(Cliente* cli, int pos);
    void vaciarHistorial(Cliente* cli);

    //manejo de rutinas
    void crearRutina(Cliente* cli);
    string toString() const;

    // Buscar instructor
    Instructor* buscarInstructor(const string& ced) const;
};

