#pragma once
#include "Prerequisites.h" 

class proveedor
{
private:
	string marca; 
	vector<string>listaproductos;

public:
	proveedor(string _marca);

	//metodos set y get
	void setmarca(string _marca);
	string getmarca();

	void agregarproducto(string producto);
	vector<string>getlistaprodctos();

};