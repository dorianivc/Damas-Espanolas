#include "Tablero.h"
#include "EstrategiaAleatoria.h"
#include  "Estrategia.h"
#include <Windows.h>
using namespace std;

int main() {
	cout << "Primer Tablero" << endl;
	Tablero* tab = Tablero::getInstancia();
	cout << tab->toString() << endl;
	tab->ingresarJugadaBlancas(8, 2);//falta impedir movimientos ambiguios
	tab->actualizar();
	cout << tab->toString() << endl;
	EstrategiaAleatoria* est = new EstrategiaAleatoria();
	vector<int> jugadas = est->calcularJugadas(tab, 0,1 );
	//cout << "Posibilidades: " << jugadas[0] << endl;
	/*for (int i = 0; i < jugadas.size(); i++) {
		cout <<"Poscicion " << i<<": "<< jugadas[i] << endl;
	}*/
	int var = 0;
	/*for (int i = -1; i < jugadas[0]-1; i++) {
		var++;
		var++;
		cout <<"Jugada Fila: "<< jugadas[i + var]+1 << endl;
		cout << "Jugada Columna: " << jugadas[i + var + 1]+1 << endl;
		cout << "Come con la Jugada?-> "; if (jugadas[i + var + 2] == 1) {
			cout << "Si" << endl;

		}
		else {
			cout << "No" << endl;
		}
		cout << "Fin del ciclo: " << i+2 << endl;
		cout << "/---------------------------------------------------/" << endl << endl;
		*/


	cout << "Probando Metodo numeros del 1 al 10" << endl; 
	for (int i = 0; i < 10; i++) {
		Sleep(1);
		cout << "# " << i+1 << endl;
		vector<int> prub = est->obtenerEstrategia(tab);
		cout << "Ficha a mover X: " << prub[0] << " Y: " << prub[1] << endl;
		cout << "Posicion a mover X: " << prub[2] << " Y: " << prub[3] << endl;
		int x1 = prub[0], x2 = prub[1], x = prub[2], y = prub[3];
		if ((x == x1 + 1 && y == x2 + 1) || (x == x1 + 1 && y == x2 - 1) || (x == x1 - 1 && y == x2 + 1) || (x == x1 - 1 && y == x2 - 1) || (x == x1 + 2 && y == x2 - 2) || (x == x1 + 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 + 2) || (x == x1 - 2 && y == x2 - 2)) {
			cout << "Movimiento Valido" << endl;
		}
		else {
			cout << "Movimiento Invalido" << endl;
		}
	}
	
	
	delete est;
	delete tab;
	
	cin.get();
	
	return 0;

}