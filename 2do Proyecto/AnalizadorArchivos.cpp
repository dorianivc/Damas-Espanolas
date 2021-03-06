#include "AnalizadorArchivos.h"

void AnalizadorArchivos::guardar(Juego* juego)
{
	ofstream archivoTablero;
	archivoTablero.open("InformacionTableroGuardada.txt");
	if (!archivoTablero.fail()) {
		archivoTablero << juego->getTablero()->serializar();
	}
	archivoTablero.close();
	//Ya se guardo el tablero

	ofstream archivoComputadora;
	archivoComputadora.open("InformacionComputadoraGuardada.txt");
	if (!archivoComputadora.fail()) {
		archivoComputadora << juego->getComputadora()->serializar();
	}
	archivoComputadora.close();
	//Ya se guardo la computadora

	ofstream archivoJugador;
	archivoJugador.open("InformacionJugadorGuardada.txt");
	if (!archivoJugador.fail()) {
		archivoJugador << juego->getJugador()->serializar();
	}
	archivoJugador.close();
	//Ya se guardo el jugador
	ofstream archivoEstrategia;
	archivoEstrategia.open("InformacionEstrategiaGuardada.txt");
	if (!archivoEstrategia.fail()) {
		archivoEstrategia << juego->getTipoEstrategia();
	}
	archivoEstrategia.close();
}

void AnalizadorArchivos::recuperar(Juego* juego)
{
	ifstream archivoTablero;
	archivoTablero.open("InformacionTableroGuardada.txt");
	if (!archivoTablero.fail()) {
		juego->getTablero()->vaciarTablero();
		
		while (!archivoTablero.eof()) {
			string auxX, auxY, negra, coronas;
			int x; int y; int esNegra; int CORONAS;
			getline(archivoTablero, auxX, '\t');
			x = atoi(auxX.c_str());
			getline(archivoTablero, auxY, '\t');
			y = atoi(auxY.c_str());
			getline(archivoTablero, negra, '\t');
			esNegra = atoi(negra.c_str());
			getline(archivoTablero, coronas, '\t');
			CORONAS = atoi(coronas.c_str());
			if (!juego->getTablero()->fichaExiste(x, y)) {
				juego->getTablero()->crear(x, y, esNegra);
			}
			//cout << "X: " << x << " Y: " << y << "Es Negra: " << esNegra << " Corona?: " << CORONAS << endl;
			if (CORONAS > 0) {
				juego->getTablero()->getFichaDelTablero(x, y)->coronar();
			}
		}
		cout << "Tablero recueperado" << endl;
		cout << juego->getTablero()->toString() << endl;
	}
	else {
		cout << "Error abriendo el archivo --> InformacionTableroGuardada.txt" << endl;
		cout << "Archivo no existe o da�ado" << endl;
	}
	archivoTablero.close();
	//ya tuvo que haber recuperado las fichas
	
	ifstream archivoJugador;
	archivoJugador.open("InformacionJugadorGuardada.txt");
	if (!archivoJugador.fail()) {
		string nombre;
		string fiRestantes;
		string corRestantes;
		int fichasRestantes;
		int cor;
		//while (!archivoJugador.eof()) {
			getline(archivoJugador, nombre, '\t');
			getline(archivoJugador, fiRestantes, '\t');
			fichasRestantes = atoi(fiRestantes.c_str());
			getline(archivoJugador, corRestantes, '\t');
			cor = atoi(corRestantes.c_str());
			juego->getJugador()->setNombre(nombre);
			juego->getJugador()->setFichasRestantes(fichasRestantes);
			juego->getJugador()->setCoronas(cor);
		//}
		cout << "Jugador recuperado" << endl;
		cout << juego->getJugador()->toString() << endl;
	}
	else {
		cout << "Error abriendo el archivo --> InformacionJugadorGuardada.txt" << endl;
		cout << "Archivo no existe o da�ado" << endl;
	}
	archivoJugador.close();
	//Ya recupero jugador

	ifstream archivoComputadora;

	archivoComputadora.open("InformacionComputadoraGuardada.txt");
	if (!archivoComputadora.fail()) {
		string fiRestantes;
		string corRestantes;
		int fichasRestantes;
		int cor;
	//	while (!archivoComputadora.eof()) {
			getline(archivoComputadora, fiRestantes, '\t');
			fichasRestantes = atoi(fiRestantes.c_str());
			getline(archivoComputadora, corRestantes, '\t');
			cor = atoi(corRestantes.c_str());
			juego->getComputadora()->setFichasRestantes(fichasRestantes);
			juego->getComputadora()->setCoronas(cor);
	//	}
		cout << "Computadora Cargada" << endl;
		cout << juego->getComputadora()->toString() << endl;
	}
	else {
		cout << "Error abriendo el archivo --> InformacionComputadoraGuardada.txt" << endl;
		cout << "Archivo no existe o da�ado" << endl;
	}
	archivoComputadora.close();

	ifstream archivoEstrategia;
	archivoEstrategia.open("InformacionEstrategiaGuardada.txt");
	if (!archivoEstrategia.fail()) {
		int elec = 1;
		string eleccion;
		while (!archivoEstrategia.eof()) {
			getline(archivoEstrategia, eleccion, '\t');
			elec = atoi(eleccion.c_str());
			if (elec == 1) {
				juego->setEstrategia(1);
			}
			else if (elec == 2) {
				juego->setEstrategia(2);
			}
			else if (elec == 3) {
				juego->setEstrategia(3);
			}
			else {
				juego->setEstrategia(1);
			}
		}
		cout << "Estrategia Cargada" << endl;
	}
	else {
		cout << "Error abriendo el archivo --> InformacionEstrategiaGuardada.txt" << endl;
		cout << "Archivo no existe o da�ado" << endl;
	}
	archivoEstrategia.close();

}
