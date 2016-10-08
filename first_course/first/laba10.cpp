#include <iostream>
int func(int *, int, int);
using namespace std;
int main()
{
	int n;
	cout << "vvedite n: "; cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "vvedite a[" << i + 1 << "]="; cin >> a[i];
	}
	cout << func(a, 0, n-1)<<endl;
	system("pause");
	delete[]a;
	return 0;
}
int func(int *a, int i, int n)
{
	if (i == n) return a[i];
	int t = (n - i) / 3;
	return func(a, i, i + t) + func(a, i + t+1, n);

}