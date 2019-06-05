#include "EstrategiaDefensiva.h"

vector<int> EstrategiaDefensiva::obtenerEstrategia(Tablero* tab)
{
	int x, y, h, k, z;
	vector<int> fichas = misFichas(tab);
	vector<int> posibles;
	vector<int> retorno; 
	for (int i = 0; i < (fichas.size() / 2); i++) {
		x = (2 * i);
		y = (2 * i) + 1;
		if (posicionDePeligro(tab, fichas[x], fichas[y])==true) {
			cout << "Ficha en peligro" << endl;
			cout << "(" << fichas[x] << "," << fichas[y] << ")" << endl;
			cin.get();
			vector<int> jugadasParaFicha = calcularJugadas(tab, fichas[x], fichas[y]);
			if (jugadasParaFicha.size() > 0) {
				for (int j = 0; j < jugadasParaFicha[0]; j++) {
					h = (3 * j)+1;
					k = (3 * j) +2;
					z = (3 * j) + 3;
					//tab->crear(jugadasParaFicha[h], jugadasParaFicha[k], true);
					if (posicionDePeligro(tab, jugadasParaFicha[h], jugadasParaFicha[k]) == false) {
						//tab->eliminar(jugadasParaFicha[h], jugadasParaFicha[k]);
						if (jugadaValida(fichas[x], fichas[y], jugadasParaFicha[h], jugadasParaFicha[k], tab->getFichaDelTablero(fichas[x], fichas[y]))) {
							posibles.push_back(fichas[x]);
							posibles.push_back(fichas[y]);
							posibles.push_back(jugadasParaFicha[h]);
							posibles.push_back(jugadasParaFicha[k]);
							posibles.push_back(jugadasParaFicha[z]);
							return posibles;
						}
					}
					//tab->eliminar(jugadasParaFicha[h], jugadasParaFicha[k]);
				}
			}
		}
	}
	
	for (int i = 0; i < ((fichas.size()) / 2); i++) {
		x = (2 * i);
		y = (2 * i) + 1;
		cout << "X: " <<x<< "Ficha x:  " << fichas[x] << endl;
		cout << "Y: " <<y<<"Ficha y:  "<<fichas[y] << endl;
		vector<int> jugadasParaFicha = calcularJugadas(tab, fichas[x], fichas[y]);
		for (int j = 0; j < jugadasParaFicha[0]; j++) {
			h = (3 * j)+1;
			k = (3 * j) + 2;
			z = (3 * j) + 3;
			tab->crear(jugadasParaFicha[h], jugadasParaFicha[k], true);
			if (tab->getFichaDelTablero(fichas[x], fichas[y])->getesCorona()) {
				tab->getFichaDelTablero(jugadasParaFicha[h], jugadasParaFicha[k])->coronar();
			}
			if (!posicionDePeligro(tab, jugadasParaFicha[h], jugadasParaFicha[k])) {
				if (jugadaValida(fichas[x], fichas[y], jugadasParaFicha[h], jugadasParaFicha[k], tab->getFichaDelTablero(fichas[x], fichas[y]))) {
					posibles.push_back(fichas[x]);
					posibles.push_back(fichas[y]);
					posibles.push_back(jugadasParaFicha[h]);
					posibles.push_back(jugadasParaFicha[k]);
					posibles.push_back(jugadasParaFicha[z]);
				}

			}

			tab->eliminar(jugadasParaFicha[h], jugadasParaFicha[k]);
		}
	}
	if (posibles.size() > 0) {
		int var, var2, var3, var4, var5;
		srand(time(NULL));
		int random = 1 + rand() % ((posibles.size() / 5) + 1 - 1);
		for (int i = 0; i < random; i++) {
			var = (5 * i);
			var2= (5 * i) + 1;
			var3 = (5 * i) + 2;
			var4 = (5 * i) + 3;
			var5 = (5 * i) + 4;

		}
		retorno.push_back(posibles[var]);
		retorno.push_back(posibles[var2]);
		retorno.push_back(posibles[var3]);
		retorno.push_back(posibles[var4]);
		retorno.push_back(posibles[var5]);
		cout << "Usando Estrategia Defensiva" << endl;
		cin.get();
		return retorno;
	}
	else {//PASAMOS A LA ESTRATEGIA ALEATORIA
		cout << "Usando Estrategia Random" << endl;
		cin.get();
		vector<int>jugada;
		vector<int>salida;
		int fila = 0, columna = 0;

		int zeta = 0; //comestibles
		bool pass = false;
		while (pass != true) {
			vector<int>posicionAleatoriaFicha = obtenerPosicionAJugarAleatoria(tab);
			jugada = calcularJugadas(tab, posicionAleatoriaFicha[0], posicionAleatoriaFicha[1]);
			int x1 = posicionAleatoriaFicha[0], x2 = posicionAleatoriaFicha[1];
			if (jugada[0] > 0) {
				int v;
				srand(time(NULL));
				for (int i = 0; i < 7; i++) {
					v = 1 + rand() % (jugada[0] + 1 - 1);
				}


				for (int i = 0; i < v; i++) {



					fila = jugada[(3 * i) + 1];


					columna = jugada[(3 * i) + 2];
					zeta = jugada[(3 * i) + 3];
					vector<int>prub;
					prub.push_back(posicionAleatoriaFicha[0]);
					prub.push_back(posicionAleatoriaFicha[1]);
					prub.push_back(fila);
					prub.push_back(columna);

					if (jugadaValida(posicionAleatoriaFicha[0], posicionAleatoriaFicha[1], fila, columna, tab->getFichaDelTablero(posicionAleatoriaFicha[0], posicionAleatoriaFicha[1]))) {
						pass = true;
						salida.push_back(posicionAleatoriaFicha[0]);
						salida.push_back(posicionAleatoriaFicha[1]);
						salida.push_back(fila);
						salida.push_back(columna);
						salida.push_back(zeta);

						return salida;


					}
					else {
						pass = false;
					}


				}

			}
			//Sleep(1);
		}
		return salida;
	}
}

string EstrategiaDefensiva::serializar()
{
	string k = "2";
	return k;
}

vector<int> EstrategiaDefensiva::calculcarJugadas(Tablero* tab, int x, int y)
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
/*bool EstrategiaDefensiva::posicionDePeligro(Tablero* tab, int x, int y)
{
	if (x >= 0 && y >= 0 && x < 8 && y < 8) {
		if (x < 7 && y>0) {
			if (tab->getFichaDelTablero(x + 1, y - 1) != NULL) {
				if (tab->getFichaDelTablero(x + 1, y - 1)->esFichaNegra() == false) {
					if (y >0 &&x<7 && y >= 0) {
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
						if (x < 7 && y < 7&&y>=0) {
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
						if (x<7&&x > 0 && y < 7) {
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
*/