#include "ColeccionClientes.h"

ColeccionClientes::ColeccionClientes(int max) {
    if (max <= 0) max = 50;
    capacidad = max;
    cantidad = 0;
    clientes = new Cliente * [capacidad];
    for (int i = 0; i < capacidad; ++i) clientes[i] = nullptr;
}

ColeccionClientes::~ColeccionClientes() {
    for (int i = 0; i < cantidad; ++i) delete clientes[i];
    delete[] clientes;
}

bool ColeccionClientes::agregarCliente(Cliente* cli) {
    if (!cli) return false;
    if (cantidad >= capacidad) return false;
    clientes[cantidad++] = cli;
    return true;
}

bool ColeccionClientes::eliminarCliente(const string& cedula) {
    for (int i = 0; i < cantidad; ++i) {
        if (clientes[i]->getCedula() == cedula) {
            delete clientes[i];
            for (int j = i; j < cantidad - 1; ++j) clientes[j] = clientes[j + 1];
            clientes[cantidad - 1] = nullptr;
            --cantidad;
            return true;
        }
    }
    return false;
}

Cliente* ColeccionClientes::buscarCliente(const string& cedula) {
    for (int i = 0; i < cantidad; ++i) {
        cout << "DEBUG -> comparando [" << clientes[i]->getCedula() << "] con [" << cedula << "]\n";
        if (clientes[i]->getCedula() == cedula) return clientes[i];
    }
    return nullptr;
}

Cliente* ColeccionClientes::getClientePorIndice(int index) const
{
    if (index < 0 || index >= cantidad) return nullptr;
    return clientes[index];
}
