#pragma once
#include "Prerequisites.h"
#include "OxxoException.h"

class Proveedor {
private:
    std::string marca_;
    std::vector<std::string> productos_; // guardamos nombres para mantenerlo ligero

public:
    Proveedor() = default;
    explicit Proveedor(std::string marca) : marca_(std::move(marca)) {
        if (marca_.empty()) throw OxxoException("Marca de proveedor vacía.");
    }

    const std::string& marca() const { return marca_; }
    const std::vector<std::string>& listaProductos() const { return productos_; }

    void agregarProducto(const std::string& nombreProducto) {
        if (nombreProducto.empty()) throw OxxoException("Nombre de producto vacío.");
        if (std::find(productos_.begin(), productos_.end(), nombreProducto) == productos_.end())
            productos_.push_back(nombreProducto);
    }
};
