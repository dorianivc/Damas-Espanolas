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
	vector<int> jugadas = est->calcularJugadas(tab, 2, 2);
	cout << "Posibilidades: " << jugadas[0] << endl;
	for (int i = 0; i < (jugadas.size()-3); i++) {
		
		if (jugadas[i + 1] != 99 && jugadas[i + 2] != 99) {
			cout << "Jugada Numero: " << i+1 << endl;
			cout << "Posicion Fila: " << jugadas[i + 1] << endl;
			cout << "Posicion de Columna: " << jugadas[i + 2] << endl;
			cout << "Come con la Jugada? -->" ; if (jugadas[i + 3] == 1) {
				cout << "SI" << endl;
			}
			else {
				cout << "NO" << endl;
			}
			cout << "/------------------------------------------/" << endl;
		}
	}
	cin.get();
	delete tab;
	return 0;

}