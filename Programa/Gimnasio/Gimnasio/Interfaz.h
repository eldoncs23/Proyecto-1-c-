#define INTERFAZ_H
#pragma once
#include "Gimnasio.h"
#include <string>
using namespace std;

class Interfaz {
private:
    Gimnasio* gimnasio;   // asociaci�n principal

public:
    Interfaz(Gimnasio* g) : gimnasio(g) {}

    void menuPrincipal();

    // === Gesti�n de entidades ===
    void agregarSucursal();
    void agregarInstructor();
    void agregarCliente();

    void mostrarSucursales();
    void mostrarInstructores();
    void mostrarClientes();

    // === Reportes ===
    void crearReporte();
    void mostrarHistorialCliente();

    // === Rutinas ===
    void crearRutinaCliente();
    void mostrarRutinaCliente();
    void eliminarRutinaCliente();

    // === Eliminaciones ===
    void eliminarSucursal();
    void eliminarInstructor();
    void eliminarCliente();
    void vaciarHistorialCliente();
};