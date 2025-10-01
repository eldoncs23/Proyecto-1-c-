#pragma once
#define GIMNASIO_H

#include <iostream>
#include "Sucursal.h"
#include <string>
using namespace std;

class Gimnasio {
private:
    string nombre;
    Sucursal** sucursales;
    int cantidadSucursales;
    int capacidadSucursales;

public:
    
    Gimnasio(const string& nombre, int maxSucursales = 30);
    ~Gimnasio();

    // Getters
    string getNombre() const;
    int getCantidadSucursales() const;
    Sucursal* getSucursal(int index) const;

    // Setters
    void setNombre(string nombre);

    // Métodos
    bool agregarSucursal(Sucursal* suc);
    Sucursal* buscarSucursal(string codigo);
};
