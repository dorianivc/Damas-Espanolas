#ifndef JUGADORES
#define JUGADORES
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include "Tablero.h"
#include "ObjetoBase.h"
#include <vector>
using namespace std;
class Jugadores:public ObjetoBase
{protected:
	int fichasRestantes;
	int coronas;
public:
	Jugadores(int=12, int=0);
	virtual int getFichasRestantes();
	virtual void setFichasRestantes(int);
	virtual void setCoronas(int);
	virtual void reiniciar();
	virtual bool restarFicha();
	virtual int getCoronas();
	virtual bool sumarCoronas();
	virtual vector<int> calcularJugadas(Tablero* tab, int x, int y) = 0;
	virtual string toString() = 0;
	virtual string serializar() = 0;
	~Jugadores();
};

#endif // !JUGADORES