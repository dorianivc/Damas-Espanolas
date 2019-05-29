#include "EstrategiaAleatoria.h"



EstrategiaAleatoria::EstrategiaAleatoria()
{
}

vector<int> EstrategiaAleatoria::obtenerEstrategia(Tablero * tab)
{
	vector<int>jugada;
	vector<int>salida;
	int x = 0, y = 0;
	
	int var = 0;
	int z = 0; //comestibles
	bool pass = false;
	while (pass != true) {
		vector<int>posicionAleatoriaFicha = obtenerPosicionAJugarAleatoria(tab);
		jugada = calcularJugadas(tab, posicionAleatoriaFicha[0], posicionAleatoriaFicha[1]);
		int x1 = posicionAleatoriaFicha[0], x2 = posicionAleatoriaFicha[1];
		if (jugada[0] > 1) {
			int v;
			srand(time(NULL));
			for (int i = 0; i < 7; i++) {
			 v = 1 + rand() % (jugada[0] + 1 - 1);
			}

			
			for (int i = -1; i <v-1; i++) {
				var++;
				
				x = jugada[var];
				var++;
				
				y = jugada[var];
				z = jugada[var + 1];
				vector<int>prub;
				prub.push_back(posicionAleatoriaFicha[0]);
				prub.push_back(posicionAleatoriaFicha[1]);
				prub.push_back(x);
				prub.push_back(y);

				if((x==x1+1&&y==x2+1)|| (x == x1 + 1 && y == x2 - 1)||(x == x1 - 1 && y == x2 + 1)||(x == x1 - 1 && y == x2 - 1)|| (x == x1 + 2 && y == x2 - 2)|| (x == x1 + 2 && y == x2 +2)|| (x == x1 - 2 && y == x2 + 2)|| (x == x1 - 2 && y == x2 - 2)){
					pass = true;
					salida.push_back(posicionAleatoriaFicha[0]);
					salida.push_back(posicionAleatoriaFicha[1]);
					salida.push_back(x);
					salida.push_back(y);
					salida.push_back(z);
					
					return salida;
					

				}
				else {
					pass = false;
				}
				

			}
			
		}
		Sleep(1);
	}
	return salida;
}



EstrategiaAleatoria::~EstrategiaAleatoria()
{
}
