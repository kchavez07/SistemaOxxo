// proveedor.cpp
#include "proveedor.h"

// Constructor
proveedor::proveedor(string _marca) : marca(_marca) {}

// M�todos set y get
void proveedor::setmarca(string _marca) { marca = _marca; }
string proveedor::getmarca() { return marca; }

void proveedor::agregarproducto(string producto) {
    // Implementa la l�gica para agregar productos al proveedor aqu�
}

vector<string> proveedor::getlistaprodctos() {
    // Implementa la l�gica para obtener la lista de productos del proveedor aqu�
    return listaproductos;
}
