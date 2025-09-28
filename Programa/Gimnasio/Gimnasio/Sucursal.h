#pragma once
#define SUCURSAL_h
#include "Instructor.h"
#include <string>
using namespace std;

class Sucursal {
private:
	string codigo;
	string provincia;
	string canton;
	string correo;
	string telefono;
	Instructor** instructores;
	int cantInstructores;
	int tam; //cantidad de instructores

public:
	Sucursal(string c, string p, string ca, string co, string t);
	~Sucursal();

	void agregarInstructor(Instructor* inst);
	void mostrar() const;
	void mostrarInstructores() const;
	Instructor* buscarInstructor(string cedula); // agregado

	string getCodigo() const { return codigo; }
	string getProvincia() const { return provincia; }
	string getCanton() const { return canton; }
	string getCorreo() const { return correo; }
	string getTelefono() const { return telefono; }
	int getCantInstructores() const { return cantInstructores; }
};
