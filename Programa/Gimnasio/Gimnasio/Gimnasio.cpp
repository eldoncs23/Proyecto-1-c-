#include "Gimnasio.h"

// Constructor por defecto
Gimnasio::Gimnasio() {
    nombre = "";
    capacidadSucursales = 10;
    cantidadSucursales = 0;
    sucursales = new Sucursal * [capacidadSucursales];
}

// Constructor con parámetros
Gimnasio::Gimnasio(string nombre, int maxSucursales) {
    this->nombre = nombre;
    capacidadSucursales = (maxSucursales > 0) ? maxSucursales : 30;
    cantidadSucursales = 0;
    sucursales = new Sucursal * [capacidadSucursales];
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
    if (index < 0 || index >= cantidadSucursales) return nullptr;
    return sucursales[index];
}

// Setter
void Gimnasio::setNombre(string nombre) { this->nombre = nombre; }

// Métodos
bool Gimnasio::agregarSucursal(Sucursal* suc) {
    if (cantidadSucursales >= capacidadSucursales) return false;
    sucursales[cantidadSucursales++] = suc;
    return true;
}

Sucursal* Gimnasio::buscarSucursalPorCodigo(string codigo) {
    for (int i = 0; i < cantidadSucursales; i++) {
        if (sucursales[i]->getCodigo() == codigo)
            return sucursales[i];
    }
    return nullptr;
}


