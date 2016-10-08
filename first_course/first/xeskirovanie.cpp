#include <iostream>
#include <string>
#include <ctime>
using namespace std;
void generate(int *,int);
struct spis
{
	string fio;
	int rost, ves;
};
void xesh(int *,spis *,spis &);
int Search(int,spis *,int *,int);
int main()
{
	srand(time(NULL));
	int i,j,n = 2,m=10,*ger=new int[n*m];
	generate(ger, n*m);
	spis *a = new spis[n],*xeshir=new spis[m];
	for (i = 0; i < m; i++)
	{
		xeshir[i].rost = -1;
	}
	for (i = 0; i < n; i++)
	{
		cout << "Dannie ob " << i + 1 << " cheloveke:" << endl;
		cout << "Vvedite fio:"; cin >> a[i].fio;
		cout << "Vvedite rost:"; cin >> a[i].rost;
		cout << "Vvedite ves:"; cin >> a[i].ves;
		xesh(ger,xeshir,a[i]);
	}
	system("cls");
	int key;
	cout << "Vvedite klych dlya poiska:"; cin >> key;
	cout << "-----------" << endl;
	j=Search(key,xeshir,ger,n*m);
	if (j == -1)
	{
		cout << "Elementa s kluchom " << key << " nety" << endl;
	}
	else
	{
		cout << "FIO y cheloveka s rostom ravnim "<<key<<":"<<xeshir[j].fio << endl;
	}
	cout << "----------------" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "  Fio:" << a[i].fio << endl;
		cout << i + 1 << ")Ves:" << a[i].ves<<endl;
		cout << "  Rost:" << a[i].rost << endl << endl;
	}
	cout << "Tablitsa xeshirovaniya:" << endl;
	for (i = 0; i < m; i++)
	{
		cout << i + 1 << ")";
		cout << xeshir[i].rost << endl;
	}
	generate(ger,2*m);
	system("pause");
	return 0;
}
void generate(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
void xesh(int *b,spis *xeshir,spis &a)
{
	int i = a.rost% 10;
	if (xeshir[i].rost == -1)
	{
		xeshir[i] = a;
		return;
	}
	int r = 0,i1=i;
	while (xeshir[i1].rost != -1)
	{
		i1 = (i + b[r])%10;
		r++;
		if (xeshir[i1].rost == -1)
		{
			xeshir[i1] = a;
			return;
		}
	}
}
int Search(int key,spis *a,int *b,int m)
{
	int d = key % 10;
	if (a[d].rost ==key)
	{
		return d;
	}
	int i1 = d,r=0;
	while (a[i1].rost != -1)
	{
		i1 = (d + b[r]) % 10;
		r++;
		if (a[i1].rost == key)
		{
			return i1;
		}
		if (r>= m)
		{
			return -1;
		}
	}
	return -1;
}