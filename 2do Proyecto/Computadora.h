#ifndef COMPUTADORA
#define COMPUTADORA
#include "Jugadores.h"
using namespace std;
class Computadora:public Jugadores
{
		
public:
	Computadora(int = 12, int = 0);
	string toString();
	~Computadora();
};

#endif // !COMPUTADORA