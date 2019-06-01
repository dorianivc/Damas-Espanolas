#include "Jugadores.h"






Jugadores::~Jugadores()
{
}

Jugadores::Jugadores(int fichasRestant, int cor)
{
	fichasRestantes = fichasRestant;
	coronas = cor;
}

int Jugadores::getFichasRestantes()
{
	return fichasRestantes;
}

void Jugadores::setFichasRestantes(int x)
{
	fichasRestantes = x;
}

void Jugadores::setCoronas(int x)
{
	coronas = x;
}

bool Jugadores::restarFicha()
{
	if (fichasRestantes > 0) {
		fichasRestantes--;
		return true;
	}
	else {
		return false;//FIN DEL JUEGO
	}
}

int Jugadores::getCoronas()
{
	return coronas;
}

bool Jugadores::sumarCoronas()
{
	if (coronas > fichasRestantes) {
		coronas++;
		return true;
	}
	else {
		return false;
	}
}


