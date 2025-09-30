#include "Reporte.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

Reporte::Reporte(double p, double a, int e, const string& s, bool ejercicio) {
    peso = p;
    altura = a;
    edad = e;
    sexo = s;
    haceEjercicio = ejercicio;
    fecha = "";
    comentario = "";

    // Inicializamos medidas corporales
    porcentajeGrasa = 0.0;
    porcentajeMusculo = 0.0;
    edadMetabolica = 0;
    cintura = cadera = pecho = muslo = 0.0;

    calcularIMC();
}

void Reporte::calcularIMC() {
    if (altura > 0) imc = peso / (altura * altura);
    else imc = 0.0;
}

double Reporte::calcularProteinas() const {
    double factor = 0.8;
    if (haceEjercicio) {
        if (!sexo.empty() && (sexo[0] == 'M' || sexo[0] == 'm')) factor = 1.8;
        else factor = 1.7;
    }
    return peso * factor;
}

double Reporte::calcularAgua() const {
    if (peso <= 0) return 0.0;
    return ceil(peso / 7.0); // vasos de 250ml
}

void Reporte::mostrarReporte() const {
    cout << "\n=== REPORTE ===\n";
    cout << "Fecha: " << fecha << "\n";
    cout << fixed << setprecision(2);
    cout << "Peso: " << peso << " kg\n";
    cout << "Altura: " << altura << " m\n";
    cout << "Edad: " << edad << " años\n";
    cout << "Sexo: " << sexo << "\n";
    cout << "IMC: " << imc << "\n";
    cout << "Porcentaje Grasa: " << porcentajeGrasa << "%\n";
    cout << "Porcentaje Musculo: " << porcentajeMusculo << "%\n";
    cout << "Edad Metabolica: " << edadMetabolica << "\n";
    cout << "Medidas (Cintura/Cadera/Pecho/Muslo): "
        << cintura << " / " << cadera << " / " << pecho << " / " << muslo << "\n";
    cout << "Proteínas recomendadas: " << calcularProteinas() << " g/día\n";
    cout << "Vasos de agua recomendados: " << calcularAgua() << " vasos de 250ml/día\n";
    if (!comentario.empty()) cout << "Comentario del instructor: " << comentario << "\n";
    cout << "================\n";
}

