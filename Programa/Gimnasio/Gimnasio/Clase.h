#pragma once
#define CLASE_H
#include <iostream>
#include <string>
#include "Cliente.h"
#include "Sucursal.h"

using namespace std;
class Clase {
private:
    int id;
    int grupo; // 1..10
    string nombre;
    Instructor* instructor;
    Cliente** clientes; // punteros a clientes
    int cantidadClientes;

public:
    Clase(int id, int grupo, const string& nombre, Instructor* inst)
        : id(id), grupo(grupo), nombre(nombre), instructor(inst), cantidadClientes(0)
    {
        clientes = new Cliente * [50]; // máximo 50 clientes por clase
    }

    ~Clase() { delete[] clientes; }

    int getId() const { return id; }
    int getGrupo() const { return grupo; }
    string getNombre() const { return nombre; }
    Instructor* getInstructor() const { return instructor; }
    int getCantidadClientes() const { return cantidadClientes; }

    void agregarCliente(Cliente* c) {
        if (cantidadClientes < 50) clientes[cantidadClientes++] = c;
    }

    Cliente* getCliente(int index) const {
        if (index < 0 || index >= cantidadClientes) return nullptr;
        return clientes[index];
    }
};

