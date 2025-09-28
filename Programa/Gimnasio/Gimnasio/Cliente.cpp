#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(string nom, string ced, string tel, string corr, string fecha, string s, string fi) {
    cedula = ced;
    nombre = nom;
    telefono = tel;
    correo = corr;
    fechaNacimiento = fecha;
    sexo = s;
    fechaInscripcion = fi;
    historial = nullptr;
    cantReportes = 0;
    rutina = nullptr;
    cantEjercicios = 0;
}

Cliente::~Cliente() {
    // no es responsable de borrar historial, ni reportes
    if (rutina) delete[] rutina;
}
void Cliente::mostrar() const {
    cout << "Cliente: " << nombre << " | Cedula: " << cedula << "\n";
    cout << "Telefono: " << telefono << " | Correo: " << correo << "\n";
    cout << "Fecha Nac.: " << fechaNacimiento << " | Sexo: " << sexo << "\n";
    cout << "Fecha Inscripción: " << fechaInscripcion << "\n";
}


void Cliente::agregarReporte(Reporte* rep) {
    Reporte** nuevo = new Reporte * [cantReportes + 1];
    for (int i = 0; i < cantReportes; i++)
        nuevo[i] = historial[i];
    nuevo[cantReportes] = rep;

    if (historial) delete[] historial;
    historial = nuevo;
    cantReportes++;
}

void Cliente::eliminarReporte(int pos) {
    if (pos < 0 || pos >= cantReportes) return;

    // Elimina el reporte seleccionado
    delete historial[pos];

    // Compacta el arreglo
    Reporte** nuevo = new Reporte * [cantReportes - 1];
    int k = 0;
    for (int i = 0; i < cantReportes; i++) {
        if (i == pos) continue;
        nuevo[k++] = historial[i];
    }

    delete[] historial;
    historial = nuevo;
    cantReportes--;
}

void Cliente::vaciarHistorial() {
    for (int i = 0; i < cantReportes; i++) {
        delete historial[i];
    }
    delete[] historial;
    historial = nullptr;
    cantReportes = 0;
}

Reporte* Cliente::getUltimoReporte() const {
    if (cantReportes == 0) return nullptr;
    return historial[cantReportes - 1];
}

void Cliente::mostrarHistorial() const {
    cout << "Historial de reportes del cliente " << nombre << ":\n";
    if (cantReportes == 0) {
        cout << "  (sin reportes)\n";
        return;
    }
    for (int i = 0; i < cantReportes; i++) {
        cout << "Reporte " << (i + 1) << ":\n";
        historial[i]->mostrarReporte();
    }
}

void Cliente::asignarRutina(string* ejercicios, int n) {
    if (rutina) delete[] rutina;

    rutina = new string[n];
    cantEjercicios = n;
    for (int i = 0; i < n; i++) {
        rutina[i] = ejercicios[i];
    }
}

void Cliente::mostrarRutina() const {
    cout << "Rutina de " << nombre << ":\n";
    if (!rutina || cantEjercicios == 0) {
        cout << "  (sin rutina asignada)\n";
        return;
    }
    for (int i = 0; i < cantEjercicios; i++) {
        cout << "  - " << rutina[i] << endl;
    }
}