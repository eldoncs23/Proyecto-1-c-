#include "Instructor.h"
#include "Reporte.h"
#include "Cliente.h"
#include <iostream>
using namespace std;

//constructor
Instructor::Instructor(string nom, string ced, string tel, string corr, string fecha,
    string* esp, int cantEsp){
    nombre = nom;
    cedula = ced;
    telefono = tel;
    correo = corr;
    fechaNacimiento = fecha;
    especialidades = esp;
    cantEspecialidades = cantEsp;

    clientesAsignados = nullptr;
    cantClientes = 0;

    if (cantEsp > 0) {
        especialidades = new string[cantEsp];
        for (int i = 0; i < cantEsp; i++)
            especialidades[i] = esp[i];
        cantEspecialidades = cantEsp;
    }
    else {
        especialidades = nullptr;
        cantEspecialidades = 0;
    }
}

Instructor::~Instructor() { 
    //destructor de instructor
    // El instructor no es responsable de destruir a sus clientes asignados, historial, esp
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
    else {
        cout << "Ninguna";
    }
    cout << endl;
}

string Instructor::toString() const {
    string s = "Instructor: " + nombre + " | Cedula: " + cedula +
        " | Telefono: " + telefono + " | Correo: " + correo +
        " | Fecha Nac: " + fechaNacimiento;
   
    return s;
}


//manejo de especialidades
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
    for (int i = 0; i < cantClientes; i++) {
        if (clientesAsignados[i]->getCedula() == ced)
            return clientesAsignados[i];
    }
    return nullptr;
}


//manejo de reportes
void Instructor::agregarReporteAHistorial(Cliente* cli, Reporte* rep) {
    cli->agregarReporte(rep); // delega al cliente
    // También podemos almacenar en historial del instructor si queremos duplicar
}

void Instructor::eliminarReporteHistorial(int index) {
    if (index < 0 || index >= cantReportes) return;

    delete historial[index];
    for (int i = index + 1; i < cantReportes; i++)
        historial[i - 1] = historial[i];
    cantReportes--;

    if (cantReportes == 0) {
        delete[] historial;
        historial = nullptr;
    }
}

void Instructor::vaciarHistorial() {
    if (historial) {
        for (int i = 0; i < cantReportes; i++)
            delete historial[i];
        delete[] historial;
        historial = nullptr;
        cantReportes = 0;
    }
}

//Manejo de rutinas
void Instructor::crearRutina(Cliente* cli) {
    if (!cli) return;
    Reporte* ult = cli->getUltimoReporte();
    if (!ult) {
        cout << "No hay reportes para generar rutina.\n";
        return;
    }

    string* rutina = nullptr;
    int n = 0;

    double imc = ult->getIMC();
    if (imc < 18.5) {
        n = 3;
        rutina = new string[n]{ "Entrenamiento fuerza", "Rutina hipercalorica", "Cardio ligero" };
    }
    else if (imc >= 18.5 && imc < 25) {
        n = 3;
        rutina = new string[n]{ "Rutina mantenimiento", "Cardio moderado", "Estiramientos" };
    }
    else {
        n = 3;
        rutina = new string[n]{ "Cardio intenso", "Entrenamiento circuito", "Dieta hipocalorica" };
    }

    cli->asignarRutina(rutina, n);
    delete[] rutina;

    cout << "Rutina creada y asignada al cliente " << cli->getNombre() << ".\n";
}

// BUSCAR INSTRUCTOR
Instructor* Instructor::buscarInstructor(const string& ced) const {
    if (cedula == ced) return (Instructor*)this;
    return nullptr;
}
