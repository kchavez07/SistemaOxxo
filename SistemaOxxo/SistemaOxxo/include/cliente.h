#pragma once
#include <string>
#include "OxxoException.h"

class Cliente {
private:
    std::string nombre_;
    int puntos_{ 0 };
    std::string telefono_;
    std::string correo_;

public:
    Cliente() = default;

    Cliente(std::string nombre, int puntos, std::string telefono, std::string correo)
        : nombre_(std::move(nombre)), puntos_(puntos),
        telefono_(std::move(telefono)), correo_(std::move(correo)) {
        if (nombre_.empty()) throw OxxoException("Nombre de cliente vacío.");
        if (puntos_ < 0) throw OxxoException("Puntos inválidos.");
        if (telefono_.empty()) throw OxxoException("Teléfono vacío.");
        if (correo_.empty()) throw OxxoException("Correo vacío.");
        if (correo_.find('@') == std::string::npos) throw OxxoException("Correo inválido (falta @).");
    }

    const std::string& nombre() const { return nombre_; }
    int puntos() const { return puntos_; }
    const std::string& telefono() const { return telefono_; }
    const std::string& correo() const { return correo_; }

    void agregarPuntos(int p) {
        if (p < 0) throw OxxoException("No se pueden agregar puntos negativos.");
        puntos_ += p;
    }

    void usarPuntos(int p) {
        if (p < 0) throw OxxoException("No se pueden usar puntos negativos.");
        if (p > puntos_) throw OxxoException("Puntos insuficientes.");
        puntos_ -= p;
    }
};
