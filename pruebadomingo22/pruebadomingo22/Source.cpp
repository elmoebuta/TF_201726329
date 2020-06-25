#include<iostream>
#include"columna.h"
using namespace std;

void main()
{
	cout << "Esta tabla trabaja solo con 2 tipos de datos," "string""and ""integer" << endl;
	cout << "menu" << endl;
	cout << "1)crear tabla" << endl;
	int num = 0;
	while (num != -1)
	{
		cin >> num;
		if (num == 1)
		{
			//ccolumna<string> columnin =  ccolumna<string>();

		}
		if (num == 2)
		{
			ccolumna<int> columnin = ccolumna<int>();
			cout << columnin.longitud();
		}
		
}
	
	

	cin.get();
	cin.get();




}