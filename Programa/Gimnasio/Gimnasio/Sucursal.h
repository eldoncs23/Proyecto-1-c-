#define SUCURSAL_H

#include <iostream>
#include "Cliente.h"
#include "Instructor.h"
#include "ColeccionClientes.h"
using namespace std;

class Sucursal {
private:
    string nombre;
    string codigo;
    string provincia;
    string canton;
    string correo;
    string telefono;

    ColeccionClientes* clientes;
    Instructor** instructores;
    int cantidadInstructores;
    //int capacidadInstructores;

public:
    // Constructor y destructor
    Sucursal();
    Sucursal(string nombre, string codigo, string provincia, string canton, string correo, string telefono);
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
    bool agregarInstructor(Instructor* inst);
    bool eliminarInstructorPorCedula(string cedula);
    Instructor* buscarInstructorPorCedula(string cedula);
    ColeccionClientes* getColeccionClientes() const;
    int getCantidadInstructores() const;
};