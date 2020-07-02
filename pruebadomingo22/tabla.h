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
	void datoentero(int dato,int ncolumna)
	{
		alto.at(ncolumna).agregarentero(dato);
	}
	void datopalabra(string dato,int ncolumna)
	{
		alto.at(ncolumna).agregarpalabra(dato);
	}
	int longitudint(string nombre)
	{
		for (int i = 0; i < alto.size(); i++)
		{
			if (alto.at(i).nombre==nombre)
			{
				return alto.at(i).entero.size();
			}
		}
	}
	int longitudstring(string nombre)
	{
		for (int i = 0; i < alto.size(); i++)
		{
			if (alto.at(i).nombre == nombre)
			{
				return alto.at(i).palabra.size();
			}
		}
	}
	int numpornombre(string nombre)
	{
		for (int i = 0; i < alto.size(); i++)
		{
			if (alto.at(i).nombre == nombre)
			{
				return i;
			}
		}
	}
	void show()
	{
		for (int i = 0; i < alto.size(); i++)
		{
			cout << alto.at(i).nombre << " ";
		}
		
		
			for (int j = 0; j < alto.at(0).entero.size(); j++)
			{
				for (int i = 0; i < alto.size(); i++)
				{
					cout<<alto.at(i).getentero(j)<<" ";
					cout << alto.at(i).getpalabra(j) << " ";

				}
				cout << endl;
			}
		
	}
public:
	vector<ccolumna> alto;
};

