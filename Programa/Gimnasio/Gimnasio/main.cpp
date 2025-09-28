#include <iostream>
#include "Sucursal.h"
#include "Instructor.h"
#include "Cliente.h"
#include "Reporte.h"

using namespace std;

int main() {
    cout << "===== PRUEBA DEL SISTEMA DE GIMNASIO =====\n";

    // 1) Crear sucursal
    Sucursal* suc = new Sucursal("5001","Sucursal Eldon", "Heredia, Central");
    cout << "Sucursal creada: S001 - Sucursal Eldon , Heredia Central\n\n";

    // 2) Crear instructor y agregarlo a la sucursal
    string esp[2] = { "Cardio", "Musculacion" };
    Instructor* inst = new Instructor("Carlos Perez", "123", "8888-9999", "carlos@mail.com", "1985-06-15", esp, 2);
    suc->agregarInstructor(inst);

    cout << "Instructor agregado:\n";
    inst->mostrar();
    cout << endl;

    // 3) Crear cliente con sexo y fecha de inscripción y agregarlo a la sucursal
    Cliente* cli = new Cliente("Ana Gomez", "456", "7777-5555", "ana@mail.com", "1990-01-20", "Femenino", "2025-09-28");
    suc->agregarCliente(cli);

    cout << "Cliente agregado:\n";
    cli->mostrar();
    cout << endl;

    // 4) Crear un reporte y asignarlo al cliente mediante el instructor
    Reporte* rep1 = new Reporte(65.0, 1.65, 35, "Femenino", true);
    cout << "Asignando reporte al cliente...\n";
    inst->agregarReporteAHistorial(cli, rep1);

    // 5) Mostrar historial del cliente
    cout << "\nHistorial del cliente tras agregar reporte:\n";
    cli->mostrarHistorial();

    // 6) Crear rutina dinámica basada en último reporte
    cout << "\nCreando rutina para cliente...\n";
    inst->crearRutina(cli);

    // 7) Mostrar rutina generada
    cout << "\nRutina generada:\n";
    cli->mostrarRutina();

    // 8) Probar eliminación de un reporte
    cout << "\nEliminando primer reporte del historial...\n";
    inst->eliminarReporteHistorial(cli, 0);

    cout << "Historial después de eliminar:\n";
    cli->mostrarHistorial();

    // 9) Agregar dos reportes más y vaciar historial
    cout << "\nAgregando dos reportes más...\n";
    inst->agregarReporteAHistorial(cli, new Reporte(80, 1.70, 30, "Femenino", false));
    inst->agregarReporteAHistorial(cli, new Reporte(75, 1.70, 30, "Femenino", true));

    cout << "\nHistorial actual:\n";
    cli->mostrarHistorial();

    cout << "\nVaciando historial...\n";
    inst->vaciarHistorial(cli);
    cli->mostrarHistorial();

    // 10) Limpieza
    delete suc; // Sucursal se encarga de borrar instructores y clientes

    cout << "\n===== FIN DE PRUEBA =====\n";
    return 0;
}
