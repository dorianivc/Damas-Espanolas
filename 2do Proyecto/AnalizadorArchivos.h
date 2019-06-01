#pragma once
#include "ObjetoBase.h"
#include "Jugador.h"
#include "Computadora.h"
#include "Juego.h"
#include "Tablero.h"
#include <fstream>
class AnalizadorArchivos
{
public:
	static void guardar(Juego*);
	static void recuperar(Juego*);
};

