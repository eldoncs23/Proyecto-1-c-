#pragma once
#define COLECCIONINSTRUCTORES_H

#include "Instructor.h"
#include <iostream>
using namespace std;

class ColeccionInstructores {
private:
    Instructor** instructores; // arreglo dinámico de punteros a Instructor
    int cant;                  // cantidad actual
    int tam;                   // tamaño máximo permitido

public:
    ColeccionInstructores(int max = 20);
    ~ColeccionInstructores();

    bool agregarInstructor(Instructor* inst);
    bool eliminarInstructor(string cedula);
    Instructor* buscarInstructor(string cedula) const;
    void listarInstructores() const;

    int getCant() const { return cant; }
    bool estaLleno() const { return cant >= tam; }
    Instructor* getInstructor(int pos) const {
        if (pos >= 0 && pos < cant) return instructores[pos];
        return nullptr;
    }
};