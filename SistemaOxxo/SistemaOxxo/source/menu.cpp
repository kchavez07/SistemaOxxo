#include <memory>
#include <optional>
#include "Menu.h"
#include "Input.h"
#include "ProductoBebida.h"
#include "ProductoSnack.h"


void Menu::ejecutar() {
    while (true) {
        std::cout << "\n=== SISTEMA OXXO ===\n"
            << "1) Registrar cliente\n"
            << "2) Borrar cliente\n"
            << "3) Registrar proveedor\n"
            << "4) Registrar producto\n"
            << "5) Vender producto\n"
            << "6) Listar (clientes/proveedores/productos)\n"
            << "0) Salir\n";

        int op = Input::leerInt("Opción: ", 0, 6);

        try {
            switch (op) {
            case 1: opcionRegistrarCliente(); break;
            case 2: opcionBorrarCliente(); break;
            case 3: opcionRegistrarProveedor(); break;
            case 4: opcionRegistrarProducto(); break;
            case 5: opcionVenderProducto(); break;
            case 6: opcionListarTodo(); break;
            case 0: std::cout << "Saliendo...\n"; return;
            }
        }
        catch (const OxxoException& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Error inesperado: " << e.what() << "\n";
        }
    }
}

void Menu::opcionRegistrarCliente() {
    std::string nombre = Input::leerTexto("Nombre: ");
    std::string tel = Input::leerTexto("Teléfono: ");
    std::string correo = Input::leerTexto("Correo: ");
    int puntos = Input::leerInt("Puntos iniciales (0-100000): ", 0, 100000);

    sistema_.registrarCliente(Cliente(nombre, puntos, tel, correo));
    std::cout << "Cliente registrado.\n";
}

void Menu::opcionBorrarCliente() {
    std::string nombre = Input::leerTexto("Nombre del cliente a borrar: ");
    sistema_.borrarClientePorNombre(nombre);
    std::cout << "Cliente borrado.\n";
}

void Menu::opcionRegistrarProveedor() {
    std::string marca = Input::leerTexto("Marca del proveedor: ");
    sistema_.registrarProveedor(Proveedor(marca));
    std::cout << "Proveedor registrado.\n";
}

void Menu::opcionRegistrarProducto() {
    std::cout << "Tipo de producto:\n"
        << "1) Bebida\n"
        << "2) Snack\n";
    int tipo = Input::leerInt("Elige tipo: ", 1, 2);

    std::string nombre = Input::leerTexto("Nombre producto: ");
    double cantidad = Input::leerDouble("Cantidad (ml/gramos): ", 0.01);
    double precio = Input::leerDouble("Precio base: ", 0.0);
    int stock = Input::leerInt("Stock inicial (0-100000): ", 0, 100000);

    std::optional<std::string> proveedor = std::nullopt;
    if (Input::leerSiNo("¿Asignar a un proveedor existente?")) {
        std::string marca = Input::leerTexto("Marca proveedor: ");
        proveedor = marca;
    }

    if (tipo == 1) {
        bool azucarada = Input::leerSiNo("¿Es azucarada?");
        auto p = std::make_unique<ProductoBebida>(nombre, cantidad, precio, stock, azucarada);
        sistema_.registrarProducto(std::move(p), proveedor);
    }
    else {
        bool importado = Input::leerSiNo("¿Es importado?");
        auto p = std::make_unique<ProductoSnack>(nombre, cantidad, precio, stock, importado);
        sistema_.registrarProducto(std::move(p), proveedor);
    }

    std::cout << "Producto registrado.\n";
}

void Menu::opcionVenderProducto() {
    std::string prod = Input::leerTexto("Nombre producto a vender: ");
    int cant = Input::leerInt("Cantidad a vender: ", 1, 100000);

    std::optional<std::string> cliente = std::nullopt;
    if (Input::leerSiNo("¿Venta ligada a cliente?")) {
        std::string nombreCliente = Input::leerTexto("Nombre cliente: ");
        cliente = nombreCliente;
    }

    sistema_.venderProducto(prod, cant, cliente);
}

void Menu::opcionListarTodo() const {
    std::cout << "\n--- CLIENTES ---\n";
    sistema_.listarClientes();
    std::cout << "\n--- PROVEEDORES ---\n";
    sistema_.listarProveedores();
    std::cout << "\n--- PRODUCTOS ---\n";
    sistema_.listarProductos();
}
