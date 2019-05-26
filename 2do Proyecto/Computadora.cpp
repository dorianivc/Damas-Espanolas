#include "Computadora.h"




Computadora::Computadora(int fichasRestantes, int coronas):Jugadores(fichasRestantes, coronas)
{
	
}

string Computadora::toString()
{
	stringstream p;
	p << "Computadora:  " << endl;
	p << "Coronas: " << coronas << endl;
	p << "Fichas Restantes: " << fichasRestantes << endl;
	return p.str();
}

Computadora::~Computadora()
{
}
