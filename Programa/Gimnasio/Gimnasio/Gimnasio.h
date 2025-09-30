
#define GIMNASIO_H

#include <iostream>
#include "Sucursal.h"
using namespace std;

class Gimnasio {
private:
    string nombre;
    Sucursal** sucursales;
    int cantidadSucursales;
    int capacidadSucursales;

public:
    Gimnasio();
    Gimnasio(string nombre, int maxSucursales = 30);
    ~Gimnasio();

    // Getters
    string getNombre() const;
    int getCantidadSucursales() const;
    Sucursal* getSucursal(int index) const;

    // Setters
    void setNombre(string nombre);

    // Métodos
    bool agregarSucursal(Sucursal* suc);
    Sucursal* buscarSucursalPorCodigo(string codigo);
};
