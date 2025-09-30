#include "Historial.h"

// Constructor
Historial::Historial() {
    capacidadMax = 10; // máximo 10 reportes por cliente
    cantidad = 0;
    reportes = new Reporte * [capacidadMax];
}

// Destructor
Historial::~Historial() {
    for (int i = 0; i < cantidad; i++) {
        delete reportes[i];
    }
    delete[] reportes;
}

// Agregar reporte
bool Historial::agregarReporte(Reporte* rep) {
    if (cantidad >= capacidadMax) return false;
    reportes[cantidad++] = rep;
    return true;
}

// Eliminar reporte por posición
bool Historial::eliminarReporte(int index) {
    if (index < 0 || index >= cantidad) return false;
    delete reportes[index];
    for (int i = index; i < cantidad - 1; i++) {
        reportes[i] = reportes[i + 1];
    }
    cantidad--;
    return true;
}

// Vaciar historial
void Historial::vaciarHistorial() {
    for (int i = 0; i < cantidad; i++) {
        delete reportes[i];
    }
    cantidad = 0;
}

// Obtener reporte
Reporte* Historial::getReporte(int index) const {
    if (index < 0 || index >= cantidad) return nullptr;
    return reportes[index];
}

// Cantidad de reportes
int Historial::getCantidad() const {
    return cantidad;
}