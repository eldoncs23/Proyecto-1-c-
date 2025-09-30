#include "Sucursal.h"

// Constructor por defecto
Sucursal::Sucursal() {
    nombre = "";
    codigo = "";
    provincia = "";
    canton = "";
    correo = "";
    telefono = "";
    clientes = new ColeccionClientes();
    //capacidadInstructores = 20;
    cantidadInstructores = 0;
    instructores = new Instructor * [capacidadInstructores];
}

// Constructor con parámetros
Sucursal::Sucursal(string nombre, string codigo, string provincia, string canton, string correo, string telefono) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->provincia = provincia;
    this->canton = canton;
    this->correo = correo;
    this->telefono = telefono;
    clientes = new ColeccionClientes();
    //capacidadInstructores = maxInstructores;
    cantidadInstructores = 0;
    instructores = new Instructor * [capacidadInstructores];
}

// Destructor
Sucursal::~Sucursal() {
    delete clientes;
    for (int i = 0; i < cantidadInstructores; i++)
        delete instructores[i];
    delete[] instructores;
}

// Getters
string Sucursal::getNombre() const { return nombre; }
string Sucursal::getCodigo() const { return codigo; }
string Sucursal::getProvincia() const { return provincia; }
string Sucursal::getCanton() const { return canton; }
string Sucursal::getCorreo() const { return correo; }
string Sucursal::getTelefono() const { return telefono; }
ColeccionClientes* Sucursal::getColeccionClientes() const { return clientes; }
int Sucursal::getCantidadInstructores() const { return cantidadInstructores; }

// Setters
void Sucursal::setNombre(string nombre) { this->nombre = nombre; }
void Sucursal::setCodigo(string codigo) { this->codigo = codigo; }
void Sucursal::setProvincia(string provincia) { this->provincia = provincia; }
void Sucursal::setCanton(string canton) { this->canton = canton; }
void Sucursal::setCorreo(string correo) { this->correo = correo; }
void Sucursal::setTelefono(string telefono) { this->telefono = telefono; }

// Métodos
bool Sucursal::agregarInstructor(Instructor* inst) {
    if (cantidadInstructores >= capacidadInstructores) return false;
    instructores[cantidadInstructores++] = inst;
    return true;
}

bool Sucursal::eliminarInstructorPorCedula(string cedula) {
    for (int i = 0; i < cantidadInstructores; i++) {
        if (instructores[i]->getCedula() == cedula) {
            delete instructores[i];
            for (int j = i; j < cantidadInstructores - 1; j++)
                instructores[j] = instructores[j + 1];
            cantidadInstructores--;
            return true;
        }
    }
    return false;
}

Instructor* Sucursal::buscarInstructorPorCedula(string cedula) {
    for (int i = 0; i < cantidadInstructores; i++) {
        if (instructores[i]->getCedula() == cedula)
            return instructores[i];
    }
    return nullptr;
}

