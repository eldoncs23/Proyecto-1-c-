#pragma once
#define SUCURSAL_h
#include "Instructor.h"
#include "Cliente.h"
#include <string>
using namespace std;

class Sucursal {
private:
	string codigo;
    string nombre;
	string direccion;
	Instructor** instructores;
	int cantInstructores;
	Cliente** clientes;
	int cantClientes;

public:
    // Constructor / Destructor
    Sucursal(string cod, string n, string dir);
    ~Sucursal();
    void mostrar() const;
    // Métodos de gestión de instructores
    void agregarInstructor(Instructor* inst);
    Instructor* buscarInstructor(const string& cedula) const;

    Instructor* getInstructor(int indice) const;
    void eliminarInstructor(const string& cedula);
    void listarInstructores() const;

    // Métodos de gestión de clientes
    Cliente* getCliente(int indice) const;
    int getCantidadClientes() const { return cantClientes; }
    void agregarCliente(Cliente* cli);
    Cliente* buscarCliente(const string& cedula) const;
    void eliminarCliente(const string& cedula);
    void listarClientes() const;
    
    // Getters
    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    string getDireccion() const { return direccion; }
    int getCantInstructores() const { return cantInstructores; }
    int getCantClientes() const { return cantClientes; }
};
