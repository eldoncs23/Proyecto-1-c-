#include "Interfaz.h"
#include <locale> //agregar caracteres
using namespace std;

int main() {
    setlocale(LC_ALL, ""); // arregla caracteres

    Gimnasio* gym = new Gimnasio("PowerLab");
    Interfaz interfaz(gym);
    interfaz.mostrarMenu();

    delete gym;
    return 0;
}
