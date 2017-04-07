#include <iostream>
#include <cstdlib>
#include<ctime>

using namespace std;

struct node
{
	node *left;
	node *right;
	int val;
} *root = NULL;

void dodaj(node* &root, int x);
void  wyswietl(node *root);
int jeden(node *root);
int lisc(node *root);
int sciezka(node *root, int dlugosc);

int main()
{
	srand(time(NULL));
	int N;
	int syn;
	int llisc;
	int max;
	cout<<"Podaj dlugosc tablicy: ";
	cin >> N;

	int *tab = new int[N];

	for (int i = 0; i < N; i++)
		tab[i] = rand() % 100 + 1;
	cout << "Wylosowana tablica: ";
	for (int i = 0; i < N; i++)
		cout << tab[i] << " ";
	cout << endl;

	for (int i = 0; i < N; i++)
		dodaj(root, tab[i]);

	syn = jeden(root);
	llisc = lisc(root);
	max = sciezka(root,0);
	cout << "Drzewo (in order): ";
	wyswietl(root);
	cout << endl;
	cout << "Liczba majacych jednego syna: " << syn << endl;
	cout << "Liczba lisci: " << llisc << endl;
	cout << "Najdluzsza sciezka do liscia: " << max << endl;
	system("PAUSE");



	return 0;
}

void dodaj(node* &root, int x)
{
	node *p = new node;
	p->left = NULL;
	p->right = NULL;
	p->val = x;
	if (root == NULL)
	{
		root = p;
		return;
	}
	else
	{
		node *d = root;

		while (true)
		{
			if (x < d->val)
			{
				if (d->left != NULL)
					d = d->left;
				else
				{
					d->left = p;
					break;
				}
			}
			else
			{
				if (d->right != NULL)
					d = d->right;
				else
				{
					d->right = p;
					break;
				}
			}
		}
	}
}

void  wyswietl(node *root)
{
	if (root == NULL)
		return;
	if (root->right != NULL)
	{
		wyswietl(root->right);
	}
	cout << root->val << " ";
	if (root->left != NULL)
	{
		wyswietl(root->left);
	}
}
int jeden(node *root)
{
	int static licznik = 0;
		if (root->right != NULL)
		{
			jeden(root->right);
		}
		if (root->left != NULL)
		{
			jeden(root->left);
		}
		if ((root->right == NULL && root->left != NULL) || (root->left == NULL && root->right != NULL))
			licznik++;
		return licznik;
}

int lisc(node *root)
{
	int static licznik = 0;
	if (root->right != NULL)
	{
		lisc(root->right);
	}
	if (root->left != NULL)
	{
		lisc(root->left);
	}
	if (root->left == NULL && root->right == NULL)
		licznik++;

	return licznik;
}

int sciezka(node *root, int dlugosc)
{
	int static max = 0;

	if (root->right != NULL)
	{
		dlugosc++;
		sciezka(root->right,dlugosc);
		dlugosc--;
	}
	if (root->left != NULL)
	{
		dlugosc++;
		sciezka(root->left,dlugosc);
		dlugosc--;
	}
	if (root->left == NULL && root->right == NULL)
	{
		if (max < dlugosc)
			max = dlugosc;
		dlugosc = 0;
	}

	return max;
}