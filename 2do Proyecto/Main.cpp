#include "EstrategiaAleatoria.h"
#include  "Estrategia.h"
#include <Windows.h>
#include "Juego.h"
#include "AnalizadorArchivos.h"
using namespace std;

int main() {
	/*
	Universidad Nacional
	Proyecto Realizado Por: Dorian Vallecillo Calderon
	Profesora: Karol Leiton
	Curso: Programacion II
	IC 2019
	*/
	string menuA, nombre;
	int MenuA;
	cout << "Bienvenido a Damas " << endl;
	cout << "Por favor ingrese su nombre " << endl;
	getline(cin, nombre);
	bool salidaMenuA = false;
	Tablero* tab = Tablero::getInstancia();
	Jugador* jugador = new Jugador(nombre);
	Computadora* compu = new Computadora();
	Juego* juegoPrincipal = new Juego(tab, jugador, compu);//seteado para ser aleatorio automaticamente
	do {
		system("cls");
		cout << "Juego De Damas" << endl;
		cout << "Digite 1 para jugar" << endl;
		cout << "Digite 2 para cambiar la estrategia de la computadora" << endl;
		cout << "Digite 3 para cargar partida guardada" << endl;
		cout << "Digite 4 para salir " << endl;
		cout << "Por favor seleccione una opcion del menu" << endl;		
		//AnalizadorArchivos::recuperar(juegoPrincipal);
		getline(cin, menuA);
		MenuA = atoi(menuA.c_str());
		if (MenuA == 1) {
			string quienEmpieza, salirS;
			int empieza = 1;
			cout << "Si desea empezar usted, presione 1" << endl;
			cout << "Si desea que la computadora empiece, presione 2" << endl;
			cin.clear();
			getline(cin, quienEmpieza);
			empieza = atoi(quienEmpieza.c_str());
			bool salir = false;
			do {
				//system("cls");
				cout << "Presione enter para seguir jugando, o eliga una opcion del menu" << endl;
				cout << "Si desea salir, presione 1" << endl;
				cout << "Si desea guardar la partida, presione 2" << endl;
				cout << "Si desea reiniciar la partida, presione 3" << endl;
				getline(cin, salirS);
				int aux = atoi(salirS.c_str());
				if (aux == 1) {
					salir = true;
				}
				else if (aux == 2) {
					AnalizadorArchivos::guardar(juegoPrincipal);
					cout << "Patida guardada" << endl;
					cout << "Presione Enter" << endl;
					cin.get();
				}
				else if (aux == 3) {
					tab->reiniciar();
					jugador->reiniciar();
					compu->reiniciar();
					cout << "Partida Reiniciada" << endl;
					cout << "Presione Enter" << endl;
				}
				else {
					system("cls");
				}
				if (salir) {
					tab->reiniciar();
					jugador->reiniciar();
					compu->reiniciar();
					cout << "Listo" << endl;
					system("cls");
					salir = true;
				}
				else {
					if (empieza == 2) {
						bool jugoPC = false;
						bool jugoJugador = false;
						do {

							cout << "Pensando" << endl;
							jugoPC = juegoPrincipal->realizarJugadaPC();
							cout << tab->toString() << endl;
							cout << "Jugada de la computadora realizada, presione enter" << endl;
							cin.get();
						} while (jugoPC != true);
						do {
							jugoJugador = juegoPrincipal->realizarJugadaJugador();
							cin.get();
						} while (jugoJugador != true);
					}
					else
					{
						cout << "Empieza jugador" << endl;
						bool jugoPC = false;
						bool jugoJugador = false;
						do {
							jugoJugador = juegoPrincipal->realizarJugadaJugador();
							cin.get();
						} while (jugoJugador != true);
						do {
							
							cout << "Computadora Pensando" << endl;
							jugoPC = juegoPrincipal->realizarJugadaPC();
							cout << tab->toString() << endl;
							cout << "Jugada de la computadora realizada, presione enter" << endl;
							cin.get();
						} while (jugoPC != true);

					}
					if (juegoPrincipal->partidaFinaliza()) {
						cout << "Partida Finalizada" << endl;
						cout << compu->toString() << endl;
						cout << jugador->toString() << endl;
						tab->reiniciar();
						jugador->reiniciar();
						compu->reiniciar();
						salir = true;
					}
				}

			} while (salir != true);
		}
		else if (MenuA == 3) {
			cout << "Cargando Partida" << endl;
			AnalizadorArchivos::recuperar(juegoPrincipal);
			cout << "Proceso recuperar juego guardado listo" << endl;
			cout << "Proceda a seleccionar la opcion de jugar en el menu principal" << endl;
		}
		else if (MenuA == 4) {
			salidaMenuA == true;
			delete juegoPrincipal;
			delete tab;
			cout << "Hasta luego" << endl;
			salidaMenuA = true;
			
		}
		else if (MenuA == 2) {
			string eleccion;
			int elec = 0;
			cout << "Digite 1 para seleccionar la estrategia Aleatoria(FACIL)" << endl;
			cout << "Digite 2 para seleccionar la estrategia Defensiva(Desafiante)" << endl;
			cout << "Digite 3 para seleccionar la estrategia Ofensiva(Dificil)" << endl;
			getline(cin, eleccion);
			elec = atoi(eleccion.c_str());
			if (elec == 1) {
				juegoPrincipal->setEstrategia(1);
				cout << "Estrategia seteada a: Aleatoria" << endl;
			}
			else if (elec == 2) {
				juegoPrincipal->setEstrategia(2);
				cout << "Estrategia seteada a: Defensiva" << endl;
				cout << juegoPrincipal->getEstrategia()->serializar() << endl;
			}
			else if (elec == 3) {
				juegoPrincipal->setEstrategia(3);
				cout << "Estrategia seteada a: Ofensiva" << endl;
				cout << juegoPrincipal->getEstrategia()->serializar() << endl;
			}
			else {
				juegoPrincipal->setEstrategia(1);
				cout << "Eleccion digitada no corresponde a una opcion del menu" << endl;
				cout << "Estrategia automaticamente seateada a Aleatoria: " << endl;
			}
		}
		cout << "Presione enter" << endl;
		cin.get();
		
	} while (salidaMenuA!=true);
	
	
	return 0;

}