#include "Interfaz.h"

void Interfaz::menuPrincipal() {
    int opcion;
    do {
        cout << "\n=== MENÚ PRINCIPAL ===\n";
        cout << "1. Agregar Sucursal\n";
        cout << "2. Agregar Instructor\n";
        cout << "3. Agregar Cliente\n";
        cout << "4. Mostrar Sucursales\n";
        cout << "5. Mostrar Instructores de una Sucursal\n";
        cout << "6. Mostrar Clientes de una Sucursal\n";
        cout << "7. Crear Reporte para un Cliente\n";
        cout << "8. Mostrar Historial de un Cliente\n";
        cout << "9. Crear Rutina para un Cliente\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: agregarSucursal(); break;
        case 2: agregarInstructor(); break;
        case 3: agregarCliente(); break;
        case 4: mostrarSucursales(); break;
        case 5: mostrarInstructores(); break;
        case 6: mostrarClientes(); break;
        case 7: crearReporte(); break;
        case 8: mostrarHistorialCliente(); break;
        case 9: crearRutinaCliente(); break;
        case 0: cout << "Saliendo...\n"; break;
        default: cout << "Opción inválida\n"; break;
        }
    } while (opcion != 0);
}

// === MÉTODOS ===

void Interfaz::agregarSucursal() {
    string codigo, nombre, direccion;
    cout << "Código sucursal: "; getline(cin, codigo);
    cout << "Nombre sucursal: "; getline(cin, nombre);
    cout << "Dirección sucursal: "; getline(cin, direccion);
    Sucursal* s = new Sucursal(codigo, nombre, direccion);
    gimnasio->agregarSucursal(s);
    cout << "Sucursal agregada al gimnasio.\n";
}

void Interfaz::agregarInstructor() {
    string codSucursal, nombre, cedula, telefono, correo, fechaNac;
    int cantEsp;
    cout << "Código de la sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Nombre del instructor: "; getline(cin, nombre);
    cout << "Cédula: "; getline(cin, cedula);
    cout << "Teléfono: "; getline(cin, telefono);
    cout << "Correo: "; getline(cin, correo);
    cout << "Fecha de nacimiento (YYYY-MM-DD): "; getline(cin, fechaNac);
    cout << "Cantidad de especialidades: "; cin >> cantEsp; cin.ignore();
    string* esp = new string[cantEsp];
    for (int i = 0; i < cantEsp; i++) {
        cout << "Especialidad " << i + 1 << ": "; getline(cin, esp[i]);
    }

    Instructor* inst = new Instructor(nombre, cedula, telefono, correo, fechaNac, esp, cantEsp);
    s->agregarInstructor(inst);
    cout << "Instructor agregado a la sucursal.\n";
    delete[] esp;
}

void Interfaz::agregarCliente() {
    string codSucursal, nombre, cedula, telefono, correo, fechaNac, sexo, fechaIns;
    cout << "Código de la sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Nombre del cliente: "; getline(cin, nombre);
    cout << "Cédula: "; getline(cin, cedula);
    cout << "Teléfono: "; getline(cin, telefono);
    cout << "Correo: "; getline(cin, correo);
    cout << "Fecha de nacimiento (YYYY-MM-DD): "; getline(cin, fechaNac);
    cout << "Sexo: "; getline(cin, sexo);
    cout << "Fecha de inscripción (YYYY-MM-DD): "; getline(cin, fechaIns);

    Cliente* cli = new Cliente(nombre, cedula, telefono, correo, fechaNac, sexo, fechaIns);
    s->agregarCliente(cli);
    cout << "Cliente agregado a la sucursal.\n";
}

void Interfaz::mostrarSucursales() { gimnasio->mostrarSucursales(); }

void Interfaz::mostrarInstructores() {
    string codSucursal;
    cout << "Código de la sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }
    s->listarInstructores();
}

void Interfaz::mostrarClientes() {
    string codSucursal;
    cout << "Código de la sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }
    s->listarClientes();
}

void Interfaz::crearReporte() {
    string codSucursal, cedInstructor, cedCliente;
    double peso, altura; int edad; string sexo; bool haceEjercicio;
    cout << "Código sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Cédula instructor: "; getline(cin, cedInstructor);
    Instructor* inst = s->buscarInstructor(cedInstructor);
    if (!inst) { cout << "Instructor no encontrado.\n"; return; }

    cout << "Cédula cliente: "; getline(cin, cedCliente);
    Cliente* cli = s->buscarCliente(cedCliente);
    if (!cli) { cout << "Cliente no encontrado.\n"; return; }

    cout << "Peso (kg): "; cin >> peso;
    cout << "Altura (m): "; cin >> altura;
    cout << "Edad: "; cin >> edad; cin.ignore();
    cout << "Sexo (M/F): "; getline(cin, sexo);
    cout << "Hace ejercicio? (1=Sí, 0=No): "; cin >> haceEjercicio; cin.ignore();

    Reporte* rep = new Reporte(peso, altura, edad, sexo, haceEjercicio);
    inst->agregarReporteAHistorial(cli, rep);
    cout << "Reporte agregado al historial del cliente.\n";
}

void Interfaz::mostrarHistorialCliente() {
    string codSucursal, cedCliente;
    cout << "Código sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Cédula cliente: "; getline(cin, cedCliente);
    Cliente* cli = s->buscarCliente(cedCliente);
    if (!cli) { cout << "Cliente no encontrado.\n"; return; }

    cli->mostrarHistorial();
}

void Interfaz::crearRutinaCliente() {
    string codSucursal, cedCliente;
    cout << "Código sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Cédula cliente: "; getline(cin, cedCliente);
    Cliente* cli = s->buscarCliente(cedCliente);
    if (!cli) { cout << "Cliente no encontrado.\n"; return; }

    Instructor* inst = nullptr;
    // Buscar el instructor asignado (tomamos el primer instructor de la sucursal)
    if (s->getCantInstructores() > 0) inst = s->getInstructor(0);
    if (!inst) { cout << "No hay instructor disponible.\n"; return; }

    inst->crearRutina(cli);
    cout << "Rutina creada para el cliente.\n";
}
