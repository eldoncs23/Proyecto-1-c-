#include "ColeccionInstructores.h"

ColeccionInstructores::ColeccionInstructores(int max) {
    tam = max;
    cant = 0;
    instructores = new Instructor * [tam];
    for (int i = 0; i < tam; i++) instructores[i] = nullptr;
}

ColeccionInstructores::~ColeccionInstructores() {
    for (int i = 0; i < cant; i++) {
        delete instructores[i];   //  liberamos memoria de cada instructor
    }
    delete[] instructores;
}

bool ColeccionInstructores::agregarInstructor(Instructor* inst) {
    if (estaLleno()) {
        cout << " No se pueden agregar más instructores.\n";
        return false;
    }
    instructores[cant++] = inst;
    return true;
}

bool ColeccionInstructores::eliminarInstructor(string cedula) {
    for (int i = 0; i < cant; i++) {
        if (instructores[i] && instructores[i]->getCedula() == cedula) {
            delete instructores[i];
            for (int j = i; j < cant - 1; j++) {
                instructores[j] = instructores[j + 1];
            }
            instructores[--cant] = nullptr;
            return true;
        }
    }
    cout << " Instructor no encontrado.\n";
    return false;
}

Instructor* ColeccionInstructores::buscarInstructor(string cedula) const {
    for (int i = 0; i < cant; i++) {
        if (instructores[i] && instructores[i]->getCedula() == cedula) {
            return instructores[i];
        }
    }
    return nullptr;
}

void ColeccionInstructores::listarInstructores() const {
    if (cant == 0) {
        cout << "No hay instructores registrados.\n";
        return;
    }
    cout << "\n=== Lista de Instructores ===\n";
    for (int i = 0; i < cant; i++) {
        cout << "- " << instructores[i]->getNombre()
            << " (Cédula: " << instructores[i]->getCedula() << ")\n";
    }
}
