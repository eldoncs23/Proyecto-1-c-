#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente(string nom, string ced, string tel, string corr, string fecha,
    const string& s, const string& fi) {
    nombre = nom;
    cedula = ced;
    telefono = tel;
    correo = corr;
    fechaNacimiento = fecha;
    sexo = s;
    fechaInscripcion = fi;

    historial = new Historial(); // crea historial propio
    rutina = nullptr;
    cantEjercicios = 0;
}

Cliente::~Cliente() {
    delete historial;  // destruye historial y todos los reportes internos
    if (rutina) delete[] rutina;
}

void Cliente::mostrar() const {
    cout << "Cliente: " << nombre << " | Cédula: " << cedula << "\n";
    cout << "Teléfono: " << telefono << " | Correo: " << correo << "\n";
    cout << "Fecha Nac.: " << fechaNacimiento << " | Sexo: " << sexo << "\n";
    cout << "Fecha Inscripción: " << fechaInscripcion << "\n";
}

void Cliente::mostrarHistorial() const {
    cout << "Historial de reportes del cliente " << nombre << ":\n";
    if (historial)
        historial->mostrarHistorial();
}

void Cliente::asignarRutina(string* ejercicios, int n) {
    if (rutina) delete[] rutina;

    rutina = new string[n];
    cantEjercicios = n;
    for (int i = 0; i < n; i++)
        rutina[i] = ejercicios[i];
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
