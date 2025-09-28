#pragma once
#define INTERFAZ_H

#include "Gimnasio.h"

class Interfaz {
private:
    Gimnasio* gimnasio;  // Punto de entrada al sistema
public:
    Interfaz();
    ~Interfaz();

    void mostrarMenuPrincipal();
    void menuSucursales();
    void menuInstructores(Sucursal* s);
    void menuClientes(Instructor* i);
};
