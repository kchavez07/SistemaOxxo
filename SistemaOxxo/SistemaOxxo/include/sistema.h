#pragma once
#include "Prerequisites.h"
#include "cliente.h"
#include "proveedor.h"
#include "producto.h"

class Sistema {
public:
    // Funciones para la l�gica del sistema
    void venderproducto(producto producto, cliente cliente);
    void registrarproducto(producto producto);
    void registrarproveedor(proveedor proveedor);
    void registrarcliente(cliente cliente);
    void borrarcliente(cliente cliente);
};
