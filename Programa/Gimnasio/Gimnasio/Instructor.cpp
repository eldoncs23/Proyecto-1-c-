#include "Instructor.h"
#include <iostream>
using namespace std;

//constructor
Instructor::Instructor(string c, string n){
    cedula = c;
    nombre = n;
    telefono = "";
    correo = "";
    fechaNacimiento = "";
    especialidades = nullptr;
    cantEspecialidades = 0;
    cantClientes = 0;
    tamClientes = 50; //el maximo establecido
    clientes = new Cliente * [tamClientes];
    for (int i = 0; i < tamClientes; ++i) clientes[i] = nullptr;
    
}

Instructor::~Instructor() {
    // El instructor es responsable de destruir a sus clientes asignados
    for (int i = 0; i < cantClientes; ++i) {
        if (clientes[i]) {
            delete clientes[i];
            clientes[i] = nullptr;
        }
    }
    delete[] clientes;

    if (especialidades) {
        delete[] especialidades;
        especialidades = nullptr;
    }
}

void Instructor::mostrar() const {
    cout << "Instructor: " << nombre << " | Cedula: " << cedula << "\n";
    cout << "Telefono: " << telefono << " | Correo: " << correo << " | Fecha Nac: " << fechaNacimiento << "\n";
    cout << "Cantidad de clientes asignados: " << cantClientes << "\n";
    cout << "Especialidades (" << cantEspecialidades << "): ";
    if (cantEspecialidades == 0) {
        cout << "Ninguna\n";
    }
    else {
        for (int i = 0; i < cantEspecialidades; ++i) {
            cout << especialidades[i];
            if (i < cantEspecialidades - 1) cout << ", ";
        }
        cout << "\n";
    }
}
string Instructor::toString() const {
    string info = "Instructor: " + nombre + " | Cedula: " + cedula +
        " | Telefono: " + telefono + " | Correo: " + correo +
        " | Fecha Nac: " + fechaNacimiento + "\nEspecialidades: ";
    if (cantEspecialidades == 0) {
        info += "Ninguna";
    }
    else {
        for (int i = 0; i < cantEspecialidades; ++i) {
            info += especialidades[i];
            if (i < cantEspecialidades - 1) info += ", ";
        }
    }
    return info;
}

//manejo de especialidades
void Instructor::setEspecialidades(const string* arr, int n) {
    if (especialidades) {
        delete[] especialidades;
        especialidades = nullptr;
        cantEspecialidades = 0;
    }
    if (n <= 0) return;
    especialidades = new string[n];
    for (int i = 0; i < n; ++i) especialidades[i] = arr[i];
    cantEspecialidades = n;
}

void Instructor::agregarEspecialidad(const string& esp) {
    if (especialidades == nullptr) {
        especialidades = new string[1];
        especialidades[0] = esp;
        cantEspecialidades = 1;
        return;
    }
    // ampliar arreglo
    string* nuevo = new string[cantEspecialidades + 1];
    for (int i = 0; i < cantEspecialidades; ++i) nuevo[i] = especialidades[i];
    nuevo[cantEspecialidades] = esp;
    delete[] especialidades;
    especialidades = nuevo;
    ++cantEspecialidades;
}

void Instructor::listarEspecialidades() const {
    if (cantEspecialidades == 0) {
        cout << "No tiene especialidades registradas.\n";
        return;
    }
    cout << "Especialidades:\n";
    for (int i = 0; i < cantEspecialidades; ++i) {
        cout << " - " << especialidades[i] << "\n";
    }
}

//manejo de clientes
void Instructor::asignarCliente(Cliente* cli) {
    if (cantClientes < tamClientes) {
        clientes[cantClientes++] = cli;
        cout << "Cliente asignado al instructor " << nombre << ".\n";
    }
    else {
        cout << "No se puede asignar cliente: maximo de clientes alcanzado.\n";
    }
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
    if (cantClientes < tamClientes) {
        clientes[cantClientes++] = cli;
        cout << "Cliente " << cli->getCedula() << " asignado al instructor " << nombre << ".\n";
    }
    else {
        cout << "No se puede asignar cliente: maximo de clientes alcanzado.\n";
    }
}

//buscar cliente
Cliente* Instructor::buscarCliente(string ced) { // buscar cliente por numero de cedula
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i]->getCedula() == ced) {
            return clientes[i];
        }
    }
    return nullptr;
}

//manejo de reportes
void Instructor::agregarReporteAHistorial(Cliente* c, Reporte* r) {
    if (!c) {
        cout << "No hay clientes.\n";
        delete r; // borrar reporte sin clientes asignados
        return;
    }

    // Si el historial no existe, reservar arreglo
    if (c->historial == nullptr) {
        c->historial = new Reporte * [c->maxReportes];
        for (int i = 0; i < c->maxReportes; ++i)
            c->historial[i] = nullptr;
            c->cantReportes = 0;
    }
    //si no hay 10 entonces ingresa reporte
    if (c->cantReportes < c->maxReportes) {
        c->historial[c->cantReportes++] = r;
        cout << "Reporte agregado al historial del cliente.\n";
    }
    else {
        //FIFO, primero en entrar primero en salir
        // Ya hay 10 reportes: preguntar si desea reemplazar el mas antiguo
        int opcion = 0;
        cout << "Se ha alcanzado el maximo de reportes en el historial (10).\n";
        cout << "Desea crear igualmente un nuevo reporte? (1 = Si, 2 = No): ";
        cin >> opcion;
        if (opcion == 1) {
            // borrar el reporte mas antiguo (pos 0)
            if (c->historial[0]) {
                delete c->historial[0];
            }
            // desplazar todo a la izquierda
            for (int i = 0; i < c->maxReportes - 1; ++i) {
                c->historial[i] = c->historial[i + 1];
            }
            c->historial[c->maxReportes - 1] = r; // nuevo al final
            cout << "Se reemplazo el reporte mas antiguo por el nuevo.\n";
        }
        else {
            cout << "No se agregó el nuevo reporte.\n";
            delete r; // como no se guarda, lo liberamos de la memoria
        }
    }
}

void Instructor::eliminarReporteDeHistorial(Cliente* c, int index) {
    if (!c || c->historial == nullptr) {
        cout << "Cliente o historial invalido.\n";
        return;
    }
    if (index < 0 || index >= c->cantReportes) {
        cout << "Indice de reporte invalido.\n";
        return;
    }

    if (c->historial[index]) {
        delete c->historial[index];
    }
    // compactar
    for (int i = index; i < c->cantReportes - 1; ++i) {
        c->historial[i] = c->historial[i + 1];
    }
    c->historial[c->cantReportes - 1] = nullptr;
    --c->cantReportes;

    // si ya no quedan reportes, liberar el arreglo y dejar en NULL
    if (c->cantReportes == 0) {
        delete[] c->historial;
        c->historial = nullptr;
    }

    cout << "Reporte eliminado del historial del cliente.\n";
}

void Instructor::vaciarHistorialCliente(Cliente* c) {
    if (!c || c->historial == nullptr) {
        cout << "Cliente o historial invalido (o ya vacio).\n";
        return;
    }
    for (int i = 0; i < c->cantReportes; ++i) {
        if (c->historial[i]) {
            delete c->historial[i];
            c->historial[i] = nullptr;
        }
    }
    delete[] c->historial;
    c->historial = nullptr;
    c->cantReportes = 0;
    cout << "Historial del cliente vaciado.\n";
}

void Instructor::crearRutina(Cliente* c, string rutina) {
    if (!c || c->historial == nullptr || c->cantReportes == 0) {
        cout << "No se puede crear rutina: cliente sin reportes.\n";
        return;
    }
    Reporte* ultimo = c->historial[c->cantReportes - 1];
    // ejemplo de decisión basada en el IMC del último reporte
    if (ultimo->getIMC() < 18.5) {
        cout << "Rutina para ganar masa muscular:\n";
        cout << "- Pesas 3x12\n- Cardio ligero 20 min\n- Estiramientos 10 min\n";
    }
    else if (ultimo->getIMC() >= 18.5 && ultimo->getIMC() <= 24.9) {
        cout << "Rutina para mantener forma:\n";
        cout << "- Pesas 2x15\n- Cardio 30 min\n- HIIT 15 min\n";
    }
    else {
        cout << "Rutina para reducir grasa corporal:\n";
        cout << "- Cardio 40 min\n- Circuito HIIT 20 min\n- Pesas 2x12\n";
    }
    cout << "Rutina generada: " << rutina << "\n";
}

