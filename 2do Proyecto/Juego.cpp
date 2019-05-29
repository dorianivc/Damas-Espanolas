#include "Juego.h"






Juego::Juego(Tablero * t, Jugador * j, Computadora * c, Estrategia * e)
{
	tab = t;
	jugador = j;
	compu = c;
	estra = e;
}

bool Juego::jugadaValida(int x1, int x2, int x, int y)
{
	if ((x == x1 + 1 && y == x2 + 1) || (x == x1 + 1 && y == x2 - 1) || (x == x1 - 1 && y == x2 + 1) || (x == x1 - 1 && y == x2 - 1) || (x == x1 + 2 && y == x2 - 2) || (x == x1 + 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 - 2)) {
		return true;
	}
	else
		return false;
}

bool Juego::realizarJugadaPC()
{
	vector<int> jugadaObtenidaEstrategia;

		jugadaObtenidaEstrategia = compu->movimientoRealizar(tab, estra);
		//Hasta aqui, el vector contiene las coordenadas de la ficha a mover y su movimiento
	int casX = jugadaObtenidaEstrategia[0]; int casY = jugadaObtenidaEstrategia[1];
	int movX = jugadaObtenidaEstrategia[2]; int movY = jugadaObtenidaEstrategia[3]; int com = jugadaObtenidaEstrategia[4];
	if (jugadaValida(casX, casY, movX, movY)) {
		tab->eliminar(casX, casY);
		tab->crear(movX, movY, true);
		if (com > 0) {
			if (movX - casX == 2) {//si come hacia adelante;
				//verificar si comio a la izquierda o a la derecha
				if (movY - casY == 2) {//derecha
					tab->eliminar((movX - 1), (movY + 1));
					jugador->restarFicha();
				}
				if (movY - casY == -2) {//izquierda
					tab->eliminar((movX - 1), (movY - 1));
					jugador->restarFicha();
				}
			}
			if (movX - casX == -2) {
				//verificar si comio a la izquierda o a la derecha
				if (movY - casY == 2) {//derecha
					tab->eliminar((movX + 1), (movY + 1));
					jugador->restarFicha();
				}
				if (movY - casY == -2) {//izquierda
					tab->eliminar((movX + 1), (movY - 1));
					jugador->restarFicha();
				}
			}
		}
	}
	else {
		return false;
	}
	cout << tab->toString() << endl;
	return true;
}

Juego::~Juego()
{
	delete estra;
	delete jugador;
	delete compu;
}
