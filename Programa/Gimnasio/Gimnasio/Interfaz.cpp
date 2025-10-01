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
        cout << "13. Mostrar rutina de cliente" << endl;
        cout << "14. Mostrar clases del instructor" << endl;
        cout << "15. Mostrar sucursal" << endl;
        cout << "16. Mostrar instructor" << endl;
        cout << "17. Mostrar cliente" << endl;

        cout << "18. Salir" << endl;
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
        case 13: mostrarRutinaCliente(); break;
        case 14: mostrarClases(); break;
        case 15: mostrarSucursal(); break;
        case 16: mostrarInstructor(); break;
        case 17: mostrarCliente(); break;
        case 18:  break;
        cout << "Saliendo del sistema..." << endl; break;
        default: cout << "Opcion invalida" << endl; break;
        }
    } while (opcion != 18);
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

    cout << "Especialidades y su código:" << endl;
    cout << "CrossFit  - 5001\nHIIT      - 5002\nTRX       - 5003\nPesas     - 5004\n";
    cout << "Spinning  - 5005\nCardio    - 5006\nYoga      - 5007\nZumba     - 5008\n";

    bool valido = false;
    do {
        cout << "Especialidad (5001-5008) o 0 para cancelar: ";
        cin >> especialidad;
        if (especialidad >= 5001 && especialidad <= 5008) {
            valido = true;
        }
        else if (especialidad == 0) {
            cout << "Creacion de instructor cancelada.\n";
            return;
        }
        else {
            cout << "Codigo invalido. Vuelva a ingresar.\n";
        }
    } while (!valido);

    string codSucursal;
    cout << "Codigo de sucursal: "; cin >> codSucursal;
    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada.\n"; return; }

    int* especialidadesArr = new int[1] { especialidad };
    Instructor* inst = new Instructor(cedula, nombre, telefono, correo, fechaNac, especialidadesArr, 1);
    suc->agregarInstructor(inst);
    cout << "Instructor agregado con exito a la sucursal!" << endl;
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
    string codSucursal, cedulaInst, nombreClase;
    int tipoClase, grupo;

    cout << "\n-- CREAR CLASE GRUPAL --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Tipo de clase (5001-5008): "; cin >> tipoClase;
    cout << "Cedula del instructor: "; cin >> cedulaInst;
    cout << "Nombre de la clase: "; cin.ignore(); getline(cin, nombreClase);
    cout << "Numero de grupo (1-10): "; cin >> grupo;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) {
        cout << "Sucursal no encontrada." << endl;
        return;
    }


    suc->crearClaseGrupal(tipoClase, cedulaInst, nombreClase, grupo);
}

void Interfaz::matricularClienteAClase() {
    string codSucursal, cedulaCli;
    int idClase, grupo;

    cout << "\n-- MATRICULAR CLIENTE A CLASE --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "ID clase grupal: "; cin >> idClase;
    cout << "Número de grupo a matricular: "; cin >> grupo;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Cliente* cli = suc->getColeccionClientes()->buscarCliente(cedulaCli);
    if (!cli) { cout << "Cliente no encontrado." << endl; return; }

    suc->matricularClienteEnClase(idClase,grupo, cli);
}
//agregar al menu
void Interfaz::mostrarRutinaCliente() {
    string codSucursal, cedulaCli;
    cout << "\n-- MOSTRAR RUTINA DEL CLIENTE --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Cliente* cli = suc->getColeccionClientes()->buscarCliente(cedulaCli);
    if (!cli) { cout << "Cliente no encontrado." << endl; return; }

    string rutina = cli->getRutinaActual();
    if (!cli->tieneRutina())
        cout << "El cliente no tiene ninguna rutina asignada.\n";
    else
        cout << "Rutina actual del cliente " << cli->getNombre() << ":\n" << rutina << endl;

    cout << "\nPresione ENTER para continuar...";
    cin.ignore(); // Ignorar el salto de línea pendiente
    cin.get();    // Esperar la tecla Enter
}

//mostrar clase opcion 15 del menu
void Interfaz::mostrarClases() {
    string codSucursal, cedulaInst;
    cout << "\n-- MOSTRAR CLASES DEL INSTRUCTOR --" << endl;
    cout << "Ingrese codigo de sucursal: "; cin >> codSucursal;
    cout << "Ingrese cedula del instructor: "; cin >> cedulaInst;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) {
        cout << "Sucursal no encontrada." << endl;
        return;
    }

    Instructor* inst = suc->buscarInstructor(cedulaInst);
    if (!inst) {
        cout << "Instructor no encontrado." << endl;
        return;
    }

    if (!suc->verificarClasesInstructor(cedulaInst)) {
        cout << "Este instructor no tiene clases asignadas en la sucursal.\n";
        return;
    }

    Clase** clasesInst;
    int cantidad = suc->getClasesPorInstructor(cedulaInst, clasesInst);

    cout << "\nClases del instructor " << inst->getNombre() << ":\n";
    for (int i = 0; i < cantidad; ++i) {
        Clase* c = clasesInst[i];
        cout << "Clase ID: " << c->getId()
            << " | Grupo: " << (c->getGrupo() < 10 ? "0" : "") << c->getGrupo()
            << " | Nombre: " << c->getNombre() << endl;

        if (c->getCantidadClientes() == 0) {
            cout << "  No hay clientes matriculados.\n";
        }
        else {
            cout << "  Clientes matriculados:\n";
            for (int j = 0; j < c->getCantidadClientes(); ++j) {
                Cliente* cli = c->getCliente(j);
                cout << "    - " << cli->getNombre()
                    << " | " << cli->getCedula() << endl;
            }
        }
        cout << "-----------------------------\n";
    }

    delete[] clasesInst; // liberar arreglo temporal
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void Interfaz::mostrarSucursal() {
    string codSucursal;
    cout << "\n-- MOSTRAR SUCURSAL --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    suc->mostrarInfo();
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void Interfaz::mostrarInstructor() {
    string codSucursal, cedulaInst;
    cout << "\n-- MOSTRAR INSTRUCTOR --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula instructor: "; cin >> cedulaInst;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Instructor* inst = suc->buscarInstructor(cedulaInst);
    if (!inst) { cout << "Instructor no encontrado." << endl; return; }

    inst->mostrarInfo();
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void Interfaz::mostrarCliente() {
    string codSucursal, cedulaCli;
    cout << "\n-- MOSTRAR CLIENTE --" << endl;
    cout << "Codigo sucursal: "; cin >> codSucursal;
    cout << "Cedula cliente: "; cin >> cedulaCli;

    Sucursal* suc = gimnasio->buscarSucursal(codSucursal);
    if (!suc) { cout << "Sucursal no encontrada." << endl; return; }

    Cliente* cli = suc->getColeccionClientes()->buscarCliente(cedulaCli);
    if (!cli) { cout << "Cliente no encontrado." << endl; return; }

    cli->mostrarInfo();
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}
