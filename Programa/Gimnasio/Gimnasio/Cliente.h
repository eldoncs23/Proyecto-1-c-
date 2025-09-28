#pragma once
#define CLIENTE_H
#include "Reporte.h"
#include <string>
using namespace std;
class Cliente{
private:
    string nombre;
    string cedula;
    string telefono;
    string correo;
    string fechaNacimiento;
    string sexo;
    string fechaInscripcion;
    // Historial de reportes (propiedad del Instructor, no se destruye en ~Cliente)
    Reporte** historial;
    int cantReportes;

    // Rutina actual asignada
    string* rutina;
    int cantEjercicios;

public:
    Cliente(string nom, string ced, string tel, string corr, string fecha, string fechaInscripcion, string sexo);
    ~Cliente();

    void mostrarHistorial() const;
    void mostrar() const;
    //gets
    string getCedula() const { return cedula; }
    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }
    string getCorreo() const { return correo; }
    string getFechaNacimiento() const { return fechaNacimiento; }
    string getSexo() const { return sexo; }
    string getFechaInscripcion() const { return fechaInscripcion; }
    int getCantReportes() const { return cantReportes; }

    //sets
    void setTelefono(const string& t) { telefono = t; }
    void setCorreo(const string& c) { correo = c; }
    void setFechaNacimiento(const string& f) { fechaNacimiento = f; }
    void setSexo(const string& s) { sexo = s; }
    void setFechaInscripcion(const string& f) { fechaInscripcion = f; }
    void setNombre(const string& n) { nombre = n; }
    void setCedula(const string& c) { cedula = c; }

    //rutinas 
    void asignarRutina(string* ejercicios, int n);
    void mostrarRutina() const;
    string* getRutina() const { return rutina; }
    int getCantEjercicios() const { return cantEjercicios; }

    //reporte
    // --- Gestión del historial (solo el Instructor debería llamarlas) ---
    void agregarReporte(Reporte* rep);
    void eliminarReporte(int pos);   // Elimina un reporte puntual
    void vaciarHistorial();          // Elimina todos los reportes
    Reporte* getUltimoReporte() const;
};

