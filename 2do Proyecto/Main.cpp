#include "Tablero.h"
#include "EstrategiaAleatoria.h"
#include  "Estrategia.h"
#include <Windows.h>
#include "Jugador.h"
#include "Juego.h"
using namespace std;

int main() {
	cout << "Primer Tablero" << endl;
	Tablero* tab = Tablero::getInstancia();
	cout << tab->toString() << endl;
	//tab->ingresarJugadaBlancas(8, 2);//falta impedir movimientos ambiguios
	tab->actualizar();
	cout << tab->toString() << endl;
	EstrategiaAleatoria* est = new EstrategiaAleatoria();
	Jugador* jug = new Jugador("Dorian");
	Computadora* po = new Computadora();
	Juego* jueguito = new Juego(tab, jug, po, est);

	for (int i = 0; i < 8; i++) {
		cout << "Ocacion # " << i + 1 << endl;
		if (jueguito->realizarJugadaPC()) {
			cout << "Exito ejecutando el metodo" << endl;

		}
		cout << tab->toString() << endl;
		if (jueguito->realizarJugadaJugador()) {
			cout << "Realizado con exito" << endl;
		}
	}

	//cout << jug->toString() << endl;
	/*vector<int> jugadas = jug->calcularJugadas(tab, 5, 1);
	
	
	cout << "Posibilidades: " << jugadas[0] << endl;
	for (int i = 0; i < jugadas.size(); i++) {
		cout <<"Poscicion " << i<<": "<< jugadas[i] << endl;
	}
	if (jugadas.size()>0) {
		int var = 0;
		for (int i = -1; i < jugadas[0] - 1; i++) {
			var++;
			var++;
			if (jugadaValida(5, 1, jugadas[i + var], jugadas[i + var + 1])) {
				cout << "Jugada Fila: " << jugadas[i + var] << endl;
				cout << "Jugada Columna: " << jugadas[i + var + 1] << endl;
				cout << "Come con la Jugada?-> "; if (jugadas[i + var + 2] == 1) {
					cout << "Si" << endl;

				}
				else {
					cout << "No" << endl;
				}
			}
			cout << "Fin del ciclo: " << i + 2 << endl;
			cout << "/---------------------------------------------------/" << endl << endl;
		}
	}

	cout << "Probando Metodo numeros del 1 al 10" << endl; 
	for (int i = 0; i < 10; i++) {
		Sleep(1);
		cout << "# " << i+1 << endl;
		vector<int> prub = est->obtenerEstrategia(tab);
		cout << "Ficha a mover X: " << prub[0] << " Y: " << prub[1] << endl;
		cout << "Posicion a mover X: " << prub[2] << " Y: " << prub[3] << endl;
		int x1 = prub[0], x2 = prub[1], x = prub[2], y = prub[3];
		if(jugadaValida(x1,x2,x,y)) {
			cout << "Movimiento Valido" << endl;
		}
		else {
			cout << "Movimiento Invalido" << endl;
		}
	}
	
	
	delete est;
	delete tab;*/
	
	cin.get();
	
	return 0;

}