#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void heapify(int tab[], int heapsize, int n);
void zamien(int &a, int &b);
void wyswietl(int *tab, int size);
void wyswietl2(int *tab);

int main()
{
	srand(time(NULL));
	int tab[11];
	for (int i = 0; i < 11; i++)
		tab[i] = rand() % 11;

	wyswietl(tab, 10);
	wyswietl2(tab);
	heapify(tab, 10, 1);
	wyswietl2(tab);
	wyswietl(tab, 10);

	return 0;
}

void wyswietl(int *tab, int size)
{
	cout << "Tablica: " << endl;
	for (int i = 0; i < size; i++)
		cout << tab[i] << '\t';
	cout << endl;
	system("PAUSE");
}

void wyswietl2(int *tab)
{
	cout << "Kopiec: " << endl;
	cout << "               "<<tab[1] << endl;
	cout << "             /     \\ "<<endl;
	cout << "         "<<tab[2]<<"          "<<tab[3] << endl;
	cout << "      /    \\       /    \\" << endl;
	cout << "    "<<tab[4]<<"        "<<tab[5]<<"    "<<tab[6]<<"      "<<tab[7] << endl;
	cout << "   / \\     /   " << endl;
	cout << " "<<tab[8]<<"     "<<tab[9]<<"  "<<tab[10]<<" "<< endl;
}

void heapify(int tab[], int heapsize, int n)
{
	int L = 2 * n;
	int R = 2 * n + 1;

	int largest = n;
	if (L <= heapsize && tab[L]>tab[n])
		largest = L;
	
	if (R <= heapsize && tab[R] > tab[largest])
		largest = R;

	cout << "n: " << n << endl;
	cout << "L: " << L << endl;
	cout << "R: " << R << endl;
	cout << "Largest: " << largest << endl;

	system("PAUSE");

	if (n != largest)
	{
		zamien(tab[n], tab[largest]);
		heapify(tab, heapsize, largest);
		wyswietl(tab, heapsize);
	}

}

void zamien(int &a, int &b)
{
	int bufor = a;
	a = b;
	b = bufor;
}