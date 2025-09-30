#include "Instructor.h"

// Constructor por defecto
Instructor::Instructor() {
    nombre = "";
    cedula = "";
    telefono = "";
    correo = "";
    fechaNacimiento = "";
    especialidades = nullptr;
    cantEspecialidades = 0;
}

// Constructor con parámetros
Instructor::Instructor(string nombre, string cedula, string telefono, string correo, string fechaNacimiento, int* especialidades, int cantEsp) {
    this->nombre = nombre;
    this->cedula = cedula;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = fechaNacimiento;
    cantEspecialidades = cantEsp;
    if (cantEsp > 0) {
        this->especialidades = new int[cantEsp];
        for (int i = 0; i < cantEsp; i++)
            this->especialidades[i] = especialidades[i];
    }
    else {
        this->especialidades = nullptr;
    }
}

// Destructor
Instructor::~Instructor() {
    delete[] especialidades;
}

// Getters
string Instructor::getNombre() const { return nombre; }
string Instructor::getCedula() const { return cedula; }
int Instructor::getCantEspecialidades() const { return cantEspecialidades; }
int Instructor::getEspecialidad(int index) const {
    if (index < 0 || index >= cantEspecialidades) return -1;
    return especialidades[index];
}

// Setters
void Instructor::setNombre(string nombre) { this->nombre = nombre; }
void Instructor::setCedula(string cedula) { this->cedula = cedula; }
void Instructor::setTelefono(string telefono) { this->telefono = telefono; }
void Instructor::setCorreo(string correo) { this->correo = correo; }
void Instructor::setFechaNacimiento(string fecha) { this->fechaNacimiento = fecha; }
void Instructor::setEspecialidades(int* especialidades, int cantEsp) {
    delete[] this->especialidades;
    cantEspecialidades = cantEsp;
    if (cantEsp > 0) {
        this->especialidades = new int[cantEsp];
        for (int i = 0; i < cantEsp; i++)
            this->especialidades[i] = especialidades[i];
    }
    else {
        this->especialidades = nullptr;
    }
}

// Métodos
bool Instructor::tieneEspecialidad(int idEsp) {
    for (int i = 0; i < cantEspecialidades; i++) {
        if (especialidades[i] == idEsp) return true;
    }
    return false;
}

// Crear reporte y añadirlo al historial del cliente
void Instructor::crearReporte(Cliente* cli, string fecha, double peso, double estatura, double porcentajeGrasa, double porcentajeMusculo, double grasaVisceral, int edadMetabolica, double cintura, double cadera, double pecho, double muslo) {
    Reporte* rep = new Reporte(fecha, cli->getNombre(), cli->getCedula(), nombre, peso, estatura, porcentajeGrasa, porcentajeMusculo, grasaVisceral, edadMetabolica, cintura, cadera, pecho, muslo);
    cli->getHistorial()->agregarReporte(rep);
}

// Asignar rutina actual al cliente
void Instructor::asignarRutina(Cliente* cli, string rutinaActual) {
    cli->setRutinaActual(rutinaActual);
}

