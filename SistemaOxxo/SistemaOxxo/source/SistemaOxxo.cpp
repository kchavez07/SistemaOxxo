#include "SistemaOxxo.h"

// =====================
// CLIENTES
// =====================
void SistemaOxxo::registrarCliente(const Cliente& c) {
    const auto& key = c.nombre();

    if (clientes_.find(key) != clientes_.end()) {
        throw OxxoException("El cliente ya existe: " + key);
    }

    clientes_.emplace(key, c);
}

void SistemaOxxo::borrarClientePorNombre(const std::string& nombre) {
    if (clientes_.find(nombre) == clientes_.end()) {
        throw OxxoException("No existe el cliente: " + nombre);
    }
    clientes_.erase(nombre);
}

void SistemaOxxo::listarClientes() const {
    if (clientes_.empty()) {
        std::cout << "No hay clientes registrados.\n";
        return;
    }

    for (const auto& [_, c] : clientes_) {
        std::cout << "- " << c.nombre()
            << " | puntos: " << c.puntos()
            << " | tel: " << c.telefono()
            << " | correo: " << c.correo()
            << "\n";
    }
}

// =====================
// PROVEEDORES
// =====================
void SistemaOxxo::registrarProveedor(const Proveedor& p) {
    const auto& key = p.marca();

    if (proveedores_.find(key) != proveedores_.end()) {
        throw OxxoException("El proveedor ya existe: " + key);
    }

    proveedores_.emplace(key, p);
}

void SistemaOxxo::listarProveedores() const {
    if (proveedores_.empty()) {
        std::cout << "No hay proveedores registrados.\n";
        return;
    }

    for (const auto& [_, p] : proveedores_) {
        std::cout << "- " << p.marca()
            << " | productos: " << p.listaProductos().size()
            << "\n";
    }
}

// =====================
// PRODUCTOS
// =====================
void SistemaOxxo::registrarProducto(std::unique_ptr<Producto> p,
    const std::optional<std::string>& marcaProveedor) {
    if (!p) {
        throw OxxoException("Producto inválido (null).");
    }

    const std::string key = p->nombre();

    if (productos_.find(key) != productos_.end()) {
        throw OxxoException("El producto ya existe: " + key);
    }

    // Asignar producto al proveedor si se especificó marca
    if (marcaProveedor.has_value()) {
        auto itProv = proveedores_.find(*marcaProveedor);
        if (itProv == proveedores_.end()) {
            throw OxxoException("Proveedor no encontrado: " + *marcaProveedor);
        }
        itProv->second.agregarProducto(key);
    }

    productos_.emplace(key, std::move(p));
}

void SistemaOxxo::listarProductos() const {
    if (productos_.empty()) {
        std::cout << "No hay productos registrados.\n";
        return;
    }

    for (const auto& [_, p] : productos_) {
        std::cout << "- " << p->tipo()
            << " | " << p->nombre()
            << " | cant: " << p->cantidad()
            << " | precio: $" << p->precioFinal()
            << " | stock: " << p->stock()
            << "\n";
    }
}

// =====================
// VENTAS
// =====================
void SistemaOxxo::venderProducto(const std::string& nombreProducto,
    int cantidad,
    const std::optional<std::string>& cliente) {
    auto itProd = productos_.find(nombreProducto);
    if (itProd == productos_.end()) {
        throw OxxoException("Producto no encontrado: " + nombreProducto);
    }

    // Validar cliente si se mandó
    if (cliente.has_value()) {
        if (clientes_.find(*cliente) == clientes_.end()) {
            throw OxxoException("Cliente no encontrado: " + *cliente);
        }
    }

    Producto* p = itProd->second.get();
    p->disminuirStock(cantidad);

    const double total = p->precioFinal() * static_cast<double>(cantidad);

    std::cout << "Venta realizada: " << nombreProducto
        << " x" << cantidad
        << " | Total: $" << total << "\n";
}
