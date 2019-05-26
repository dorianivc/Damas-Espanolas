#ifndef ESTRATEGIA
#define ESTRATEGIA
#include "Tablero.h"
#include <math.h>
#include <vector>
#include <exception>
using namespace std;
class Estrategia
{
public:

	virtual vector<int> obtenerEstrategia(Tablero*) = 0;

};

#endif // !ESTRATEGIA
