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
    clientesAsignados = nullptr;
    cantClientes = 0;
    cantPecho = 3;
    ejerciciosPecho = new string[cantPecho]{ "Press banca", "Fondos", "Aperturas con mancuernas" };
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
//asignar cliente apunta a ellos no los elimina
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
    cout << "Desea agregar un comentario al reporte? (si/no): ";
    string resp;
    cin >> resp;
    cin.ignore(); // limpiar buffer
    if (resp == "si" || resp == "SI") {
        cout << "Ingrese comentario (max 100 caracteres): ";
        string com;
        getline(cin, com);
        rep->setComentario(com);
    }

    // Agregar al historial del cliente después de editar el comentario
    cli->agregarReporte(rep);

    // Mostrar el mismo reporte directamente
    rep->mostrarReporte();
}
void Instructor::eliminarReporteHistorial(Cliente* cli, int pos) {
    if (!cli) return;
    cli->eliminarReporte(pos);
}

void Instructor::vaciarHistorial(Cliente* cli) {
    if (!cli) return;
    cli->vaciarHistorial();
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

void Instructor::crearReporte(Cliente* cli,
    double peso, double altura, int edad, const string& sexo, bool haceEjercicio,
    double grasa, double musculo, int edadMetabolica,
    double grasaVisceral, double cintura, double cadera,
    double pecho, double muslo,
    const string& comentario) {
    if (!cli) {
        cout << "Cliente nulo.\n";
        return;
    }

    // crear el reporte (Instructor es responsable de crearlo)
    Reporte* rep = new Reporte(peso, altura, edad, sexo, haceEjercicio,
        grasa, musculo, edadMetabolica, grasaVisceral,
        cintura, cadera, pecho, muslo, "", comentario);

    // si el cliente ya tiene 10 reportes, preguntar si desea sobrescribir (reemplazar el más antiguo)
    int actuales = cli->getCantReportes();
    if (actuales < 10) {
        cli->agregarReporte(rep);
    }
    else {
        cout << "Se ha alcanzado el máximo de 10 reportes para este cliente.\n";
        cout << "Desea crear uno nuevo y eliminar el reporte más antiguo? (si/no): ";
        string resp; cin >> resp; cin.ignore();
        if (resp == "si" || resp == "SI") {
            // eliminar el mas antiguo (pos 0) y luego agregar nuevo
            cli->eliminarReporte(0);
            cli->agregarReporte(rep);
            cout << "Reporte agregado, el reporte más antiguo fue eliminado.\n";
        }
        else {
            // no deseado -> instructor decide eliminar el nuevo rep y no agregar
            delete rep;
            cout << "No se agregó el nuevo reporte.\n";
            return;
        }
    }

    // Mostrar el reporte que acaban de crear
    cout << "Reporte creado:\n";
    rep->mostrarReporte();
}