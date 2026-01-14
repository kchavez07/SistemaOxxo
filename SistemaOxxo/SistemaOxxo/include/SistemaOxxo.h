#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <optional>
#include <iostream>

#include "Cliente.h"
#include "Proveedor.h"
#include "Producto.h"
#include "OxxoException.h"

class SistemaOxxo {
private:
    std::unordered_map<std::string, Cliente> clientes_;
    std::unordered_map<std::string, Proveedor> proveedores_;
    std::unordered_map<std::string, std::unique_ptr<Producto>> productos_; // ✅ polimorfismo

public:
    // Clientes
    void registrarCliente(const Cliente& c);
    void borrarClientePorNombre(const std::string& nombre);
    void listarClientes() const;

    // Proveedores
    void registrarProveedor(const Proveedor& p);
    void listarProveedores() const;

    // Productos
    void registrarProducto(std::unique_ptr<Producto> p,
        const std::optional<std::string>& marcaProveedor = std::nullopt);
    void listarProductos() const;

    // Ventas
    void venderProducto(const std::string& nombreProducto,
        int cantidad,
        const std::optional<std::string>& cliente = std::nullopt);
};
