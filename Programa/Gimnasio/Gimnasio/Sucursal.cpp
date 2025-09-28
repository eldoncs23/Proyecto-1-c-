#include "Sucursal.h"
#include <iostream>
using namespace std;

Sucursal::Sucursal(string cod, string n, string dir)
    : codigo(cod), nombre(n), direccion(dir), instructores(nullptr), cantInstructores(0),
    clientes(nullptr), cantClientes(0) {
}

Sucursal::~Sucursal() {
    // Destruir instructores
    for (int i = 0; i < cantInstructores; i++) {
        delete instructores[i];
    }
    delete[] instructores;

    // Destruir clientes
    for (int i = 0; i < cantClientes; i++) {
        delete clientes[i];
    }
    delete[] clientes;
}

// ----- Instructores -----
void Sucursal::agregarInstructor(Instructor* inst) {
    Instructor** nuevo = new Instructor * [cantInstructores + 1];
    for (int i = 0; i < cantInstructores; i++)
        nuevo[i] = instructores[i];
    nuevo[cantInstructores] = inst;

    if (instructores) delete[] instructores;
    instructores = nuevo;
    cantInstructores++;
}
//buscar por cedula
Instructor* Sucursal::buscarInstructor(const string& cedula) const {
    for (int i = 0; i < cantInstructores; i++) {
        if (instructores[i] && instructores[i]->getCedula() == cedula) return instructores[i];
    }
    return nullptr;
}

Instructor* Sucursal::getInstructor(int indice) const {
    if (indice >= 0 && indice < cantInstructores) return instructores[indice];
    return nullptr;
}

void Sucursal::eliminarInstructor(const string& cedula) {
    int pos = -1;
    for (int i = 0; i < cantInstructores; i++) {
        if (instructores[i]->getCedula() == cedula) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return;

    delete instructores[pos];
    for (int i = pos; i < cantInstructores - 1; i++) {
        instructores[i] = instructores[i + 1];
    }
    cantInstructores--;

    if (cantInstructores == 0) {
        delete[] instructores;
        instructores = nullptr;
    }
}

void Sucursal::listarInstructores() const {
    cout << "Instructores en sucursal " << codigo << ":\n";
    for (int i = 0; i < cantInstructores; i++) {
        instructores[i]->mostrar();
    }
}

// ----- Clientes -----
Cliente* Sucursal::getCliente(int indice) const {
    if (indice >= 0 && indice < cantClientes) return clientes[indice];
    return nullptr;
}
void Sucursal::agregarCliente(Cliente* cli) {
    Cliente** nuevo = new Cliente * [cantClientes + 1];
    for (int i = 0; i < cantClientes; i++)
        nuevo[i] = clientes[i];
    nuevo[cantClientes] = cli;

    if (clientes) delete[] clientes;
    clientes = nuevo;
    cantClientes++;
}

Cliente* Sucursal::buscarCliente(const string& cedula) const {
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i] && clientes[i]->getCedula() == cedula)
            return clientes[i];
    }
    return nullptr;
}

void Sucursal::eliminarCliente(const string& cedula) {
    int pos = -1;
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i]->getCedula() == cedula) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return;

    delete clientes[pos];
    for (int i = pos; i < cantClientes - 1; i++) {
        clientes[i] = clientes[i + 1];
    }
    cantClientes--;

    if (cantClientes == 0) {
        delete[] clientes;
        clientes = nullptr;
    }
}

void Sucursal::listarClientes() const {
    cout << "Clientes en sucursal " << codigo << ":\n";
    for (int i = 0; i < cantClientes; i++) {
        clientes[i]->mostrar();
    }
}

void Sucursal::mostrar() const {
    cout << "Sucursal: " << codigo << " - " << nombre << "-"<< direccion<< "\n";
    cout << "Cantidad de instructores: " << cantInstructores << "\n";
    cout << "Cantidad de clientes: " << cantClientes << "\n";
}