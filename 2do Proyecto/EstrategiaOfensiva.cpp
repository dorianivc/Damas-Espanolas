#include "EstrategiaOfensiva.h"

vector<int> EstrategiaOfensiva::obtenerEstrategia(Tablero* tab)
{

	int x, y, h, k, z;
	vector<int> fichas = misFichas(tab);
	vector<int> posibles;
	vector<int> retorno;
	for (int i = 0; i < (fichas.size() / 2); i++) {
		x = (2 * i);
		y = (2 * i) + 1;
		if (posicionDePeligro(tab, fichas[x], fichas[y]) == true) {
			/*cout << "Ficha en peligro" << endl;
			cout << "(" << valorCoordenadaSalida(fichas[x]) << "," << fichas[y]+1 << ")" << endl;
			cin.get();*/
			vector<int> jugadasParaFicha = calcularJugadas(tab, fichas[x], fichas[y]);
			if (jugadasParaFicha.size() > 0) {
				for (int j = 0; j < jugadasParaFicha[0]; j++) {
					h = (3 * j) + 1;
					k = (3 * j) + 2;
					z = (3 * j) + 3;
					//tab->crear(jugadasParaFicha[h], jugadasParaFicha[k], true);
					if (posicionDePeligro(tab, jugadasParaFicha[h], jugadasParaFicha[k]) == false) {
						//tab->eliminar(jugadasParaFicha[h], jugadasParaFicha[k]);
						if (jugadaValida(fichas[x], fichas[y], jugadasParaFicha[h], jugadasParaFicha[k], tab->getFichaDelTablero(fichas[x], fichas[y]))) {
							posibles.push_back(fichas[x]);
							posibles.push_back(fichas[y]);
							posibles.push_back(jugadasParaFicha[h]);
							posibles.push_back(jugadasParaFicha[k]);
							posibles.push_back(jugadasParaFicha[z]);
							return posibles;
						}
					}
					//tab->eliminar(jugadasParaFicha[h], jugadasParaFicha[k]);
				}
			}
		}
	}

	bool come = false;
	vector<int> lasfichas = misFichas(tab);
	vector<int> estrategia;
	int indiceX, indiceY;//primer ciclo
	int  indiceH, indiceK, indiceZ;//segundo ciclo
	for (int i = 0; i < (lasfichas.size() / 2); i++) {
		indiceX = (2 * i);
		indiceY = (2 * i) + 1;
		x = lasfichas[indiceX];
		y = lasfichas[indiceY];
		vector<int> jugadasPosibles = calcularJugadas(tab, x, y);
		if (jugadasPosibles[0] > 0) {
			
			for (int i2 = 0; i2 < jugadasPosibles[0]; i2++) {
				indiceH = (3 * i2) + 1;
				indiceK = (3 * i2) + 2;
				indiceZ = (3 * i2) + 3;
				h = jugadasPosibles[indiceH];
				k = jugadasPosibles[indiceK];
				z = jugadasPosibles[indiceZ];
				/*cout << "Ficha: " << "(" << valorCoordenadaSalida(x) << "," << y+1 << ")" << " puede moverse a : " << "(" << valorCoordenadaSalida(h) << "," << k+1 << ")" << endl;
				if (z > 0) {
					cout << "Si come" << endl;
				}
				else {
					cout << "No come" << endl;
				}
				cout <<"Estatus de Peligro: "<< posicionDePeligro(tab, h, k) << endl;*/
				if (jugadaValida(x, y, h, k, tab->getFichaDelTablero(x, y))&&!posicionDePeligro(tab,h,k)) {
					if (z > 0) {
						come = true;
						estrategia.push_back(x);
						estrategia.push_back(y);
						estrategia.push_back(h);
						estrategia.push_back(k);
						estrategia.push_back(z);
						return estrategia;
					}
				}
			}
		}
	}
	if (come == false) {
		for (int i = 0; i < ((fichas.size()) / 2); i++) {
			x = (2 * i);
			y = (2 * i) + 1;
			/*cout << "X: " << x << "Ficha x:  " << fichas[x] << endl;
			cout << "Y: " << y << "Ficha y:  " << fichas[y] << endl;*/
			vector<int> jugadasParaFicha = calcularJugadas(tab, fichas[x], fichas[y]);
			for (int j = 0; j < jugadasParaFicha[0]; j++) {
				h = (3 * j) + 1;
				k = (3 * j) + 2;
				z = (3 * j) + 3;
				tab->crear(jugadasParaFicha[h], jugadasParaFicha[k], true);
				if (tab->getFichaDelTablero(fichas[x], fichas[y])->getesCorona()) {
					tab->getFichaDelTablero(jugadasParaFicha[h], jugadasParaFicha[k])->coronar();
				}
				if (!posicionDePeligro(tab, jugadasParaFicha[h], jugadasParaFicha[k])) {
					if (jugadaValida(fichas[x], fichas[y], jugadasParaFicha[h], jugadasParaFicha[k], tab->getFichaDelTablero(fichas[x], fichas[y]))) {
						posibles.push_back(fichas[x]);
						posibles.push_back(fichas[y]);
						posibles.push_back(jugadasParaFicha[h]);
						posibles.push_back(jugadasParaFicha[k]);
						posibles.push_back(jugadasParaFicha[z]);
					}

				}

				tab->eliminar(jugadasParaFicha[h], jugadasParaFicha[k]);
			}
		}
		if (posibles.size() > 0) {
			int var, var2, var3, var4, var5;
			srand(time(NULL));
			int random = 1 + rand() % ((posibles.size() / 5) + 1 - 1);
			for (int i = 0; i < random; i++) {
				var = (5 * i);
				var2 = (5 * i) + 1;
				var3 = (5 * i) + 2;
				var4 = (5 * i) + 3;
				var5 = (5 * i) + 4;

			}
			retorno.push_back(posibles[var]);
			retorno.push_back(posibles[var2]);
			retorno.push_back(posibles[var3]);
			retorno.push_back(posibles[var4]);
			retorno.push_back(posibles[var5]);
			//cout << "Usando Estrategia Defensiva" << endl;
			cin.get();
			return retorno;
		}
		else {//PASAMOS A LA ESTRATEGIA ALEATORIA
			//cout << "Usando Estrategia Random" << endl;
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

}

string EstrategiaOfensiva::serializar()
{
	string k = "3";
	return k;
}
