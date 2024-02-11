#pragma once
#include "Prerequisites.h"

class producto
{
	string nombre;
	string cantidad; 

public:
	//Constructor 
	producto(string _nombre, string _cantidad): nombre(_nombre),cantidad(_cantidad){}

	//set y get 
	void setnombre(string _nombre) { nombre = _nombre; }
	void setcantidad(string _nombre) { cantidad = cantidad; }

	string getnombre() { return nombre; }
	string getcantidad() { return cantidad; }

};