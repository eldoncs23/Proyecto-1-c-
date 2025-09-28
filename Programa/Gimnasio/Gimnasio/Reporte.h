#pragma once
#define REPORTE_H
#include <string>
using namespace std;
class Reporte{
private:
	double peso;
	double altura;
	int edad;
	string sexo;
	bool haceEjercicio;
	string fecha;
	double imc;

public:
	Reporte(double peso, double altura, int edad, const string& sexo, bool ejercicio, string fecha);
	float calcularIMC();
	double calcularProteinas(string sexo, bool ejercicio);
	double calcularAgua();
	void mostrarReporte();
	string getFecha() { return fecha; }
	void setFecha(string& t) { fecha = t; }
	string getFecha() const;
	float getIMC() const;
};

