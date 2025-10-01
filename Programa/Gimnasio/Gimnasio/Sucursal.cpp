#include "Sucursal.h"

// Constructor por defecto
Sucursal::Sucursal(string codigo, string provincia, string canton, string correo, string telefono) {
    this->codigo = codigo;
    this->provincia = provincia;
    this->canton = canton;
    this->correo = correo;
    this->telefono = telefono;

    clientes = new ColeccionClientes();

    // Inicialización instructores
    maxInstructores = 50;
    cantidadInstructores = 0;
    instructores = new Instructor * [maxInstructores];
    for (int i = 0; i < maxInstructores; ++i)
        instructores[i] = nullptr;

    // Inicialización clases
    maxClases = 10;
    cantidadClases = 0;
    clases = new Clase * [maxClases];
    for (int i = 0; i < maxClases; ++i){
        clases[i] = nullptr;
    }
}

// Destructor
Sucursal::~Sucursal() {
    delete clientes;

    for (int i = 0; i < cantidadInstructores; ++i) {
        delete instructores[i];
    }
    delete[] instructores;

    for (int i = 0; i < cantidadClases; ++i) {
        delete clases[i];
    }
    delete[] clases;
}
// Getters

string Sucursal::getCodigo() const { return codigo; }
string Sucursal::getProvincia() const { return provincia; }
string Sucursal::getCanton() const { return canton; }
string Sucursal::getCorreo() const { return correo; }
string Sucursal::getTelefono() const { return telefono; }
ColeccionClientes* Sucursal::getColeccionClientes() const { return clientes; }
int Sucursal::getCantidadInstructores() const { return cantidadInstructores; }

// Setters

void Sucursal::setCodigo(string codigo) { this->codigo = codigo; }
void Sucursal::setProvincia(string provincia) { this->provincia = provincia; }
void Sucursal::setCanton(string canton) { this->canton = canton; }
void Sucursal::setCorreo(string correo) { this->correo = correo; }
void Sucursal::setTelefono(string telefono) { this->telefono = telefono; }

// Métodos
void Sucursal::agregarInstructor(Instructor* inst) {
    if (cantidadInstructores < maxInstructores) {
        instructores[cantidadInstructores++] = inst;
        cout << "Instructor agregado con cedula: [" << inst->getCedula() << "]" << endl;
    }
    else {
        cout << "No se pueden agregar más instructores a la sucursal." << endl;
    }
}

bool Sucursal::eliminarInstructor(const string& cedula) {
    for (int i = 0; i < cantidadInstructores; ++i) {
        if (instructores[i]->getCedula() == cedula) {
            delete instructores[i];
            for (int j = i; j < cantidadInstructores - 1; ++j) {
                instructores[j] = instructores[j + 1];
            }
            instructores[cantidadInstructores - 1] = nullptr;
            --cantidadInstructores;
            return true;
        }
    }
    return false;
}

Instructor* Sucursal::buscarInstructor(string cedula) {
    for (int i = 0; i < cantidadInstructores; ++i) {
        if (instructores[i]->getCedula() == cedula) {
            return instructores[i];
        }
    }
    return nullptr;
}

// Crear clase grupal
void Sucursal::crearClaseGrupal(int idClase, const string& cedulaInstructor,
    const string& nombreClase, int grupo) {

    Instructor* inst = buscarInstructor(cedulaInstructor);
    if (!inst) {
        cout << "Instructor no encontrado.\n";
        return;
    }
    if (!inst->tieneEspecialidad(idClase)) {
        cout << "El instructor no tiene la especialidad requerida para esta clase.\n";
        return;
    }
    if (cantidadClases >= maxClases) {
        cout << "No se pueden crear más clases grupales en esta sucursal, máximo alcanzado (10).\n";
        return;
    }

    Clase* nueva = new Clase(idClase, grupo, nombreClase, inst);
    clases[cantidadClases++] = nueva;

    cout << "Clase grupal '" << nombreClase << "' creada y asignada al instructor "
        << cedulaInstructor << ".\n";
}

Clase* Sucursal::buscarClasePorID(int idClase) const {
    for (int i = 0; i < cantidadClases; ++i) {
        if (clases[i]->getId() == idClase) {
            return clases[i];
        }
    }
    return nullptr;
}

// Matricular cliente en clase
void Sucursal::matricularClienteEnClase(int idClase, int grupo, Cliente* cli) {
    if (!cli) return;

    Clase* c = nullptr;
    for (int i = 0; i < cantidadClases; ++i) {
        if (clases[i]->getId() == idClase && clases[i]->getGrupo() == grupo) {
            c = clases[i];
            break;
        }
    }

    if (!c) {
        cout << "Clase no encontrada (ID o grupo incorrectos).\n";
        return;
    }

    if (!cli->puedeMatricular()) {
        cout << "El cliente ya tiene el máximo de 3 clases.\n";
        return;
    }

    c->agregarCliente(cli);
    cli->matricularClase(idClase);

    cout << "Cliente " << cli->getNombre() << " matriculado en clase "
        << idClase << " (Grupo " << grupo << ", Instructor: "
        << c->getInstructor()->getNombre() << ")\n";
}


bool Sucursal::verificarClasesInstructor(const string& cedulaInst) const {
    for (int i = 0; i < cantidadClases; ++i) {
        if (clases[i]->getInstructor()->getCedula() == cedulaInst) {
            return true;
        }
    }
    return false;
}
// Obtener clases de un instructor
int Sucursal::getClasesPorInstructor(const string& cedulaInst, Clase**& resultado) const {
    int count = 0;
    resultado = new Clase * [cantidadClases]; // reservar máximo posible
    for (int i = 0; i < cantidadClases; ++i) {
        if (clases[i]->getInstructor()->getCedula() == cedulaInst) {
            resultado[count++] = clases[i];
        }
    }
    return count;
}
void Sucursal::mostrarClases() const {
    if (cantidadClases == 0) {
        cout << "No hay clases registradas en la sucursal.\n";
        return;
    }

    for (int i = 0; i < cantidadClases; ++i) {
        Clase* c = clases[i];
        cout << "Clase ID: " << c->getId()
            << " | Grupo: " << (c->getGrupo() < 10 ? "0" : "") << c->getGrupo()
            << " | Nombre: " << c->getNombre() << "\n";
        cout << "Instructor: "
            << (c->getInstructor() ? c->getInstructor()->getNombre() : "N/A") << "\n";
        cout << "Clientes matriculados:\n";

        if (c->getCantidadClientes() == 0) {
            cout << " - Ninguno\n";
        }
        else {
            for (int j = 0; j < c->getCantidadClientes(); ++j) {
                Cliente* cli = c->getCliente(j);
                cout << " - " << cli->getNombre() << " | " << cli->getCedula() << "\n";
            }
        }
        cout << "------------------------\n";
    }
}

