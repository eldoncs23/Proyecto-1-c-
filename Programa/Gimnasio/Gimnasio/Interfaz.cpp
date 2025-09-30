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
        cout << "10. Mostrar Rutina de un Cliente\n";
        cout << "11. Eliminar Cliente\n";
        cout << "12. Eliminar Instructor\n";
        cout << "13. Eliminar Sucursal\n";
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
        case 10: mostrarRutinaCliente(); break;
        case 11: eliminarCliente(); break;
        case 12: eliminarInstructor(); break;
        case 13: eliminarSucursal(); break;
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

    if (gimnasio->buscarSucursal(codigo)) {
        cout << "Ya existe una sucursal con ese código.\n";
        return;
    }

    Sucursal* s = new Sucursal(codigo, nombre, direccion);
    gimnasio->agregarSucursal(s);
    cout << "Sucursal agregada correctamente.\n";
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
    cout << "Instructor agregado correctamente.\n";
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
    cout << "Sexo (M/F): "; getline(cin, sexo);
    cout << "Fecha de inscripción (YYYY-MM-DD): "; getline(cin, fechaIns);

    Cliente* cli = new Cliente(nombre, cedula, telefono, correo, fechaNac, sexo, fechaIns);
    s->agregarCliente(cli);
    cout << "Cliente agregado correctamente.\n";
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

// Crear Reporte (llama al Instructor)
void Interfaz::crearReporte() {
    string codSucursal, cedInstructor, cedCliente;
    double peso, altura, grasa = 0, musculo = 0, cintura = 0, cadera = 0, pecho = 0, muslo = 0;
    int edad = 0, edadMet = 0;
    string sexo, comentario;
    bool haceEjercicio;
    char opcion;

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

    cout << "Desea ingresar mediciones opcionales? (s/n): "; cin >> opcion; cin.ignore();
    if (opcion == 's' || opcion == 'S') {
        cout << "Porcentaje grasa: "; cin >> grasa;
        cout << "Porcentaje musculo: "; cin >> musculo;
        cout << "Edad metabolica: "; cin >> edadMet;
        cout << "Medidas (cintura cadera pecho muslo): "; cin >> cintura >> cadera >> pecho >> muslo; cin.ignore();
        cout << "Comentario opcional del instructor (max 100 caracteres): "; getline(cin, comentario);
    }

    inst->crearReporte(cli, peso, altura, edad, sexo, haceEjercicio,
        grasa, musculo, edadMet, cintura, cadera, pecho, muslo, comentario);

    cout << "Reporte agregado correctamente.\n";
}

// Mostrar historial
void Interfaz::mostrarHistorialCliente() {
    string codSucursal, cedCliente;
    cout << "Código de la sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Cédula cliente: "; getline(cin, cedCliente);
    Cliente* cli = s->buscarCliente(cedCliente);
    if (!cli) { cout << "Cliente no encontrado.\n"; return; }

    cli->getHistorial()->mostrarHistorial();
}

// Crear Rutina
void Interfaz::crearRutinaCliente() {
    string codSucursal, cedCliente;
    cout << "Código sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Cédula cliente: "; getline(cin, cedCliente);
    Cliente* cli = s->buscarCliente(cedCliente);
    if (!cli) { cout << "Cliente no encontrado.\n"; return; }

    Instructor* inst = nullptr;
    if (s->getCantInstructores() > 0) inst = s->getInstructor(0);
    if (!inst) { cout << "No hay instructor disponible.\n"; return; }

    inst->crearRutina(cli);
    cout << "Rutina creada correctamente.\n";
}

// Mostrar Rutina
void Interfaz::mostrarRutinaCliente() {
    string codSucursal, cedCliente;
    cout << "Código sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Cédula cliente: "; getline(cin, cedCliente);
    Cliente* cli = s->buscarCliente(cedCliente);
    if (!cli) { cout << "Cliente no encontrado.\n"; return; }

    cli->mostrarRutina();
}

// Eliminar Cliente
void Interfaz::eliminarCliente() {
    string codSucursal, cedCliente;
    cout << "Código de la sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Cédula cliente a eliminar: "; getline(cin, cedCliente);
    if (s->eliminarCliente(cedCliente))
        cout << "Cliente eliminado correctamente.\n";
    else
        cout << "Cliente no encontrado.\n";
}

// Eliminar Instructor
void Interfaz::eliminarInstructor() {
    string codSucursal, cedInstructor;
    cout << "Código de la sucursal: "; getline(cin, codSucursal);
    Sucursal* s = gimnasio->buscarSucursal(codSucursal);
    if (!s) { cout << "Sucursal no encontrada.\n"; return; }

    cout << "Cédula instructor a eliminar: "; getline(cin, cedInstructor);
    if (s->eliminarInstructor(cedInstructor))
        cout << "Instructor eliminado correctamente.\n";
    else
        cout << "Instructor no encontrado.\n";
}

// Eliminar Sucursal
void Interfaz::eliminarSucursal() {
    string codSucursal;
    cout << "Código de la sucursal a eliminar: "; getline(cin, codSucursal);
    if (gimnasio->eliminarSucursal(codSucursal))
        cout << "Sucursal eliminada correctamente.\n";
    else
        cout << "Sucursal no encontrada.\n";
}


