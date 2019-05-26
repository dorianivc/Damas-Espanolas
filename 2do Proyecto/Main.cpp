#include "Tablero.h"
#include "EstrategiaAleatoria.h"
#include  "Estrategia.h"
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
	for (int i = -1; i < jugadas[0]-1; i++) {
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

	}

	
	cin.get();
	delete tab;
	return 0;

}