#ifndef ESTRATEGIADEFENSIVA
#define ESTRATEGIADEFENSIVA
#include "Estrategia.h"
class EstrategiaDefensiva: public Estrategia
{
public:
	vector<int> obtenerEstrategia(Tablero*);
	string serializar();
	vector<int> calculcarJugadas(Tablero*, int, int);
	//bool posicionDePeligro(Tablero*, int, int);// Metodo heredado

};
#endif
