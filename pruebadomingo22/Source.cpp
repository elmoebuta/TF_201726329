#include<iostream>
#include"tabla.h"
using namespace std;

void main()
{
	cout << "Esta tabla trabaja solo con 2 tipos de datos," "string""and ""integer" << endl;
	cout << "menu" << endl;
	cout << "0)salir"<<endl;
	cout << "1)crear tabla" << endl;
	cout << "2)indexar por columnas" << endl;
	cout << "3)seleccion de datos por columnas" << endl;
	cout << "4)filtrado de datos por columnas" << endl;
	cout << "5)ordenamiento de datos por columnas" << endl;
	cout << "6)exportar" << endl;
	int num = -1;
	string res = "";
	string nombre;
	int tipo;
	while (num != 0)
	{
		ctabla t1 = ctabla();
		if (num==1)
		{
			cout << "agregar columna,si o no" << endl;
			cin >> res;
			while (res == "si")
			{
				cin >> nombre;
				cin >> tipo;
				t1.agregarcolumna(nombre, tipo);
				cout << "agregar columna,si o no" << endl;
				cin >> res;
			}

		}
		




	}
	
	

	cin.get();
	cin.get();




}