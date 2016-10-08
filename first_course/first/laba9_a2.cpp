#include <iostream>
using namespace std;
int poisk(int *, int, int);
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
int poisk(int *a, int i, int n)
{
	int k, p;
	if (i == n)
		if (a[i] > 0) return a[i]; else return 0;
	p = (n - i) / 3;
	p += i;
	return (a, poisk(a, i, p) + poisk(a, p + 1, n));
}