#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
template<class T>
class ccolumna
{
public:
	ccolumna()
	{
		columna = vector<T>();
	
	};
	~ccolumna() {};
	void agregar(T dato)
	{
		columna.push_back(dato);
	}
	int longitud()
	{
		return columna.size();
	}

public:
	vector<T> columna;
};

