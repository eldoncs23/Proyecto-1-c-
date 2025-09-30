#pragma once
#include "Instructor.h"
#include "ColeccionClientes.h"
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

    ColeccionClientes* clientes; // ahora usamos ColeccionClientes

public:
    Sucursal(const string& cod, const string& prov, const string& can, const string& corr, const string& tel);
    ~Sucursal();

    // Gestión de instructores
    void agregarInstructor(Instructor* inst);
    Instructor* buscarInstructor(const string& ced) const;
    void eliminarInstructor(const string& ced);
    void listarInstructores() const;

    // Gestión de clientes (delegamos a ColeccionClientes)
    void agregarCliente(Cliente* cli);
    Cliente* buscarCliente(const string& ced) const;
    void eliminarCliente(const string& ced);
    void listarClientes() const;

    // Getters
    int getCantInstructores() const { return cantInstructores; }
    Instructor* getInstructor(int index) const { return (index < cantInstructores) ? instructores[index] : nullptr; }
    ColeccionClientes* getClientes() const { return clientes; }
};
