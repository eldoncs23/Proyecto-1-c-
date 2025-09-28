#define INTERFAZ_H

#include <iostream>
#include "Gimnasio.h"
#include "Sucursal.h"
#include "Instructor.h"
#include "Cliente.h"
#include "Reporte.h"

using namespace std;

class Interfaz {
private:
    Gimnasio* gimnasio;

public:
    Interfaz(Gimnasio* g) : gimnasio(g) {}
    void menuPrincipal();
private:
    void agregarSucursal();
    void agregarInstructor();
    void agregarCliente();
    void mostrarSucursales();
    void mostrarInstructores();
    void mostrarClientes();
    void crearReporte();
    void mostrarHistorialCliente();
    void crearRutinaCliente();
};
