#include "ColeccionClientes.h"

// Constructor
ColeccionClientes::ColeccionClientes(int max) {
    if (max <= 0) max = 50;
    capacidadMax = max;
    cantidad = 0;
    clientes = new Cliente * [capacidadMax];
}

// Destructor
ColeccionClientes::~ColeccionClientes() {
    for (int i = 0; i < cantidad; i++) {
        delete clientes[i];
    }
    delete[] clientes;
}

// Agregar cliente
bool ColeccionClientes::agregarCliente(Cliente* cli) {
    if (cantidad >= capacidadMax) return false;
    clientes[cantidad++] = cli;
    return true;
}

// Eliminar cliente por cédula
bool ColeccionClientes::eliminarClientePorCedula(string cedula) {
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i]->getCedula() == cedula) {
            delete clientes[i];
            for (int j = i; j < cantidad - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            cantidad--;
            return true;
        }
    }
    return false;
}

// Buscar cliente por cédula
Cliente* ColeccionClientes::buscarClientePorCedula(string cedula) {
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i]->getCedula() == cedula)
            return clientes[i];
    }
    return nullptr;
}

// Cantidad de clientes
int ColeccionClientes::getCantidadClientes() const {
    return cantidad;
}
