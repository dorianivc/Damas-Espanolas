#ifndef JUGADOR
#define JUGADOR
#include"Jugadores.h"
using namespace std;
class Jugador:public Jugadores
{private:
	string nombre;
public:
	Jugador(string = "Jugador", int=12, int=0);
	string getNombre();
	void setNombre(string);
	string toString();
	Jugador(const Jugador&);
	bool validarJugada(int, int, int, int);
	vector<int> calcularJugadas(Tablero* tab, int x, int y);
	string serializar();
	~Jugador();
};
#endif // !JUGADOR
