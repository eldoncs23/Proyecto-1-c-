#include "Historial.h"

Historial::Historial() {
    reportes = nullptr;
    cantReportes = 0;
}

Historial::~Historial() {
    vaciarHistorial();
}

bool Historial::agregarReporte(Reporte* rep) {
    if (cantReportes >= MAX_REPORTES) return false;

    Reporte** nuevo = new Reporte * [cantReportes + 1];
    for (int i = 0; i < cantReportes; i++)
        nuevo[i] = reportes[i];
    nuevo[cantReportes] = rep;

    if (reportes) delete[] reportes;
    reportes = nuevo;
    cantReportes++;
    return true;
}

bool Historial::eliminarReporte(int pos) {
    if (pos < 0 || pos >= cantReportes) return false;

    delete reportes[pos];

    Reporte** nuevo = new Reporte * [cantReportes - 1];
    int k = 0;
    for (int i = 0; i < cantReportes; i++) {
        if (i == pos) continue;
        nuevo[k++] = reportes[i];
    }

    delete[] reportes;
    reportes = nuevo;
    cantReportes--;
    return true;
}

void Historial::vaciarHistorial() {
    for (int i = 0; i < cantReportes; i++)
        delete reportes[i];
    delete[] reportes;
    reportes = nullptr;
    cantReportes = 0;
}

Reporte* Historial::getUltimoReporte() const {
    if (cantReportes == 0) return nullptr;
    return reportes[cantReportes - 1];
}

void Historial::mostrarHistorial() const {
    if (cantReportes == 0) {
        cout << "  (sin reportes)\n";
        return;
    }
    for (int i = 0; i < cantReportes; i++) {
        cout << "Reporte " << (i + 1) << ":\n";
        reportes[i]->mostrarReporte();
    }
}




