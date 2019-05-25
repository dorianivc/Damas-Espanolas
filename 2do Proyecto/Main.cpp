#include "Tablero.h"
using namespace std;

int main() {
	cout << "Primer Tablero" << endl;
	Tablero* tab = Tablero::getInstancia();
	cout << tab->toString() << endl;
	tab->ingresarJugada(5, 2);
	cout << tab->toString() << endl;
	cout << "Segundo Tablero" << endl;
	Tablero* tab2 = Tablero::getInstancia();
	cout << tab->toString() << endl;
	tab->ingresarJugada(-5, 10);
	cout << tab->toString() << endl;
	cin.get();
	delete tab;
	return 0;

}