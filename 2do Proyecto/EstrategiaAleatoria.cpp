#include "EstrategiaAleatoria.h"



EstrategiaAleatoria::EstrategiaAleatoria()
{
}

vector<int> EstrategiaAleatoria::obtenerEstrategia(Tablero * tab)
{
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

			
			for (int i = 0; i <v; i++) {
				
				
				
				fila = jugada[(3*i)+1];
			
				
				columna = jugada[(3*i)+2];
				zeta = jugada[(3*i)+3];
				vector<int>prub;
				prub.push_back(posicionAleatoriaFicha[0]);
				prub.push_back(posicionAleatoriaFicha[1]);
				prub.push_back(fila);
				prub.push_back(columna);

				if(jugadaValida(posicionAleatoriaFicha[0], posicionAleatoriaFicha[1],fila,columna,tab->getFichaDelTablero(posicionAleatoriaFicha[0], posicionAleatoriaFicha[1]))){
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

string EstrategiaAleatoria::serializar()
{
	string k = "1";
	return k;
}



EstrategiaAleatoria::~EstrategiaAleatoria()
{
}

