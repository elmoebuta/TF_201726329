#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class ccolumna
{
public:
	ccolumna()
	{
		nombre = "prueba";
		tipo = 1;
	 entero=vector<int>();
		palabra= vector <string>();
		

	
	};
	ccolumna(string nombre,int tipo)
	{
		this->nombre = nombre;
		this->tipo = tipo;
		 entero =  vector<int>();
		 palabra=  vector <string>();

	};
	void agregarentero(int dato) {
		entero.push_back(dato);
	}
	void agregarpalabra(string dato) {
		palabra.push_back(dato);
	}
	string getpalabra(int n)
	{
		return palabra[n];
	}
	int getentero(int n)
	{
		return entero[n];
	}
	~ccolumna() {};
	
	

public:
	
	string nombre;
	int tipo;
	vector<int> entero;
	vector<string> palabra;
	
};

