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
		if (posicionDePeligro(tab, fichas[x], fichas[y])) {
			cout << "Ficha en peligro" << endl;
			cout << "(" << fichas[x] << "," << fichas[y] << ")" << endl;
			cin.get();
			vector<int> jugadasParaFicha = calcularJugadas(tab, fichas[x], fichas[y]);
			for (int j = 0; j < jugadasParaFicha[0]; j++) {
				h = (3 * i);
				k = (3 * i) + 1;
				z = (3 * i) + 2;
				if (posicionDePeligro(tab, jugadasParaFicha[h], jugadasParaFicha[k])==false) {
					posibles.push_back(x);
					posibles.push_back(y);
					posibles.push_back(jugadasParaFicha[h]);
					posibles.push_back(jugadasParaFicha[k]);
					posibles.push_back(jugadasParaFicha[z]);
					return posibles;
				}
			}
		}
	}
	cout << "Limpiando Posibles" << endl;
	posibles.clear();
	for (int i = 0; i < ((fichas.size()) / 2); i++) {
		x = (2 * i);
		y = (2 * i) + 1;
		vector<int> jugadasParaFicha = calcularJugadas(tab, x, y);
		for (int j = 0; j < jugadasParaFicha[0]; j++) {
			h = (3 * i);
			k = (3 * i) + 1;
			z = (3 * i) + 2;
			if (!posicionDePeligro(tab, jugadasParaFicha[h], jugadasParaFicha[k])) {
				posibles.push_back(jugadasParaFicha[h]);
				posibles.push_back(jugadasParaFicha[k]);
				posibles.push_back(jugadasParaFicha[z]);
			}
		}
	}
	if (posibles.size() > 0) {
		int var, var2, var3;
		srand(time(NULL));
		int random = 1 + rand() % ((posibles.size() / 3) + 1 - 1);
		for (int i = 0; i < random; i++) {
			var = (3 * i);
			var2= (3 * i) + 1;
			var3 = (3 * i) + 2;

		}
		retorno.push_back(x);
		retorno.push_back(y);
		retorno.push_back(posibles[var]);
		retorno.push_back(posibles[var2]);
		retorno.push_back(posibles[var3]);
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

bool EstrategiaDefensiva::posicionDePeligro(Tablero* tab, int x, int y)
{

	if (tab->getFichaDelTablero(x + 1, y - 1) !=NULL) {
		if (tab->getFichaDelTablero(x + 1, y - 1)->esFichaNegra() == false) {
			return true;
		}
	}
	else if (tab->getFichaDelTablero(x + 1, y + 1) != NULL) {
		if (tab->getFichaDelTablero(x + 1, y + 1)->esFichaNegra()==false) {
			return true;
		}
	}
	else if (tab->getFichaDelTablero(x - 1, y - 1) != NULL) {
		if (tab->getFichaDelTablero(x - 1, y - 1)->esFichaNegra() == false && tab->getFichaDelTablero(x + 1, y - 1)->getesCorona()) {
			return true;
		}
	}
	else if (tab->getFichaDelTablero(x - 1, y + 1) != NULL) {
		if (tab->getFichaDelTablero(x - 1, y + 1)->esFichaNegra() == false && tab->getFichaDelTablero(x + 1, y + 1)->getesCorona()) {
			return true;
		}
	}
	else {
		return false;
	}
}
