#include "Instructor.h"
#include "Reporte.h"
#include <iostream>
#include <sstream>
using namespace std;

// Constructor por defecto
Instructor::Instructor(string cedula, string nombre, string telefono, string correo,
    string fechaNacimiento, int* especialidades, int cantidadEspecialidades) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->telefono = telefono;
    this->correo = correo;
    this->fechaNacimiento = fechaNacimiento;

    this->cantidadEspecialidades = cantidadEspecialidades;
   
    this->especialidades = new int[cantidadEspecialidades];
    for (int i = 0; i < cantidadEspecialidades; i++) {
        this->especialidades[i] = especialidades[i];
    }

    cout << "DEBUG -> Instructor creado con cedula: " << this->cedula << endl;

    maxClientes = 50;
    clientesAsignados = new Cliente * [maxClientes];
    cantidadClientes = 0;
    for (int i = 0; i < maxClientes; ++i) clientesAsignados[i] = nullptr;
}

// Destructor
Instructor::~Instructor() {
    delete[] especialidades;
    delete[] clientesAsignados; // no elimina clientes (los gestiona la sucursal)
}

// Getters
string Instructor::getNombre() const { return nombre; }
string Instructor::getCedula() const { return cedula; }
int Instructor::getCantEspecialidades() const { return cantidadEspecialidades; }
int Instructor::getEspecialidad(int index) const {
    if (index < 0 || index >= cantidadEspecialidades) return -1;
    return especialidades[index];
}

// Setters
void Instructor::setNombre(string nombre) { this->nombre = nombre; }
void Instructor::setCedula(string cedula) { this->cedula = cedula; }
void Instructor::setTelefono(string telefono) { this->telefono = telefono; }
void Instructor::setCorreo(string correo) { this->correo = correo; }
void Instructor::setFechaNacimiento(string fecha) { this->fechaNacimiento = fecha; }
void Instructor::setEspecialidades(int* especialidades, int cantEsp) {
    delete[] this->especialidades;
    cantidadEspecialidades = cantEsp;
    if (cantEsp > 0) {
        this->especialidades = new int[cantEsp];
        for (int i = 0; i < cantEsp; i++)
            this->especialidades[i] = especialidades[i];
    }
    else {
        this->especialidades = nullptr;
    }
}

// Métodos
bool Instructor::tieneEspecialidad(int idEsp) {
    for (int i = 0; i < cantidadEspecialidades; i++) {
        if (especialidades[i] == idEsp) return true;
    }
    return false;
}

// Crear reporte y añadirlo al historial del cliente
bool Instructor::asignarCliente(Cliente* c) {
    if (!c) return false;
    if (cantidadClientes >= maxClientes) return false;
    clientesAsignados[cantidadClientes++] = c;
    return true;
}

void Instructor::crearReporteParaCliente(Cliente* c) {
    if (!c) return;
    double peso, estatura, pctGrasa, pctMusculo, grasaVisceral;
    int edadMetab;
    double cintura, cadera, pecho, muslo;
    int haceEjercicioInt;
    string fecha;

    cout << "Ingrese fecha medicion (YYYY-MM-DD): "; cin >> fecha;
    cout << "Peso (kg): "; cin >> peso;
    cout << "Estatura (m): "; cin >> estatura;
    cout << "Porcentaje grasa (%): "; cin >> pctGrasa;
    cout << "Porcentaje musculo (%): "; cin >> pctMusculo;
    cout << "Grasa visceral (%): "; cin >> grasaVisceral;
    cout << "Edad metabolica: "; cin >> edadMetab;
    cout << "Cintura (cm): "; cin >> cintura;
    cout << "Cadera (cm): "; cin >> cadera;
    cout << "Pecho (cm): "; cin >> pecho;
    cout << "Muslo (cm): "; cin >> muslo;
    cout << "Hace ejercicio? (1=si,0=no): "; cin >> haceEjercicioInt;

    Reporte* r = new Reporte(fecha, c->getNombre(), c->getCedula(), nombre,
        peso, estatura, pctGrasa, pctMusculo, grasaVisceral,
        edadMetab, cintura, cadera, pecho, muslo);
    r->calcularProteinaYAgua(c->getSexo(), haceEjercicioInt == 1);
    // opcional: pedir comentario
    cout << "Desea agregar comentario al reporte? (1=si,0=no): ";
    int resp; cin >> resp;
    if (resp == 1) {
        cin.ignore();
        string com;
        cout << "Ingrese comentario (max 100 chars): ";
        getline(cin, com);
        r->setComentario(com);
    }

    bool ok = c->getHistorial()->agregarReporte(r);
    if (!ok) {
        cout << "Historial lleno. Se debe decidir recircular o rechazar (no implementado automatico).\n";
        delete r;
    }
    else {
        cout << "Reporte agregado al historial del cliente " << c->getNombre() << ".\n";
    }
}
void Instructor::crearRutinaParaCliente(Cliente* c) {
    if (!c) return;
    // Intentamos basar la rutina en el ultimo IMC si existe
    Reporte* ult = c->getHistorial()->getUltimoReporte();
    string rutina;
    if (!ult) {
        rutina = "Rutina general: Cardio moderado, Estiramientos, Pesas ligeras";
    }
    else {
        double imc = ult->getIMC();
        if (imc < 18.5) rutina = "Entrenamiento fuerza, Alimentacion hipercalorica, Estiramientos";
        else if (imc < 25) rutina = "Rutina mantenimiento: Cardio moderado, Pesas, Estiramientos";
        else rutina = "Rutina perdida grasa: Cardio intenso, Circuito, Trabajo de fuerza moderado";
    }
    c->setRutinaActual(rutina);
    cout << "Rutina creada y asignada al cliente " << c->getNombre() << ".\n";
}

void Instructor::modificarRutinaDeCliente(Cliente* c) {
    if (!c) return;
    cin.ignore();
    string nueva;
    cout << "Ingrese la nueva rutina (texto): ";
    getline(cin, nueva);
    c->setRutinaActual(nueva);
    cout << "Rutina actualizada.\n";
}

void Instructor::mostrarInfo() const {
    cout << "\n--- Informacion de Instructor ---\n";
    cout << "Cedula: " << cedula << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Correo: " << correo << endl;
    cout << "Fecha Nacimiento: " << fechaNacimiento << endl;

    cout << "Especialidades: ";
    for (int i = 0; i < cantidadEspecialidades; i++) {
        cout << especialidades[i];
        if (i < cantidadEspecialidades - 1) cout << ", ";
    }
    cout << endl;
}

