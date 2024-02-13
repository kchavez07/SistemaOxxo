#include "agregarcliente.h"
#include <iostream>
#include "sistema.h"

using namespace std;

void AgregarCliente::agregar(Sistema& sistema) 
{
    // L�gica para registrar cliente
    string nombreCliente;
    string telefonoCliente;
    string correoCliente;
    int puntosCliente = 0;

    // Captura de datos
    cliente nuevoCliente(nombreCliente, puntosCliente, telefonoCliente, correoCliente);
    sistema.registrarcliente(nuevoCliente);
    cout << "Cliente registrado con �xito." << endl;
}
