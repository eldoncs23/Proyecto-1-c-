#include "Cliente.h"

// Constructores
Cliente::Cliente() {
    nombre = "";
    cedula = "";
    telefono = "";
    correo = "";
    fechaNacimiento = "";
    sexo = "";
    fechaInscripcion = "";
    rutinaActual = "";
    historial = new Historial();
}

Cliente::Cliente(string nombre, string cedula, string telefono, string correo,
    string fechaNacimiento, string sexo, string fechaInscripcion) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = fechaNacimiento;
    this->sexo = sexo;
    this->fechaInscripcion = fechaInscripcion;
    rutinaActual = "";
    historial = new Historial();
}

// Destructor
Cliente::~Cliente() {
    delete historial;
}

// Setters
void Cliente::setNombre(string nombre) { this->nombre = nombre; }
void Cliente::setCedula(string cedula) { this->cedula = cedula; }
void Cliente::setTelefono(string telefono) { this->telefono = telefono; }
void Cliente::setCorreo(string correo) { this->correo = correo; }
void Cliente::setFechaNacimiento(string fechaNacimiento) { this->fechaNacimiento = fechaNacimiento; }
void Cliente::setSexo(string sexo) { this->sexo = sexo; }
void Cliente::setFechaInscripcion(string fechaInscripcion) { this->fechaInscripcion = fechaInscripcion; }
void Cliente::setRutinaActual(string rutina) { rutinaActual = rutina; }

// Getters
string Cliente::getNombre() const { return nombre; }
string Cliente::getCedula() const { return cedula; }
string Cliente::getTelefono() const { return telefono; }
string Cliente::getCorreo() const { return correo; }
string Cliente::getFechaNacimiento() const { return fechaNacimiento; }
string Cliente::getSexo() const { return sexo; }
string Cliente::getFechaInscripcion() const { return fechaInscripcion; }
string Cliente::getRutinaActual() const { return rutinaActual; }

// Historial
Historial* Cliente::getHistorial() const { return historial; }

