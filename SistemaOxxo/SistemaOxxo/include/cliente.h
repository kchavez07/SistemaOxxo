#pragma once
#include "Prerequisites.h" 

class cliente {
private:
	string nombre;
	int puntos;
	string Telefono;
	string correo;

public: //Contructor 
	cliente(string _nombre, int _puntos, string _telefono, string _correo)
		: nombre(nombre), puntos(puntos), Telefono(Telefono), correo(correo) {}

	//declaracion
	void setNombre(string _nombre) { nombre = nombre; }
	void setpuntos(int _puntos) { puntos = puntos; }
	void SetTelefono(string _telefono) { Telefono = Telefono; }
	void setcorreo(string _correo) { correo = _correo; }

	string getnombre() { return nombre; }
	int getpuntos() { return puntos; }
	string getTelefono() { return Telefono; }
	string getcorreo() { return correo; }
};