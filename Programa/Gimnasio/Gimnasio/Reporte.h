#pragma once
#define REPORTE_H
#include <string>
using namespace std;
class Reporte{
private:
	string fecha;
	float peso, estatura, grasa, musculo;
	int edadMetabolica;
	float cintura, cadera, pecho, muslo;
	float imc;

public:
	Reporte(string f, float p, float e);
	float calcularIMC();
	double calcularProteinas(string sexo, bool ejercicio);
	double calcularAgua();
	void mostrarReporte();
	string getFecha() { return fecha; }
	void setFecha(string& t) { fecha = t; }
	string getFecha() const;
	float getIMC() const;
};

