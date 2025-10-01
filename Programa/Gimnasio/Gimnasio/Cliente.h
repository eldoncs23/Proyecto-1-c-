#pragma once
#define CLIENTE_H

#include <string>
#include "Historial.h"
using namespace std;

class Cliente {
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string fechaNacimiento;
    string sexo;
    string fechaInscripcion;
    string rutinaActual;

    Historial* historial;
    int clasesMatriculadas[3]; // 3 como maximo establecido por el sistema
    int cantidadClasesMatriculadas;
public:
    Cliente();
    Cliente(string cedula, string nombre, string telefono, string correo,
        string fechaNacimiento, string sexo, string fechaInscripcion);
    ~Cliente();

    // getters / setters
    string getCedula() const;
    string getNombre() const;
    string getTelefono() const;
    string getCorreo() const;
    string getFechaNacimiento() const;
    string getSexo() const;
    string getFechaInscripcion() const;
    string getRutinaActual() const;
    
    void setTelefono(const string& t) { telefono = t; }
    void setCorreo(const string& c) { correo = c; }
    void setRutinaActual(const string& r) { rutinaActual = r; }

    // historial
    Historial* getHistorial() const;

    // mostrar
    void mostrarInfo() const;


    // validaciones
    bool puedeMatricular() const;
    void matricularClase(int idClase);
    int getClase(int index) const;
    int getCantidadClases() const;
    bool tieneRutina() const;
};

