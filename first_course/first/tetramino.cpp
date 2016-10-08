#include <iostream>
using namespace std;
void proverka(int **,int,int,const int [3][2]);
void vichislyat(int **, int, int, int, int,int,const int [3][2]);
int max(int, int);
const int a[3][2] = { {1,1},{1,0},{1,0} },  d[3][2] = { {5,0},{5,5},{5,0} }, e[3][2] = { {9,0},{9,9},{0,9} };
int tsvet = 0;
int main()
{
	int n, m,i,j;
	cin >> n >> m;
	int **mas;
	mas = new int*[n];
	for (i = 0; i < n; i++)
	{
		mas[i] = new int[m];
		for (j = 0; j < m; j++)
			mas[i][j] = 0;
	}
	proverka(mas,n,m,a);
	proverka(mas, n, m, b);
	proverka(mas, n, m, c);
	proverka(mas, n, m, d);
	proverka(mas, n, m, e);
	system("pause");
	return 0;
}
void proverka(int **mas,int n,int m,const int al[3][2])
{
	int i, j,**bl;
	bl = new int*[n];
	for (i = 0; i < n; i++)
	{
		bl[i] = new int[m];
		memcpy(bl[i], mas[i], sizeof(int)*m);
	}

	bool o = true;
	for (int i1 = 0; i1 < n; i1++)
		{
			for (int j1 = 0; j1 < m; j1++)
				if (mas[i1][j1] == 0)
				{
					o = false;
					i = i1;
					j = j1;
					break;
				}
			if (!o) break;
		} 
	if (o)
	{
		for (int i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				cout << mas[i][j];
			cout << endl;
		}
		system("pause");
		exit(0);
	}
	else
	{
		vichislyat(bl,n,m,i,j,1,al);
		vichislyat(bl, n, m, i, j, 2,al);
		vichislyat(bl, n, m, i, j, 3,al);
		vichislyat(bl, n, m, i, j, 4,al);
	}
	
		
}
void vichislyat(int **mas, int n, int m, int i, int j,int k,const int al[3][2])
{
	int **bl;
	bl = new int*[n];
	for (int i1 = 0; i1 < n; i1++)
	{
		bl[i1] = new int[m];
		memcpy(bl[i1], mas[i1], sizeof(int)*m);
	}
	switch (k)
	{
	case 1:
		{
			if (i + 2 >= n ||j + 1 >= m) return;
 			if (al[0][0] != 0)
			bl[i][j] = al[0][0];
			if (al[0][1] != 0) bl[i][j + 1] = max(al[0][1], bl[i][j + 1]);
			i++;
			if (al[1][0] != 0) bl[i][j] = max(al[1][0], bl[i][j]);
			if (al[1][1] != 0) bl[i][j + 1] = max(al[1][1], bl[i][j+1]);
			i++;
			if (al[2][0] != 0)	 bl[i][j] = max(al[2][0], bl[i][j]);
			if (al[2][1] != 0) bl[i][j + 1] = max(al[2][1], bl[i][j+1]);
			break;
		}
	case 2:
		{
			if (i + 2 >= n || j + 1 >= m) return;
			if (al[2][1] != 0)
				bl[i][j] = al[2][1]+1;
			if (al[2][0] != 0)	 bl[i][j + 1] = max(al[2][0]+1, bl[i][j + 1]);
			i++;
			if (al[1][1] != 0)	 bl[i][j] = max(al[1][1], bl[i][j]);
			if (al[1][0] != 0) bl[i][j + 1] = max(al[1][0], bl[i][j+1]);
			i++;
			if (al[0][1] != 0) bl[i][j] = max(al[0][1], bl[i][j]);
			if (al[0][0] != 0) bl[i][j + 1] = max(al[0][0], bl[i][j+1]);
			break;
	
		}
	case 3:
		{
			if (j + 2 >= m || i + 1 >= n) return;
			bl[i][j] = (al[0][1]);
			if (al[1][1] != 0) bl[i][j + 1] = max(al[1][1], bl[i][j+1]);
			if (al[2][1] != 0) bl[i][j + 2] = max(al[2][1], bl[i][j+2]);
			i++;
			if (al[0][0] != 0)  bl[i][j] = max(al[0][0], bl[i][j]);
			if (al[1][0] != 0)  bl[i][j + 1] = max(al[1][0], bl[i][j+1]);
		    if (al[2][0] != 0)  bl[i][j + 2] = max(al[2][0], bl[i][j+2]);
			break;
		}
	case 4:
		{
			if (j + 2 >= m || i + 1 >= n) return;
			bl[i][j] = al[2][0];
			if (al[1][0] != 0) bl[i][j + 1] = max(al[1][0], bl[i][j+1]);
			if (al[0][0] != 0) bl[i][j + 2] = max(al[0][0], bl[i][j+2]);
			i++;
			if (al[2][1] != 0)  bl[i][j] = max(al[2][1], bl[i][j]);
			if (al[1][1] != 0)  bl[i][j + 1] = max(al[1][1], bl[i][j+1]);
			if (al[0][1] != 0)  bl[i][j + 2] = max(al[0][1], bl[i][j+2]);
			break;
			}
	}
	proverka(bl, n, m, a);
	proverka(bl, n, m, b);
	proverka(bl, n, m, c);
	proverka(bl, n, m, d);
	proverka(bl, n, m, e);
}
int max(int a1, int b)
{
	if (a1 > b) return a1; else return b;
}