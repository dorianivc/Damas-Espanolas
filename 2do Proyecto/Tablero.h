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
	bool ingresarJugada(int , int );
	string toString();
	~Tablero();
	bool esPar(int);
};

#endif