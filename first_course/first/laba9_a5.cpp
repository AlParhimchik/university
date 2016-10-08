#include <iostream>
using namespace std;
int poisk(int *, int, int);
int min(int, int);
int main()
{
	int i, *a, n;
	cout << "Vvedite n: "; cin >> n;
	a = new int[n];
	for (i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "]="; cin >> a[i];
	}
	cout << poisk(a, 0, n - 1)  << endl;
	system("pause");
	return 0;
}
int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}
int poisk(int *a, int i, int n)
{
	if (i == n) return a[i];
	return min(poisk(a, i, (i + n) / 2), poisk(a, (i + n) / 2 + 1, n));
}