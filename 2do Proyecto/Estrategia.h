#ifndef ESTRATEGIA
#define ESTRATEGIA
#include "Tablero.h"
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <exception>
using namespace std;
class Estrategia
{
public:

	virtual vector<int> obtenerEstrategia(Tablero*) = 0;
	virtual vector<int> obtenerPosicionAJugarAleatoria(Tablero*);
	virtual vector<int> calcularJugadas(Tablero* tab, int x, int y);//CALCULA LA JUGADA EN LA POSICION DE LA FICHA INGRESADA

};

#endif // !ESTRATEGIA
