#include<iostream>
#include<string>

#include"tabla.h"
#include"arbolavl.h"

using namespace std;
template<typename T>
void imprimir(T e) {
	cout << " " << e;
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;


		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void main()
{
	cout << "Esta tabla trabaja solo con 2 tipos de datos," "string""and ""integer" << endl;
	cout << "menu" << endl;
	cout << "0)salir" << endl;
	cout << "1)crear tabla" << endl;
	cout << "2)insertar datos  de columnas" << endl;
	cout << "3)seleccion de datos por columnas" << endl;
	cout << "4)filtrado de datos  comienza por 's'" << endl;
	cout << "5)filtrado de datos  mayor de 30 y menor de 50" << endl;
	cout << "6)ordenamiento de datos por columnas" << endl;
	cout << "7)exportar" << endl;
	int num = -1;
	string res = "";
	string nombre;
	int tipo;
	int datoint = 0;
	string datostring = "hapy";
	int ncolumna = 0;
	ctabla t1 = ctabla();
	vector<ArbolAVL<int>> arbolentero = vector<ArbolAVL<int>>();
	vector<ArbolAVL<string>>arbolstring = vector<ArbolAVL<string>>();;
	int contcolumna=0;
	int contint = -1;
	int contstring = -1;
	while (num != 0)
	{

		if (num == 1)
		{
			cout << "¿agregar columna?(si / no)" << endl;
			cin >> res;
			while (res == "si")
			{
				cin >> nombre;
				cin >> tipo;
				t1.agregarcolumna(nombre, tipo);
				contcolumna = contcolumna + 1;
				
					ArbolAVL<int>* arbolitoint = new ArbolAVL<int>(imprimir<int>);
					arbolentero.push_back(*arbolitoint);
					
				
					ArbolAVL<string>* arbolitostring = new ArbolAVL<string>(imprimir<string>);
					arbolstring.push_back(*arbolitostring);
					
				
				cout << "agregar columna,si o no" << endl;
				cin >> res;

			}


		}
		else if (num == 2)
		{
			cout << "¿desea agregar dato? (si / no)" << endl;
			cin >> res;
			while (res == "si")
			{
				cout << "escriba el nombre,tipo y dato de su columna y la posicion" << endl;
				cin >> nombre;
				cin >> tipo;
				if (tipo == 1)
				{
					cin >> datoint;
					cin >> ncolumna;
					t1.datoentero(datoint, ncolumna - 1);
					arbolentero.at(ncolumna-1).Insertar(datoint);

				}
				else
				{
					cin >> datostring;
					cin >> ncolumna;
					t1.datopalabra(datostring, ncolumna - 1);
					arbolstring.at(ncolumna-1).Insertar(datostring);
				}

			}
		}
		else if (num == 3)
		{
			cout << "elija la cantidad de columnas que desea para su tabla" << endl;
			cin >> num;
			ctabla tablaaux = ctabla();
			for (int i = 0; i < num; i++)
			{
				cin >> nombre;
				cin >> tipo;
				tablaaux.agregarcolumna(nombre, tipo);
				int valaux = 0;
				if (tipo == 1)
				{
					valaux = t1.longitudint(nombre);
				}
				else
				{
					valaux = t1.longitudstring(nombre);
				}
				int numaux = tablaaux.numpornombre(nombre);
				for (i = 0; i < valaux; i++)
				{
					if (tipo == 1)
					{

						tablaaux.alto.at(numaux).agregarentero(t1.alto.at(numaux).getentero(i));
					}
					else if (tipo == 2)
					{

						tablaaux.alto.at(numaux).agregarpalabra(t1.alto.at(numaux).getpalabra(i));
					}
				}


			}


		}
		else if (num==4)
		{
			//////////////////////////////////////////////////////////////////////////////////////////////////
			//cout << "4)filtrado de datos  comienza por 's'" << endl;
			cout << "ingrese una columna que tenga palabras" << endl;
			int filcol;
			cin >> filcol;
			arbolentero.at(filcol).buscar2();
			
		}
		else if (num == 5)
		{

		//////////////////////////////////////////////////////////////////////////////////////////////////
		//cout << "5)filtrado de datos  mayor de 30 y menor de 50" << endl;
		cout << "ingrese una columna que tenga numeros" << endl;
		int filcol;
		cin >> filcol;
		arbolentero.at(filcol).buscar1();

		}
		else if (num == 6)
		{
		ctabla tablaaux = ctabla();
		for (int i = 0; i <contcolumna; i++)
		{
			string nombre= t1.alto.at(i).nombre;
			int tipo = t1.alto.at(i).tipo;
			tablaaux.agregarcolumna(nombre,tipo);
			int valaux = 0;
			if (tipo == 1)
			{
				valaux = t1.longitudint(nombre);
			}
			else
			{
				valaux = t1.longitudstring(nombre);
			}
			int numaux = tablaaux.numpornombre(nombre);
			for (i = 0; i < valaux; i++)
			{
				if (tipo == 1)
				{

					tablaaux.alto.at(numaux).agregarentero(t1.alto.at(numaux).getentero(i));
				}
				else if (tipo == 2)
				{

					tablaaux.alto.at(numaux).agregarpalabra(t1.alto.at(numaux).getpalabra(i));
				}
			}


		}
		///sigue;
		cout << "que columna desea ordenar?(nombre,tipo)" << endl;
		int numcol;
		cin >> numcol;
		cin >> tipo;
		
		if (tipo == 1)
		{

			for (int i = 1; i < tablaaux.alto.at(numcol-1).entero.size(); i++)
			{
				/////////////

				
				
				vector<int> flagint = vector<int>();
				vector<string> flagstr = vector<string>();
				for (int x = 0; x < tablaaux.alto.size(); x++)
				{
					flagint[x] = tablaaux.alto.at(x).entero[i];
					flagstr[x] = tablaaux.alto.at(x).palabra[i];
					
				}
				
				int j = i - 1;

					while (j >= 0 && tablaaux.alto.at(numcol-1).entero[j] > flagint[numcol-1])
					{
						for (int x = 0; x < tablaaux.alto.size(); x++)
						{
							 tablaaux.alto.at(x).entero[j+1]= tablaaux.alto.at(x).entero[j];;
							 tablaaux.alto.at(x).palabra[j+1]=tablaaux.alto.at(x).palabra[j];;

						}
						j = j - 1;
					}
					for (int x = 0; x < tablaaux.alto.size(); x++)
					{
						flagint[x] = tablaaux.alto.at(x).entero[j+1]=flagint[x];
						flagstr[x] = tablaaux.alto.at(x).palabra[j+1]=flagstr[x];

					}
				



			}
		}
		else if (tipo == 2)
		{
			for (int i = 1; i < tablaaux.alto.at(numcol - 1).palabra.size(); i++)
			{
				/////////////



				vector<int> flagint = vector<int>();
				vector<string> flagstr = vector<string>();
				for (int x = 0; x < tablaaux.alto.size(); x++)
				{
					flagint[x] = tablaaux.alto.at(x).entero[i];
					flagstr[x] = tablaaux.alto.at(x).palabra[i];

				}

				int j = i - 1;

				while (j >= 0 && tablaaux.alto.at(numcol - 1).palabra[j] > flagstr[numcol - 1])
				{
					for (int x = 0; x < tablaaux.alto.size(); x++)
					{
						tablaaux.alto.at(x).entero[j + 1] = tablaaux.alto.at(x).entero[j];;
						tablaaux.alto.at(x).palabra[j + 1] = tablaaux.alto.at(x).palabra[j];;

					}
					j = j - 1;
				}
				for (int x = 0; x < tablaaux.alto.size(); x++)
				{
					flagint[x] = tablaaux.alto.at(x).entero[j + 1] = flagint[x];
					flagstr[x] = tablaaux.alto.at(x).palabra[j + 1] = flagstr[x];

				}




			}



		}

		}

		else if (num == 7)
		{
		t1.show();

           }

	}



	cin.get();
	cin.get();




}





