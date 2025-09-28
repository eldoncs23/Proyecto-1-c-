#include "Interfaz.h"
#include "Sucursal.h"
#include "Instructor.h"
#include "Cliente.h"
#include "Reporte.h"
#include "Sucursal.cpp"
#include "Instructor.cpp"
#include "Cliente.cpp"
#include "Reporte.cpp"
#include <iostream>
using namespace std;

Interfaz::Interfaz() {
    string a = "powerlab";
    gimnasio = new Gimnasio(a);
}

Interfaz::~Interfaz() {
    if (gimnasio) delete gimnasio;
}

void Interfaz::mostrarMenuPrincipal() {
    int opcion =0;
    do {
        cout << "\n===== MENU PRINCIPAL - GIMNASIO POWERLAB =====\n";
        cout << "1. Agregar sucursal\n";
        cout << "2. Mostrar sucursales\n";
        cout << "3. Agregar instructor a sucursal\n";
        cout << "4. Mostrar instructores de una sucursal\n";
        cout << "5. Asignar cliente a instructor\n";
        cout << "6. Mostrar historial de cliente\n";
        cout << "7. Crear reporte para cliente\n";
        cout << "8. Eliminar reporte de cliente\n";
        cout << "9. Vaciar historial de cliente\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string cod, prov, cant, corr, tel;
            cout << "Codigo: "; cin >> cod;
            cout << "Provincia: "; cin >> prov;
            cout << "Canton: "; cin >> cant;
            cout << "Correo: "; cin >> corr;
            cout << "Telefono: "; cin >> tel;
            gimnasio->agregarSucursal(new Sucursal(cod, prov, cant, corr, tel));
            break;
        }
        case 2: {
            gimnasio->mostrarSucursales();
            break;
        }
        case 3: {
            string cod;
            cout << "Ingrese codigo de sucursal: ";
            cin >> cod;
            Sucursal* s = gimnasio->buscarSucursal(cod);
            if (!s) {
                cout << "Sucursal no encontrada.\n";
                break;
            }
            string ced, nom, t, co, fNac;
            string* esp;
            int cantEsp;
            cout << "Cedula instructor: "; cin >> ced;
            cout << "Nombre instructor: "; cin >> nom;
            cout << "Correo instructor: "; cin >> co;
            cout << "Telefono instructor: "; cin >> t;
            cout << "Fecha de Nacimiento de instructor: "; cin >> fNac;
            cout << "Especialidad instructor: "; cin >> nom;
            cout << "Cantidad especialidades instructor: "; cin >> cantEsp;
            s->agregarInstructor(new Instructor(ced, nom, co, t, fNac, esp, cantEsp));
            break;
        }
        case 4: {
            string cod;
            cout << "Ingrese codigo de sucursal: ";
            cin >> cod;
            Sucursal* s = gimnasio->buscarSucursal(cod);
            if (!s) {
                cout << "Sucursal no encontrada.\n";
                break;
            }
            s->mostrarInstructores();
            break;
        }
        case 5: {
            string cod, cedInstructor, cedCliente, nomCliente;
            cout << "Codigo sucursal: "; cin >> cod;
            Sucursal* s = gimnasio->buscarSucursal(cod);
            if (!s) { cout << "Sucursal no encontrada.\n"; break; }

            cout << "Cedula del instructor: "; cin >> cedInstructor;
            // Buscar instructor en la sucursal
            Instructor* inst = s->buscarInstructor(cedInstructor);
            if (!inst) { cout << "Instructor no encontrado.\n"; break; }
            cout << "Cedula cliente: "; cin >> cedCliente;
            cout << "Nombre cliente: "; cin >> nomCliente;
            inst->asignarCliente(new Cliente(cedCliente, nomCliente));
            break;
        }
        case 6: {
            string cod, cedInstructor, cedCliente;
            cout << "Codigo sucursal: "; cin >> cod;
            Sucursal* s = gimnasio->buscarSucursal(cod);
            if (!s) { cout << "Sucursal no encontrada.\n"; break; }

            cout << "Cedula instructor: "; cin >> cedInstructor;
            
            break;
        }
        case 7: {
            string cod, cedInstructor, cedCliente, fecha;
            float peso, estatura;
            cout << "Codigo sucursal: "; cin >> cod;
            Sucursal* s = gimnasio->buscarSucursal(cod);
            
            break;
        }
        case 8: {
            string cod, cedInstructor, cedCliente;
            int idx;
            cout << "Codigo sucursal: "; cin >> cod;
            Sucursal* s = gimnasio->buscarSucursal(cod);
            if (!s) { cout << "Sucursal no encontrada.\n"; break; }

            cout << "Cedula instructor: "; cin >> cedInstructor;
           
            break;
        }
        case 9: {
            string cod, cedInstructor, cedCliente;
            cout << "Codigo sucursal: "; cin >> cod;
            Sucursal* s = gimnasio->buscarSucursal(cod);
           
            break;
        }
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

void Interfaz::menuSucursales() {
    cout << "[Aqui se gestiona sucursales]\n";
    // Llamará a metodos de Gimnasio
}

void Interfaz::menuInstructores(Sucursal* s) {
    cout << "[Aqui se gestionan instructores de la sucursal]\n";
    // Llamará a metodos de Sucursal
}

void Interfaz::menuClientes(Instructor* i) {
    cout << "[Aqui se gestionan clientes de un instructor]\n";
    // Llamará a metodos de Instructor
}