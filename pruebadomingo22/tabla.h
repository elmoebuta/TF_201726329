#pragma once
#include"columna.h"

class ctabla
{
public:
	ctabla() 
	{
		alto = vector<ccolumna>();

	};
	~ctabla() 
	{
		
	};
	void agregarcolumna(string nombre,int tipo)
	{
		alto.push_back(ccolumna(nombre, tipo));
	}

private:
	vector<ccolumna> alto;
};

