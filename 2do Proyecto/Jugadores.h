#ifndef JUGADORES
#define JUGADORES
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include "Tablero.h"
#include <vector>
using namespace std;
class Jugadores
{protected:
	int fichasRestantes;
	int coronas;
public:
	Jugadores(int=12, int=0);
	virtual int getFichasRestantes();
	virtual bool restarFicha();
	virtual int getCoronas();
	virtual bool sumarCoronas();
	virtual vector<int> calcularJugadas(Tablero* tab, int x, int y) = 0;
	virtual string toString() = 0;
	~Jugadores();
};

#endif // !JUGADORES