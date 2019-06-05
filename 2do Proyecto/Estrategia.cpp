#include "Estrategia.h"

vector<int> Estrategia::obtenerPosicionAJugarAleatoria(Tablero* tab)
{
	int  y;
	int cuenta = 0;
	vector<int> vec, retorno;
	srand(time(NULL));
	bool pass = false;
	for (int i = 0; i < TAMTABLERO; i++) {
		for (int y = 0; y < TAMTABLERO; y++) {
			if (tab->getFichaDelTablero(i, y)!=NULL) {
				if (tab->getFichaDelTablero(i, y)->esFichaNegra()) {
					vector<int> jugadas = calcularJugadas(tab, i, y);

					if (jugadas[0] > 0) {
						vec.push_back(i);
						vec.push_back(y);
						vec.push_back(jugadas[0]);
						cuenta++;
					}
				}
			}
		}
	}
	int v = 0 + rand() % (cuenta + 1 - 1);
	int x=0, j=1, z=2;
	for (int i = 0; i < v; i++) {
		x = (3 * i);
		j = (3 * i) + 1;
		z = (3 * i)+2;
	}
	retorno.push_back(vec[x]);
	retorno.push_back(vec[j]);
	retorno.push_back(vec[z]);
	return retorno;
	/*while (pass != true) {
		for (int i = 0; i < 3; i++) {
			x = 0 + rand() % (7 + 1 - 0);
		}
		for (int i = 0; i < 4; i++) {
			y = 0 + rand() % (7 + 1 - 0);
		}
		if (tab->getFichaDelTablero(x, y) != NULL) {
			if (tab->getFichaDelTablero(x, y)->esFichaNegra() == true) {
				vector<int> jugadas = calcularJugadas(tab, x, y);
				if (jugadas[0] > 0) {
					pass = true;
				}
				else {
					pass = false;
				}
			}
			else {
				pass = false;
			}
		}
	}*/


}

vector<int> Estrategia::calcularJugadas(Tablero* tab, int x, int y)
{
	try {
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			vector<int> estrategia;
			//Variable int comestible es la cantidad de fichas que se come si hace ese movimiento, tomara la posicion 9 dentro del vector
			int posibilidades = 0;
			int x1Aux = 99, x2Aux = 99, x3Aux = 99, x4Aux = 99, x5Aux = 99, x6Aux = 99, x7Aux = 99, x8Aux = 99;
			int comestible1 = 0, comestible2 = 0, comestible3 = 0, comestible4 = 0, comestible5 = 0, comestible6 = 0, comestible7 = 0, comestible8 = 0;
			int y1Aux = 99, y2Aux = 99, y3Aux = 99, y4Aux = 99, y5Aux = 99, y6Aux = 99, y7Aux = 99, y8Aux = 99;
			Ficha* aux = tab->getFichaDelTablero(x, y);
			Ficha* aux2 = NULL;
			if (aux != NULL) {
				if (aux->esFichaNegra() == true) {
					if (x < 7) {// ficha sin corona;
						if (y < 7) {
							if (tab->getFichaDelTablero(x + 1, y + 1) == NULL) {// 1 PASO DIAGONAL DERECHA
								posibilidades++;
								x1Aux = x + 1;
								y1Aux = y + 1;
							}
							if (y < 6) {
								if (tab->getFichaDelTablero(x + 2, y + 2) == NULL) {//2 PASO DIAGONAL DERECHA
									if (tab->getFichaDelTablero(x + 1, y + 1) == NULL || tab->getFichaDelTablero(x + 1, y + 1)->esFichaNegra() == false) {
										posibilidades++;
										x3Aux = x + 2;
										y3Aux = y + 2;
										if (tab->getFichaDelTablero(x + 1, y + 1) != NULL && tab->getFichaDelTablero(x + 1, y + 1)->esFichaNegra() == false) {
											comestible3 = 1;
										}
									}
								}
							}
						}
						if (y > 0) {
							if (tab->getFichaDelTablero(x + 1, y - 1) == NULL) {//1 PASO DIAGONAL IZQUIERDA
								posibilidades++;
								x2Aux = x + 1;
								y2Aux = y - 1;

							}

							if (y > 1) {
								if (tab->getFichaDelTablero(x + 2, y - 2) == NULL) {//2 PASO  DIAGONAL IZQUIERDA
									if (tab->getFichaDelTablero(x + 1, y - 1) == NULL || tab->getFichaDelTablero(x + 1, y - 1)->esFichaNegra() == false) {
										posibilidades++;
										x4Aux = x + 2;
										y4Aux = y - 2;
										if (tab->getFichaDelTablero(x + 1, y - 1) != NULL && tab->getFichaDelTablero(x + 1, y - 1)->esFichaNegra() == false) {
											comestible4 = 1;
										}
									}
								}
							}
						}
					}
					if (aux->getesCorona() == true) {
						if (x > 0) {
							if (y > 0) {
								if (tab->getFichaDelTablero(x - 1, y - 1) == NULL) {// 1 ATRASO DIAGONAL IZQUIERDA
									posibilidades++;
									x5Aux = x - 1;
									y5Aux = y - 1;
								}


							}
							if (y < 7) {
								if (tab->getFichaDelTablero(x - 1, y + 1) == NULL) {// 1 ATRASO DERECHA
									posibilidades++;
									x7Aux = x - 1;
									y7Aux = y + 1;
								}
							}
						}


						if (x > 1) {
							if (y > 1) {
								if (tab->getFichaDelTablero(x - 2, y - 2) == NULL) {//2 ATRASO DIAGONAL IZQUIERDA
									if (tab->getFichaDelTablero(x - 1, y - 1) == NULL || tab->getFichaDelTablero(x - 1, y - 1)->esFichaNegra() == false) {
										posibilidades++;
										x6Aux = x - 2;
										x6Aux = y - 2;
										if (tab->getFichaDelTablero(x - 1, y - 1) != NULL && tab->getFichaDelTablero(x - 1, y - 1)->esFichaNegra() == false) {
											comestible6 = 1;
										}
									}
								}
							}
							if (y < 6) {
								if (tab->getFichaDelTablero(x - 2, y + 2) == NULL) {// 2 ATRASO DIAGONAL DERECHA
									if (tab->getFichaDelTablero(x - 1, y + 1) == NULL || tab->getFichaDelTablero(x - 1, y + 1)->esFichaNegra() == false) {
										posibilidades++;
										x8Aux = x - 2;
										y8Aux = y + 2;
										if (tab->getFichaDelTablero(x - 1, y + 1) != NULL && tab->getFichaDelTablero(x - 1, y + 1)->esFichaNegra() == false) {
											comestible8 = 1;
										}
									}

								}
							}
						}



					}

					estrategia.push_back(posibilidades);
					if (x1Aux != 99) {
						estrategia.push_back(x1Aux);
						estrategia.push_back(y1Aux);
						estrategia.push_back(comestible1);
					}
					if (x2Aux != 99) {
						estrategia.push_back(x2Aux);
						estrategia.push_back(y2Aux);
						estrategia.push_back(comestible2);
					}
					if (x3Aux != 99) {
						estrategia.push_back(x3Aux);
						estrategia.push_back(y3Aux);
						estrategia.push_back(comestible3);
					}
					if (x4Aux != 99) {
						estrategia.push_back(x4Aux);
						estrategia.push_back(y4Aux);
						estrategia.push_back(comestible4);
					}if (x5Aux != 99) {
						estrategia.push_back(x5Aux);
						estrategia.push_back(y5Aux);
						estrategia.push_back(comestible5);
					}
					if (x6Aux != 99) {
						estrategia.push_back(x6Aux);
						estrategia.push_back(y6Aux);
						estrategia.push_back(comestible6);
					}if (x7Aux != 99) {
						estrategia.push_back(x7Aux);
						estrategia.push_back(y7Aux);
						estrategia.push_back(comestible7);
					}
					if (x8Aux != 99) {
						estrategia.push_back(x8Aux);
						estrategia.push_back(y8Aux);
						estrategia.push_back(comestible8);
					}
				}
			}

		/*	for (int i = 0; i < estrategia.size(); i++) {
				cout <<"Posibles moviminetos pos #"<<i<<"  " <<estrategia[i] << endl;
			}*/
			return estrategia;
		}
		else {
			string excepcion;
			throw excepcion;
		}
	}
	catch (string p) {
		cout << "Ha digitado una tecla de rango indefinido en la matriz" << endl;
	}
}

vector<int> Estrategia::misFichas(Tablero* tab)
{
	vector<int> fichas;
	for (int i = 0; i < TAMTABLERO; i++) {
		for (int y = 0; y < TAMTABLERO; y++) {
			if (tab->getFichaDelTablero(i, y) != NULL) {
				if (tab->getFichaDelTablero(i, y)->esFichaNegra()) {
					fichas.push_back(i);
					fichas.push_back(y);
				}
			}
		}
	}
	return fichas;
}

bool Estrategia::jugadaValida(int x1, int x2, int jugadaDefinitivaX, int jugadaDefinitivaY, Ficha* fic)
{
	if (fic->getesCorona() == false) {
		if ((jugadaDefinitivaX == x1 + 1 && jugadaDefinitivaY == x2 + 1) || (jugadaDefinitivaX == x1 + 1 && jugadaDefinitivaY == x2 - 1) || (jugadaDefinitivaX == x1 + 2 && jugadaDefinitivaY == x2 + 2) || (jugadaDefinitivaX == x1 + 2 && jugadaDefinitivaY == x2 - 2)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if ((jugadaDefinitivaX == x1 + 1 && jugadaDefinitivaY == x2 + 1) || (jugadaDefinitivaX == x1 + 1 && jugadaDefinitivaY == x2 - 1) || (jugadaDefinitivaX == x1 - 1 && jugadaDefinitivaY == x2 + 1) || (jugadaDefinitivaX == x1 - 1 && jugadaDefinitivaY == x2 - 1) || (jugadaDefinitivaX == x1 + 2 && jugadaDefinitivaY == x2 + 2) || (jugadaDefinitivaX == x1 + 2 && jugadaDefinitivaY == x2 - 2) || (jugadaDefinitivaX == x1 - 2 && jugadaDefinitivaY == x2 + 2) || (jugadaDefinitivaX == x1 - 2 && jugadaDefinitivaY == x2 - 2)) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool Estrategia::posicionDePeligro(Tablero* tab, int x, int y)
{
	if (x >= 0 && y >= 0 && x < 8 && y < 8) {
		if (x < 7 && y>0) {
			if (tab->getFichaDelTablero(x + 1, y - 1) != NULL) {
				if (tab->getFichaDelTablero(x + 1, y - 1)->esFichaNegra() == false) {
					if (y > 0 && x < 7 && y >= 0) {
						if (tab->getFichaDelTablero(x - 1, y + 1) == NULL) {
							return true;
						}

					}

				}
			}
		}
		if (x < 7 && y>0 && 7 > y) {
			if (tab->getFichaDelTablero(x + 1, y + 1) != NULL) {
				if (tab->getFichaDelTablero(x + 1, y + 1)->esFichaNegra() == false) {
					if (x < 7 && y < 7 && y >= 0) {
						if (tab->getFichaDelTablero(x - 1, y - 1) == NULL) {
							return true;
						}
					}

				}
			}
		}
		if (x > 1 && y > 0) {
			if (tab->getFichaDelTablero(x - 1, y - 1) != NULL) {
				if (tab->getFichaDelTablero(x - 1, y - 1)->esFichaNegra() == false && tab->getFichaDelTablero(x - 1, y - 1)->getesCorona()) {
					if (x < 7 && x > 0 && y > 0) {
						if (tab->getFichaDelTablero(x + 1, y + 1) == NULL) {
							return true;
						}
					}

				}
			}
		}
		if (x > 1 && y < 7) {
			if (tab->getFichaDelTablero(x - 1, y + 1) != NULL) {
				if (tab->getFichaDelTablero(x - 1, y + 1)->esFichaNegra() == false && tab->getFichaDelTablero(x - 1, y + 1)->getesCorona()) {
					if (x < 7 && x > 0 && y < 7) {
						if (tab->getFichaDelTablero(x + 1, y - 1) == NULL) {
							return true;
						}
					}

				}
			}
		}
		return false;


	}
}
