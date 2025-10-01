#include "Gimnasio.h"

// Constructor por defecto
Gimnasio::Gimnasio(const string& nombre, int maxSucursales) {
    this->nombre = nombre;
    capacidadSucursales = (maxSucursales > 0) ? maxSucursales : 30;
    sucursales = new Sucursal * [capacidadSucursales];
    cantidadSucursales = 0;
    for (int i = 0; i < capacidadSucursales; ++i) sucursales[i] = nullptr;
}

// Destructor
Gimnasio::~Gimnasio() {
    for (int i = 0; i < cantidadSucursales; i++)
        delete sucursales[i];
    delete[] sucursales;
}

// Getters
string Gimnasio::getNombre() const { return nombre; }
int Gimnasio::getCantidadSucursales() const { return cantidadSucursales; }
Sucursal* Gimnasio::getSucursal(int index) const {
    if (index < 0 || index >= cantidadSucursales) 
        return nullptr;
        return sucursales[index];
}

// Setter
void Gimnasio::setNombre(string nombre) { this->nombre = nombre; }

// Métodos
bool Gimnasio::agregarSucursal(Sucursal* s) {
    if (!s) return false;
    if (cantidadSucursales >= capacidadSucursales) return false;
    sucursales[cantidadSucursales++] = s;
    return true;
}

Sucursal* Gimnasio::buscarSucursal(string codigo) {
    for (int i = 0; i < cantidadSucursales; ++i) {
        if (sucursales[i] && sucursales[i]->getCodigo() == codigo) return sucursales[i];
    }
    return nullptr;
}


