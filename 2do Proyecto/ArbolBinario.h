#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Nodo.h"
using namespace std;
class ArbolBinario{

	private:
		Nodo* raiz;
	public:
		ArbolBinario(int);
		void insertarNodo(Nodo*, int);
};
