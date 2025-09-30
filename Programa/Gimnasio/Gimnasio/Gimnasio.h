#pragma once
#define GIMNASIO_H

#include "Sucursal.h"
#include <string>
using namespace std;

class Gimnasio {
private:
    string nombre;
    Sucursal** sucursales;
    int cantSucursales;

public:
    Gimnasio(const string& nom);
    ~Gimnasio();

    void agregarSucursal(Sucursal* s);
    void mostrarSucursales() const;

    // Búsquedas
    Sucursal* buscarSucursal(const string& codigo) const;

    // Eliminaciones
    void eliminarSucursal(const string& codigo);

    // Getters
    string getNombre() const { return nombre; }
    int getCantSucursales() const { return cantSucursales; }
    Sucursal* getSucursal(int i) const {
        if (i < 0 || i >= cantSucursales) return nullptr;
        return sucursales[i];
    }
};
