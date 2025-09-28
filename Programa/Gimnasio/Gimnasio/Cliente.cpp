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
    cout << "Rutina asignada: ";
    if (rutina && cantEjercicios > 0) {
        for (int i = 0; i < cantEjercicios; i++) {
            cout << rutina[i];
            if (i < cantEjercicios - 1) cout << ", ";
        }
    }
    else {
        cout << "Ninguna";
    }
    cout << endl;
}

void Cliente::asignarRutina(string* r, int cant) {
    if (rutina) delete[] rutina;

    if (cant > 0 && r != nullptr) {
        cantEjercicios = cant;
        rutina = new string[cant];
        for (int i = 0; i < cant; i++)
            rutina[i] = r[i];
    }
    else {
        rutina = nullptr;
        cantEjercicios = 0;
    }
}