#pragma once
#include "Prerequisites.h"
#include "SistemaOxxo.h"

class Menu {
private:
    SistemaOxxo& sistema_;

public:
    explicit Menu(SistemaOxxo& s) : sistema_(s) {}

    void ejecutar();

private:
    void opcionRegistrarCliente();
    void opcionBorrarCliente();
    void opcionRegistrarProveedor();
    void opcionRegistrarProducto();
    void opcionVenderProducto();
    void opcionListarTodo() const;
};
