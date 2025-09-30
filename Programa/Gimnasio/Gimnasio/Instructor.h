#define INSTRUCTOR_H

#include <iostream>
#include "Cliente.h"
#include "Historial.h"
using namespace std;

class Instructor {
private:
    string nombre;
    string cedula;
    string telefono;
    string correo;
    string fechaNacimiento;
    int* especialidades; // vector dinámico de IDs de especialidades
    int cantEspecialidades;

public:
    // Constructor y destructor
    Instructor();
    Instructor(string nombre, string cedula, string telefono, string correo, string fechaNacimiento, int* especialidades, int cantEsp);
    ~Instructor();

    // Getters
    string getNombre() const;
    string getCedula() const;
    int getCantEspecialidades() const;
    int getEspecialidad(int index) const;

    // Setters
    void setNombre(string nombre);
    void setCedula(string cedula);
    void setTelefono(string telefono);
    void setCorreo(string correo);
    void setFechaNacimiento(string fecha);
    void setEspecialidades(int* especialidades, int cantEsp);

    // Métodos
    bool tieneEspecialidad(int idEsp);
    void crearReporte(Cliente* cli, string fecha, double peso, double estatura, double porcentajeGrasa, double porcentajeMusculo, double grasaVisceral, int edadMetabolica, double cintura, double cadera, double pecho, double muslo);
    void asignarRutina(Cliente* cli, string rutinaActual);
};