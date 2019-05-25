#include "Tablero.h"


Tablero* Tablero::instancia = NULL;


Tablero::Tablero()
{	
	for (int i = 0; i < TAMTABLERO; i++)
	{
		for (int y = 0; y < TAMTABLERO; y++)
		{
			tablero[i][y] = NULL;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (!esPar(i+1)) {
			for (int y = 0; y < TAMTABLERO; y++) {
				if (esPar(y)) {
					tablero[i][y] = new Ficha(i, y, true);
				}

			}
		}
		else {
			for (int y = 0; y < TAMTABLERO; y++) {
				if (!esPar(y)) {
					tablero[i][y] = new Ficha(i, y, true);
				}
			}
		}
	}

	for (int i = 5; i <8 ; i++) {
		if (!esPar(i+1)) {
			for (int y = 0; y < TAMTABLERO; y++) {
				if (esPar(y)) {
					tablero[i][y] = new Ficha(i, y, false);
				}

			}
		}
		else {
			for (int y = 0; y < TAMTABLERO; y++) {
				if (!esPar(y)) {
					tablero[i][y] = new Ficha(i, y, false);
				}
			}
		}
	}

}



Tablero * Tablero::getInstancia()
{
	if (!instancia) {
		instancia = new Tablero();
	}
	return instancia;
}

bool Tablero::ingresarJugada(int x, int y)
{
	switch (x) {
	case 8:
		x = 1;
		break;
	case 7:
		x = 2;
		break;
	case 6:	
		x = 3;
		break;
	case 5:
		x = 4;
		break;
	case 4:
		x = 5;
		break;
	case 3:
		x = 6;
		break;
	case 2:
		x = 7;
		break;
	case 1:
		x = 8;
	}
	if (x > 0 && y > 0 && y<=8&& x<=8) {
		tablero[x - 1][y - 1] = new Ficha (x-1, y-1, false);
		return true;
	}
	else
		return false;
}

string Tablero::toString()
{
		stringstream p;
	
		int tam = TAMTABLERO;
		for (int i = 0; i < TAMTABLERO; i++)
		{
			
			p << tam;
			for (int y = 0; y < TAMTABLERO; y++)
			{
				if (tablero[i][y] == NULL) {
					p << "[   ]";
				}
				else {
					p << "[" << tablero[i][y]->imprimeFicha() << "]";
				}
				

			}
			p << endl;
			tam--;
		}

		for (int i = 0; i < TAMTABLERO; i++) {
			p << "    " << i+1;
		}


		return p.str();
	}




Tablero::~Tablero()
{
	instancia=NULL;
}

bool Tablero::esPar(int k)
{
	if (k % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}
