#pragma once
#include "Producto.h"

class ProductoSnack : public Producto {
private:
    bool esImportado_{ false };

public:
    ProductoSnack(std::string nombre, double gramos, double precio, int stock, bool importado)
        : Producto(std::move(nombre), gramos, precio, stock), esImportado_(importado) {
    }

    double precioFinal() const override {
        // Ejemplo simple: importado +12%
        return esImportado_ ? precio_ * 1.12 : precio_;
    }

    std::string tipo() const override { return "Snack"; }
};
