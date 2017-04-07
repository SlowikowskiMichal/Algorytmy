#include <iostream>
#include <cstdlib>

using namespace std;

bool isFull(int poczatek, int koniec);
bool isEmpty(int poczatek, int koniec);
void Enqueue(int kolejka[], int &poczatek, int &koniec);
void Dequeue(int kolejka[], int &poczatek, int &koniec);


int main()
{
	int kolejka[10], poczatek = -1, koniec = -1;
	char wyb;
	do
	{
		cout << "---------------------------------------------" << endl;
		cout << "Co chcesz wykonac?" << endl;
		cout << "f - sprawdza czy jest kolejka pelna" << endl;
		cout << "e - sprawdza czy kolejka jest pusta" << endl;
		cout << "d - dodaje element do kolejki" << endl;
		cout << "u - usuwa element z kolejki" << endl;
		cout << "Koniec programu ctrl+c" << endl << endl;
		cin >> wyb;
		cout << endl;
		switch (wyb)
		{
		case 'f':
			if (isFull(poczatek, koniec))
				cout << "Kolejka jest pelna" << endl;
			else
				cout << "Kolejka nie jest pelna" << endl;
			break;
		case 'e':
			if (isEmpty(poczatek, koniec))
				cout << "Kolejka jest pusta" << endl;
			else
				cout << "Kolejka nie jest pusta" << endl;
			break;
		case 'd':
			Enqueue(kolejka, poczatek, koniec);
			break;
		case 'u':
			Dequeue(kolejka, poczatek, koniec);
			break;
		default:
			cout << "Podano nieistniejaca komende" << endl;
		}
		cout << endl;
		if (!isEmpty(poczatek, koniec))
		{
			cout << "Obecnie w kolejce:" << endl;
			if (poczatek < koniec)
			{
				cout << "| ";
				for (int i = poczatek; i <= koniec; i++)
					cout << kolejka[i] << " | ";
				cout << endl;
			}
			else if (poczatek > koniec)
			{
				cout << "| ";
				for (int i = poczatek; i <10; i++)
					cout << kolejka[i] << " | ";
				for (int i = 0; i <= koniec; i++)
					cout << kolejka[i] << " | ";
				cout << endl;
			}
			else
				cout << "| " << kolejka[poczatek] << " | ";
			cout << "Poczatek wskazuje na: " << poczatek << " element." << endl;
			cout << "Koniec wskazuje na: " << koniec << " element." << endl;
			cout << endl << endl << endl;

		}



	} while (true);


	system("PAUSE");
	return 0;
}

bool isEmpty(int poczatek, int koniec)
{
	if (poczatek == -1 && koniec == -1)
		return 1;
	return 0;
}

bool isFull(int poczatek, int koniec)
{
	if ((koniec + 1) % 10 == poczatek)
		return 1;
	return 0;
}

void Enqueue(int kolejka[], int &poczatek, int &koniec)
{
	if (isFull(poczatek, koniec))
	{
		cout << "Kolejka jest pelna, nie mozna nic dodac." << endl;
		return;
	}
	else if (isEmpty(poczatek, koniec))
	{
		poczatek = 0;
		koniec = 0;
		cout << "Wprowadz liczbe: ";
		cin >> kolejka[koniec];
	}
	else
	{
		koniec = (koniec + 1) % 10;
		cout << "Wprowadz liczbe: ";
		cin >> kolejka[koniec];
	}
	return;
}

void Dequeue(int kolejka[], int &poczatek, int &koniec)
{
	if (isEmpty(poczatek, koniec))
	{
		cout << "Kolejka jest pusta, nie mozna nic wyjac." << endl;
		return;
	}
	else if (poczatek == koniec)
	{
		cout << "Zdejmuje: " << kolejka[poczatek] << " z pozycji " << poczatek << endl;
		poczatek = -1;
		koniec = -1;
		cout << "Kolejka jest teraz pusta!" << endl;
	}
	else
	{
		cout << "Zdejmuje: " << kolejka[poczatek] << " z pozycji " << poczatek << endl;
		poczatek = (poczatek + 1) % 10;
	}
	return;
}
