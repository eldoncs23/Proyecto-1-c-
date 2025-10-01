#pragma once
#define INTERFAZ_H

#include <iostream>
#include <string>
#include "Gimnasio.h"
#include "Sucursal.h"
#include "Instructor.h"
#include "Cliente.h"
#include "Historial.h"
#include "Reporte.h"
#include "Clase.h"

using namespace std;

class Interfaz {
private:
    Gimnasio* gimnasio; //puntero al gimnasio relación de composición con gimnasio

public:
    // Constructor / destructor
    Interfaz(Gimnasio* gym);
    ~Interfaz();

    // Menú principal
    void mostrarMenu();

    // Métodos de operaciones principales
    void agregarSucursal();
    void agregarInstructor();
    void asignarClienteAInstructor();

    void crearReporte();
    void mostrarHistorialCliente();

    void crearRutinaCliente();
    void modificarRutinaCliente();
    void eliminarRutinaCliente();

    // (Opcionales extra para tu flujo completo)
    void eliminarCliente();
    void eliminarInstructor();
    void crearClaseGrupal();
    void matricularClienteAClase();
    //mas metodos utiles
    void mostrarRutinaCliente();
    void mostrarClases();
    void mostrarCliente();
    void mostrarInstructor();
    void mostrarSucursal();
};