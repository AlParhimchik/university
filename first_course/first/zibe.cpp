#include<iostream>
#include<math.h>
#include<stdlib.h>
#include <conio.h>
using namespace std;
int SearchElements(int*);
int main()
{
	int a[5], b[5], i;
	for (i = 0; i < 5; i++)
	{
		cout << "a[" << i + 1 << "]=";
		cin >> a[i];
	}
	cout << endl;
	for (i = 0; i < 5; i++)
	{
		cout << "b[" << i + 1 << "]=";
		cin >> b[i];
	}
	if (SearchElements(a) < SearchElements(b))

	{
		for (i = 0; i < 5; i++)
			cout << a[i] << " ";
		cout << endl;
		for (i = 0; i < 5; i++)
			cout << b[i] << " ";
	}
	else
	{
		for (i = 0; i < 5; i++)
			cout << b[i] << " ";
		cout << endl;
		for (i = 0; i < 5; i++)
			cout << a[i] << " ";
	}
	getch();
	return 0;
	
}
int SearchElements(int *a)
{
	int kol_vo=0;
	for (int i = 0; i < 5; i++)
		if (a[i] < 0) kol_vo++;
	return kol_vo;
}
