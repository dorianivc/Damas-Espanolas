#include "Jugador.h"





Jugador::Jugador(string nombre, int fichasRestantes, int coronas) :Jugadores(fichasRestantes, coronas)
{
	this->nombre = nombre;
}

string Jugador::getNombre()
{
	return nombre;
}

void Jugador::setNombre(string nomb)
{
	nombre = nomb;
}

string Jugador::toString()
{
	stringstream p;
	p << "Nombre del Jugador: " << nombre << endl;
	p << "Coronas: " << coronas << endl;
	p << "Fichas Restantes: " << fichasRestantes << endl;
	return p.str();
}

Jugador::Jugador(const Jugador &  x)
{
	this->nombre = x.nombre;
	this->fichasRestantes = x.fichasRestantes;
	this->coronas = x.coronas;
}

Jugador::~Jugador()
{
}
