#define CLIENTE_H

#include <iostream>
#include <string>
#include "Historial.h"
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
    string rutinaActual;
    Historial* historial; // Historial de reportes del cliente

public:
    // Constructores
    Cliente();
    Cliente(string nombre, string cedula, string telefono, string correo,
        string fechaNacimiento, string sexo, string fechaInscripcion);

    // Destructor
    ~Cliente();

    // Setters
    void setNombre(string nombre);
    void setCedula(string cedula);
    void setTelefono(string telefono);
    void setCorreo(string correo);
    void setFechaNacimiento(string fechaNacimiento);
    void setSexo(string sexo);
    void setFechaInscripcion(string fechaInscripcion);
    void setRutinaActual(string rutina);

    // Getters
    string getNombre() const;
    string getCedula() const;
    string getTelefono() const;
    string getCorreo() const;
    string getFechaNacimiento() const;
    string getSexo() const;
    string getFechaInscripcion() const;
    string getRutinaActual() const;

    // Historial
    Historial* getHistorial() const;
};


