#include "Juego.h"






Juego::Juego(Tablero * t, Jugador * j, Computadora * c, Estrategia * e)
{
	tab = t;
	jugador = j;
	compu = c;
	estra = e;
}

Juego::~Juego()
{
	delete estra;
	delete jugador;
	delete compu;
}
