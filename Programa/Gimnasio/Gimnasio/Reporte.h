#pragma once
#define REPORTE_H
#include <string>
using namespace std;

class Reporte {
private:
    double peso;
    double altura;
    int edad;
    string sexo;
    bool haceEjercicio;
    string fecha;
    double imc;

    // Composición corporal adicional
    double grasa;                 // porcentaje de grasa corporal
    double musculo;               // porcentaje de músculo
    int edadMetabolica;
    double grasaVisceral;         // % o índice según lo uses
    double cintura;
    double cadera;
    double pecho;
    double muslo;

    string comentario;            // comentario opcional del instructor

public:
    Reporte(double peso, double altura, int edad, const string& sexo, bool ejercicio,
        double grasa = 0.0, double musculo = 0.0, int edadMetabolica = 0,
        double grasaVisceral = 0.0, double cintura = 0.0, double cadera = 0.0,
        double pecho = 0.0, double muslo = 0.0, const string& fecha = "", const string& comentario = "");

    // Getters
    double getIMC() const;
    string getFecha() const;
    double getGrasa() const { return grasa; }
    double getMusculo() const { return musculo; }
    int getEdadMetabolica() const { return edadMetabolica; }
    double getGrasaVisceral() const { return grasaVisceral; }
    double getCintura() const { return cintura; }
    double getCadera() const { return cadera; }
    double getPecho() const { return pecho; }
    double getMuslo() const { return muslo; }
    string getComentario() const { return comentario; }

    // Setters
    void setFecha(const string& t) { fecha = t; }
    void setComentario(const string& c) { comentario = c.size() > 100 ? c.substr(0, 100) : c; }

    // Cálculos / utilidades
    double calcularProteinas() const;
    int calcularVasosAgua() const; // devuelve número de vasos de 250 ml
    string clasificarIMC() const;  // devuelve la categoría como string
    bool esAltoRiesgo() const;     // si IMC >= 30 (leve/medio/mórbida)

    // Mostrar
    void mostrarReporte() const;
};


