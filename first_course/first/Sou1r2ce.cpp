#include <iostream>
#include <conio.h>

using namespace std;

int nod(int a, int b) {
	while (a != b) {
		if (a>b) {
			a = a - b;
		}
		else {
			b = b - a;
		}
	}
	return a;
}

int main()
{
	unsigned int K;
	cin >> K;
	int i, j, k = 0;

	for (i = 1; i<1000000000; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (nod(i, j) == 1) k++;
			if (k == K) break;
		}
		if (k == K) break;
	}
	cout << j << "/" << i << endl;
	getch();
	return 0;
}