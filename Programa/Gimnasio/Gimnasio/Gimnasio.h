#pragma once
#define GIMNASIO_H
#include "Sucursal.h"
using namespace std;
class Gimnasio{
private:
	string nombre;
	Sucursal** sucursales;
	int cantSucursales;
	int tam; //cantidad de sucursales
public:
	Gimnasio(string nombre);
	~Gimnasio();
	void agregarSucursal(Sucursal* s);
	void mostrarSucursales()const;
	Sucursal* buscarSucursal(string codigo);
	// getter
	string getNombre() const { return nombre; }
	int getCantSucursales() const { return cantSucursales; }
};

