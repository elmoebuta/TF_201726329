#pragma once
#include "nodoavl.h"

template<class T>
class ArbolAVL {
private:
	Nodo<T>* raiz;
	void(*procesar)(T); //puntero a función

	//Operaciones privadas
	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}

	void _rotarDerecha(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;
		//Actualizamos la altura

		nodo = p;
	}

	void _rotarIzquierda(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;
		//Actualizamos la altura

		nodo = p;
	}
	void _balanceo(Nodo<T>*& nodo) {
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		int fb = hder - hizq;

		if (fb > 1) { //rotar a la izq
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) { //verificar si aplica doble rotación
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1) { //rotar a la der
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) {//verificar si aplica doble rotación 
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
		//Actualizar la altura del nodo raiz
		hizq = _altura(nodo->izq);
		hder = _altura(nodo->der);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}
	void _buscar1(Nodo<T>*& nodo, int num1,int num2)
	{
		auto caso1 = [](int x, int y, int e)
		{
			if (e < x)
			{
				return 1;
			}
			else if ((x < e) && (e < y))
			{
				return 2;
			}
			else if (e > y)
			{
				return 3;
			};
		};
		if (nodo == nullptr)
		{
			return;
		}

		else if (caso1(num1,num2,nodo->elemento)==1)

		{
			_buscar1(nodo->izq, num1, num2);
		}
		else if (caso1(num1, num2, nodo->elemento) == 3)

		{
			_buscar1(nodo->der, num1, num2);
		}
		else if (caso1(num1, num2, nodo->elemento) == 2)

		{
			////
			busquedaentero[contador1] = nodo->elemento;
			contador1 = contador1 + 1;
			_buscar1(nodo->der, num1, num2);
			_buscar1(nodo->izq, num1, num2);
		}
		
	}
	void _buscar2(Nodo<T>*& nodo, char num1)
	{
		auto caso2 = [](char x,  string e)
		{
			if (e[0] < x)
			{
				return 1;
			}
			else if (x == e[0])
			{
				return 2;
			}
			else if ( x<e[0])
			{
				return 3;
			};
		};
		if (nodo == nullptr)
		{
			return;
		}

		else if (caso2(num1, nodo->elemento) == 1)

		{
			_buscar2(nodo->izq, num1);
		}
		else if (caso2(num1, nodo->elemento) == 3)

		{
			_buscar2(nodo->der, num1);
		}
		else if (caso2(num1, nodo->elemento) == 2)

		{
			////
			busquedastring[contador2] = nodo->elemento;
			contador2 = contador2 + 1;
			_buscar2(nodo->der, num1);
			_buscar2(nodo->izq, num1);
		}
	}
	bool _insertar(Nodo<T>*& nodo, T e) {

		if (nodo == nullptr) {
			//Nuevo elemento
			nodo = new Nodo<T>();
			nodo->elemento = e;
			return true;
		}
		else if (e == nodo->elemento)
			return false;
		else if (e < nodo->elemento) {
			_insertar(nodo->izq, e);
		}
		else if (e > nodo->elemento) {
			_insertar(nodo->der, e);
		}
		_balanceo(nodo);
		return true;
	}

	void _inOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrden(nodo->izq);
		procesar(nodo->elemento);
		_inOrden(nodo->der);
	}

	void _inOrdenH(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrdenH(nodo->izq);
		procesar(nodo->altura);
		_inOrdenH(nodo->der);
	}

public:
	int busquedaentero[1000];
	int contador1;
	string busquedastring[1000];
	int contador2;
	ArbolAVL(void(*nuevaFuncion)(T)) {
		this->procesar = nuevaFuncion;
		this->raiz = nullptr;
		 
		 contador1=0;
		 for (int i = 0; i < 1000; i++)
		 {
			 busquedastring[i] = "";
			 busquedaentero[i]=0;
		 }
		
		 contador2=0;
	}
	void buscar1()
	{
		_buscar1(raiz, 30,50);
		for (int i = 0; i < contador1; i++)
		{
			cout << busquedaentero[i] << endl;
		}
	}
	void buscar2()
	{
		_buscar2(raiz, 's');
		for (int i = 0; i < contador2; i++)
		{
			cout << busquedastring[i] << endl;
		}
	}
		
	bool Insertar(T e) {
		return _insertar(raiz, e);
	}
	void inOrden() {
		_inOrden(raiz);
	}
	void inOrdenH() {
		_inOrdenH(raiz);
	}
	
};
