#include <iostream>
using namespace std;
void qsort(int*,int, int);
int main()
{
	int a[5];
	int i;
	for (i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	qsort(a,0, 2);
	for (i = 0; i < 3; i++)
		cout << a[i] << " " << endl;
	system("pause");
	return 0;
}
void qsort(int *a, int left, int rigth)
{
	int i = left, j = rigth, t;

	t = a[(i + j) / 2];
	do
	{ 
		while (a[i] < t&& i< rigth) i++;;
		while (a[j] > t && j>left) j--;
		if (i <= j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;

		}
	} while (i <= j);
	if (i<rigth) qsort(a,i,rigth);
	if (j>left) qsort(a,left,j);
}