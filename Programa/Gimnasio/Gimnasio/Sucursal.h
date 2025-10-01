#pragma once
#define SUCURSAL_H

#include <iostream>
#include "Cliente.h"
#include "Instructor.h"
#include "ColeccionClientes.h"
using namespace std;

class Sucursal {
private:
    string codigo;
    string provincia;
    string canton;
    string correo;
    string telefono;

    ColeccionClientes* clientes;
    Instructor** instructores;
    int cantidadInstructores;
    int capacidadInstructores;

    // Para clases grupales (implementación simple para compilar)
    int* clasesIDs;
    string* clasesInstructorCedula;
    int cantidadClases;
    int maxClases;
    int maxInstructores;

public:
    // Constructor y destructor
    Sucursal(string codigo, string provincia, string canton, string correo, string telefono);
    ~Sucursal();

    // Getters y setters
    string getNombre() const;
    string getCodigo() const;
    string getProvincia() const;
    string getCanton() const;
    string getCorreo() const;
    string getTelefono() const;
    void setNombre(string nombre);
    void setCodigo(string codigo);
    void setProvincia(string provincia);
    void setCanton(string canton);
    void setCorreo(string correo);
    void setTelefono(string telefono);

    // Métodos
    void agregarInstructor(Instructor* inst);
    bool eliminarInstructor(const string& cedula);
    Instructor* buscarInstructor(string cedula);
    ColeccionClientes* getColeccionClientes() const;
    int getCantidadInstructores() const;

    // clases grupales (simplificado)
    void crearClaseGrupal(int idClase, const string& cedulaInstructor);
    void matricularClienteEnClase(int idClase, Cliente* cli);
};