#include"Tablero.h"
#include "Jugador.h"
#include "Computadora.h"
#include "Estrategia.h"
#include "EstrategiaAleatoria.h"
using namespace std;
class Juego
{private:
	Tablero* tab;
	Jugador* jugador;
	Computadora* compu;
	Estrategia* estra;
public:
	Juego(Tablero*, Jugador* = new Jugador("Jugador"), Computadora* = new Computadora(), Estrategia * = new EstrategiaAleatoria());
	~Juego();
};

