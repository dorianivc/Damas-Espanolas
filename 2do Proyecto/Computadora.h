#ifndef COMPUTADORA
#define COMPUTADORA
#include "Jugadores.h"
#include "Estrategia.h"
using namespace std;
class Computadora:public Jugadores
{
		
public:
	Computadora(int = 12, int = 0);
	string toString();
	vector<int> calcularJugadas(Tablero* tab, int x, int y);//Metodo Heredado
	vector<int> movimientoRealizar(Tablero*, Estrategia*);
	string serializar();
	~Computadora();
};

#endif // !COMPUTADORA