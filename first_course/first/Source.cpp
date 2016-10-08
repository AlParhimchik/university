#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	char a[100];
	int i, n,nac,con,min=100,max=0,maxi,mini;
	bool o = false,k=false;
	cout << "vvedite stroky: " << endl;
	cin.getline(a, 100);
	strcat(a, " ");
	for (i = 0; i < strlen(a); i++)
	{
		if (a[i] == ' ')
		{
			if (!k)
			{
				o = false;
				con = i;
				if (con - nac > max)
				{
					max = con - nac;
					maxi = nac;
				}
				if (con - nac < min)
				{
					min = con - nac;
					mini = nac;
				}
				k = true;
			}
		}
		else
		{
			if (!o)
			{
				nac = i;
				 o= true;
				 k = false;
			}
			
		}
	}
	cout << max << endl << min << endl << maxi << " " << mini << endl;

	system("pause");
	return 0;
}