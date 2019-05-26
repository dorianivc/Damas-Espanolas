#pragma once
#include "Estrategia.h"
class EstrategiaAleatoria :public Estrategia
{
public:
	EstrategiaAleatoria();
	vector<int> obtenerEstrategia(Tablero*);
	vector<int> calcularJugadas(Tablero*, int x, int y);//CALCULA LA JUGADA EN LA POSICION DE LA FICHA INGRESADA
	~EstrategiaAleatoria();
};

