#include <iostream>
#include <cstdlib>

using namespace std;

struct node
{
	int val;
	node* next;
	node* prev;
};

void dodajp(node* &H, node* &T, int x);
void dodajk(node* &H, node* &T, int x);
void dodajn(node* &H, node* &T, int x);
void usunp(node* &H, node* &T);
void usunk(node* &H, node* &T);
void reset(node* &H, node* &T);
void wyswietl(node* H);
void wyswietl2(node* T);
void zamienn(node* &H, node* &T, int x);
int zlicz(node* W);
void sortzderzak(node* &H, node* &T);
int main()
{
	node *H = NULL, *T = NULL;
	char wyb;
	int x;

	while (true)
	{
		cout << "-------------------Menu-------------------" << endl;
		cout << "o - dodaje na poczatek listy." << endl;
		cout << "p - dodaje na koniec listy." << endl;
		cout << "t - dodaje do listy wartosci od 0 do n (n podane z klawiatury)" << endl;
		cout << "k - usuwa z poczatku listy." << endl;
		cout << "l - usuwa z konca listy." << endl;
		cout << "r - usuwa wszystkie elementy listy (reset)." << endl;
		cout << "w - wyswietla wszystkie elementy listy." << endl;
		cout << "W - wyswietla wszystkie elementy listy od konca." << endl;
		cout << "b - sortowanie ze zderzakami." << endl;
		cout << "q - wyjdz z programu" << endl;

		cout << "Wybieram: ";
		cin >> wyb;
		switch (wyb)
		{
		case 'o':
			cout << endl << "Podaj liczbe: ";
			cin >> x;
			dodajp(H, T, x);
			break;
		case 'p':
			cout << endl << "Podaj liczbe: ";
			cin >> x;
			dodajk(H, T, x);
			break;
		case 't':
			cout << endl << "Podaj liczbe: ";
			cin >> x;
			dodajn(H, T, x);
			break;
		case 'n':
			cout << endl << "Podaj liczbe: ";
			cin >> x;
			zamienn(H, T, x);
			break;
		case 'k':
			usunp(H, T);
			break;
		case 'l':
			usunk(H, T);
			break;
		case 'r':
			reset(H, T);
			break;
		case 'w':
			wyswietl(H);
			break;
		case 'W':
			wyswietl2(T);
			break;
		case 'b':
			sortzderzak(H, T);
			break;
		case 'q':
			return 0;
		default:
			cout << "Nie ma takiej komendy." << endl;
			system("PAUSE");
			break;
		}
		system("CLS");
	}

	return 0;
}

void dodajp(node* &H, node* &T, int x)
{
	node *p = new node;
	p->val = x;
	p->next = H;
	if (H != NULL)
		p->next->prev = p;
	else
	{
		T = p;
	}
	H = p;
	p->prev = NULL;
}
void dodajk(node* &H, node* &T, int x)
{
	if (T != NULL)
	{
		node *p = new node;
		p->val = x;
		p->prev = T;
		T->next = p;
		p->next = NULL;
		T = p;
	}
	else
		dodajp(H, T, x);
}
void dodajn(node* &H, node* &T, int x)
{
	for (int i = 0; i <= x; i++)
		dodajk(H, T, i);
}
void usunp(node* &H, node* &T)
{
	if (H != NULL)
	{
		node *p = H;
		H = p->next;
		if (H == NULL)
			T = NULL;
		delete p;
		H->prev = NULL;
	}
	else
	{
		cout << "Lista jest pusta." << endl;
		system("PAUSE");
	}
}
void usunk(node* &H, node* &T)
{
	if (T != NULL)
	{
		node *p = T;
		T = T->prev;
		if (T == NULL)
			H = NULL;
		delete p;
		T->next = NULL;
	}
	else
	{
		cout << "Lista jest pusta." << endl;
		system("PAUSE");
	}
}
void reset(node* &H, node* &T)
{
	if (H != NULL)
	{
		node *p = H, *d = NULL;
		while (p != NULL)
		{
			d = p->next;
			delete p;
			p = d;
		}
		H = NULL;
		T = NULL;
	}
	else
	{
		cout << "Lista jest pusta." << endl;
		system("PAUSE");
	}
}
void wyswietl(node* H)
{
	if (H == NULL)
		cout << "Lista jest pusta." << endl;
	else
	{
		cout << "| ";
		while (H != NULL)
		{
			cout << H->val << " | ";
			H = H->next;
		}
	}
	cout << endl;
	system("PAUSE");
}
void wyswietl2(node* T)
{
	if (T == NULL)
		cout << "Lista jest pusta." << endl;
	else
	{
		cout << "| ";
		while (T != NULL)
		{
			cout << T->val << " | ";
			T = T->prev;
		}
	}
	cout << endl;
	system("PAUSE");
}
void zamienn(node* &H, node* &T, int x)
{
	if (H != NULL && H->next != NULL && x > 0)
	{
		if (x == 1)
		{
			H->prev = H->next;
			H->next = H->next->next;
			H->prev->next = H;
			H->prev->prev = NULL;
			if (H->next != NULL)
				H->next->prev = H;
			else
				T = H;
			H = H->prev;
		}
		else
		{
			node *p = H->next;
			for (int i = 2; i < x; i++)
			{
				if (p->next != NULL && p->next->next != NULL)
					p = p->next;
				else
				{
					cout << "Za malo elementow" << endl;
					system("PAUSE");
					return;
				}
			}
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p->prev = p->next;
			p->next = p->next->next;
			p->prev->next = p;
			if (p->next != NULL)
				p->next->prev = p;
			else
				T = T->next;
		}
	}

}
void zamienp(node* &H, node* &T, int x)
{
	if (H != NULL && H->next != NULL )
	{
		if (x == 2)
		{
			H->prev = H->next;
			H->next = H->next->next;
			H->prev->prev = NULL;
			H->prev->next = H;
			if (H->next != NULL)
				H->next->prev = H;
			else
				T = H;
			H = H->prev;
		}
		else
		{
			node *p = H->next;
			for (int i = 3; i < x; i++)
			{
				if (p->next != NULL)
					p = p->next;
				else
				{
					cout << "Za malo elementow" << endl;
					system("PAUSE");
					return;
				}
			}
			if (p->next != NULL)
			{
				p = p->next;
				p->prev->next = p->next;
				p->next = p->prev;
				p->prev = p->prev->prev;
				p->prev->next = p;
				p->next->prev = p;
				if (p->next->next != NULL)
					p->next->next->prev = p->next;
				else
					T = T->next;
			}
			else
			{
				cout << "Za malo elementow" << endl;
				system("PAUSE");
				return;
			}
		}
	}
	else
	{
		cout << "Za malo elementow" << endl;
		system("PAUSE");
	}

}
int zlicz(node* W)
{
	int licznik = 0;
	while (W != NULL)
	{
		licznik++;
		W = W->next;
	}

	return licznik;
}
void sortbabel(node* &H, node* &T)
{
	if (H != NULL && H->next != NULL)
	{
		node *p = H;
		bool zamiana;
		int x;
		do
		{
			p = H;
			x = 1;
			zamiana = false;
			while (p->next != NULL)
			{
				if (p->val > p->next->val)
				{
					zamienn(H, T, x);
					zamiana = true;
				}
				else
					p = p->next;
				x++;
			}
		} while (zamiana);
	}
	else
	{
		cout << "Lista jest pusta lub za malo elementow." << endl;
		system("PAUSE");
	}
}
void sortbabel1(node* &p, node* &q)
{
	node *r = p;
	int x = 1;
		while (r != q)
		{
			if (r->val > r->next->val)
			{
				zamienn(p, q, x);
			}
			else
				r = r->next;
			x++;
		}
}
void sortbabel2(node* &p, node* &q, int &x)
{
	node *r = q;
	x = x-1;
	cout << "x: " << x << endl;
		while (r != p)
		{
			if (r->val < r->prev->val)
			{
				zamienp(p, q, x);
			}
			else
				r = r->prev;
			x--;
		}
}
void sortzderzak(node* &H, node* &T)
{
	if (H != NULL && H->next != NULL)
	{

		node *p = H;
		node *q = T;

		wyswietl(p);
		wyswietl2(q);

		int x = zlicz(p)+1;

		do
		{
			sortbabel1(p, q);
			q = q->prev;
			cout << "1." << endl;
			wyswietl(p);
			wyswietl2(q);
			if (p != q)
			{
				sortbabel2(H, q, x);
			}
			else
				return;
			p = p->next;
			cout << "2." << endl;
			wyswietl(p);
			wyswietl2(q);
		} while (p != q && p->next != q);
	}
}