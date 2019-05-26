#pragma once
#include "Estrategia.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
class EstrategiaAleatoria :public Estrategia
{
public:
	EstrategiaAleatoria();
	vector<int> obtenerEstrategia(Tablero*);//retorna el movimiento a proceder, 
	vector<int> obtenerPosicionAJugarAleatoria(Tablero*);
	vector<int> calcularJugadas(Tablero*, int x, int y);//CALCULA LA JUGADA EN LA POSICION DE LA FICHA INGRESADA
	~EstrategiaAleatoria();
};

