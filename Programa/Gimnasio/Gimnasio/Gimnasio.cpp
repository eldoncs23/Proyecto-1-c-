#include "Gimnasio.h"
#include <iostream>
using namespace std;

Gimnasio::Gimnasio(const string nom) {
    cantSucursales = 0;
    tam = 10;
    sucursales = new Sucursal * [tam];
    for (int i = 0; i < tam; ++i)
       sucursales[i] = nullptr;
}

Gimnasio::~Gimnasio() {
    for (int i = 0; i < cantSucursales; ++i) {
        if (sucursales[i]) {
            delete sucursales[i];
            sucursales[i] = nullptr;
        }
    }
    delete[] sucursales;
}

void Gimnasio::agregarSucursal(Sucursal* s) {
    if (cantSucursales < tam) {
        sucursales[cantSucursales++] = s;
        cout << "Sucursal agregada al gimnasio.\n";
    }
    else {
        cout << "No se pueden agregar más sucursales, máximo de sucursales alcanzado.\n";
    }
}

void Gimnasio::mostrarSucursales() const{
    if (cantSucursales == 0) {
        cout << "No hay sucursales registradas.\n";
        return;
    }
    cout << "--- Sucursales del gimnasio " << nombre << " ---\n";
    for (int i = 0; i < cantSucursales; ++i) {
        if (sucursales[i]) sucursales[i]->mostrar();
    }
}
Sucursal* Gimnasio::buscarSucursal(string codigo) {
    for (int i = 0; i < cantSucursales; ++i) {
        if (sucursales[i] && sucursales[i]->getCodigo() == codigo) {
            return sucursales[i];
        }
    }
    return nullptr;
}
