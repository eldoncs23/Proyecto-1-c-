#define REPORTE_H
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Reporte {
private:
    string fecha;
    string nombreCliente;
    string cedulaCliente;
    string nombreInstructor;
    double peso;
    double estatura;
    double porcentajeGrasa;
    double porcentajeMusculo;
    double grasaVisceral;
    int edadMetabolica;
    double cintura, cadera, pecho, muslo;
    double imc;
    double proteinaDiaria;
    double vasosAgua;

public:
    // Constructores
    Reporte();
    Reporte(string fecha, string nombreCliente, string cedulaCliente, string nombreInstructor,
        double peso, double estatura, double porcentajeGrasa, double porcentajeMusculo,
        double grasaVisceral, int edadMetabolica, double cintura, double cadera,
        double pecho, double muslo);

    // Setters
    void setFecha(string fecha);
    void setNombreCliente(string nombreCliente);
    void setCedulaCliente(string cedulaCliente);
    void setNombreInstructor(string nombreInstructor);
    void setPeso(double peso);
    void setEstatura(double estatura);
    void setPorcentajeGrasa(double porcentajeGrasa);
    void setPorcentajeMusculo(double porcentajeMusculo);
    void setGrasaVisceral(double grasaVisceral);
    void setEdadMetabolica(int edadMetabolica);
    void setCintura(double cintura);
    void setCadera(double cadera);
    void setPecho(double pecho);
    void setMuslo(double muslo);

    // Getters
    string getFecha() const;
    string getNombreCliente() const;
    string getCedulaCliente() const;
    string getNombreInstructor() const;
    double getPeso() const;
    double getEstatura() const;
    double getPorcentajeGrasa() const;
    double getPorcentajeMusculo() const;
    double getGrasaVisceral() const;
    int getEdadMetabolica() const;
    double getCintura() const;
    double getCadera() const;
    double getPecho() const;
    double getMuslo() const;

    // Cálculos
    void calcularIMC();
    double getIMC() const;
    void calcularProteinaYAgua(string sexo, bool haceEjercicio);
    double getProteinaDiaria() const;
    double getVasosAgua() const;
};
