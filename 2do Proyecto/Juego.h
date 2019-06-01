#pragma once
#include"Tablero.h"
#include "Jugador.h"
#include "Computadora.h"
#include "EstrategiaAleatoria.h"
using namespace std;
class Juego
{
private:
	Tablero* tab;
	Jugador* jugador;
	Computadora* compu;
	Estrategia* estra;
public:
	Juego(Tablero*, Jugador* = new Jugador("Jugador"), Computadora* = new Computadora(), Estrategia* = new EstrategiaAleatoria());
	bool jugadaValidaBlancas(int, int, int, int, Ficha*);
	bool jugadaValidaNegras(int, int, int, int, Ficha*);
	bool realizarJugadaPC();
	Estrategia* getEstrategia();
	void setEstrategia(Estrategia*);
	Tablero* getTablero();
	Jugador* getJugador();
	Computadora* getComputadora();
	int getTipoEstrategia();
	bool realizarJugadaJugador();
	void setEstrategia(int);
	bool partidaFinaliza();
	bool ganoNegras();
	bool ganoBlancas();
	~Juego();
};

