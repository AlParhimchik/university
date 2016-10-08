#include "iostream"
using namespace std;
int main()
{
	int i, n, j, p, p1, p3, gra, p2, ch;
	cout << "Vvedite razmer kvadratnoi matrici= " << endl;
	cin >> n;
	int **a = new int *[n];
	for (i = 0; i < n; i++) a[i] = new int[n];
	if (n % 2 == 1)
	{
		a[n / 2][n / 2] = n*n;
	}
	gra = 0;
	p = 0;
	p1 = n * 2;
	p3 = 2 * n + n - 2;
	p2 = 2 * n + n - 2;
	for (j = 0; j < n / 2; j++)
	{
		ch = 1;
		for (i = gra; i < n - gra; i++, ch++)
		{
			if (i<n - j - 1) a[j][n - 1 - i] = p3 + ch - 1;
			a[n - j - 1][n - i - 1] = p1 - ch;
			a[i][n - j - 1] = p2 - ch + 1;
			a[i][j] = ch + p;
		}
		p3 += 3 * (n - (j)* 2 - 2) + (n - (j)* 2 - 4);
		p1 += 4 * (n - (j)* 2 - 2);
		p += 2 * (n - (j)* 2) + 2 * (n - (j)* 2 - 2);
		p2 += 3 * (n - (j)* 2 - 2) + (n - (j)* 2 - 4);
		gra++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) cout << a[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
