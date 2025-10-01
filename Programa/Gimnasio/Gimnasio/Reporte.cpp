#include "Reporte.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Constructores
Reporte::Reporte() {
    fecha = "";
    nombreCliente = "";
    cedulaCliente = "";
    nombreInstructor = "";
    peso = estatura = porcentajeGrasa = porcentajeMusculo = grasaVisceral = 0;
    edadMetabolica = 0;
    cintura = cadera = pecho = muslo = 0;
    imc = proteinaDiaria = vasosAgua = 0;
    proteinaDiaria = 0.0;
    vasosAgua = 0;
    comentario = "";

}

Reporte::Reporte(string fecha, string nombreCliente, string cedulaCliente, string nombreInstructor,
    double peso, double estatura, double porcentajeGrasa, double porcentajeMusculo,
    double grasaVisceral, int edadMetabolica, double cintura, double cadera,
    double pecho, double muslo) {
    this->fecha = fecha;
    this->nombreCliente = nombreCliente;
    this->cedulaCliente = cedulaCliente;
    this->nombreInstructor = nombreInstructor;
    this->peso = peso;
    this->estatura = estatura;
    this->porcentajeGrasa = porcentajeGrasa;
    this->porcentajeMusculo = porcentajeMusculo;
    this->grasaVisceral = grasaVisceral;
    this->edadMetabolica = edadMetabolica;
    this->cintura = cintura;
    this->cadera = cadera;
    this->pecho = pecho;
    this->muslo = muslo;
    imc = proteinaDiaria = vasosAgua = 0;
    proteinaDiaria = 0.0;
    vasosAgua = 0;
    comentario = "";
    calcularIMC();
}

// Setters
void Reporte::setFecha(string fecha) { this->fecha = fecha; }
void Reporte::setNombreCliente(string nombreCliente) { this->nombreCliente = nombreCliente; }
void Reporte::setCedulaCliente(string cedulaCliente) { this->cedulaCliente = cedulaCliente; }
void Reporte::setNombreInstructor(string nombreInstructor) { this->nombreInstructor = nombreInstructor; }
void Reporte::setPeso(double peso) { this->peso = peso; }
void Reporte::setEstatura(double estatura) { this->estatura = estatura; }
void Reporte::setPorcentajeGrasa(double porcentajeGrasa) { this->porcentajeGrasa = porcentajeGrasa; }
void Reporte::setPorcentajeMusculo(double porcentajeMusculo) { this->porcentajeMusculo = porcentajeMusculo; }
void Reporte::setGrasaVisceral(double grasaVisceral) { this->grasaVisceral = grasaVisceral; }
void Reporte::setEdadMetabolica(int edadMetabolica) { this->edadMetabolica = edadMetabolica; }
void Reporte::setCintura(double cintura) { this->cintura = cintura; }
void Reporte::setCadera(double cadera) { this->cadera = cadera; }
void Reporte::setPecho(double pecho) { this->pecho = pecho; }
void Reporte::setMuslo(double muslo) { this->muslo = muslo; }

// Getters
string Reporte::getFecha() const { return fecha; }
string Reporte::getNombreCliente() const { return nombreCliente; }
string Reporte::getCedulaCliente() const { return cedulaCliente; }
string Reporte::getNombreInstructor() const { return nombreInstructor; }
double Reporte::getPeso() const { return peso; }
double Reporte::getEstatura() const { return estatura; }
double Reporte::getPorcentajeGrasa() const { return porcentajeGrasa; }
double Reporte::getPorcentajeMusculo() const { return porcentajeMusculo; }
double Reporte::getGrasaVisceral() const { return grasaVisceral; }
int Reporte::getEdadMetabolica() const { return edadMetabolica; }
double Reporte::getCintura() const { return cintura; }
double Reporte::getCadera() const { return cadera; }
double Reporte::getPecho() const { return pecho; }
double Reporte::getMuslo() const { return muslo; }

// Cálculos
void Reporte::calcularIMC() {
    if (estatura > 0.0)
        imc = peso / (estatura * estatura);
    else
        imc = 0.0;
}
double Reporte::getIMC() const { return imc; }

void Reporte::calcularProteinaYAgua(string sexo, bool haceEjercicio) {
    double factor = 0.8;
    if (haceEjercicio) {
        if (!sexo.empty() && (sexo[0] == 'M' || sexo[0] == 'm')) factor = 1.8; // ejemplo
        else factor = 1.7;
    }
    proteinaDiaria = peso * factor;
    // vasos de 250 ml = peso / 7 (redondeado)
    vasosAgua = static_cast<int>(ceil(peso / 7.0));
}

double Reporte::getProteinaDiaria() const { return proteinaDiaria; }
double Reporte::getVasosAgua() const { return vasosAgua; }

void Reporte::mostrarReporte() const {
    cout << "---- REPORTE ----\n";
    cout << "Fecha: " << fecha << "\n";
    cout << "Cliente: " << nombreCliente << " (ID: " << cedulaCliente << ")\n";
    cout << "Instructor: " << nombreInstructor << "\n";
    cout << fixed << setprecision(2);
    cout << "Peso: " << peso << " kg\n";
    cout << "Estatura: " << estatura << " m\n";
    cout << "IMC: " << imc << "\n";
    cout << "Porc. Grasa: " << porcentajeGrasa << "%\n";
    cout << "Porc. Musculo: " << porcentajeMusculo << "%\n";
    cout << "Grasa visceral: " << grasaVisceral << "%\n";
    cout << "Edad metabolica: " << edadMetabolica << "\n";
    cout << "Medidas (cintura/cadera/pecho/muslo): " << cintura << " / " << cadera << " / " << pecho << " / " << muslo << "\n";
    cout << "Proteina diaria aprox: " << proteinaDiaria << " g\n";
    cout << "Vasos 250ml recomendados: " << vasosAgua << "\n";
    if (!comentario.empty()) cout << "Comentario: " << comentario << "\n";
    cout << "-----------------\n";
}