#define RUTINA_H
#pragma once
#include <string>
using namespace std;

class Rutina {
private:
    string* ejercicios; // arreglo dinámico de strings
    int cantEjercicios;
    int maxEjercicios;
public:
    Rutina(int max = 10);
    ~Rutina();

    void asignarRutina(string* arr, int n);
    void mostrarRutina() const;
    int getCantidad() const { return cantEjercicios; }
    string* getEjercicios() const { return ejercicios; }
};


