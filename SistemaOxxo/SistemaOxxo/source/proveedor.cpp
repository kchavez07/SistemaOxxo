// proveedor.cpp
#include "proveedor.h"

// Constructor
proveedor::proveedor(string _marca) : marca(_marca) {}

// Métodos set y get
void proveedor::setmarca(string _marca) { marca = _marca; }
string proveedor::getmarca() { return marca; }

void proveedor::agregarproducto(string producto) {
    // Implementa la lógica para agregar productos al proveedor aquí
}

vector<string> proveedor::getlistaprodctos() {
    // Implementa la lógica para obtener la lista de productos del proveedor aquí
    return listaproductos;
}
