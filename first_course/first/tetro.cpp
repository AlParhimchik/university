#include <iostream>
using namespace std;
void rekyrs(int **,const int[3][2]);
int max(int **);
int ** rotate(const int[3][2],int);
void compatibility(int **,int**,int,int);
void compatibility(int **, int, int,int);

void ochistka(int **,int);

const int a[3][2] = { {1,1},{1,0},{1,0} }, b[3][2] = { { 1,0 },{ 1,0 },{ 1,1 } }, c[3][2] = { { 1,0 },{ 1,1 },{ 1,0 } }, d[3][2] = { { 0,1 },{ 1,1 },{ 1,0 } }, e[3][2] = { { 1,0 },{ 1,1 },{ 0,1 } };
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
	rekyrs(mas, a);
	rekyrs(mas, b);
	rekyrs(mas, c);
	rekyrs(mas, d);
	rekyrs(mas, e);
	return 0;
}
void rekyrs(int**mas, const int qt[3][2] )
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
		system("pause");
		exit(0);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (i + 3 < n)
				if (new_mas[i][j] == 0 && new_mas[i+1][j ] == 0 && new_mas[i+2][j] == 0 && new_mas[i+3][j] == 0)
					compatibility(new_mas, i, j, 2);
			if (j + 3 < m)
			if (new_mas[i][j]==0&& new_mas[i][j+1] == 0 && new_mas[i][j+2] == 0 && new_mas[i][j+3] == 0 )
				compatibility(new_mas, i, j,1);
			if (i+1<n &&j+1<m)
			if (new_mas[i][j] == 0 && new_mas[i][j + 1] == 0 && new_mas[i+1][j ] == 0 && new_mas[i+1][j + 1] == 0)
				compatibility(new_mas, i, j, 3);

			compatibility(new_mas, rotate(qt, 1), i, j);
			compatibility(new_mas, rotate(qt, 2), i, j);
			compatibility(new_mas, rotate(qt, 3), i, j);
			compatibility(new_mas, rotate(qt, 4), i, j);
		}
	}
	ochistka(new_mas,n);

}
int ** rotate(const int qt[3][2], int dir)
{
	if (dir == 1 || dir == 3)
	{
		n1 = 3;
		m1 = 2;
	}
	else
	{
		n1 = 2;
		m1 = 3;
	}
	int **new_const;
	new_const = new int*[n1];
	for (int i = 0; i < n1; i++)
		new_const[i] = new int[m1];
	switch (dir)
	{
	case 1:
	{
		for (int i = 0; i < n1;i++)
		memcpy(new_const[i], qt[i], sizeof(int)*m1);
		break;
	}
	case 2:
	{
		new_const[0][0] = qt[2][0];
		new_const[0][1] = qt[1][0];
		new_const[0][2] = qt[0][0];
		new_const[1][0] = qt[2][1];
		new_const[1][1] = qt[1][1];
		new_const[1][2] = qt[0][1];
		break;
	}
	case 3:
	{
		new_const[0][0] = qt[2][1];
		new_const[0][1] = qt[2][0];
		new_const[1][0] = qt[1][1];
		new_const[1][1] = qt[1][0];
		new_const[2][0] = qt[0][1];
		new_const[2][1] = qt[0][0];
		break;
	}
	case 4:
	{
		new_const[0][0] = qt[0][1];
		new_const[0][1] = qt[1][1];
		new_const[0][2] = qt[2][1];
		new_const[1][0] = qt[0][0];
		new_const[1][1] = qt[1][0];
		new_const[1][2] = qt[2][0];
		break;
	}
	
	}
	return new_const;
}
void compatibility(int**mas, int**qt,int niz,int pravo)
{
	int number = max(mas)+1;
	if (niz + n1 > n || pravo + m1 >m)
	{
		ochistka(qt,n1);
		return;
	}

	int **new_mas,i,j,i1=0,j1=0;
	new_mas = new int *[n];
	for (int i = 0; i < n; i++)
	{
		new_mas[i] = new int[m];
		memcpy(new_mas[i],mas[i],sizeof(int)*m);
	}
	for (i = niz; i < niz + n1;i++)
	{
		for (j = pravo; j < pravo + m1;j++)
		{
			if (qt[i1][j1] != 0)
			{
				if (new_mas[i][j] != 0)
				{
					ochistka(new_mas, n);
					ochistka(qt, n1);
					return;
				}
				new_mas[i][j] = number;
			}
			j1 = (j1 + 1) % m1;
		}
		i1 = (i1 + 1) % n1;
	}
	ochistka(qt, n1);;
	rekyrs(new_mas, a);
	rekyrs(mas, b);
	rekyrs(mas, c);
	rekyrs(mas, d);
	rekyrs(mas, e);
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
	delete []mas;
}
void compatibility(int**mas, int niz, int pravo,int dir)
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
		new_mas[niz+1][pravo] = number;
		new_mas[niz+2][pravo] = number;
		new_mas[niz+3][pravo] = number;
		break;
	}
	case 3:
	{
		
		new_mas[niz][pravo] = number;
		new_mas[niz][pravo + 1] = number;
		new_mas[niz+1][pravo ] = number;
		new_mas[niz+1][pravo +1] = number;
		break;
	}
	}

	rekyrs(new_mas, a);
	rekyrs(mas, b);
	rekyrs(mas, c);
	rekyrs(mas, d);
	rekyrs(mas, e);
}
