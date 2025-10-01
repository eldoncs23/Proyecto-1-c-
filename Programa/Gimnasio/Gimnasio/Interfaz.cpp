/*
 * Proyecto 1 - Programación 1
 * Universidad Nacional de Costa Rica
 * Nombre del estudiante: Eldon Caldwell Salazar
 * Nombre del profesor: Legner
 * Fecha de entrega actualizada: 30/9/2025
 * Descripción: Este proyecto aborda los temas de programación 1 en C++,
 *              incluyendo memoria dinamica, punteros, colecciones, vectores dinamicos.
 */
#include "Interfaz.h"

Interfaz::Interfaz(Gimnasio* gym) {
    this->gimnasio = gym;
}

Interfaz::~Interfaz() {
    
}

// ========================
//   MENÚ PRINCIPAL
// ========================
void Interfaz::mostrarMenu() {
    int opcion = 0;
    do {
        cout << "\n===== MENU PRINCIPAL =====" << endl;
        cout << "1. Crear sucursal" << endl;
        cout << "2. Crear instructor" << endl;
        cout << "3. Asignar cliente a instructor" << endl;
        cout << "4. Crear reporte de cliente" << endl;
        cout << "5. Mostrar historial de cliente" << endl;
        cout << "6. Crear rutina de cliente" << endl;
        cout << "7. Modificar rutina de cliente" << endl;
        cout << "8. Eliminar rutina de cliente" << endl;
        cout << "9. Eliminar cliente" << endl;
        cout << "10. Eliminar instructor" << endl;
        cout << "11. Crear clase grupal" << endl;
        cout << "12. Matricular cliente a clase" << endl;
        cout << "13. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: agregarSucursal(); break;
        case 2: agregarInstructor(); break;
        case 3: asignarClienteAInstructor(); break;
        case 4: crearReporte(); break;
        case 5: mostrarHistorialCliente(); break;
        case 6: crearRutinaCliente(); break;
        case 7: modificarRutinaCliente(); break;
        case 8: eliminarRutinaCliente(); break;
        case 9: eliminarCliente(); break;
        case 10: eliminarInstructor(); break;
        case 11: crearClaseGrupal(); break;
        case 12: matricularClienteAClase(); break;
        case 13: cout << "Saliendo del sistema..." << endl; break;
        default: cout << "Opcion invalida" << endl; break;
        }
    } while (opcion != 13);
}

// ========================
//   METODOS DE OPERACION
// ========================

void Interfaz::agregarSucursal() {
    string codigo, provincia, canton, correo, telefono;

    cout << "\n-- CREAR SUCURSAL --" << endl;
    cout << "Codigo: "; cin >> codigo;
    cout << "Provincia: "; cin >> provincia;
    cout << "Canton: "; cin >> canton;
    cout << "Correo: "; cin >> correo;
    cout << "Telefono: "; cin >> telefono;

    gimnasio->agregarSucursal(new Sucursal(codigo, provincia, canton, correo, telefono));
    cout << "Sucursal creada con exito!" << endl;
}

void Interfaz::agregarInstructor() {
    string cedula, nombre, telefono, correo, fechaNac;
    int especialidad;

    cout << "\n-- CREAR INSTRUCTOR --" << endl;
    cout << "Cedula: "; cin >> cedula;
    cout << "Nombre completo: "; cin.ignore(); getline(cin, nombre);
    cout << "Telefono: "; cin >> telefono;
    cout << "Correo: "; cin >> correo;
    cout << "Fecha de nacimiento: "; cin >> fechaNac;
    cout << "Especialidades y su código: " << endl;
    cout << "CrossFit  - 5001" << endl;
    cout << "HIIT      - 5002" << endl;
    cout << "TRX       - 5003" << endl;
    cout << "Pesas     - 5004" << endl;
    cout << "Spinning  - 5005" << endl;
    cout << "Cardio    - 5006" << endl;
    cout << "Yoga      - 5007" << endl;
    cout << "Zumba     - 5008" << endl;
    cout << "Especialidad (5001-5008): "; cin >> especialidad;

    // pedimos sucursal
    string codSucursal;
    cout << "Codigo de sucursal: "; cin >> codSucursal;
    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (suc) {
        int* especialidades = new int[1];
            especialidades[0] = especialidad;
        Instructor* inst = new Instructor(cedula, nombre, telefono, correo, fechaNac, especialidades,1);
        suc->agregarInstructor(inst);
        cout << "Instructor agregado con exito a la sucursal!" << endl;
    }
    else {
        cout << "Sucursal no encontrada." << endl;
    }
}

void Interfaz::asignarClienteAInstructor() {
    string cedula, nombre, telefono, correo, fechaNac, sexo;
    string fechaInscripcion;
    string codSucursal, cedulaInst;

    cout << "\n-- ASIGNAR CLIENTE A INSTRUCTOR --" << endl;
    cout << "Codigo de sucursal: "; cin >> codSucursal;
    cout << "Cedula del instructor: ";
    cin.ignore();
    getline(cin, cedulaInst);
    //eliminar espacios
    cedulaInst.erase(0, cedulaInst.find_first_not_of(" \t\n\r"));
    cedulaInst.erase(cedulaInst.find_last_not_of(" \t\n\r") + 1);
    //
    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) {
        cout << "Sucursal no encontrada." << endl;
        return;
    }

    Instructor* inst = suc->buscarInstructor(cedulaInst);
    if (inst == nullptr) {
        cout << "Instructor no encontrado." << endl;
        return;
    }

    cout << "Cedula cliente: "; cin >> cedula;
    cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
    cout << "Telefono: "; cin >> telefono;
    cout << "Correo: "; cin >> correo;
    cout << "Fecha de nacimiento: "; cin >> fechaNac;
    cout << "Sexo: "; cin >> sexo;
    cout << "Fecha de inscripcion: "; cin >> fechaInscripcion;

    Cliente* cli = new Cliente(cedula, nombre, telefono, correo, fechaNac, sexo, fechaInscripcion);
    suc->getColeccionClientes()->agregarCliente(cli);
    inst->asignarCliente(cli);

    cout << "Cliente asignado correctamente!" << endl;
}

void Interfaz::crearReporte() {
    string codSucursal, cedulaInst, cedulaCli;
    cout << "\n-- CREAR REPORTE --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula instructor: "; cin >> cedulaInst;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Instructor* inst = suc->buscarInstructor(cedulaInst);
    if (!inst) { cout << "Instructor no encontrado." << endl; return; }

    Cliente* cli = suc->getColeccionClientes()->buscarCliente(cedulaCli);
    if (!cli) { cout << "Cliente no encontrado." << endl; return; }

    inst->crearReporteParaCliente(cli);
}

void Interfaz::mostrarHistorialCliente() {
    string codSucursal, cedulaCli;
    cout << "\n-- MOSTRAR HISTORIAL DE CLIENTE --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Cliente* cli = suc->getColeccionClientes()->buscarCliente(cedulaCli);
    if (!cli) { cout << "Cliente no encontrado." << endl; return; }

    cli->getHistorial()->mostrarReportes();
}

void Interfaz::crearRutinaCliente() {
    string codSucursal, cedulaInst, cedulaCli;
    cout << "\n-- CREAR RUTINA --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula instructor: "; cin >> cedulaInst;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Instructor* inst = suc->buscarInstructor(cedulaInst);
    if (!inst) { cout << "Instructor no encontrado." << endl; return; }

    Cliente* cli = suc->getColeccionClientes()->buscarCliente(cedulaCli);
    if (!cli) { cout << "Cliente no encontrado." << endl; return; }

    inst->crearRutinaParaCliente(cli);
}

void Interfaz::modificarRutinaCliente() {
    string codSucursal, cedulaInst, cedulaCli;
    cout << "\n-- MODIFICAR RUTINA --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula instructor: "; cin >> cedulaInst;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Instructor* inst = suc->buscarInstructor(cedulaInst);
    if (!inst) { cout << "Instructor no encontrado." << endl; return; }

    Cliente* cli = suc->getColeccionClientes()->buscarCliente(cedulaCli);
    if (!cli) { cout << "Cliente no encontrado." << endl; return; }

    inst->modificarRutinaDeCliente(cli);
}

void Interfaz::eliminarRutinaCliente() {
    string codSucursal, cedulaCli;
    cout << "\n-- ELIMINAR RUTINA --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Cliente* cli = suc->getColeccionClientes()->buscarCliente(cedulaCli);
    if (!cli) { cout << "Cliente no encontrado." << endl; return; }

    cli->setRutinaActual("");
    cout << "Rutina eliminada correctamente." << endl;
}

void Interfaz::eliminarCliente() {
    string codSucursal, cedulaCli;
    cout << "\n-- ELIMINAR CLIENTE --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    if (suc->getColeccionClientes()->eliminarCliente(cedulaCli)) {
        cout << "Cliente eliminado correctamente." << endl;
    }
    else {
        cout << "Cliente no encontrado." << endl;
    }
}

void Interfaz::eliminarInstructor() {
    string codSucursal, cedulaInst;
    cout << "\n-- ELIMINAR INSTRUCTOR --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula instructor: "; cin >> cedulaInst;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    if (suc->eliminarInstructor(cedulaInst)) {
        cout << "Instructor eliminado correctamente." << endl;
    }
    else {
        cout << "Instructor no encontrado." << endl;
    }
}

void Interfaz::crearClaseGrupal() {
    string codSucursal;
    int tipo;
    string cedulaInst;

    cout << "\n-- CREAR CLASE GRUPAL --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Tipo de clase (5001-5008): "; cin >> tipo;
    cout << "Cedula del instructor: "; cin >> cedulaInst;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    suc->crearClaseGrupal(tipo, cedulaInst);
}

void Interfaz::matricularClienteAClase() {
    string codSucursal, cedulaCli;
    int idClase;

    cout << "\n-- MATRICULAR CLIENTE A CLASE --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "ID clase grupal: "; cin >> idClase;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Cliente* cli = suc->getColeccionClientes()->buscarCliente(cedulaCli);
    if (!cli) { cout << "Cliente no encontrado." << endl; return; }

    suc->matricularClienteEnClase(idClase, cli);
}

