#pragma once
#define SUCURSAL_H

#include <iostream>
#include "Cliente.h"
#include "Instructor.h"
#include "ColeccionClientes.h"
#include "Clase.h"
using namespace std;

class Sucursal {
private:
    // Datos de identificación
    string codigo;
    string provincia;
    string canton;
    string correo;
    string telefono;

    // Clientes
    ColeccionClientes* clientes;

    // Instructores
    Instructor** instructores;
    int maxInstructores;
    int cantidadInstructores;

    // Clases
    Clase** clases;
    int cantidadClases;
    int maxClases;

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
    ColeccionClientes* getColeccionClientes() const;
    int getCantidadInstructores() const;

    void setNombre(string nombre);
    void setCodigo(string codigo);
    void setProvincia(string provincia);
    void setCanton(string canton);
    void setCorreo(string correo);
    void setTelefono(string telefono);

    //mostrar sucursal
    void mostrarInfo()const;
    // Metodos instructor
    void agregarInstructor(Instructor* inst);
    bool eliminarInstructor(const string& cedula);
    Instructor* buscarInstructor(string cedula);


    // clases grupales (simplificado)
    void crearClaseGrupal(int idClase, const string& cedulaInstructor,
        const string& nombreClase, int grupo);
    Clase* buscarClasePorID(int idClase) const;
    void matricularClienteEnClase(int idClase, int grupo, Cliente* cli);
    bool verificarClasesInstructor(const string& cedulaInst) const;
    int getClasesPorInstructor(const string& cedulaInst, Clase**& resultado) const;
    void mostrarClases() const;
};