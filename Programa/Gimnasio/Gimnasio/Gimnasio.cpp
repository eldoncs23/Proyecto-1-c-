#include "Gimnasio.h"
#include <iostream>
using namespace std;

Gimnasio::Gimnasio(const string& nom) {
    nombre = nom;
    sucursales = nullptr;
    cantSucursales = 0;
}

Gimnasio::~Gimnasio() {
    for (int i = 0; i < cantSucursales; i++) {
        delete sucursales[i];
    }
    delete[] sucursales;
}

void Gimnasio::agregarSucursal(Sucursal* s) {
    Sucursal** nuevo = new Sucursal * [cantSucursales + 1];
    for (int i = 0; i < cantSucursales; i++) {
        nuevo[i] = sucursales[i];
    }
    nuevo[cantSucursales] = s;

    delete[] sucursales;
    sucursales = nuevo;
    cantSucursales++;
}

void Gimnasio::mostrarSucursales() const {
    if (cantSucursales == 0) {
        cout << "No hay sucursales registradas.\n";
        return;
    }
    cout << "--- Sucursales del gimnasio " << nombre << " ---\n";
    for (int i = 0; i < cantSucursales; i++) {
        if (sucursales[i]) sucursales[i]->mostrar();
    }
}

Sucursal* Gimnasio::buscarSucursal(const string& codigo) const {
    for (int i = 0; i < cantSucursales; i++) {
        if (sucursales[i]->getCodigo() == codigo)
            return sucursales[i];
    }
    return nullptr;
}

void Gimnasio::eliminarSucursal(const string& codigo) {
    int pos = -1;
    for (int i = 0; i < cantSucursales; i++) {
        if (sucursales[i]->getCodigo() == codigo) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Sucursal no encontrada.\n";
        return;
    }

    delete sucursales[pos];

    // compactar arreglo
    Sucursal** nuevo = new Sucursal * [cantSucursales - 1];
    int k = 0;
    for (int i = 0; i < cantSucursales; i++) {
        if (i == pos) continue;
        nuevo[k++] = sucursales[i];
    }
    delete[] sucursales;
    sucursales = nuevo;
    cantSucursales--;

    cout << "Sucursal eliminada.\n";
}

