#include "Instructor.h"
#include "Cliente.h"
#include "Reporte.h"
#include <iostream>
using namespace std;

// Constructor
Instructor::Instructor(string nom, string ced, string tel, string corr, string fecha,
    string* esp, int cantEsp) {
    nombre = nom;
    cedula = ced;
    telefono = tel;
    correo = corr;
    fechaNacimiento = fecha;

    if (cantEsp > 0) {
        especialidades = new string[cantEsp];
        for (int i = 0; i < cantEsp; i++) especialidades[i] = esp[i];
        cantEspecialidades = cantEsp;
    }
    else {
        especialidades = nullptr;
        cantEspecialidades = 0;
    }

    clientesAsignados = nullptr;
    cantClientes = 0;
}

Instructor::~Instructor() {
    if (clientesAsignados) delete[] clientesAsignados;
    if (especialidades) delete[] especialidades;
}

void Instructor::mostrar() const {
    cout << "Instructor: " << nombre << " | Cedula: " << cedula
        << " | Telefono: " << telefono << " | Correo: " << correo
        << " | Fecha Nac: " << fechaNacimiento << endl;
    cout << "Especialidades: ";
    if (cantEspecialidades > 0) {
        for (int i = 0; i < cantEspecialidades; i++) {
            cout << especialidades[i];
            if (i < cantEspecialidades - 1) cout << ", ";
        }
    }
    else cout << "Ninguna";
    cout << endl;
}

string Instructor::toString() const {
    return "Instructor: " + nombre + " | Cedula: " + cedula + " | Telefono: " + telefono +
        " | Correo: " + correo + " | Fecha Nac: " + fechaNacimiento;
}

// Clientes
void Instructor::asignarCliente(Cliente* cli) {
    Cliente** nuevo = new Cliente * [cantClientes + 1];
    for (int i = 0; i < cantClientes; i++)
        nuevo[i] = clientesAsignados[i];
    nuevo[cantClientes] = cli;
    if (clientesAsignados) delete[] clientesAsignados;
    clientesAsignados = nuevo;
    cantClientes++;
}

Cliente* Instructor::buscarCliente(const string& ced) const {
    for (int i = 0; i < cantClientes; i++)
        if (clientesAsignados[i]->getCedula() == ced)
            return clientesAsignados[i];
    return nullptr;
}

// Historial
void Instructor::crearReporte(Cliente* cli, double peso, double altura, int edad,
    const string& sexo, bool haceEjercicio,
    double grasa, double musculo, int edadMet,
    double cintura, double cadera, double pecho, double muslo,
    const string& comentario) {
    if (!cli) return;
    Reporte* rep = new Reporte(peso, altura, edad, sexo, haceEjercicio);
    rep->setGrasa(grasa);
    rep->setMusculo(musculo);
    rep->setEdadMetabolica(edadMet);
    rep->setMedidas(cintura, cadera, pecho, muslo);
    rep->setComentario(comentario);

    cli->getHistorial()->agregarReporte(rep);
    cout << "Reporte agregado al historial de " << cli->getNombre() << ".\n";
}

void Instructor::eliminarReporteCliente(Cliente* cli, int pos) {
    if (!cli) return;
    cli->getHistorial()->eliminarReporte(pos);
}

void Instructor::vaciarHistorialCliente(Cliente* cli) {
    if (!cli) return;
    cli->getHistorial()->vaciarHistorial();
}

// Rutina
void Instructor::crearRutina(Cliente* cli) {
    if (!cli) return;
    Reporte* ult = cli->getHistorial()->getUltimoReporte();
    if (!ult) {
        cout << "No hay reportes para generar rutina.\n";
        return;
    }

    string* rutina = nullptr;
    int n = 3;
    double imc = ult->getIMC();

    if (imc < 18.5)
        rutina = new string[n]{ "Entrenamiento fuerza", "Rutina hipercalorica", "Cardio ligero" };
    else if (imc >= 18.5 && imc < 25)
        rutina = new string[n]{ "Rutina mantenimiento", "Cardio moderado", "Estiramientos" };
    else
        rutina = new string[n]{ "Cardio intenso", "Entrenamiento circuito", "Dieta hipocalorica" };

    cli->asignarRutina(rutina, n);
    delete[] rutina;
    cout << "Rutina creada y asignada al cliente " << cli->getNombre() << ".\n";
}

// Buscar instructor
Instructor* Instructor::buscarInstructor(const string& ced) const {
    if (cedula == ced) return (Instructor*)this;
    return nullptr;
}




