#include "Rutina.h"
#include <iostream>
using namespace std;

Rutina::Rutina(int max) {
    if (max <= 0) max = 10;
    maxEjercicios = max;
    cantEjercicios = 0;
    ejercicios = new string[maxEjercicios];
}

Rutina::~Rutina() {
    delete[] ejercicios;
}

void Rutina::asignarRutina(string* arr, int n) {
    if (n > maxEjercicios) n = maxEjercicios;
    for (int i = 0; i < n; i++) ejercicios[i] = arr[i];
    cantEjercicios = n;
}

void Rutina::mostrarRutina() const {
    if (cantEjercicios == 0) {
        cout << "  (sin rutina asignada)\n";
        return;
    }
    for (int i = 0; i < cantEjercicios; i++) cout << "  - " << ejercicios[i] << endl;
}

