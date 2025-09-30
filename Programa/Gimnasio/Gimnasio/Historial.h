#pragma once
#include "Reporte.h"
#include <iostream>
using namespace std;

class Historial {
private:
    Reporte** reportes;
    int cantReportes;
    const int MAX_REPORTES = 10; // m�ximo 10 mediciones por cliente

public:
    Historial();
    ~Historial();

    // Gesti�n de reportes
    bool agregarReporte(Reporte* rep);
    bool eliminarReporte(int pos);
    void vaciarHistorial();

    Reporte* getUltimoReporte() const;

    // Mostrar historial
    void mostrarHistorial() const;

    int getCantReportes() const { return cantReportes; }
};



