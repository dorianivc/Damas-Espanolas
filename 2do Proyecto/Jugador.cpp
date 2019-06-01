#include "Jugador.h"





Jugador::Jugador(string nombre, int fichasRestantes, int coronas) :Jugadores(fichasRestantes, coronas)
{
	this->nombre = nombre;
}

string Jugador::getNombre()
{
	return nombre;
}

void Jugador::setNombre(string nomb)
{
	nombre = nomb;
}

string Jugador::toString()
{
	stringstream p;
	p << "Nombre del Jugador: " << nombre << endl;
	p << "Coronas: " << coronas << endl;
	p << "Fichas Restantes: " << fichasRestantes << endl;
	return p.str();
}

Jugador::Jugador(const Jugador &  x)
{
	this->nombre = x.nombre;
	this->fichasRestantes = x.fichasRestantes;
	this->coronas = x.coronas;
}

bool Jugador::validarJugada(int x1, int x2, int x, int y)
{
	if ((x == x1 + 1 && y == x2 + 1) || (x == x1 + 1 && y == x2 - 1) || (x == x1 - 1 && y == x2 + 1) || (x == x1 - 1 && y == x2 - 1) || (x == x1 + 2 && y == x2 - 2) || (x == x1 + 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 - 2)) {
		return true;
	}
	else
		return false;
}

vector<int> Jugador::calcularJugadas(Tablero* tab, int x, int y)
{
	vector<int> estrategia;
	int posibilidades = 0;
	int x1Aux = 99, x2Aux = 99, x3Aux = 99, x4Aux = 99, x5Aux = 99, x6Aux = 99, x7Aux = 99, x8Aux = 99;
	int comestible1 = 0, comestible2 = 0, comestible3 = 0, comestible4 = 0, comestible5 = 0, comestible6 = 0, comestible7 = 0, comestible8 = 0;
	int y1Aux = 99, y2Aux = 99, y3Aux = 99, y4Aux = 99, y5Aux = 99, y6Aux = 99, y7Aux = 99, y8Aux = 99;
	try {
		if (x >= 0 && x < 8 && y >= 0 && y < 8) {
			
			//Variable int comestible es la cantidad de fichas que se come si hace ese movimiento, tomara la posicion 9 dentro del vector
			
			Ficha* aux = tab->getFichaDelTablero(x, y);
			Ficha* aux2 = NULL;
			if (aux != NULL) {
				try {
					if (aux->esFichaNegra() == false) {
						if (x < 8) {// ficha sin corona;
							
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
											if (tab->getFichaDelTablero(x - 1, y - 1) == NULL || tab->getFichaDelTablero(x - 1, y - 1)->esFichaNegra() == true) {
												posibilidades++;
												x6Aux = x - 2;
												y6Aux = y - 2;
												if (tab->getFichaDelTablero(x - 1, y - 1) != NULL && tab->getFichaDelTablero(x - 1, y - 1)->esFichaNegra() == true) {
													comestible6 = 1;
												}
											}
										}
									}

									if (y < 6) {
										if (tab->getFichaDelTablero(x - 2, y + 2) == NULL) {// 2 ATRASO DIAGONAL DERECHA
											if (tab->getFichaDelTablero(x - 1, y + 1) == NULL || tab->getFichaDelTablero(x - 1, y + 1)->esFichaNegra() == true) {
												posibilidades++;
												x8Aux = x - 2;
												y8Aux = y + 2;
												if (tab->getFichaDelTablero(x - 1, y + 1) != NULL && tab->getFichaDelTablero(x - 1, y + 1)->esFichaNegra() == true) {
													comestible8 = 1;
												}
											}

										}
									}
								}
								if (aux->getesCorona() == true) {
									{// ficha con corona;
										if (y < 7) {
											if (tab->getFichaDelTablero(x + 1, y + 1) == NULL) {// 1 PASO DIAGONAL DERECHA
												posibilidades++;
												x1Aux = x + 1;
												y1Aux = y + 1;
											}
											if (y < 6) {
												if (tab->getFichaDelTablero(x + 2, y + 2) == NULL) {//2 PASO DIAGONAL DERECHA
													if (tab->getFichaDelTablero(x + 1, y + 1) == NULL || tab->getFichaDelTablero(x + 1, y + 1)->esFichaNegra() == true) {
														posibilidades++;
														x3Aux = x + 2;
														y3Aux = y + 2;
														if (tab->getFichaDelTablero(x + 1, y + 1) != NULL && tab->getFichaDelTablero(x + 1, y + 1)->esFichaNegra() == true) {
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
													if (tab->getFichaDelTablero(x + 1, y - 1) == NULL || tab->getFichaDelTablero(x + 1, y - 1)->esFichaNegra() == true) {
														posibilidades++;
														x4Aux = x + 2;
														y4Aux = y - 2;
														if (tab->getFichaDelTablero(x + 1, y - 1) != NULL && tab->getFichaDelTablero(x + 1, y - 1)->esFichaNegra() == true) {
															comestible4 = 1;
														}
													}
												}
											}
										}
									}




								}



								
								
							
						}
					}
else {
string p;
throw p;
}
				}
				catch (string x) {
					x = "Error al digitar la casilla: No corresponde a sus fichas";
					cout << x << endl;
				}
			}
			
		}
		else {
			string excepcion;
			throw excepcion;
		}
	}
	catch (string p) {
		cout << "Ha digitado una tecla de rango indefinido en la matriz" << endl;
	}

	
	estrategia.push_back(posibilidades);

	if (x1Aux != 99) {

		estrategia.push_back(x1Aux);
		estrategia.push_back(y1Aux);
		//cout <<"Aqui1: "<< y1Aux << endl;
		estrategia.push_back(comestible1);
	}
	if (x2Aux != 99) {
		estrategia.push_back(x2Aux);
		estrategia.push_back(y2Aux);
		//cout << "Aqui2: " << y2Aux << endl;
		estrategia.push_back(comestible2);
	}
	if (x3Aux != 99) {
		estrategia.push_back(x3Aux);
		estrategia.push_back(y3Aux);
		//cout << "Aqui3: " << y3Aux << endl;
		estrategia.push_back(comestible3);
	}
	if (x4Aux != 99) {
		estrategia.push_back(x4Aux);
		estrategia.push_back(y4Aux);
		//cout << "Aqui4: " << y4Aux << endl;
		estrategia.push_back(comestible4);
	}if (x5Aux != 99) {
		estrategia.push_back(x5Aux);
		estrategia.push_back(y5Aux);
		//cout << "Aqui5: " << y5Aux << endl;
		estrategia.push_back(comestible5);
	}
	if (x6Aux != 99) {
		estrategia.push_back(x6Aux);
		estrategia.push_back(y6Aux);
		estrategia.push_back(comestible6);
		//cout << "Aqui6: " << y6Aux << endl;
	}if (x7Aux != 99) {
		estrategia.push_back(x7Aux);
		estrategia.push_back(y7Aux);
		estrategia.push_back(comestible7);
		//cout << "Aqui7: " << y7Aux << endl;
	}
	if (x8Aux != 99) {
		estrategia.push_back(x8Aux);
		estrategia.push_back(y8Aux);
		//cout << "Aqui8: " << y8Aux << endl;
		estrategia.push_back(comestible8);
	}

	
	return estrategia;
}

string Jugador::serializar()
{
	stringstream p;
	p << nombre << "\t" << fichasRestantes << "\t" << coronas << "\t";
	return p.str();
}

Jugador::~Jugador()
{
}
