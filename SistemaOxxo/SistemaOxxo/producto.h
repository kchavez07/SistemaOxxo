#pragma once
#include "Prerequisites.h"

class producto {
private:
    string nombre;
    string cantidad;

public:
    // Constructor
    producto(string _nombre, string _cantidad);

    // Declaraciones de métodos
    void setnombre(string _nombre);
    void setcantidad(string _cantidad);

    string getnombre();
    string getcantidad();
};
