#pragma once
#include "Prerequisites.h" 

class cliente {
private:
	string nombre;
	int puntos;
	string Telefono;
	string correo;

public: //Contructor 
	cliente(std::string _nombre);
	cliente(string _nombre, int _puntos, string _telefono, string _correo);

	//declaracion
	void setNombre(string _nombre);
	void setpuntos(int _puntos);
	void SetTelefono(string _telefono);
	void setcorreo(string _correo);

	string getnombre();
	int getpuntos();
	string getTelefono();
	string getcorreo();
};