#include "cliente.h"

// Constructor
cliente::cliente(string _nombre, int _puntos, string _telefono, string _correo)
    : nombre(_nombre), puntos(_puntos), Telefono(_telefono), correo(_correo) {}

// Métodos set y get
void cliente::setNombre(string _nombre) { nombre = _nombre; }
void cliente::setpuntos(int _puntos) { puntos = _puntos; }
void cliente::SetTelefono(string _telefono) { Telefono = _telefono; }
void cliente::setcorreo(string _correo) { correo = _correo; }

string cliente::getnombre() { return nombre; }
int cliente::getpuntos() { return puntos; }
string cliente::getTelefono() { return Telefono; }
string cliente::getcorreo() { return correo; }
