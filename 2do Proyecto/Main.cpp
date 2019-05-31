#include "Tablero.h"
#include "EstrategiaAleatoria.h"
#include  "Estrategia.h"
#include <Windows.h>
#include "Jugador.h"
#include "Juego.h"
using namespace std;

int main() {
	string menuA, nombre;
	int MenuA;
	cout << "Bienvenido a Damas " << endl;
	cout << "Por favor ingrese su nombre " << endl;
	getline(cin, nombre);
	cout << "Digite 1 para jugar" << endl;
	cout << "Digite 2 para cambiar la estrategia de la computadora" << endl;
	cout << "Digite 3 para cargar partida guardada" << endl;
	cout << "Por favor seleccione una opcion del menu" << endl;
	Tablero* tab = Tablero::getInstancia();
	Jugador* jugador = new Jugador(nombre);
	Computadora* compu = new Computadora();
	Juego* juegoPrincipal = new Juego(tab, jugador, compu);//seteado para ser aleatorio automaticamente
	getline(cin, menuA);
	MenuA = atoi(menuA.c_str());
	if (MenuA == 1) {
		string quienEmpieza, salirS;
		int empieza = 1;
		cout << "Si desea empezar usted, presione 1" << endl;
		cout << "Si desea que la computadora empiece, presione 2" << endl;
		getline(cin, quienEmpieza);
		empieza = atoi(quienEmpieza.c_str());
		bool salir = false;
		do{
			cout << "Si desea salir, presione 1, sino solo presione enter" << endl;
			getline(cin, salirS);
			int aux = atoi(salirS.c_str());
			if (aux == 1) {
				salir = true;
			}
			else {
				system("cls");
			}
			if (salir) {
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
					} while (jugoPC != true);
					do {
						jugoJugador = juegoPrincipal->realizarJugadaJugador();
					} while (jugoJugador != true);
				}
				else
				{
					cout << "Empieza jugador" << endl;
					bool jugoPC = false;
					bool jugoJugador = false;
					do {
						jugoJugador = juegoPrincipal->realizarJugadaJugador();
					} while (jugoJugador != true);
					do {
						cout << "Pensando" << endl;
						jugoPC = juegoPrincipal->realizarJugadaPC();
					} while (jugoPC != true);

				}
			}

		} while (salir != true);
	}
	cin.get();
	
	return 0;

}