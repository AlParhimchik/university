#include <iostream>
using namespace std;
int main()
{
	const int size = 10;
	char **a,b,*x;
	int prob[size], i, j, kol = 0, max = 0, min = size, maxI, minI;
	a = new char *[size];
	for (i = 0; i < size; i++)
	{
		a[i] = new char[size];
	}
	i = 0;
	cin.get(b);
	while (b != '\n')
	{
		if (b == ' ')
			
		{
			prob[kol] = 0;
			while (b == ' ')
			{
				prob[kol]++;
				cin.get(b);
			}
			kol++;
			prob[kol] = 0;
		}
		else
		{
			if (i == 0 && kol == 1)
			{
				a[i] = "\0";
				i++;
			}
			j = 0;
			while (b != ' '&&b != '\n')
			{
				a[i][j] = b;
				j++;
				a[i][j] = '\0';
				cin.get(b);
			}
			if (j > max)
			{
				max = j;
				maxI = i;
			}
			if (j < min)
			{
				min = j;
				minI = i;
			}
			i++;
		}
	}
	
	x=(a[maxI]);
	a[maxI]=(a[minI]);
	a[minI] = x;
	for (int j = 0; j < i; j++)
	{
		cout << a[j];
		for (int z = 0; z < prob[j]; z++)
			cout << ' ';
	}cout << endl;
	system("pause");
	return 0;
}