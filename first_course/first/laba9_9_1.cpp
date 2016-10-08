#include <iostream>
using namespace std;
int poisk(int *, int, int);
int main()
{
	int *a,n,i;
	cout << "enter dliny: ";
	cin >> n;
	a = new int[n];
	for (i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "]=";
		cin >> a[i];
	}
	cout<<poisk(a, 0, n - 1)<<endl;
	system("pause");
	return 0;
}
int poisk(int *a, int i, int n)
{
	if (i == n)
	{
		if (a[i] * a[i]>10) return a[i];
		else return 0;
	}
	//cout << i << " " << n << endl;
	return poisk(a, i, int(2*(i+n)/3.)) + poisk(a, int(2*(i+n)/3.)+1, n);
	
}
