#pragma once
#include "Cliente.h"
#include <iostream>
using namespace std;

class ColeccionClientes {
private:
    Cliente** clientes;
    int cantClientes;

public:
    ColeccionClientes();
    ~ColeccionClientes();

    bool agregarCliente(Cliente* cli);
    bool eliminarCliente(const string& cedula);
    Cliente* buscarCliente(const string& cedula) const;

    void mostrarClientes() const;

    // Rutinas
    bool asignarRutina(Cliente* cli, string* ejercicios, int n);
};




