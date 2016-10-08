#include <iostream>
#include <stdio.h>
void proverka(int, int, int&, int&, int&, int&);
using namespace std;
int main()
{
	char **a, b = ' ',*x;
	int i, j,k=0,pr[100],maxi,mini,min=100,max=0;
	bool q = true;
	const int size=10;
	a = new char *[size];
	for (i = 0; i < size; i++)
		a[i] = new char[size];
	i = j=k=0;
	pr[0] = 0;
	cin.get(b);
	while (b != '\n')
	{
		
		if (b == ' ')
		{
			if (i == 0 && k == 0)
			{
				a[i] = "\0";
				i++;
			}
			proverka(i, j, max, min, maxi, mini);
			
			if (j != 0)	i++;
			j = 0;
			pr[k]++;
		}
		else
		{
			if (pr[k]!=0)
			{
				k++;
				pr[k] = 0;
			}
			a[i][j] = b;
			j++;
			a[i][j] = '\0';
		}
		cin.get(b);
	}
	if (j == 0) i--;
	proverka(i, j, max, min, maxi, mini);
	{
		x = a[maxi];
		a[maxi] = a[mini];
		a[mini] = x;
	}
		for (j = 0; j <= i; j++)
	{
		 cout << a[j];
		for (int p = 0; p < pr[j]; p++)
				cout << ' ';
	}
	cout << endl;
	for (i = 0; i < size; i++)
		delete []a[i];
	delete[]a;
	system("pause");
	return 0;
}
void proverka(int i, int j, int& max, int& min, int& maxi, int&mini)
{
	if (j > max)
	{
		max = j;
		maxi = i;
	}
	if (j < min && j != 0)
	{
		min = j;
		mini = i;
	}
}