#pragma once
#define HISTORIAL_H

#include "Reporte.h"
#include <iostream>
using namespace std;

class Historial {
private:
    Reporte** reportes;
    int cantidad;
    int capacidad;

public:
    Historial(int maxReportes = 10);
    ~Historial();

    bool agregarReporte(Reporte* r);      // agrega (si hay espacio)
    bool eliminarReporte(int indice);     // elimina por índice
    void vaciarHistorial();               // elimina todos
    void mostrarReportes() const;         // imprime todos
    Reporte* getUltimoReporte() const;    // nullptr si vacío
    int getCantidad() const;
    
};

