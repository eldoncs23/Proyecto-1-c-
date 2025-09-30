#pragma once
#include "Cliente.h"
#include "Historial.h"
#include <string>
using namespace std;

class Instructor {
private:
    string nombre;
    string cedula;
    string telefono;
    string correo;
    string fechaNacimiento;
    string* especialidades;
    int cantEspecialidades;

    // Clientes asignados
    Cliente** clientesAsignados;
    int cantClientes;

public:
    Instructor(string nom, string ced, string tel, string corr, string fecha,
        string* esp, int cantEsp);
    ~Instructor();

    void mostrar() const;
    string toString() const;

    // Gets
    string getCedula() const { return cedula; }
    string getNombre() const { return nombre; }
    int getCantClientes() const { return cantClientes; }

    // Sets
    void setNombre(const string& n) { nombre = n; }
    void setTelefono(const string& t) { telefono = t; }
    void setCorreo(const string& e) { correo = e; }
    void setFechaNacimiento(const string& f) { fechaNacimiento = f; }

    // Manejo de clientes
    void asignarCliente(Cliente* cli);
    Cliente* buscarCliente(const string& ced) const;
    Cliente** getClientesAsignados() const { return clientesAsignados; }

    // Manejo de historial
    void crearReporte(Cliente* cli, double peso, double altura, int edad,
        const string& sexo, bool haceEjercicio,
        double grasa = 0, double musculo = 0, int edadMet = 0,
        double cintura = 0, double cadera = 0, double pecho = 0, double muslo = 0,
        const string& comentario = "");

    void eliminarReporteCliente(Cliente* cli, int pos);
    void vaciarHistorialCliente(Cliente* cli);

    // Rutinas
    void crearRutina(Cliente* cli);

    // Buscar instructor
    Instructor* buscarInstructor(const string& ced) const;
};







