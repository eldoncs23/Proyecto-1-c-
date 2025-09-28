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
	string comentario;
	double imc;

	// Composición corporal adicional
	double grasa;
	double musculo;
	int edadMetabolica;
	double cintura;
	double cadera;
	double pecho;
	double muslo;
public:
	Reporte(double peso, double altura, int edad, const string& sexo,
		bool ejercicio, const string& fecha = "");
	// Getters
	double getIMC() const;
	string getFecha() const;
	double getGrasa() const { return grasa; }
	double getMusculo() const { return musculo; }
	int getEdadMetabolica() const { return edadMetabolica; }
	double getCintura() const { return cintura; }
	double getCadera() const { return cadera; }
	double getPecho() const { return pecho; }
	double getMuslo() const { return muslo; }
	// Setters (solo lo esencial)
	void setFecha(const string& t) { fecha = t; }
	void setGrasa(double g) { grasa = g; }
	void setMusculo(double m) { musculo = m; }
	void setEdadMetabolica(int e) { edadMetabolica = e; }
	void setCintura(double c) { cintura = c; }
	void setCadera(double c) { cadera = c; }
	void setPecho(double p) { pecho = p; }
	void setMuslo(double m) { muslo = m; }
	// Métodos de cálculo
	double calcularProteinas() const;
	double calcularAgua() const;

	// Mostrar reporte completo
	void mostrarReporte() const;
	string setComentario(const string& c);
    string getComentario() const { return comentario; }
};

