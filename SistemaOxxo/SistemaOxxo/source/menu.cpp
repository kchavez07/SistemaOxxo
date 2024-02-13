#include "menu.h"
#include "sistema.h"
#include <iostream>
#include <borrarcliente.h>

using namespace std;

void Menu::mostrarMenu(Sistema& sistema) {
    int opcion;
    do {
        // Mostrar opciones del menú
        cout << "1. Registrar producto" << endl;
        cout << "2. Vender producto" << endl;
        cout << "3. Registrar proveedor" << endl;
        cout << "4. Registrar cliente" << endl;
        cout << "5. Eliminar cliente" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        // Realizar acciones según la opción seleccionada
        switch (opcion) {
        case 1: {
            // Lógica para registrar producto
            string nombreProducto;
            string cantidadProducto;
            // Captura de datos
            // ...
            producto nuevoProducto(nombreProducto, cantidadProducto);
            sistema.registrarproducto(nuevoProducto);
            cout << "Producto registrado con éxito." << endl;
            break;
        }
        case 2: {
            // Lógica para vender producto
            // ...
            cout << "Producto vendido con éxito." << endl;
            break;
        }
        case 3: {
            // Lógica para registrar proveedor
            string marcaProveedor;
            // Captura de datos
            // ...
            proveedor nuevoProveedor(marcaProveedor);
            sistema.registrarproveedor(nuevoProveedor);
            cout << "Proveedor registrado con éxito." << endl;
            break;
        }
        case 4: {
            // Lógica para registrar cliente
            string nombreCliente;
            string telefonoCliente;
            string correoCliente;
            int puntosCliente = 0;  

            // Captura de datos
  
            cliente nuevoCliente(nombreCliente, puntosCliente, telefonoCliente, correoCliente);
            sistema.registrarcliente(nuevoCliente);
            cout << "Cliente registrado con éxito." << endl;
            break;
        }

        case 5: {
            // Lógica para eliminar cliente
            string nombreCliente;
            string telefonoCliente;
            string correoCliente;

            // Captura de datos
            // ...
// Crear un objeto de tipo cliente usando los datos capturados
            cliente clienteAEliminar(nombreCliente, 0, telefonoCliente, correoCliente);

            // Llamar a la función borrarcliente con el objeto cliente
            sistema.borrarcliente(clienteAEliminar);
            cout << "Cliente eliminado con éxito." << endl;
            break;
        }

              
        }

    } while (opcion != 0);
}
