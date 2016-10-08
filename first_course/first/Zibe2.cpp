#include <iostream>
#include <conio.h>
void Rotate(int **,int);
using namespace std;
int main()
{
	int n,**mas,i,j;
	cout << "Vvedite razmer massiva: "; cin >> n;
	mas = new int*[n];
	for (i = 0; i < n; i++)
	{
		mas[i] = new int[n];
		for (j = 0; j < n; j++)
		{
			cout << "mas[" << i + 1 << "][" << j + 1 << "]="; cin >> mas[i][j];
		}
	}
	Rotate(mas,n);
	cout << "isxodniy masssiv:\n";
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	for (i = 0; i < n; i++)
		delete[]mas[i];
	delete[]  mas;
	getch();
	return 0;
}
void Rotate(int **mas,int n)
{
	cout << "Povernytiy masssiv\n";
	int i, j;
	for (i = n-1; i >=0; i--)
	{
		for (j = 0; j<n; j++)
		{
			cout << mas[j][i] << " ";
		}
		cout << endl;
	}
	cout << "-----------------\n";
}