#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(string c, string n) {
    cedula = "";
    nombre = "";
    telefono = "";
    correo = "";
    fechaNacimiento = "";
    sexo = "";
    fechaInscripcion = "";
    historial = nullptr;
    cantReportes = 0;
}

Cliente::~Cliente() {
    if (historial) {
        for (int i = 0; i < cantReportes; ++i) {
            if (historial[i]) {
                delete historial[i]; //libera el historial
                historial[i] = nullptr;
            }
        }
        delete[] historial; //libera el vector
        historial = nullptr;
    }
}

void Cliente::mostrarHistorial() const {
    if (historial == nullptr || cantReportes == 0) {
        cout << "El cliente no tiene reportes en su historial.\n";
        return;
    }
    cout << "Historial de reportes (" << cantReportes << "):\n";
    for (int i = 0; i < cantReportes; ++i) {
        cout << "---- Reporte #" << i + 1 << " ----\n";
        if (historial[i]) historial[i]->mostrarReporte();
    }
}
