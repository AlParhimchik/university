#include <iostream>
#include <cstring>
using namespace std;
void rekyrs(int **);
int max(int **);
void compatibility(int **, int, int, int);

void ochistka(int **, int);

 int  n, m, n1, m1;
int main()
{
	cin >> n >> m;
	int **mas;
	mas = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[m];
		for (int j = 0; j < m; j++)
			mas[i][j] = 0;
	}
	rekyrs(mas);
return 0;
}
void rekyrs(int**mas)
{
	int **new_mas;
	int niz, pravo;
	new_mas = new int*[n];
	int i, j;
	bool o = true;
	for (i = 0; i < n; i++)
	{
		new_mas[i] = new int[m];
		memcpy(new_mas[i], mas[i], sizeof(int)*m);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (new_mas[i][j] == 0)
			{
				o = false;
				break;
			}
		}
		if (!o) break;
	}
	if (o)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				cout << char(new_mas[i][j] + 96);
			cout << endl;
		}
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (i + 3 < n)
				if (new_mas[i][j] == 0 && new_mas[i + 1][j] == 0 && new_mas[i + 2][j] == 0 && new_mas[i + 3][j] == 0)
					compatibility(new_mas, i, j, 2);
			if (j + 3 < m)
				if (new_mas[i][j] == 0 && new_mas[i][j + 1] == 0 && new_mas[i][j + 2] == 0 && new_mas[i][j + 3] == 0)
					compatibility(new_mas, i, j, 1);
			if (i + 1<n &&j + 1<m)
				if (new_mas[i][j] == 0 && new_mas[i][j + 1] == 0 && new_mas[i + 1][j] == 0 && new_mas[i + 1][j + 1] == 0)
					compatibility(new_mas, i, j, 3);
		}
	}
	ochistka(new_mas, n);
}
int max(int **mas)
{
	int i, j, maxim = 0;;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			if (mas[i][j]>maxim) maxim = mas[i][j];
		}
	return maxim;
}
void ochistka(int **mas, int n1)
{
	for (int i1 = 0; i1 < n1; i1++)
		delete[]mas[i1];
	delete[]mas;
}
void compatibility(int**mas, int niz, int pravo, int dir)
{
	int **new_mas;
	new_mas = new int *[n];
	for (int i = 0; i < n; i++)
	{
		new_mas[i] = new int[m];
		memcpy(new_mas[i], mas[i], sizeof(int)*m);
	}
	int number = max(mas) + 1;
	switch (dir)
	{
	case 1:
	{
		new_mas[niz][pravo] = number;
		new_mas[niz][pravo + 1] = number;
		new_mas[niz][pravo + 2] = number;
		new_mas[niz][pravo + 3] = number;
		break;
	}
	case 2:
	{
		new_mas[niz][pravo] = number;
		new_mas[niz + 1][pravo] = number;
		new_mas[niz + 2][pravo] = number;
		new_mas[niz + 3][pravo] = number;
		break;
	}
	case 3:
	{

		new_mas[niz][pravo] = number;
		new_mas[niz][pravo + 1] = number;
		new_mas[niz + 1][pravo] = number;
		new_mas[niz + 1][pravo + 1] = number;
		break;
	}
	}

	rekyrs(new_mas);

}
