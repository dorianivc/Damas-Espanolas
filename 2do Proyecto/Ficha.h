#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "ObjetoBase.h"
using namespace std;
class Ficha:public ObjetoBase
{private:
	bool esNegra;
	bool esCorona;
public:
	Ficha(bool);
	Ficha(const Ficha&);
	string imprimeFicha();
	bool esFichaNegra();
	bool getesCorona();
	string serializar();
	void coronar();
	~Ficha();
};

