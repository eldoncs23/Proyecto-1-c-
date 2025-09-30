#include "Reporte.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;

Reporte::Reporte(double p, double a, int e, const string& s, bool ejercicio,
    double g, double m, int eMet, double gVisc, double cint, double cad,
    double pe, double mu, const string& f, const string& com) {
    peso = p;
    altura = a;
    edad = e;
    sexo = s;
    haceEjercicio = ejercicio;
    grasa = g;
    musculo = m;
    edadMetabolica = eMet;
    grasaVisceral = gVisc;
    cintura = cint;
    cadera = cad;
    pecho = pe;
    muslo = mu;
    comentario = com;

    // Fecha automática si no se pasa
    if (f.empty()) {
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        char buf[20];
        strftime(buf, sizeof(buf), "%Y-%m-%d", now);
        fecha = buf;
    }
    else {
        fecha = f;
    }

    // calcular IMC (proteger división por cero)
    imc = (altura > 0.0) ? (peso / (altura * altura)) : 0.0;
}

double Reporte::getIMC() const { return imc; }
string Reporte::getFecha() const { return fecha; }

double Reporte::calcularProteinas() const {
    // Baseline 0.8 g/kg. Si hace ejercicio: hombre 1.7-2.5 y mujer 1.6-1.8 (tomamos valores representativos)
    double factor = 0.8;
    if (haceEjercicio) {
        if (!sexo.empty() && (sexo[0] == 'M' || sexo[0] == 'm')) factor = 1.8; // puedes ajustar dentro del rango
        else factor = 1.7;
    }
    return peso * factor;
}

int Reporte::calcularVasosAgua() const {
    if (peso <= 0.0) return 0;
    return static_cast<int>(ceil(peso / 7.0)); // vasos de 250 ml
}

string Reporte::clasificarIMC() const {
    double v = imc;
    if (v < 16.0) return "Delgadez severa";
    if (v < 17.0) return "Delgadez moderada";
    if (v < 18.5) return "Delgadez leve";
    if (v < 25.0) return "Normal";
    if (v < 30.0) return "Pre-obesidad";
    if (v < 35.0) return "Obesidad leve";
    if (v < 40.0) return "Obesidad media";
    return "Obesidad morbida";
}

bool Reporte::esAltoRiesgo() const {
    string cat = clasificarIMC();
    return (cat == "Obesidad leve" || cat == "Obesidad media" || cat == "Obesidad morbida");
}

void Reporte::mostrarReporte() const {
    cout << "---- REPORTE ----\n";
    cout << "Fecha: " << fecha << "\n";
    cout << fixed << setprecision(2);
    cout << "Peso: " << peso << " kg\n";
    cout << "Altura: " << altura << " m\n";
    cout << "Edad: " << edad << " años\n";
    cout << "Sexo: " << sexo << "\n";
    cout << "Ejercicio: " << (haceEjercicio ? "Sí" : "No") << "\n";
    cout << "IMC: " << imc << " (" << clasificarIMC() << ")\n";
    cout << "Grasa corporal: " << grasa << "%\n";
    cout << "Musculo: " << musculo << "%\n";
    cout << "Edad metabólica: " << edadMetabolica << " años\n";
    cout << "Grasa visceral: " << grasaVisceral << "\n";
    cout << "Medidas (cintura/cadera/pecho/muslo): " << cintura << " / " << cadera << " / " << pecho << " / " << muslo << "\n";
    cout << "Proteínas recomendadas (g/día aprox): " << calcularProteinas() << "\n";
    cout << "Cantidad vasos (250ml) recomendados: " << calcularVasosAgua() << "\n";
    if (!comentario.empty()) cout << "Comentario del instructor: " << comentario << "\n";
    if (esAltoRiesgo()) cout << "*** ATENCION: Paciente de alto riesgo por obesidad. ***\n";
    cout << "-----------------\n";
}

