#ifndef JUGADOR
#define JUGADOR
#include <string>
#include <iostream>
#include <sstream>
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
	~Jugador();
};
#endif // !JUGADOR
