#define HISTORIAL_H

#include <iostream>
#include "Reporte.h"
using namespace std;

class Historial {
private:
    Reporte** reportes; // arreglo din�mico de punteros a Reporte
    int cantidad;
    int capacidadMax;

public:
    // Constructores y destructor
    Historial();
    ~Historial();

    // M�todos
    bool agregarReporte(Reporte* rep);
    bool eliminarReporte(int index); // por posici�n
    void vaciarHistorial();
    Reporte* getReporte(int index) const;
    int getCantidad() const;
};
