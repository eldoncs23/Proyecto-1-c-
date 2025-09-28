#include <iostream>
#include "Gimnasio.h"
#include "Sucursal.h"
#include "Instructor.h"
#include "Cliente.h"
#include "Reporte.h"
#include <locale> //agregar caracteres
using namespace std;

int main() {
    setlocale(LC_ALL, ""); //arregla caracteres
    cout << "===== PRUEBA DEL SISTEMA DE GIMNASIO =====\n";

    // 1) Crear gimnasio
    Gimnasio* gym = new Gimnasio("PowerLab");
    cout << "Gimnasio creado: " << "PowerLab" << "\n\n";

    // 2) Crear sucursales y agregarlas al gimnasio
    Sucursal* suc1 = new Sucursal("5001","Sucursal tray", "Sucursal Central");
    Sucursal* suc2 = new Sucursal("S002","Sucursal eldon", "Sucursal Norte");
    gym->agregarSucursal(suc1);
    gym->agregarSucursal(suc2);

    cout << "Sucursales registradas:\n";
    gym->mostrarSucursales();
    cout << endl;

    // 3) Crear instructores y agregarlos a sucursales
    string esp1[2] = { "Cardio", "Musculacion" };
    Instructor* inst1 = new Instructor("Carlos Perez", "123", "8888-9999", "carlos@mail.com", "1985-06-15", esp1, 2);
    suc1->agregarInstructor(inst1);

    string esp2[3] = { "Yoga", "TRX", "Zumba" };
    Instructor* inst2 = new Instructor("Maria Lopez", "124", "7777-8888", "maria@mail.com", "1990-09-10", esp2, 3);
    suc2->agregarInstructor(inst2);

    // Listar instructores de cada sucursal
    cout << "\nInstructores en Sucursal Central:\n";
    suc1->listarInstructores();

    cout << "\nInstructores en Sucursal Norte:\n";
    suc2->listarInstructores();
    cout << endl;

    // 4) Crear clientes y agregarlos a sucursales
    Cliente* cli1 = new Cliente("Ana Gomez", "456", "7777-5555", "ana@mail.com", "1990-01-20", "Femenino", "2025-09-28");
    Cliente* cli2 = new Cliente("Juan Perez", "457", "6666-4444", "juan@mail.com", "1988-03-15", "Masculino", "2025-09-28");
    suc1->agregarCliente(cli1);
    suc2->agregarCliente(cli2);

    // Listar clientes
    cout << "Clientes en Sucursal Central:\n";
    suc1->listarClientes();
    cout << "\nClientes en Sucursal Norte:\n";
    suc2->listarClientes();
    cout << endl;

    // 5) Crear reportes y agregarlos al historial de clientes
    Reporte* rep1 = new Reporte(65.0, 1.65, 35, "Femenino", true);
    inst1->agregarReporteAHistorial(cli1, rep1);

    Reporte* rep2 = new Reporte(80.0, 1.75, 37, "Masculino", false);
    inst2->agregarReporteAHistorial(cli2, rep2);

    cout << "\nHistorial de Ana Gomez:\n";
    cli1->mostrarHistorial();

    cout << "\nHistorial de Juan Perez:\n";
    cli2->mostrarHistorial();

    // 6) Crear rutinas basadas en último reporte
    inst1->crearRutina(cli1);
    inst2->crearRutina(cli2);

    cout << "\nRutina de Ana Gomez:\n";
    cli1->mostrarRutina();

    cout << "\nRutina de Juan Perez:\n";
    cli2->mostrarRutina();

    // 7) Probar eliminar un reporte
    cout << "\nEliminando primer reporte de Ana Gomez...\n";
    inst1->eliminarReporteHistorial(cli1, 0);
    cli1->mostrarHistorial();

    // 8) Probar vaciar historial de Juan Perez
    cout << "\nVaciando historial de Juan Perez...\n";
    inst2->vaciarHistorial(cli2);
    cli2->mostrarHistorial();

    // 9) Mostrar todas las sucursales, instructores y clientes
    cout << "\n=== Estado final del gimnasio ===\n";
    gym->mostrarSucursales();
    for (int i = 0; i < 2; i++) {
        Sucursal* s = (i == 0 ? suc1 : suc2);
        cout << "\nInstructores en " << s->getNombre() << ":\n";
        s->listarInstructores();
        cout << "Clientes en " << s->getNombre() << ":\n";
        s->listarClientes();
    }

    // Limpieza: Sucursal destruye instructores y clientes
    delete gym;

    cout << "\n===== FIN DE PRUEBA =====\n";
    return 0;
}
