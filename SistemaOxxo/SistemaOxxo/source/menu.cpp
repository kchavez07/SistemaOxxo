#include "menu.h"
#include <iostream>

using namespace std;

void Menu::mostrarMenu(Sistema& sistema) {
    int opcion;
    do {
        // Mostrar opciones del men�
        cout << "1. Registrar producto" << endl;
        cout << "2. Vender producto" << endl;
        cout << "3. Registrar proveedor" << endl;
        cout << "4. Registrar cliente" << endl;
        cout << "5. Eliminar cliente" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opci�n: ";
        cin >> opcion;

        // Realizar acciones seg�n la opci�n seleccionada
        switch (opcion) {
        case 1: {
            // L�gica para registrar producto
            string nombreProducto;
            string cantidadProducto;
            // Captura de datos
            // ...
            producto nuevoProducto(nombreProducto, cantidadProducto);
            sistema.registrarproducto(nuevoProducto);
            cout << "Producto registrado con �xito." << endl;
            break;
        }
        case 2: {
            // L�gica para vender producto
            // ...
            cout << "Producto vendido con �xito." << endl;
            break;
        }
        case 3: {
            // L�gica para registrar proveedor
            string marcaProveedor;
            // Captura de datos
            // ...
            proveedor nuevoProveedor(marcaProveedor);
            sistema.registrarproveedor(nuevoProveedor);
            cout << "Proveedor registrado con �xito." << endl;
            break;
        }
        case 4: {
            // L�gica para registrar cliente
            string nombreCliente;
            string telefonoCliente;
            string correoCliente;
            // Captura de datos
            // ...
            cliente nuevoCliente(nombreCliente, telefonoCliente, correoCliente);
            sistema.registrarcliente(nuevoCliente);
            cout << "Cliente registrado con �xito." << endl;
            break;
        }
        case 5: {
            // L�gica para eliminar cliente
            string borrarcliente;
            // Captura de datos
            // ...
            sistema.borrarcliente(borrarcliente);
            cout << "Cliente eliminado con �xito." << endl;
            break;
        }
              // Agrega m�s casos seg�n sea necesario
        }

    } while (opcion != 0);
}
