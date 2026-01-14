#include "borrarcliente.h"
#include <iostream>
#include <sistema.h>

using namespace std;

// En borrarcliente.cpp
void BorrarCliente::borrar(Sistema& sistema) {
    // Lógica para eliminar cliente
    string nombreCliente;
    // Captura de datos
    // ...

    cliente clienteAEliminar(nombreCliente);
    sistema.borrarcliente(clienteAEliminar);
    cout << "Cliente eliminado con éxito." << endl;
}

