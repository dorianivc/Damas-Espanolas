#ifndef ESTRATEGIAOFENSIVA
#define ESTRATEGIAOFENSIVA
#include "Estrategia.h"
class EstrategiaOfensiva :public Estrategia
{
public:
	vector<int> obtenerEstrategia(Tablero*);
	string serializar();
	
};

#endif