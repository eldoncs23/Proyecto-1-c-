#include "Instructor.h"
#include <iostream>
using namespace std;

//constructor
Instructor::Instructor(string c, string n, string t, string co, string fNac,
    string* esp, int cantEsp){
    cedula = c;
    nombre = n;
    telefono = t;
    correo = co;
    fechaNacimiento = fNac;
    if (cantEsp > 0 && esp != nullptr) {
        cantEspecialidades = cantEsp;
        especialidades = new string[cantEsp];
        for (int i = 0; i < cantEsp; i++) {
            especialidades[i] = esp[i];
        }
    }
    else {
        cantEspecialidades = 0;
        especialidades = nullptr;
    }

    clientes = nullptr;
    cantClientes = 0;

    historial = nullptr;
    cantReportes = 0;
    
}

Instructor::~Instructor() { 
    //destructor de instructor
    // El instructor es responsable de destruir a sus clientes asignados, historial, esp
    if (especialidades) delete[] especialidades;

    if (clientes) {
        for (int i = 0; i < cantClientes; i++)
            delete clientes[i];
        delete[] clientes;
    }

    if (historial) {
        for (int i = 0; i < cantReportes; i++)
            delete historial[i];
        delete[] historial;
    }
}

void Instructor::mostrar() const {
    cout << "Instructor: " << nombre
        << " | Cedula: " << cedula
        << " | Telefono: " << telefono
        << " | Correo: " << correo
        << " | Fecha Nac.: " << fechaNacimiento
        << endl;

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
void Instructor::setEspecialidades(string* esp, int cant) {
    if (especialidades) delete[] especialidades;

    if (cant > 0 && esp != nullptr) {
        cantEspecialidades = cant;
        especialidades = new string[cant];
        for (int i = 0; i < cant; i++)
            especialidades[i] = esp[i];
    }
    else {
        cantEspecialidades = 0;
        especialidades = nullptr;
    }
}

//manejo de clientes
void Instructor::asignarCliente(Cliente* c) {
    Cliente** nuevo = new Cliente * [cantClientes + 1];
    for (int i = 0; i < cantClientes; i++)
        nuevo[i] = clientes[i];
    nuevo[cantClientes] = c;

    if (clientes) delete[] clientes;
    clientes = nuevo;
    cantClientes++;
}

Cliente* Instructor::buscarCliente(const string& ced) const {
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i]->getCedula() == ced)
            return clientes[i];
    }
    return nullptr;
}
void Instructor::despedirCliente(int index) {
    if (index < 0 || index >= cantClientes) {
        cout << "Indice de cliente invalido.\n";
        return;
    }
    if (clientes[index]) {
        delete clientes[index];
        // compactar el arreglo
        for (int i = index; i < cantClientes - 1; ++i) {
            clientes[i] = clientes[i + 1];
        }
        clientes[cantClientes - 1] = nullptr;
        --cantClientes;
        cout << "Cliente eliminado correctamente.\n";
    }
}

void Instructor::asignarCliente(Cliente* cli) {
    Cliente** nuevo = new Cliente * [cantClientes + 1];
    for (int i = 0; i < cantClientes; i++)
        nuevo[i] = clientes[i];
    nuevo[cantClientes] = cli;

    if (clientes) delete[] clientes;
    clientes = nuevo;
    cantClientes++;
}

//buscar cliente
Cliente* Instructor::buscarCliente(const string& ced) const{ // buscar cliente por numero de cedula
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i]->getCedula() == ced) {
            return clientes[i];
        }
    }
    return nullptr;
}

//manejo de reportes
void Instructor::agregarReporteAHistorial(Reporte* r) {
    if (cantReportes < 10) {
        Reporte** nuevo = new Reporte * [cantReportes + 1];
        for (int i = 0; i < cantReportes; i++)
            nuevo[i] = historial[i];
        nuevo[cantReportes] = r;

        if (historial) delete[] historial;
        historial = nuevo;
        cantReportes++;
    }
    else {
        // desplazar: eliminar el más viejo (posición 0)
        delete historial[0];
        for (int i = 1; i < cantReportes; i++)
            historial[i - 1] = historial[i];
        historial[cantReportes - 1] = r;
    }
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
void Instructor::crearRutina(Cliente* cli, const string& nombreRutina) {
    if (!cli) {
        cout << "Cliente invalido.\n";
        return;
    }

    // Usamos el último reporte del historial del cliente
    Reporte** hist = cli->getHistorial();
    int cant = cli->getCantReportes();

    if (!hist || cant == 0) {
        cout << "El cliente no tiene reportes.\n";
        return;
    }

    Reporte* ult = hist[cant - 1];

    // Generar rutina basada en IMC y peso
    string* ejercicios = nullptr;
    int n = 0;

    if (ult->getIMC() < 18.5) {
        n = 3;
        ejercicios = new string[n]{ "Pesas básicas", "Alimentación hipercalórica", "Descanso activo" };
    }
    else if (ult->getIMC() >= 18.5 && ult->getIMC() < 25) {
        n = 3;
        ejercicios = new string[n]{ "Cardio moderado", "Pesas intermedias", "Flexibilidad" };
    }
    else {
        n = 3;
        ejercicios = new string[n]{ "Cardio intenso", "Circuito HIIT", "Dieta balanceada" };
    }

    cli->asignarRutina(ejercicios, n);

    cout << "Rutina \"" << nombreRutina << "\" asignada al cliente " << cli->getNombre() << ".\n";

    delete[] ejercicios; // liberamos temporal
}

// BUSCAR INSTRUCTOR
Instructor* Instructor::buscarInstructor(const string& ced) const {
    if (cedula == ced) return (Instructor*)this;
    return nullptr;
}
