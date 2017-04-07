#include <iostream>
#include <cstdlib>

using namespace std;


struct lista
{
	int val;
	lista *next;
};

void dodaj(lista **tab, int a);
void wyswietl(lista **tab);

int main()
{

	lista *tab[13];
	for (int i = 0; i < 13; i++)
		tab[i] = NULL;
	int a;



	char wyb;
	while (true)
	{
		cout << "MENU" << endl;
		cout << "d - dodaj \nw - wyswietl\nq - wyjdz\n";
		cin >> wyb;
		switch (wyb)
		{
		case 'd':
			cout << "Podaj wartosc: ";
			cin >> a;
			dodaj(tab,a);
			break;
		case 'w':
			wyswietl(tab);
			break;
		case 'n':
			for (int i = 1; i < 131; i++)
				dodaj(tab, i);
			break;
		case 'q':
			return 0;
			break;
		default:
			cout << "Nie ma takiego polecenia\n";
			system("PAUSE");
			break;
		}
		system("cls");
	}

	return  0;
}

void dodaj(lista **tab, int a)
{
	lista *p = new lista;
	p->val = a;
	p->next = NULL;
	
	int b = a % 13;

	if (tab[b] == NULL)
	{
		tab[b] = p;
	}
	else
	{
		lista *d = tab[b];
		while (d->next != NULL)
			d = d->next;
		d->next = p;
	}
	
}
void wyswietl(lista **tab)
{
	lista *p = NULL;
	for (int i = 0; i < 13; i++)
	{
		cout << i  << ". ";
		p = tab[i];
		while (p != NULL)
		{
			cout << p->val << " -> ";
			p = p->next;
		}
		cout << endl;
	}
	system("PAUSE");
}