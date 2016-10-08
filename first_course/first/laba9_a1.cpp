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
	if (i == n)
	{
	if	(a[i] < 0) return 1;
	else return 0;
	}
	return  poisk(a, i, (i+n)/2) +poisk(a, (i+n)/2+1, n);
}