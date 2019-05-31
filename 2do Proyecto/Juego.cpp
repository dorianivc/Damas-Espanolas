#include "Juego.h"






Juego::Juego(Tablero * t, Jugador * j, Computadora * c, Estrategia * e)
{
	tab = t;
	jugador = j;
	compu = c;
	estra = e;
}

bool Juego::jugadaValida(int x1, int x2, int x, int y)
{
	if ((x == x1 + 1 && y == x2 + 1) || (x == x1 + 1 && y == x2 - 1) || (x == x1 - 1 && y == x2 + 1) || (x == x1 - 1 && y == x2 - 1) || (x == x1 + 2 && y == x2 - 2) || (x == x1 + 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 - 2)) {
		return true;
	}
	else
		return false;
}

bool Juego::realizarJugadaPC()
{
	vector<int> jugadaObtenidaEstrategia;

		jugadaObtenidaEstrategia = compu->movimientoRealizar(tab, estra);
		//Hasta aqui, el vector contiene las coordenadas de la ficha a mover y su movimiento
	int casX = jugadaObtenidaEstrategia[0]; int casY = jugadaObtenidaEstrategia[1];
	int movX = jugadaObtenidaEstrategia[2]; int movY = jugadaObtenidaEstrategia[3]; int com = jugadaObtenidaEstrategia[4];
	if (jugadaValida(casX, casY, movX, movY)) {
		if (tab->getFichaDelTablero(casX, casY)->getesCorona()) {
			tab->eliminar(casX, casY);
			tab->crear(movX, movY, true);
			tab->getFichaDelTablero(movX, movY)->coronar();
		}
		else {
			tab->eliminar(casX, casY);
			tab->crear(movX, movY, true);
		}
		if (com > 0) {
			if (movX - casX == 2) {//si come hacia adelante;
				//verificar si comio a la izquierda o a la derecha
				if (movY - casY == 2) {//derecha
					tab->eliminar((movX - 1), (movY + 1));
					jugador->restarFicha();
					cout << jugador->toString() << endl;
				}
				if (movY - casY == -2) {//izquierda
					tab->eliminar((movX - 1), (movY - 1));
					jugador->restarFicha();
					cout << jugador->toString() << endl;
				}
			}
			if (movX - casX == -2) {
				//verificar si comio a la izquierda o a la derecha
				if (movY - casY == 2) {//derecha
					tab->eliminar((movX + 1), (movY + 1));
					jugador->restarFicha();
					cout << jugador->toString() << endl;
				}
				if (movY - casY == -2) {//izquierda
					tab->eliminar((movX + 1), (movY - 1));
					jugador->restarFicha();
					cout << jugador->toString() << endl;
				}
			}
		}
	}
	else {
		return false;
	}
	tab->actualizar();

	return true;
}

bool Juego::realizarJugadaJugador()
{
	cout << tab->toString() << endl;
	int x1=0, y1=0, x2=0, y2=0;
	string aux1, aux2, aux3, aux4;
	cout << "Digite el #  de la fila de la ficha a mover" << endl;
	getline(cin, aux1);
	cout << "Digite el #  de la columna de la ficha a mover" << endl;
	getline(cin, aux2);
	x1 = atoi(aux1.c_str());
	x2 = atoi(aux2.c_str());
	//bool pass = false;
	vector<int> salida;//Con este vector se imprimen las opciones
	if (x1 >= 0 && x1 < 8 && x2 >= 0 && x2 < 8) {
		if (tab->getFichaDelTablero(x1, x2) != NULL) {
			if (tab->getFichaDelTablero(x1, x2)->esFichaNegra() == false) {
				
				//Esta variable contiene los posibles(0-8) movimientos que puede realizar
				vector<int> jugada = jugador->calcularJugadas(tab, x1, x2);
				if (jugada[0] > 0) {
					/*
					int var = -1;
					int x = 0;
					int z = 0;
					int y = 0;
					for (int i = 0; i <jugada[0] ; i++) {
						var++;

						x = jugada[var];
						var++;

						y = jugada[var];
						z = jugada[var + 1];
						vector<int>prub;
						prub.push_back(x1);
						prub.push_back(x2);
						prub.push_back(x);
						prub.push_back(y);
						prub.push_back(z);

						if ((x == x1 + 1 && y == x2 + 1) || (x == x1 + 1 && y == x2 - 1) || (x == x1 - 1 && y == x2 + 1) || (x == x1 - 1 && y == x2 - 1) || (x == x1 + 2 && y == x2 - 2) || (x == x1 + 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 - 2)) {
							salida.push_back(x1);
							salida.push_back(x2);
							salida.push_back(x);
							salida.push_back(y);
							salida.push_back(z);
							cout << salida.size() << endl;

						}
						


					}//hasta aqui salida contiene todos los movimientos que puede hacer con la ficha ya verificados
					*/
					int limite = 0;
					limite = jugada[0];
					if (limite > 0) {
						int x = 0;
						int y = 0;
						int z = 0;
						cout << "Usted puede mover la ficha a " << limite << " posibles posiciones" << endl;
						
						for (int i = 0; i <(3-1)*jugada[0]; i++) {
							/*cout << i + 1 << " Aqui el i+1" << endl;
							cout << i + 2 << " Aqui el i+2" << endl;
							cout << i + 3 << " Aqui el i+3" << endl;*/
							cout << "Fila : " << jugada[i+1] << endl;
							cout << "Columna: " << jugada[i+2] << endl;
							cout << "Come con la jugada: ";
							if (jugada[i+3] > 0) {
									cout << " SI" << endl;
							}
							else {
									cout << " NO" << endl;
								}
						cout << "/-----------------------------/" << endl;
							
						i++;
						i++;
						}
						int jugadaDefinitivaX = 0, jugadaDefinitivaY = 0;
						string jugadaX;
						string jugadaY;
						cout << "Digite la jugada a realizar" << endl;
						cout << "Digite la fila a mover" << endl;
						getline(cin, jugadaX);
						jugadaDefinitivaX = atoi(jugadaX.c_str());
						cout << "Digite la columna a mover" << endl;
						getline(cin, jugadaY);
						jugadaDefinitivaY = atoi(jugadaY.c_str());
						bool pass = true;
						if ((jugadaDefinitivaX == x1 + 1 && jugadaDefinitivaY == x2 + 1) || (jugadaDefinitivaX == x1 + 1 && jugadaDefinitivaY == x2 - 1) || (jugadaDefinitivaX == x1 - 1 && jugadaDefinitivaY == x2 + 1) || (jugadaDefinitivaX == x1 - 1 && jugadaDefinitivaY == x2 - 1) || (jugadaDefinitivaX == x1 + 2 && jugadaDefinitivaY == x2 + 2) || (jugadaDefinitivaX == x1 + 2 && jugadaDefinitivaY == x2 - 2) || (jugadaDefinitivaX == x1 - 2 && jugadaDefinitivaY == x2 + 2) || (jugadaDefinitivaX == x1 - 2 && jugadaDefinitivaY == x2 - 2)) {
							int x = jugadaDefinitivaX;
							int y = jugadaDefinitivaY;
							if (tab->getFichaDelTablero(x1, x2)->getesCorona()) {
								tab->eliminar(x1, x2);
								tab->crear(jugadaDefinitivaX, jugadaDefinitivaY, false);
								tab->getFichaDelTablero(jugadaDefinitivaX, jugadaDefinitivaY)->coronar();
							}
							else {
								
								tab->eliminar(x1, x2);
								tab->crear(jugadaDefinitivaX, jugadaDefinitivaY, false);
							}
							cout <<"Restas de X :"<< x - x1 << endl;
							cout << "Restas de Y :" << y - x2 << endl;
							//verificar si comio a la izquierda o a la derecha

							if (x - x1 == -2) {
								//verificar si comio a la izquierda o a la derecha
								if (y - x2 == 2) {//izquierda
									tab->eliminar((x + 1), (y -1));
									compu->restarFicha();
									cout << compu->toString() << endl;
								}
								if (y - x2 == -2) {//derecha
									tab->eliminar((x + 1), (y +1));
									compu->restarFicha();
									cout << compu->toString() << endl;
								}
							}
							if (tab->getFichaDelTablero(x, y)->getesCorona()) {//si come hacia adelante;		
								if (x - x1 == 2) {
									if (y - x2 == -2) {
										//izquierda
										tab->eliminar((x - 1), (y + 1));
										compu->restarFicha();
										cout << compu->toString() << endl;
									}
									if (y - x2 == 2) {

										//derecha
										tab->eliminar((x - 1), (y - 1));
										compu->restarFicha();
										cout << compu->toString() << endl;
									}
								}

							}
								
							tab->actualizar();
							
							
							return true;
						}
						else {
							cout << "Jugada Invalida" << endl;
							return false;
						}

					}
					else {
						cout << "La ficha seleccionada no puede ser movida" << endl;
						return false;
					}


				}
				else {
					cout << "La ficha no tiene a donde moverse" << endl;
					return false;
				}
			}
			else {
				cout << "La ficha seleccionada no correspone a una ficha blanca ---> X" << endl;
				return false;
			}
		}
		else {
			cout << "La ficha ingresada no existe" << endl;
			return false;
		}
	}
	else {
		cout << "Los datos ingresados no son validos" << endl;
		return false;
	}
}

Juego::~Juego()
{
	delete estra;
	delete jugador;
	delete compu;
}
