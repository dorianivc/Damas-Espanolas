#pragma once
#include "Estrategia.h"
class EstrategiaAleatoria :public Estrategia
{
public:
	EstrategiaAleatoria();
	vector<int> obtenerEstrategia(Tablero*);//retorna el movimiento a proceder
	~EstrategiaAleatoria();
	bool jugadaValida(int, int,int,int);
};

