#pragma once
#include "Gimnasio.h"
#include <iostream>
#include <string>
using namespace std;

class Interfaz {
private:
    Gimnasio* gimnasio;

    // Métodos internos
    void agregarSucursal();
    void agregarInstructor();
    void agregarCliente();
    void mostrarSucursales();
    void mostrarInstructores();
    void mostrarClientes();
    void crearReporte();
    void mostrarHistorialCliente();
    void crearRutinaCliente();
    void mostrarRutinaCliente();
    void eliminarCliente();
    void eliminarInstructor();
    void eliminarSucursal();
    void vaciarHistorialCliente();
    void eliminarRutinaCliente();

public:
    Interfaz(Gimnasio* gym) : gimnasio(gym) {}
    void menuPrincipal();
};
