#include "Reporte.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

Reporte::Reporte(double p, double a, int e, const string& s, bool ejercicio, const string& f) {
    peso = p;
    altura = a;
    edad = e;
    sexo = s;
    haceEjercicio = ejercicio;
    fecha = f;
    imc = peso / (altura * altura);
    // Valores por defecto para composición corporal
    grasa = 0.0;
    musculo = 0.0;
    edadMetabolica = 0;
    cintura = 0.0;
    cadera = 0.0;
    pecho = 0.0;
    muslo = 0.0;
    
}
double Reporte::getIMC() const {
    return imc;            // imc se inicializa en el constructor/calcularIMC()
}
string Reporte::getFecha() const {
    return fecha;
}

double Reporte::calcularProteinas() const {
    // Baseline 0.8 g/kg. Si hace ejercicio: hombre 1.8, mujer 1.7
    double factor = 0.8;
    if (haceEjercicio) {
        if (!sexo.empty() && (sexo[0] == 'M' || sexo[0] == 'm')) factor = 1.8;
        else factor = 1.7;
    }
    return peso * factor;
}
double Reporte::calcularAgua() const {
    if (peso <= 0.0) return 0;
    return static_cast<int>(ceil(peso / 7.0)); // vasos de 250 ml
}

string Reporte::setComentario(const string& c) {
    if (c.size() > 100) comentario = c.substr(0, 100);
    else comentario = c;
    return c;
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
    cout << "IMC: " << imc << "\n";

    // Composición corporal
    cout << "Grasa: " << grasa << "%\n";
    cout << "Musculo: " << musculo << "%\n";
    cout << "Edad metabólica: " << edadMetabolica << " años\n";
    cout << "Medidas (cintura/cadera/pecho/muslo): "
        << cintura << " / " << cadera << " / " << pecho << " / " << muslo << "\n";

    // Recomendaciones
    cout << "Proteínas recomendadas (g/día): " << calcularProteinas() << "\n";
    cout << "Cantidad vasos (250ml) de agua: " << calcularAgua() << "\n";
    if (!comentario.empty())
        cout << "Comentario del instructor: " << comentario << "\n";

    cout << "-----------------\n";
    
}
