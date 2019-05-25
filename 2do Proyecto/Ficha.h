#pragma once
#include <string>
using namespace std;
class Ficha
{private:
	bool esNegra;
	bool esCorona;
public:
	Ficha(bool);
	Ficha(const Ficha&);
	string imprimeFicha();
	void coronar();
	~Ficha();
};

