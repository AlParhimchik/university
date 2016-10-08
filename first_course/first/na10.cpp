#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	char a[100], *a1, *b, *max, *min;
	int i, n;
	cout << "vvedite stroky: " << endl;
	cin.getline(a, 100);
	a1 = strdup(a);
	b = strtok(a1, " ");
	max = min = b;
	while (b != NULL)
	{
		if (strlen(b) > strlen(max)) max = b;
		if (strlen(b) < strlen(min)) min = b;
		b = strtok(NULL, " ");
	}
	cout << min << endl << max << endl;
	system("pause");
	free(a1);
	return 0;
}