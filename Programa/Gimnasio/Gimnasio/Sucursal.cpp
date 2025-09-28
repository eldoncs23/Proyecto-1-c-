#include "Sucursal.h"
#include <iostream>
using namespace std;

Sucursal::Sucursal(string c, string p, string ca, string co, string t) {
    codigo = c;
    provincia = p;
    canton = ca;
    correo = co;
    telefono = t;
    cantInstructores = 0;
    tam = 20;
    instructores = new Instructor * [tam];
    for (int i = 0; i < tam; ++i)
       instructores[i] = nullptr;
}

Sucursal::~Sucursal() {
    for (int i = 0; i < cantInstructores; ++i) {
        if (instructores[i]) {
            delete instructores[i];
            instructores[i] = nullptr;
        }
    }
    delete[] instructores;
}

void Sucursal::agregarInstructor(Instructor* inst) {
    if (cantInstructores < tam) {
        instructores[cantInstructores++] = inst;
        cout << "Instructor agregado a la sucursal.\n";
    }
    else {
        cout << "No se pueden agregar mas instructores.\n";
    }
}

void Sucursal::mostrar() const {
    cout << "Sucursal: " << codigo << " | Provincia: " << provincia
        << " | Canton: " << canton << " | Correo: " << correo
        << " | Telefono: " << telefono << " | Instructores: " << cantInstructores << "\n";
}
void Sucursal::mostrarInstructores() const {
    if (cantInstructores == 0) {
        cout << "No hay instructores en esta sucursal.\n";
        return;
    }
    cout << "--- Instructores en sucursal " << codigo << " ---\n";
    for (int i = 0; i < cantInstructores; ++i) {
        if (instructores[i]) instructores[i]->mostrar();
    }
}

Instructor* Sucursal::buscarInstructor(string cedula) const{ // va a buscar instructor por la cedula
    for (int i = 0; i < cantInstructores; ++i) {
        if (instructores[i] && instructores[i]->getCedula() == cedula) return instructores[i];
    }
    return nullptr;
}