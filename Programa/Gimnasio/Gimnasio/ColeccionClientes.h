#pragma once
#define COLECCIONCLIENTES_H

#include "Cliente.h"
using namespace std;

class ColeccionClientes {
private:
    Cliente** clientes;
    int cantidad;
    int capacidad;

public:
    ColeccionClientes(int max = 50);
    ~ColeccionClientes();

    bool agregarCliente(Cliente* cli);
    bool eliminarCliente(const string& cedula);   // nombre usado en interfaz
    Cliente* buscarCliente(const string& cedula); // nombre usado en interfaz
    int getCantidadClientes() const { return cantidad; }
};