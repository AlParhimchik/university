#include<iostream>
int func(int, int);
using namespace std;
int main()
{
	int n, k;
	cout << "VVedite n: "; cin >> n;
	cout << "vvedite k: "; cin >> k;
	if (k >= n)
	{
		cout << "Vvedite pravil'no dannie!"<<endl;
		system("pause");
		return 1;
	}
	cout << func(n, k) << endl;
	system("pause");
	return 0;
}
int func(int n, int k)
{
	if (k == 0 || k == n) return 1;
	return func(n - 1, k) + func(n-1,k-1);
}