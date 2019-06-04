#ifndef ESTRATEGIADEFENSIVA
#define ESTRATEGIADEFENSIVA
#include "Estrategia.h"
class EstrategiaDefensiva: public Estrategia
{
public:
	vector<int> obtenerEstrategia(Tablero*);
	string serializar();
	bool posicionDePeligro(Tablero*, int, int);// verifica si en esa casilla, se es vulnerable

};
#endif
