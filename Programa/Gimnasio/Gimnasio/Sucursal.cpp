#include "Sucursal.h"

// Constructor por defecto
Sucursal::Sucursal(string codigo, string provincia, string canton, string correo, string telefono) {
    this->codigo = codigo;
    this->provincia = provincia;
    this->canton = canton;
    this->correo = correo;
    this->telefono = telefono;
    maxInstructores = 50;
    clientes = new ColeccionClientes();
    capacidadInstructores = maxInstructores;
    instructores = new Instructor * [capacidadInstructores];
    cantidadInstructores = 0;
    for (int i = 0; i < capacidadInstructores; ++i) instructores[i] = nullptr;

    maxClases = 8;
    clasesIDs = new int[maxClases];
    clasesInstructorCedula = new string[maxClases];
    cantidadClases = 0;
}

// Destructor
Sucursal::~Sucursal() {
    delete clientes;
    for (int i = 0; i < cantidadInstructores; ++i) delete instructores[i];
    delete[] instructores;
    delete[] clasesIDs;
    delete[] clasesInstructorCedula;
}

// Getters

string Sucursal::getCodigo() const { return codigo; }
string Sucursal::getProvincia() const { return provincia; }
string Sucursal::getCanton() const { return canton; }
string Sucursal::getCorreo() const { return correo; }
string Sucursal::getTelefono() const { return telefono; }
ColeccionClientes* Sucursal::getColeccionClientes() const { return clientes; }
int Sucursal::getCantidadInstructores() const { return cantidadInstructores; }

// Setters

void Sucursal::setCodigo(string codigo) { this->codigo = codigo; }
void Sucursal::setProvincia(string provincia) { this->provincia = provincia; }
void Sucursal::setCanton(string canton) { this->canton = canton; }
void Sucursal::setCorreo(string correo) { this->correo = correo; }
void Sucursal::setTelefono(string telefono) { this->telefono = telefono; }

// Métodos
void Sucursal::agregarInstructor(Instructor* inst) {
    if (cantidadInstructores < maxInstructores) {
        instructores[cantidadInstructores++] = inst;
        cout << "DEBUG -> Instructor agregado con cedula: [" << inst->getCedula() << "]" << endl;
    }
    else {
        cout << "No se pueden agregar más instructores a la sucursal." << endl;
    }
}

bool Sucursal::eliminarInstructor(const string& cedula) {
    for (int i = 0; i < cantidadInstructores; ++i) {
        if (instructores[i]->getCedula() == cedula) {
            delete instructores[i];
            for (int j = i; j < cantidadInstructores - 1; ++j) instructores[j] = instructores[j + 1];
            instructores[cantidadInstructores - 1] = nullptr;
            --cantidadInstructores;
            return true;
        }
    }
    return false;
}

Instructor* Sucursal::buscarInstructor(string cedula) {
    string cedulaLimpia = cedula;
    cedulaLimpia.erase(remove(cedulaLimpia.begin(), cedulaLimpia.end(), '\n'), cedulaLimpia.end());
    cedulaLimpia.erase(remove(cedulaLimpia.begin(), cedulaLimpia.end(), '\r'), cedulaLimpia.end());

    for (int i = 0; i < cantidadInstructores; i++) {
        string cedulaInst = instructores[i]->getCedula();
        cedulaInst.erase(remove(cedulaInst.begin(), cedulaInst.end(), '\n'), cedulaInst.end());
        cedulaInst.erase(remove(cedulaInst.begin(), cedulaInst.end(), '\r'), cedulaInst.end());

        cout << "DEBUG -> comparando [" << cedulaInst << "] con [" << cedulaLimpia << "]" << endl;

        if (cedulaInst == cedulaLimpia) {
            return instructores[i]; // Devuelve si coincide
        }
    }
    return nullptr; // No encontrado
}

void Sucursal::crearClaseGrupal(int idClase, const string& cedulaInstructor) {
    if (cantidadClases >= maxClases) {
        cout << "No se pueden crear más clases grupales en esta sucursal.\n";
        return;
    }
    clasesIDs[cantidadClases] = idClase;
    clasesInstructorCedula[cantidadClases] = cedulaInstructor;
    ++cantidadClases;
    cout << "Clase grupal " << idClase << " creada y asignada al instructor " << cedulaInstructor << ".\n";
}

void Sucursal::matricularClienteEnClase(int idClase, Cliente* cli) {
    int idx = -1;
    for (int i = 0; i < cantidadClases; ++i) if (clasesIDs[i] == idClase) { idx = i; break; }
    if (idx == -1) { cout << "Clase no encontrada.\n"; return; }
    // implementación simple: no guardamos lista detallada de inscritos (puede ampliarse)
    cout << "Matriculando cliente " << cli->getNombre() << " en clase " << idClase << " (Instructor: " << clasesInstructorCedula[idx] << ").\n";
}

