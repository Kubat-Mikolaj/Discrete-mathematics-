#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include<cmath>
#include <iomanip>

using namespace std;

int n;
int funkcje[16];
int funkcje_liczba = 0;
int x[16][4];
int X[4][4];
string tablicaXX[4][4];

string zmienna[10];
int zmienna_liczba = 0;

void Tablica();
void Tablica_zmiennych();
void Wyswietl_Funkcje();
void Tabela_karnaugh();
void Wyswietl_karnaugh();
void Przeszukiwanie_tablicy_karnaugh();

int main()
{
	Tablica();
	Tablica_zmiennych();
	Wyswietl_Funkcje();
	Tabela_karnaugh();
	Wyswietl_karnaugh();
	Przeszukiwanie_tablicy_karnaugh();
}

//Funkcje:

void Tablica()
{
	cout << "Podaj wielkosc n zmiennych \n";
	cin >> n;
	cout << "Podaj kolejno funkcje \n";

	for (int i = 0; i <= pow(2, n) - 1; i++) cin >> funkcje[i];
	cout << endl << "Tablica z funkcja:" << endl;


	// x[i][j] --> i[kolumna], j[wiersz]

	x[0][0]=0; x[0][1]=0; x[0][2]=0;    // Tablica - Wariant 3
	x[1][0]=0; x[1][1]=0; x[1][2]=1;
	x[2][0]=0; x[2][1]=1; x[2][2]=0;
	x[3][0]=0; x[3][1]=1; x[3][2]=1;
	x[4][0]=1; x[4][1]=0; x[4][2]=0;
	x[5][0]=1; x[5][1]=0; x[5][2]=1;
	x[6][0]=1; x[6][1]=1; x[6][2]=0;
	x[7][0]=1; x[7][1]=1; x[7][2]=1;

	for (int i = 0; i <= pow(2, n) - 1; i++)
	{

		if (n == 3)
			cout << x[i][0] << "   " << x[i][1] << "   " << x[i][2] << "   " << funkcje[i] << endl;
		if (n == 2)
			cout << x[i][0] << "   " << x[i][1] << "   " << funkcje[i] << endl;
	}
}

void Tablica_zmiennych()
{
	//tablicaXX
	if (n == 2)
	{
		// TablicaA\B
		tablicaXX[0][0] = "!A!B";
		tablicaXX[0][1] = "!AB";
		tablicaXX[1][0] = "A!B";
		tablicaXX[1][1] = "AB";
	}
	if (n == 3)
	{
		//TablicaA\BC
		tablicaXX[0][0] = "!A!B!C";
		tablicaXX[0][1] = "!A!BC";
		tablicaXX[0][2] = "!ABC";
		tablicaXX[0][3] = "!AB!C";
		tablicaXX[1][0] = "A!B!C";
		tablicaXX[1][1] = "A!BC";
		tablicaXX[1][2] = "ABC";
		tablicaXX[1][3] = "AB!C";
	}

}

void Wyswietl_Funkcje()
{
	cout << endl;
	//Przepisanie dla f==1
	for (int i = 0; i <= pow(2, n) - 1; i++)
	{
		if (funkcje[i] == 1)
		{
			for (int j = 0; j <= n - 1; j++)
			{
				if (x[i][0] == 0 && j == 0) cout << "!A";
				if (x[i][0] == 1 && j == 0) cout << "A";
				if (x[i][1] == 0 && j == 1) cout << "!B";
				if (x[i][1] == 1 && j == 1) cout << "B";
				if (x[i][2] == 0 && j == 2) cout << "!C";
				if (x[i][2] == 1 && j == 2) cout << "C";
				if (x[i][3] == 0 && j == 3) cout << "!D";
				if (x[i][3] == 1 && j == 3) cout << "D";
			}
			if (i != pow(2, n) - 1)cout << " + ";
		}
	}
}

void Tabela_karnaugh()
{
	// Tabela karnaugh
	for (int i = 0; i <= pow(2, n) - 1; i++)
	{
		if (n == 2)
		{
			if (funkcje[i] == 1)
			{
				if (x[i][0] == 0 && x[i][1] == 0)X[0][0] = 1;
				if (x[i][0] == 0 && x[i][1] == 1)X[0][1] = 1;
				if (x[i][0] == 1 && x[i][1] == 0)X[1][0] = 1;
				if (x[i][0] == 1 && x[i][1] == 1)X[1][1] = 1;
			}
			if (funkcje[i] == 0)
			{
				if (x[i][0] == 0 && x[i][1] == 0)X[0][0] = 0;
				if (x[i][0] == 0 && x[i][1] == 1)X[0][1] = 0;
				if (x[i][0] == 1 && x[i][1] == 0)X[1][0] = 0;
				if (x[i][0] == 1 && x[i][1] == 1)X[1][1] = 0;
			}
		}
		if (n == 3)
		{
			if (funkcje[i] == 1)
			{
				if (x[i][0] == 0 && x[i][1] == 0 && x[i][2] == 0)X[0][0] = 1;
				if (x[i][0] == 0 && x[i][1] == 0 && x[i][2] == 1)X[0][1] = 1;
				if (x[i][0] == 0 && x[i][1] == 1 && x[i][2] == 1)X[0][2] = 1;
				if (x[i][0] == 0 && x[i][1] == 1 && x[i][2] == 0)X[0][3] = 1;
				if (x[i][0] == 1 && x[i][1] == 0 && x[i][2] == 0)X[1][0] = 1;
				if (x[i][0] == 1 && x[i][1] == 0 && x[i][2] == 1)X[1][1] = 1;
				if (x[i][0] == 1 && x[i][1] == 1 && x[i][2] == 1)X[1][2] = 1;
				if (x[i][0] == 1 && x[i][1] == 1 && x[i][2] == 0)X[1][3] = 1;
			}
			if (funkcje[i] == 0)
			{
				if (x[i][0] == 0 && x[i][1] == 0 && x[i][2] == 0)X[0][0] = 0;
				if (x[i][0] == 0 && x[i][1] == 0 && x[i][2] == 1)X[0][1] = 0;
				if (x[i][0] == 0 && x[i][1] == 1 && x[i][2] == 1)X[0][2] = 0;
				if (x[i][0] == 0 && x[i][1] == 1 && x[i][2] == 0)X[0][3] = 0;
				if (x[i][0] == 1 && x[i][1] == 0 && x[i][2] == 0)X[1][0] = 0;
				if (x[i][0] == 1 && x[i][1] == 0 && x[i][2] == 1)X[1][1] = 0;
				if (x[i][0] == 1 && x[i][1] == 1 && x[i][2] == 1)X[1][2] = 0;
				if (x[i][0] == 1 && x[i][1] == 1 && x[i][2] == 0)X[1][3] = 0;
			}
		}


		}
	}


void Wyswietl_karnaugh()
{
	if (n == 2)
	{
		cout
			<< endl
			<< endl
			<< left
			<< setw(5)
			<< "A\\B"
			<< left
			<< setw(3)
			<< "0"
			<< left
			<< setw(3)
			<< "1"
			<< endl;
		// x[i][j] --> i[kolumna], j[wiersz]
		for (int i = 0; i <= n - 1; i++)
		{
			if (i == 0)cout << left << setw(5) << " 0 ";
			if (i == 1)cout << left << setw(5) << " 1 ";

			for (int j = 0; j <= n - 1; j++)
			{
				cout << left << setw(3) << X[i][j];
			}
			cout << endl;
		}
	}
	if (n == 3)
	{
		cout
			<< endl
			<< endl
			<< left
			<< setw(5)
			<< "A\\BC"
			<< left
			<< setw(3)
			<< "00"
			<< left
			<< setw(3)
			<< "01"
			<< left
			<< setw(3)
			<< "11"
			<< left
			<< setw(3)
			<< "10"
			<< endl;
		// x[i][j] --> i[kolumna], j[wiersz]
		for (int i = 0; i <= n - 2; i++)
		{
			if (i == 0)cout << left << setw(5) << " 0 ";
			if (i == 1)cout << left << setw(5) << " 1 ";

			for (int j = 0; j <= n; j++)
			{
				cout << left << setw(3) << X[i][j];
			}
			cout << endl;
		}

	}

}

void Przeszukiwanie_tablicy_karnaugh()
{
	//Przeszukiwanie tablicy karnaugh
	cout << endl;

	if (n == 2)
	{
		// Dla 4
		if (X[0][0] == 1 && X[0][1] == 1 && X[1][0] == 1 && X[1][1] == 1)cout << "1 ";
		else
		{
			// Dla 2
			if (X[0][0] == 1 && X[0][1] == 1)cout << "!A ";
			if (X[1][0] == 1 && X[1][1] == 1)cout << "A ";
			if (X[0][0] == 1 && X[1][0] == 1)cout << "!B ";
			if (X[0][1] == 1 && X[1][1] == 1)cout << "B ";
			// Dla 1

			if (X[0][0] == 1 && X[0][1] == 0 && X[1][0] == 0)cout << "!A!B ";
			if (X[0][0] == 0 && X[0][1] == 1 && X[1][1] == 0)cout << "!AB ";
			if (X[1][0] == 1 && X[0][0] == 0 && X[1][1] == 0)cout << "A!B ";
			if (X[1][0] == 0 && X[1][1] == 1 && X[0][1] == 0)cout << "AB ";
		}
	}

	if (n == 3)
	{
		//Dla 8 podłużnie [1 1 1 1]
		if (X[0][0] == 1 && X[0][1] == 1 && X[0][2] == 1 && X[0][3] == 1 &&
			X[1][0] == 1 && X[1][1] == 1 && X[1][2] == 1 && X[1][3] == 1)
		{
			zmienna[zmienna_liczba] = "1";
			zmienna_liczba = zmienna_liczba + 1;
		}

		else
		{
			//Dla 4 poziomo [1 1 1 1]
			for (int i = 0; i <= 1; i++)
			{
				if (X[i][0] == 1 && X[i][1] == 1 && X[i][2] == 1 && X[i][3] == 1)
				{
					X[i][0] = 2;
					X[i][1] = 2;
					X[i][2] = 2;
					X[i][3] = 2;
					if (i == 0)
					{
						zmienna[zmienna_liczba] = "!A";
						zmienna_liczba = zmienna_liczba + 1;
					}
					if (i == 1)
					{
						zmienna[zmienna_liczba] = "A";
						zmienna_liczba = zmienna_liczba + 1;
					}
				}
			}

			// Dla 4 kwadratowych
			if ((X[0][0] == 1 || X[0][0] == 2) && (X[0][1] == 1 || X[0][1] == 2) && (X[1][0] == 1 || X[1][0] == 2) && (X[1][1] == 1 || X[1][1] == 2))
			{
				X[0][0] = 2;
				X[0][1] = 2;
				X[1][0] = 2;
				X[1][1] = 2;
				zmienna[zmienna_liczba] = "!B";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if ((X[0][1] == 1 || X[0][1] == 2) && (X[0][2] == 1 || X[0][2] == 2) && (X[1][1] == 1 || X[1][1] == 2) && (X[1][2] == 1 || X[1][2] == 2))
			{
				X[0][1] = 2;
				X[0][2] = 2;
				X[1][1] = 2;
				X[1][2] = 2;
				zmienna[zmienna_liczba] = "C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if ((X[0][2] == 1 || X[0][2] == 2) && (X[0][3] == 1 || X[0][3] == 2) && (X[1][2] == 1 || X[1][2] == 2) && (X[1][3] == 1 || X[1][3] == 2))
			{
				X[0][2] = 2;
				X[0][3] = 2;
				X[1][2] = 2;
				X[1][3] = 2;
				zmienna[zmienna_liczba] = "B";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if ((X[0][3] == 1 || X[0][3] == 2) && (X[0][0] == 1 || X[0][0] == 2) && (X[1][3] == 1 || X[1][3] == 2) && (X[1][0] == 1 || X[1][0] == 2))
			{
				X[0][3] = 2;
				X[0][0] = 2;
				X[1][3] = 2;
				X[1][0] = 2;
				zmienna[zmienna_liczba] = "!C";
				zmienna_liczba = zmienna_liczba + 1;
			}

			// Dla 2
            // Dla grupowania w 2 pary (1 1)
			if (X[0][0] == 1 && X[0][3] == 1)
			{
				X[0][0] = 2;
				X[0][3] = 2;
				zmienna[zmienna_liczba] = "!A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[0][0] == 1 && X[0][1] == 1)
			{
				X[0][0] = 2;
				X[0][1] = 2;
				zmienna[zmienna_liczba] = "!A!B";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][0] == 1 && X[1][0] == 1)
			{
				X[0][0] = 2;
				X[1][0] = 2;
				zmienna[zmienna_liczba] = "!B!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][1] == 1 && X[0][0] == 1)
			{
				X[0][1] = 2;
				X[0][0] = 2;
				zmienna[zmienna_liczba] = "!A!B";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[0][1] == 1 && X[0][2] == 1)
			{
				X[0][1] = 2;
				X[0][2] = 2;
				zmienna[zmienna_liczba] = "!A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][1] == 1 && X[1][1] == 1)
			{
				X[0][1] = 2;
				X[1][1] = 2;
				zmienna[zmienna_liczba] = "!BC";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][2] == 1 && X[0][1] == 1)
			{
				X[0][2] = 2;
				X[0][1] = 2;
				zmienna[zmienna_liczba] = "!AC";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[0][2] == 1 && X[0][3] == 1)
			{
				X[0][2] = 2;
				X[0][3] = 2;
				zmienna[zmienna_liczba] = "!AB";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][2] == 1 && X[1][2] == 1)
			{
				X[0][2] = 2;
				X[1][2] = 2;
				zmienna[zmienna_liczba] = "BC";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][3] == 1 && X[0][2] == 1)
			{
				X[0][3] = 2;
				X[0][2] = 2;
				zmienna[zmienna_liczba] = "!AB";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[0][3] == 1 && X[0][0] == 1)
			{
				X[0][3] = 2;
				X[0][0] = 2;
				zmienna[zmienna_liczba] = "!A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][3] == 1 && X[1][3] == 1 )
			{
				X[0][3] = 2;
				X[1][3] = 2;
				zmienna[zmienna_liczba] = "B!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][0] == 1 && X[1][3] == 1)
			{
				X[1][0] = 2;
				X[1][3] = 2;
				zmienna[zmienna_liczba] = "A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][0] == 1 && X[1][1] == 1)
			{
				X[1][0] = 2;
				X[1][1] = 2;
				zmienna[zmienna_liczba] = "A!B";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][0] == 1 && X[0][0] == 1)
			{
				X[1][0] = 2;
				X[0][0] = 2;
				zmienna[zmienna_liczba] = "!B!C";
				zmienna_liczba = zmienna_liczba + 1;
			}//////////////// w gore
			if (X[1][1] == 1 && X[1][0] == 1)
			{
				X[1][1] = 2;
				X[1][0] = 2;
				zmienna[zmienna_liczba] = "A!B";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[1][1] == 1 && X[1][2] == 1)
			{
				X[1][1] = 2;
				X[1][2] = 2;
				zmienna[zmienna_liczba] = "AC";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][1] == 1 && X[0][1] == 1)
			{
				X[1][1] = 2;
				X[0][1] = 2;
				zmienna[zmienna_liczba] = "!BC";
				zmienna_liczba = zmienna_liczba + 1;
			}//////////// w gore
			if (X[1][2] == 1 && X[1][1] == 1)
			{
				X[1][2] = 2;
				X[1][1] = 2;
				zmienna[zmienna_liczba] = "AC";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[1][2] == 1 && X[1][3] == 1)
			{
				X[1][2] = 2;
				X[1][3] = 2;
				zmienna[zmienna_liczba] = "AB";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][2] == 1 && X[0][2] == 1)
			{
				X[1][2] = 2;
				X[0][2] = 2;
				zmienna[zmienna_liczba] = "BC";
				zmienna_liczba = zmienna_liczba + 1;
			}/////////////// w gore
			if (X[1][3] == 1 && X[1][2] == 1)
			{
				X[1][3] = 2;
				X[1][2] = 2;
				zmienna[zmienna_liczba] = "AB";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[1][3] == 1 && X[1][0] == 1)
			{
				X[1][3] = 2;
				X[1][0] = 2;
				zmienna[zmienna_liczba] = "A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][3] == 1 && X[0][3] == 1)
			{
				X[1][3] = 2;
				X[0][3] = 2;
				zmienna[zmienna_liczba] = "B!C";
				zmienna_liczba = zmienna_liczba + 1;
			}///////////////// w gore


			// Dla 1

		    // Dla łączenie samotnych 1 w pare z istniejącą grupą (1 2)
			if (X[0][0] == 1 && X[0][3] == 2)
			{
				X[0][0] = 2;
				zmienna[zmienna_liczba] = "!A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[0][0] == 1 && X[0][1] == 2)
			{
				X[0][0] = 2;
				zmienna[zmienna_liczba] = "!A!B";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][0] == 1 && X[1][0] == 2)
			{
				X[0][0] = 2;
				zmienna[zmienna_liczba] = "!B!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][1] == 1 && X[0][0] == 2)
			{
				X[0][1] = 2;
				zmienna[zmienna_liczba] = "!A!B";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[0][1] == 1 && X[0][2] == 2)
			{
				X[0][1] = 2;
				zmienna[zmienna_liczba] = "!A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][1] == 1 && X[1][1] == 2)
			{
				X[0][1] = 2;
				zmienna[zmienna_liczba] = "!BC";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][2] == 1 && X[0][1] == 2)
			{
				X[0][2] = 2;
				zmienna[zmienna_liczba] = "!AC";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[0][2] == 1 && X[0][3] == 2)
			{
				X[0][2] = 2;
				zmienna[zmienna_liczba] = "!AB";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][2] == 1 && X[1][2] == 2)
			{
				X[0][2] = 2;
				zmienna[zmienna_liczba] = "BC";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][3] == 1 && X[0][2] == 2)
			{
				X[0][3] = 2;
				zmienna[zmienna_liczba] = "!AB";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[0][3] == 1 && X[0][0] == 2)
			{
				X[0][3] = 2;
				zmienna[zmienna_liczba] = "!A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[0][3] == 1 && X[1][3] == 2)
			{
				X[0][3] = 2;
				zmienna[zmienna_liczba] = "B!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][0] == 1 && X[1][3] == 2)
			{
				X[1][0] = 2;
				zmienna[zmienna_liczba] = "A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][0] == 1 && X[1][1] == 2)
			{
				X[1][0] = 2;
				zmienna[zmienna_liczba] = "A!B";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][0] == 1 && X[0][0] == 2)
			{
				X[1][0] = 2;
				zmienna[zmienna_liczba] = "!B!C";
				zmienna_liczba = zmienna_liczba + 1;
			}//////////////// w gore
			if (X[1][1] == 1 && X[1][0] == 2)
			{
				X[1][1] = 2;
				zmienna[zmienna_liczba] = "A!B";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[1][1] == 1 && X[1][2] == 2)
			{
				X[1][1] = 2;
				zmienna[zmienna_liczba] = "AC";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][1] == 1 && X[0][1] == 2)
			{
				X[1][1] = 2;
				zmienna[zmienna_liczba] = "!BC";
				zmienna_liczba = zmienna_liczba + 1;
			}//////////// w gore
			if (X[1][2] == 1 && X[1][1] == 2)
			{
				X[1][2] = 2;
				zmienna[zmienna_liczba] = "AC";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[1][2] == 1 && X[1][3] == 2)
			{
				X[1][2] = 2;
				zmienna[zmienna_liczba] = "AB";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][2] == 1 && X[0][2] == 2)
			{
				X[1][2] = 2;
				zmienna[zmienna_liczba] = "BC";
				zmienna_liczba = zmienna_liczba + 1;
			}/////////////// w gore
			if (X[1][3] == 1 && X[1][2] == 2)
			{
				X[1][3] = 2;
				zmienna[zmienna_liczba] = "AB";
				zmienna_liczba = zmienna_liczba + 1;
			}//
			if (X[1][3] == 1 && X[1][0] == 2)
			{
				X[1][3] = 2;
				zmienna[zmienna_liczba] = "A!C";
				zmienna_liczba = zmienna_liczba + 1;
			}
			if (X[1][3] == 1 && X[0][3] == 2)
			{
				X[1][3] = 2;
				zmienna[zmienna_liczba] = "B!C";
				zmienna_liczba = zmienna_liczba + 1;
			}///////////////// w gore

			// Dla 1 samotnych
			for (int i = 0; i <= 1; i++)
			{
				for (int j = 0; j <= 3; j++)
				{
					if (X[i][j] == 1)
					{
						zmienna[zmienna_liczba] = tablicaXX[i][j];
						zmienna_liczba = zmienna_liczba + 1;
					}
				}
			}
		}
	}
	for (int i = 0; i <= zmienna_liczba - 1; i++)
	{
		cout << zmienna[i];
		if (i <= zmienna_liczba - 2)
			cout << " + ";
	}
	cout << endl;
}
