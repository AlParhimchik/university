#include <iostream>
#include <math.h>
using namespace std;
int nod(int, int);
int Delitel(int);
void  Search(int, int);
 int main()
{
	long long n,i=1,j,sum=1,k,k1;
	cin >> n;
	if (n > 48634207310)
	{
		i = 400000;
		sum = 48634207310;
	}
	else
	if (n > 27356748484)
	{
		i = 300000;
		sum = 27356748484;
	}
	else
	if (n > 7781474124)
	{
		i = 160000;
		sum = 7781474124;
	}
	else
	if (n > 5957720032)
	{
		i = 140000;
		sum = 5957720032;
	}
	else
	if (n > 3039650754)
	{
		i = 100000;
		sum = 3039650754;
	}
	else
	if (n > 2000003170)
	{

		i = 81115;
		sum= 2000003170;
	}
	else
		if (n > 1094277506)
		{
			i = 60000;
			sum = 1094277506;
		}
		else
			if (n > 486345716)
			{
				i = 40000;
				sum = 486345716;
			}
	if (n == 1) cout << "1/1";
	else 
	while (true)
	{
		i++;
		 j= Delitel(i);
		 sum += j;
		 if (i == 400000) cout << sum << endl;
		  if (sum >=n)
		 {
		
			 Search(i, n-sum+j);
			 cout << "lolpzdc" << i<<" "<<sum<<endl;
			 system("pause");
		 }
		 

	}

	

	return 0;
}
 void  Search(int i, int sum)
 {
	 int j,p=0;
	 for (j = 1; j < i;j++)
	 {
		 if (nod(i, j) == 1) p++;
		 if (p == sum)

		 {
			 cout << j << "/" << i << endl;
			 system("pause");
			 exit(0);
		 }
	 }
 }
int nod(int a, int b)
{
	unsigned t;
	while (b)
	{
		a %= b;
		t = a;
		a = b;
		b = t;
	}
	return a ;
}
int Delitel(int k)
{
	int t = k, sum = 0,p=1,j;
	//k = sqrt(k);
	for (int i = 2; i <=sqrt(t); i++)
	{
		if (t % i == 0)
		{
			j = 0;
			while (t%i == 0)
			{
				t = t / i;
				j++;

			}
			if (j == 1) p *= i - 1;
			else p*= pow(i,j-1)*(i-1);
 		}
	}
	if (t != 1) p *= t - 1;
	return p;
}
