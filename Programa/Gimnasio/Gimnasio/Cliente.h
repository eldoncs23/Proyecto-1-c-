#pragma once
#define CLIENTE_H
#include "Reporte.h"
#include <string>
using namespace std;
class Cliente{
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNacimiento;
    string sexo;
    string fechaInscripcion;
    Reporte** historial;
    int cantReportes;
    const int maxReportes = 10;
    string* rutina;
    int cantEjercicios;

public:
    Cliente(string c, string n);
    ~Cliente();

    void mostrarHistorial() const;
    //gets
    string getCedula() const { return cedula; }
    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }
    string getCorreo() const { return correo; }
    string getFechaNacimiento() const { return fechaNacimiento; }
    string getSexo() const { return sexo; }
    string getFechaInscripcion() const { return fechaInscripcion; }
    int getCantReportes() const { return cantReportes; }
    int getMaxReportes() const { return maxReportes; }

    //sets
    void setTelefono(const string& t) { telefono = t; }
    void setCorreo(const string& c) { correo = c; }
    void setFechaNacimiento(const string& f) { fechaNacimiento = f; }
    void setSexo(const string& s) { sexo = s; }
    void setFechaInscripcion(const string& f) { fechaInscripcion = f; }
    void setNombre(const string& n) { nombre = n; }
    void setCedula(const string& c) { cedula = c; }

    //rutinas 
    void asignarRutina(string* r, int cant);
    string* getRutina() const { return rutina; }
    int getCantEjercicios() const { return cantEjercicios; }

    //reporte
    int getCantReportes() const { return cantReportes; }
    Reporte** getHistorial() const { return historial; }
    // Solo el Instructor puede modificar el historial
    friend class Instructor;
};

