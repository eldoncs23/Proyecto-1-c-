#pragma once
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
    cantidadClasesMatriculadas = 0;
    for (int i = 0; i < 3; ++i) clasesMatriculadas[i] = -1;
}

Cliente::Cliente(string cedula, string nombre, string telefono, string correo,
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
    cantidadClasesMatriculadas = 0;
    for (int i = 0; i < 3; ++i) clasesMatriculadas[i] = -1;

}

// Destructor
Cliente::~Cliente() {
    delete historial;
}


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

void Cliente::mostrar() const {
    cout << "Cliente: " << nombre << " | Cedula: " << cedula << "\n";
    cout << "Telefono: " << telefono << " | Correo: " << correo << "\n";
    cout << "Fecha Nac.: " << fechaNacimiento << " | Sexo: " << sexo << "\n";
    cout << "Fecha Inscripcion: " << fechaInscripcion << "\n";
    if (!rutinaActual.empty()) {
        cout << "Rutina actual: " << rutinaActual << "\n";
    }
}

bool Cliente::puedeMatricular() const
{
    return cantidadClasesMatriculadas < 3;;
}

void Cliente::matricularClase(int idClase)
{
    if (cantidadClasesMatriculadas < 3)
        clasesMatriculadas[cantidadClasesMatriculadas++] = idClase;
}

int Cliente::getClase(int index) const
{
    if (index < 0 || index >= cantidadClasesMatriculadas) return -1;
    return clasesMatriculadas[index];
}

int Cliente::getCantidadClases() const
{
    return cantidadClasesMatriculadas;
}

bool Cliente::tieneRutina() const {
    // verificamos si el primero caracter de la cadena no es 0
    return rutinaActual[0] != '\0';
}