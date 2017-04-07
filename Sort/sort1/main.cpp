#include <iostream>

using namespace std;

struct node
{
	int val;
	node *next;
};

struct lista
{
	node *H = NULL;
	lista()
	{
		H = NULL;
	}

	void dodajp();
	void dodajk();
	void dodajkolej();
	void usunp();
	void usunk();
	void usunwartosc();
	void reset();
	void poprzedni();
	void nastepny();
	void zamienxy();
	void babel();
	void wyswietl();
	void scalaniewstep();
	void scalanie(int rozmiar);
	int zlicz();
};

int main()
{
	lista l;
	while (true)
	{
		cout << "------Menu------" << endl;
		cout << "o - dodaje do poczatku listy" << endl;
		cout << "p - dodaje do konca listy" << endl;
		cout << "y - dodaje n+1 elementow od 0 do n" << endl;
		cout << "k - usuwa z poczatku listy" << endl;
		cout << "l - usuwa z konca listy" << endl;
		cout << "j - usuwa wybrana wartosc z listy (pierwsza z lewej)" << endl;
		cout << "r - usuwa cala liste" << endl;
		cout << "n - zamienia element o podanej wartosci z poprzednim" << endl;
		cout << "m - zamienia element o podanej wartosci z nastepnym" << endl;
		cout << "b - zamienia dwa elementy elementy o podanych wartosciach" << endl;
		cout << "s - sortowanie babelkowe" << endl;
		cout << "w - wyswietla elementy listy" << endl;
		cout << "Aby zakonczyc dzialanie programu wcisnij q" << endl;
		cout << "Wybieram: ";

		char wyb;
		cin >> wyb;

		switch (wyb)
		{
		case 'o':
			l.dodajp();
			break;
		case 'p':
			l.dodajk();
			break;
		case 'y':
			l.dodajkolej();
			break;
		case 'k':
			l.usunp();
			break;
		case 'l':
			l.usunk();
			break;
		case 'w':
			cout << endl;
			l.wyswietl();
			system("PAUSE");
			break;
		case 'j':
			l.usunwartosc();
			break;
		case 'r':
			cout << endl;
			l.reset();
			system("PAUSE");
			break;
		case 'n':
			l.poprzedni();
			break;
		case 'm':
			l.nastepny();
			break;
		case 'b':
			l.zamienxy();
			break;
		case 's':
			l.babel();
			break;
		case 'q':
			return 0;
			break;
		default:
			cout << "Nie ma takiej komendy" << endl;
			system("PAUSE");
			break;
		}
		system("cls");

	}
	return 0;
}

void lista::dodajp()
{
	int x;
	cout << "Podaj wartosc: ";
	cin >> x;
	node *p = new node;
	p->val = x;
	p->next = H;
	H = p;
}
void lista::dodajk()
{
	int x;
	cout << "Podaj wartosc: ";
	cin >> x;
	node *p = new node;
	p->val = x;
	p->next = H;
	if (H != NULL)
	{
		node *d = H;
		while (d->next != NULL)
			d = d->next;
		p->next = d->next;
		d->next = p;
	}
	else
	{
		p->next = H;
		H = p;
	}

}
void lista::dodajkolej()
{
	node *p;
	cout << "Podaj ile chcesz elementow: ";
	int liczba;
	cin >> liczba;
	for (int i = liczba; i >= 0; i--)
	{
		p = new node;
		p->val = i;
		p->next = H;
		H = p;
	}
}
void lista::usunp()
{
	if (H != NULL)
	{
		node *p = H;
		H = H->next;
		delete p;
	}
	else
	{
		cout << "Lista jest pusta." << endl;
		system("PAUSE");
	}
}
void lista::usunk()
{
	if (H != NULL)
	{
		node *p = H;
		if (p->next == NULL)
		{
			H = p->next;
			delete p;
		}
		else
		{
			node *d;
			while (p->next->next != NULL)
			{
				p = p->next;
			}
			d = p->next;
			p->next = d->next;
			delete d;
		}
	}
	else
	{
		cout << "Lista jest pusta." << endl;
		system("PAUSE");
	}

}
void lista::usunwartosc()
{
	if (H != NULL)
	{
		cout << "Podaj wartosc do usuniecia: ";
		int x;
		cin >> x;
		if (H->val == x)
		{
			node *p = H;
			H = H->next;
			delete p;
		}
		else
		{
			node *p = H;
			while (p->next != NULL && p->next->val != x)
				p = p->next;
			if (p->next != NULL)
			{
				node *d = p->next;
				p->next = d->next;
				delete d;
			}
			else
			{
				cout << "Nie znaleziono podanej wartosci w liscie." << endl;
				system("PAUSE");
			}

		}
	}
	else
	{
		cout << "Lista jest pusta." << endl;
		system("PAUSE");
	}
}
void lista::reset()
{
	node *p;
	while (H != NULL)
	{
		p = H;
		H = H->next;
		delete p;
	}
	cout << "Lista jest pusta." << endl;

}
void lista::zamienxy()
{
	if (H != NULL && H->next != NULL)
	{
		cout << "Podaj wartosci elementow jakie chcesz zamienic: ";
		int x, y;
		cin >> x >> y;
		node *p = H;
		node *d = H;
		if (x != y)
		{
			if (H->val == x)
			{
				while (d->next != NULL && d->next->val != y)
					d = d->next;
				if (d->next != NULL)
				{
					if (p != d)
					{
						node *q = d->next;
						H = q;
						d->next = p->next;
						p->next = q->next;
						q->next = d->next;
						d->next = p;
					}
					else
					{
						H = p->next;
						p->next = H->next;
						H->next = p;
					}
				}
				else
				{
					cout << "Nie znaleziono elementu o wartosci: " << y << endl;
					system("PAUSE");
					return;
				}

			}
			else if (H->val == y)
			{
				while (d->next != NULL && d->next->val != x)
					d = d->next;
				if (d->next != NULL)
				{
					if (d != p)
					{
						node *q = d->next;
						H = q;
						d->next = p->next;
						p->next = q->next;
						q->next = d->next;
						d->next = p;
					}
					else
					{
						H = p->next;
						p->next = H->next;
						H->next = p;
					}
				}
				else
				{
					cout << "Nie znaleziono elementu o wartosci: " << x << endl;
					system("PAUSE");
					return;
				}
			}
			else
			{
				while (p->next != NULL && p->next->val != x)
					p = p->next;

				if (p->next != NULL)
				{
					while (d->next != NULL && d->next->val != y)
						d = d->next;
					if (d->next != NULL)
					{
						if (p->next == d)
						{
							p->next = d->next;
							d->next = p->next->next;
							p->next->next = d;
						}
						else if (d->next == p)
						{
							d->next = p->next;
							p->next = d->next->next;
							d->next->next = p;
						}
						else
						{
							node *q = d->next;
							node *r = p->next;
							p->next = q;
							d->next = r->next;
							r->next = q->next;
							q->next = d->next;
							d->next = r;
						}
					}
					else
					{
						cout << "Nie znaleziono elementu o wartosci: " << y << endl;
						system("PAUSE");
						return;
					}
				}
				else
				{
					cout << "Nie znaleziono elementu o wartosci: " << x << endl;
					system("PAUSE");
					return;
				}
			}
		}
		else
		{
			cout << "Podano dwie takie same wartosci." << endl;
			system("PAUSE");
			return;
		}
	}
	else
	{
		cout << "Lista ma za malo elementow." << endl;
		system("PAUSE");
	}
}
void lista::poprzedni()
{
	if (H != NULL&&H->next != NULL)
	{
		cout << "Podaj wartosc do zamiany: ";
		int x;
		cin >> x;
		node *p = H;
		if (p->next->val == x)
		{
			H = H->next;
			p->next = H->next;
			H->next = p;
		}
		else
		{
			while (p->next->next != NULL && p->next->next->val != x)
				p = p->next;
			if (p->next->next != NULL)
			{
				node *d = p->next;
				p->next = d->next;
				d->next = p->next->next;
				p->next->next = d;
			}
			else
			{
				cout << "Nie znaleziono elementu o takiej wartosci na liscie, lub znajduje sie na pierwszym miejscu." << endl;
				system("PAUSE");
			}
		}
	}
	else
	{
		cout << "Za malo elementow do zamiany." << endl;
		system("PAUSE");
	}
}
void lista::nastepny()
{
	if (H != NULL && H->next != NULL)
	{
		cout << "Podaj wartosc do zamiany: ";
		int x;
		cin >> x;
		if (H->val == x)
		{
			node *p = H;
			H = H->next;
			p->next = H->next;
			H->next = p;
		}
		else
		{
			node *p = H;
			while (p->next != NULL && p->next->val != x)
				p = p->next;
			if (p->next != NULL && p->next->next != NULL)
			{
				node *d = p->next;
				p->next = d->next;
				d->next = d->next->next;
				p->next->next = d;
			}
			else if (p->next == NULL || p->next->val == x)
			{
				cout << "Nie znaleziono elementu o tej wartosci, lub element do zamiany jest ostatni." << endl;
				system("PAUSE");
			}
		}
	}
	else
	{
		cout << "Za malo elementow do zamiany, lub element do zamiany jest ostatni." << endl;
		system("PAUSE");
	}

}
void lista::babel()
{
	if (H != NULL && H->next != NULL)
	{
		node *p = H;
		node *d;
		bool licznik = false;
		do
		{
			licznik = false;
			p = H;
			if (p->val > p->next->val)
			{
				H = H->next;
				p->next = H->next;
				H->next = p;
				licznik = true;
			}
			while (p->next != NULL&&p->next->next != NULL)
			{
				if (p->next->val > p->next->next->val)
				{
					d = p->next;
					p->next = d->next;
					d->next = p->next->next;
					p->next->next = d;
					licznik = true;
				}
				p = p->next;
			}
		} while (licznik);
	}
	else
	{
		cout << "Lista jest pusta lub za malo elementow." << endl;
		system("PAUSE");
	}
}
void lista::wyswietl()
{
	node *p = H;
	if (H != NULL)
	{
		cout << "| ";
		do
		{
			cout << p->val << " | ";
			p = p->next;
		} while (p != NULL);
	}
	else
		cout << "Lista jest pusta." << endl;
	cout << endl;
}
void lista::scalaniewstep()
{
	int rozmiar = zlicz();
	scalanie(rozmiar);
}
void lista::scalanie(int rozmiar)
{
	rozmiar = rozmiar / 2;
	rozmiar = rozmiar / 2;
	node *d = H;
	node *p = H;
	node *q = H;
	for (int i = 1; i < rozmiar; i++)
	{
		d = d->next;
	}
	if (d != NULL)
	{
		q = d->next;
	}

	d->next = NULL;
	d = q;
	
}
int lista::zlicz()
{
	int licznik = 0;
	node *p = H;
	while (p != NULL)
	{
		p = p->next;
		licznik++;
	}

	return licznik;
}


//by Micha³ S³owikowski