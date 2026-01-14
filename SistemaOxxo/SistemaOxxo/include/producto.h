#pragma once
#include "Prerequisites.h"
#include "OxxoException.h"

class Producto {
protected:
    std::string nombre_;
    double cantidad_{ 0.0 };  // kg o ml (según tipo)
    double precio_{ 0.0 };    // precio base
    int stock_{ 0 };          // unidades disponibles

public:
    Producto(std::string nombre, double cantidad, double precio, int stock)
        : nombre_(std::move(nombre)), cantidad_(cantidad), precio_(precio), stock_(stock) {
        validarBase();
    }

    virtual ~Producto() = default;

    const std::string& nombre() const { return nombre_; }
    double cantidad() const { return cantidad_; }
    double precio() const { return precio_; }
    int stock() const { return stock_; }

    void setStock(int s) {
        if (s < 0) throw OxxoException("Stock no puede ser negativo.");
        stock_ = s;
    }

    void disminuirStock(int n) {
        if (n <= 0) throw OxxoException("Cantidad a vender inválida.");
        if (n > stock_) throw OxxoException("Stock insuficiente.");
        stock_ -= n;
    }

    // Polimorfismo: cada tipo puede calcular su precio final distinto
    virtual double precioFinal() const = 0;
    virtual std::string tipo() const = 0;

    virtual std::string descripcion() const {
        return tipo() + " | " + nombre_ + " | cant: " + std::to_string(cantidad_) +
            " | precio: " + std::to_string(precioFinal()) + " | stock: " + std::to_string(stock_);
    }

protected:
    void validarBase() const {
        if (nombre_.empty()) throw OxxoException("Nombre de producto vacío.");
        if (cantidad_ <= 0.0) throw OxxoException("Cantidad inválida (debe ser > 0).");
        if (precio_ < 0.0) throw OxxoException("Precio inválido (no puede ser negativo).");
        if (stock_ < 0) throw OxxoException("Stock inválido (no puede ser negativo).");
    }
};
