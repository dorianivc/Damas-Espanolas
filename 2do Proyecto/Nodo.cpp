#include "Nodo.h"
#include "ArbolBinario.h"




Nodo::Nodo(int da)
{
	dato = da;
	izquierdo = NULL;
	derecho = NULL;

}

int Nodo::getDato()
{
	return dato;
}

void Nodo::setDato(int dato)
{
	this->dato = dato;
}

Nodo * Nodo::getIzquierdo()
{
	return izquierdo;
}

void  Nodo::setIzquierdo(Nodo *x)
{
	this->izquierdo = x;
}

Nodo * Nodo::getDerecho()
{
return derecho;
}

void  Nodo::setDerecho(Nodo * der)
{
	derecho = der;
}



Nodo::~Nodo()
{
}

