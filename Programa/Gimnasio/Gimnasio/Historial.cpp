#include "Historial.h"

Historial::Historial(int maxReportes) {
    if (maxReportes <= 0) maxReportes = 10;
    capacidad = maxReportes;
    cantidad = 0;
    reportes = new Reporte * [capacidad];
    for (int i = 0; i < capacidad; ++i) reportes[i] = nullptr;
}

Historial::~Historial() {
    vaciarHistorial();
    delete[] reportes;
}

bool Historial::agregarReporte(Reporte* r) {
    if (!r) return false;
    if (cantidad >= capacidad) return false;
    reportes[cantidad++] = r;
    return true;
}

bool Historial::eliminarReporte(int indice) {
    if (indice < 0 || indice >= cantidad) return false;
    delete reportes[indice];
    for (int i = indice; i < cantidad - 1; ++i) reportes[i] = reportes[i + 1];
    reportes[cantidad - 1] = nullptr;
    --cantidad;
    return true;
}

void Historial::vaciarHistorial() {
    for (int i = 0; i < cantidad; ++i) {
        delete reportes[i];
        reportes[i] = nullptr;
    }
    cantidad = 0;
}

void Historial::mostrarReportes() const {
    if (cantidad == 0) {
        cout << "No hay reportes registrados.\n";
        return;
    }
    for (int i = 0; i < cantidad; ++i) {
        cout << "Reporte " << i + 1 << ":\n";
        reportes[i]->mostrarReporte();
    }
}

Reporte* Historial::getUltimoReporte() const {
    if (cantidad == 0) return nullptr;
    return reportes[cantidad - 1];
}
int Historial::getCantidad() const { return cantidad; }