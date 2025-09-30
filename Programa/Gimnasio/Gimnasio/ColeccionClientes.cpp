#include "ColeccionClientes.h"

ColeccionClientes::ColeccionClientes() {
    clientes = nullptr;
    cantClientes = 0;
}

ColeccionClientes::~ColeccionClientes() {
    for (int i = 0; i < cantClientes; i++)
        delete clientes[i];
    delete[] clientes;
}

bool ColeccionClientes::agregarCliente(Cliente* cli) {
    Cliente** nuevo = new Cliente * [cantClientes + 1];
    for (int i = 0; i < cantClientes; i++)
        nuevo[i] = clientes[i];
    nuevo[cantClientes] = cli;

    if (clientes) delete[] clientes;
    clientes = nuevo;
    cantClientes++;
    return true;
}

bool ColeccionClientes::eliminarCliente(const string& cedula) {
    int pos = -1;
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i]->getCedula() == cedula) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return false;

    delete clientes[pos];

    Cliente** nuevo = new Cliente * [cantClientes - 1];
    int k = 0;
    for (int i = 0; i < cantClientes; i++) {
        if (i == pos) continue;
        nuevo[k++] = clientes[i];
    }

    delete[] clientes;
    clientes = nuevo;
    cantClientes--;
    return true;
}

Cliente* ColeccionClientes::buscarCliente(const string& cedula) const {
    for (int i = 0; i < cantClientes; i++)
        if (clientes[i]->getCedula() == cedula) return clientes[i];
    return nullptr;
}

void ColeccionClientes::mostrarClientes() const {
    if (cantClientes == 0) { cout << "(sin clientes)\n"; return; }
    for (int i = 0; i < cantClientes; i++)
        clientes[i]->mostrar();
}

bool ColeccionClientes::asignarRutina(Cliente* cli, string* ejercicios, int n) {
    if (!cli) return false;
    cli->asignarRutina(ejercicios, n);
    return true;
}



