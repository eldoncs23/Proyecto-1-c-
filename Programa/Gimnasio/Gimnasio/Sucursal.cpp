#include "Sucursal.h"
#include <iostream>
using namespace std;

Sucursal::Sucursal(const string& cod, const string& prov, const string& can, const string& corr, const string& tel) {
    codigo = cod;
    provincia = prov;
    canton = can;
    correo = corr;
    telefono = tel;

    instructores = nullptr;
    cantInstructores = 0;

    clientes = new ColeccionClientes(); // inicializamos la colección
}

Sucursal::~Sucursal() {
    for (int i = 0; i < cantInstructores; i++)
        delete instructores[i];
    delete[] instructores;
    delete clientes;
}

// Gestión de instructores
void Sucursal::agregarInstructor(Instructor* inst) {
    Instructor** nuevo = new Instructor * [cantInstructores + 1];
    for (int i = 0; i < cantInstructores; i++)
        nuevo[i] = instructores[i];
    nuevo[cantInstructores] = inst;

    delete[] instructores;
    instructores = nuevo;
    cantInstructores++;
}

Instructor* Sucursal::buscarInstructor(const string& ced) const {
    for (int i = 0; i < cantInstructores; i++) {
        if (instructores[i]->getCedula() == ced)
            return instructores[i];
    }
    return nullptr;
}

void Sucursal::eliminarInstructor(const string& ced) {
    int pos = -1;
    for (int i = 0; i < cantInstructores; i++) {
        if (instructores[i]->getCedula() == ced) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return;

    delete instructores[pos];

    Instructor** nuevo = new Instructor * [cantInstructores - 1];
    int k = 0;
    for (int i = 0; i < cantInstructores; i++) {
        if (i == pos) continue;
        nuevo[k++] = instructores[i];
    }

    delete[] instructores;
    instructores = nuevo;
    cantInstructores--;
}

void Sucursal::listarInstructores() const {
    for (int i = 0; i < cantInstructores; i++)
        instructores[i]->mostrar();
}

// Gestión de clientes (delegamos a ColeccionClientes)
void Sucursal::agregarCliente(Cliente* cli) {
    clientes->agregarCliente(cli);
}

Cliente* Sucursal::buscarCliente(const string& ced) const {
    return clientes->buscarCliente(ced);
}

void Sucursal::eliminarCliente(const string& ced) {
    clientes->eliminarCliente(ced);
}

void Sucursal::listarClientes() const {
    clientes->mostrarClientes();
}
