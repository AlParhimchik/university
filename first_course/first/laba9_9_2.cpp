#include <iostream>
#include <math.h>
using namespace std;
double fun(int, int);
int main()
{
	int n;
	cout << "Vvedite n: "; cin >> n;
	cout << (fun(1, n)) << endl;
	system("pause");
	return 0;
}
double fun(int i, int n)
{
	if (i == n) return sqrt(n);
	return sqrt(i + fun(i + 1, n));
}