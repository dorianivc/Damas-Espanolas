#include "Ficha.h"

Ficha::Ficha(bool esNegra)
{
	
	this->esNegra = esNegra;
	esCorona = false;
}

Ficha::Ficha(const Ficha & x)
{
	
	this->esCorona = x.esCorona;
	this->esNegra = x.esNegra;
}

string Ficha::imprimeFicha()
{
	string salida=" ";
	if (this->esNegra==true&& this->esCorona == false) {
		salida = " O ";
	}
	 if (this->esNegra== true && this->esCorona == true) {
		salida = " N ";
	}
	 if (this->esNegra== false && this->esCorona == false) {
		salida = " X ";
	}
	 if (this->esNegra == false && this->esCorona == true) {
		salida = " B ";
	}
	return salida;
}

bool Ficha::esFichaNegra()
{
	return esNegra;
}

bool Ficha::getesCorona()
{
	return esCorona;
}

string Ficha::serializar()
{
	stringstream p;
	int negra = 0;
	int cor = 0;
	if (esNegra) {
		negra = 1;
	}
	else {
		negra = 0;
	}
	if (esCorona) {
		cor = 1;
	}
	else {
		cor = 0;
	}
	p << negra << "\t" << cor<<"\t";
	return p.str();
}



void Ficha::coronar()
{
	esCorona = true;
}

Ficha::~Ficha()
{
}
