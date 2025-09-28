#include "Reporte.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

Reporte::Reporte(double p, double a, int e, const string& s, bool ejercicio, string f){
    fecha = f;
    peso = p;
    altura = a;
    sexo = s;
    haceEjercicio = ejercicio;
    //grasa = 0.0f;
    //musculo = 0.0f;
    //edadMetabolica = 0;
    //cintura = cadera = pecho = muslo = 0.0f;
    imc = peso / (altura * altura);
}
float Reporte::getIMC() const {
    return imc;            // imc se inicializa en el constructor/calcularIMC()
}
string Reporte::getFecha() const {
    return fecha;
}

//float Reporte::calcularIMC() {
//    peso /(altura * altura)
//}

double Reporte::calcularProteinas(string sexo, bool ejercicio) {
    // Baseline 0.8 g/kg. Si hace ejercicio: hombre 1.8, mujer 1.7 (valores seleccionados dentro de rangos mencionados)
    float factor = 0.8f;
    if (ejercicio) {
        if (!sexo.empty() && (sexo[0] == 'M' || sexo[0] == 'm')) factor = 1.8f;
        else factor = 1.7f;
    }
    return peso * factor;
}

double Reporte::calcularAgua() {
    // Cantidad de vasos de 250 ml = peso / 7 (redondeamos hacia arriba)
    if (peso <= 0.0f) return 0;
    return static_cast<int>(ceil(peso / 7.0f));
}

void Reporte::mostrarReporte(){
    cout << "---- REPORTE ----\n";
    cout << "Fecha: " << fecha << "\n";
    cout << "Peso: " << peso << " kg\n";
    cout << "Altura: " << altura << " m\n";
    cout << "Edad: " << edad << " años\n";
    cout << "Sexo: " << sexo << "\n";
    cout << "Ejercicio: " << (haceEjercicio ? "Sí" : "No") << "\n";
    cout << fixed << setprecision(2);
    cout << "IMC: " << imc << "\n";
    cout << "-----------------\n";
}
//
//void Reporte::mostrarReporte() {
//    cout << fixed << setprecision(2);
//    cout << "Fecha: " << fecha << "\n";
//    cout << "Peso (kg): " << peso << "\n";
//    cout << "Estatura (m): " << estatura << "\n";
//    cout << "IMC: " << calcularIMC() << "\n";
//    cout << "Porcentaje grasa: " << grasa << "\n";
//    cout << "Porcentaje musculo: " << musculo << "\n";
//    cout << "Edad metabolica: " << edadMetabolica << "\n";
//    cout << "Medidas (cintura/cadera/pecho/muslo): " << cintura << " / " << cadera << " / " << pecho << " / " << muslo << endl;
//    cout << "Recomendacion proteinas (g/dia aprox, si hace ejercicio/hombre): "
//        << calcularProteinas("M", true) << " (ejemplo)" << endl;

//    cout << "Cantidad vasos (250ml) recomendados: "<< calcularAgua() <<endl;
//}
