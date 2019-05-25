#pragma once
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Nodo
{
	int dato;
	Nodo* izquierdo;
	Nodo* derecho;
public:
	Nodo(int =0);
	int getDato();
	void setDato(int);
	Nodo* getIzquierdo();
	void setIzquierdo(Nodo*);
	Nodo* getDerecho();
	void setDerecho(Nodo*);
	~Nodo();
};

