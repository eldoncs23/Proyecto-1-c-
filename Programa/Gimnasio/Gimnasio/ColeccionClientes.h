#define COLECCIONCLIENTES_H

#include <iostream>
#include "Cliente.h"
using namespace std;

class ColeccionClientes {
private:
    Cliente** clientes; // vector din�mico de clientes
    int cantidad;
    int capacidadMax;

public:
    // Constructor y destructor
    ColeccionClientes(int max = 50);
    ~ColeccionClientes();

    // M�todos
    bool agregarCliente(Cliente* cli);
    bool eliminarClientePorCedula(string cedula);
    Cliente* buscarClientePorCedula(string cedula);
    int getCantidadClientes() const;
};