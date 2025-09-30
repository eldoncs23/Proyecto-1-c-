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

    // Datos corporales
    double porcentajeGrasa;
    double porcentajeMusculo;
    int edadMetabolica;
    double cintura;
    double cadera;
    double pecho;
    double muslo;

    // Comentario opcional del instructor
    string comentario;

    void calcularIMC();

public:
    Reporte(double peso, double altura, int edad, const string& sexo, bool ejercicio);

    // Getters
    double getIMC() const { return imc; }
    string getFecha() const { return fecha; }
    string getComentario() const { return comentario; }

    // Setters
    void setFecha(const string& f) { fecha = f; }
    void setPorcentajeGrasa(double g) { porcentajeGrasa = g; }
    void setPorcentajeMusculo(double m) { porcentajeMusculo = m; }
    void setEdadMetabolica(int e) { edadMetabolica = e; }
    void setCintura(double c) { cintura = c; }
    void setCadera(double c) { cadera = c; }
    void setPecho(double p) { pecho = p; }
    void setMuslo(double m) { muslo = m; }
    void setComentario(const string& c) { comentario = c; }

    // Cálculos
    double calcularProteinas() const;
    double calcularAgua() const;

    // Mostrar
    void mostrarReporte() const;
};


