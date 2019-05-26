#ifndef TABLERO
#define TABLERO
#define TAMTABLERO 8
#include <string>
#include <sstream>
#include <iostream>
#include "Ficha.h"
using namespace std;
class Tablero
{
	Ficha* tablero[TAMTABLERO][TAMTABLERO];
	Tablero();
	static Tablero * instancia;
public:
	static Tablero* getInstancia();
	bool ingresarJugadaBlancas(int , int );//falta impedir movimientos ambiguios
	bool ingresarJugadaNegras(int, int);//falta impedir movimientos ambiguios
	Ficha* getFichaDelTablero(int, int);
	void actualizar();//refresca las fichas para coronarlas si llegaron al espacio correspondiente
	string toString();
	~Tablero();
	bool esPar(int);
};

#endif