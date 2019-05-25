#include "ArbolBinario.h"

ArbolBinario::ArbolBinario(int dato)
{
	raiz = new Nodo(dato);
}

void ArbolBinario::insertarNodo(Nodo * raiz, int f)
{
	if (raiz == NULL) {//si el arbol esta vacio;
		raiz = new Nodo(f);
	}
	else {//si el arbol tiene un nodo o mas
		int valorRaiz = raiz->getDato();
		if (f < valorRaiz) {
			insertarNodo(raiz->getIzquierdo(), f);
		}
		else {
			insertarNodo(raiz->getDerecho(), f);
		}
	}
}
