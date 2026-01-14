#pragma once
#include "Producto.h"

class ProductoBebida : public Producto {
private:
    bool esAzucarada_{ false };

public:
    ProductoBebida(std::string nombre, double ml, double precio, int stock, bool azucarada)
        : Producto(std::move(nombre), ml, precio, stock), esAzucarada_(azucarada) {
    }

    double precioFinal() const override {
        // Ejemplo simple: bebidas azucaradas +8%
        return esAzucarada_ ? precio_ * 1.08 : precio_;
    }

    std::string tipo() const override { return "Bebida"; }
};
