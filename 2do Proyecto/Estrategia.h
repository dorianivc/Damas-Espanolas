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
	virtual int valorCoordenadaEntrada(int);
	virtual int valorCoordenadaSalida(int x);
	virtual vector<int> obtenerEstrategia(Tablero*) = 0;
	virtual vector<int> obtenerPosicionAJugarAleatoria(Tablero*);
	virtual vector<int> calcularJugadas(Tablero* tab, int x, int y);//CALCULA LA JUGADA EN LA POSICION DE LA FICHA INGRESADA
	virtual vector<int> misFichas(Tablero*);//retorna una vector con todas las fichasNegras
	virtual bool jugadaValida(int, int, int, int, Ficha*);
	virtual string serializar() = 0;
	virtual bool posicionDePeligro(Tablero*, int, int);// verifica si en esa casilla, se es vulnerable
};

#endif // !ESTRATEGIA
