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
void zamienp(node* &H, node* &T, int x);
void zamienn(node* &H, node* &T, int x);
int zlicz(node* W);
int gap(int x);
void sortgrzebien(node* &H);
void sortbabel(node* &H, node* &T);
void sortzderzak(node* &H, node* &T);
void zamienxy(node* &H, node* &T, int x, int y);

int main()
{
	node *H = NULL, *T = NULL;
	char wyb;
	int x;

	while (true)
	{
		cout << "-------------------Menu-------------------"<<endl;
		cout << "o - dodaje na poczatek listy." << endl;
		cout << "p - dodaje na koniec listy." << endl;
		cout << "t - dodaje do listy wartosci od 0 do n (n podane z klawiatury)" << endl;
		cout << "k - usuwa z poczatku listy." << endl;
		cout << "l - usuwa z konca listy." << endl;
		cout << "r - usuwa wszystkie elementy listy (reset)." << endl;
		cout << "w - wyswietla wszystkie elementy listy." << endl;
		cout << "W - wyswietla wszystkie elementy listy od konca." << endl;
		cout << "n - zamienia liczbe z poprzednia" << endl;
		cout << "m - zamienia liczbe z nastepna" << endl;
		cout << "q - wyjdz z programu" << endl;
		
		cout << "Wybieram: ";
		cin >> wyb;
		switch (wyb)
		{
		case 'o':
			cout << endl << "Podaj liczbe: ";
			cin >> x;
			dodajp(H,T,x);
			break;
		case 'p':
			cout << endl << "Podaj liczbe: ";
			cin >> x;
			dodajk(H,T,x);
			break;
		case 't':
			cout << endl << "Podaj liczbe: ";
			cin >> x;
			dodajn(H,T, x);
			break;
		case 'k':
			usunp(H,T);
			break;
		case 'l':
			usunk(H,T);
			break;
		case 'r':
			reset(H,T);
			break;
		case 'w':
			wyswietl(H);
			break;
		case 'W':
			wyswietl2(T);
			break;
		case 'n':
			cout << endl << "Podaj liczbe: ";
			cin >> x;
			zamienp(H,T, x);
			break;
		case 'm':
			cout << endl << "Podaj liczbe: ";
			cin >> x;
			zamienn(H, T, x);
			break;
		case 'a':
			sortbabel(H, T);
			break;
		case 'b':
			sortzderzak(H, T);
			break;
		case 'q':
			return 0;
		default:
			cout << "Nie ma takiej komendy." << endl;
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
		dodajp(H,T,x);
}
void dodajn(node* &H, node* &T, int x)
{
	for (int i = 0; i <= x; i++)
		dodajk(H,T,i);
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
		while(H != NULL)
		{
			cout << H->val<<" | ";
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
void zamienp(node* &H, node* &T,int x)
{
	if (H != NULL && H->next != NULL && x > 1)
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
		wyswietl(H);

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
void zamienxy(node* &H, node* &T, int x, int y)
{

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
int gap(int x)
{
	x = (x * 10) / 13;
	if (x == 9 || x == 10)
		return 11;
	if (x > 1)
		return x;
	return 1;
}
void sortgrzebien(node* &H, node* &T)
{
	if (H != NULL && H != NULL)
	{
		
	}
	else
	{
		cout << "Lista jest pusta lub ma za ma³o elementow." << endl;
		system("PAUSE");
	}
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
	bool zamiana;
	int x;
	do
	{
		r = p;
		x = 1;
		zamiana = false;
		while (r->next != NULL)
		{
			if (r->val > r->next->val)
			{
				zamienn(p, q, x);
				zamiana = true;
			}
			else
				r = r->next;
			x++;
		}
	} while (zamiana);
}
void sortbabel2(node* &p, node* &q)
{
	node *r = q;
	bool zamiana;
	int x;
	do
	{
		r = q;
		x = zlicz(p);
		zamiana = false;
		while (r->next != NULL)
		{
			if (r->val > r->next->val)
			{
				zamienp(p, q, x);
				zamiana = true;
			}
			else
				r = r->next;
			x--;
		}
	} while (zamiana);
}
void sortzderzak(node* &H, node* &T)
{
	if (H != NULL && H->next != NULL)
	{
		
		node *p = H;
		node *q = T;
		sortbabel1(p, q);
		sortbabel2(p, q);
		H = p;
		T = q;
		do
		{	
			sortbabel1(p, q);
			q = q->prev;
			if (p != q)
			{
				sortbabel2(p, q);
			}
			else
				return;
			p = p->next;
		} while (p != q && p->next != q);
	}
}