#include "producto.h"

// Implementaci�n del constructor
producto::producto(string _nombre, string _cantidad) : nombre(_nombre), cantidad(_cantidad) {}

// Implementaci�n de los m�todos
void producto::setnombre(string _nombre) { nombre = _nombre; }
void producto::setcantidad(string _cantidad) { cantidad = _cantidad; }

string producto::getnombre() { return nombre; }
string producto::getcantidad() { return cantidad; }
