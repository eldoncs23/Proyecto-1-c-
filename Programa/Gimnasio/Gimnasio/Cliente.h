#pragma once
#define CLIENTE_H

#include "Reporte.h"
#include "Historial.h"
#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
    string cedula;
    string telefono;
    string correo;
    string fechaNacimiento;
    string sexo;
    string fechaInscripcion;

    // Historial de reportes (colección)
    Historial* historial;

    // Rutina actual asignada
    string* rutina;
    int cantEjercicios;

public:
    Cliente(string nom, string ced, string tel, string corr, string fecha,
        const string& sexo, const string& fechaInscripcion);
    ~Cliente();

    void mostrar() const;
    void mostrarHistorial() const;
    void mostrarRutina() const;

    // Gets
    string getCedula() const { return cedula; }
    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }
    string getCorreo() const { return correo; }
    string getFechaNacimiento() const { return fechaNacimiento; }
    string getSexo() const { return sexo; }
    string getFechaInscripcion() const { return fechaInscripcion; }
    Historial* getHistorial() const { return historial; }
    int getCantEjercicios() const { return cantEjercicios; }
    string* getRutina() const { return rutina; }

    // Sets
    void setTelefono(const string& t) { telefono = t; }
    void setCorreo(const string& c) { correo = c; }
    void setFechaNacimiento(const string& f) { fechaNacimiento = f; }
    void setSexo(const string& s) { sexo = s; }
    void setFechaInscripcion(const string& f) { fechaInscripcion = f; }
    void setNombre(const string& n) { nombre = n; }
    void setCedula(const string& c) { cedula = c; }

    // Rutina
    void asignarRutina(string* ejercicios, int n);
};


