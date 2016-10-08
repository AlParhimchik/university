#include <iostream>
#include <string.h>
using namespace std;
void k(int*);
int main()
{
	int *mas;
	mas = new int[5];
	mas[0] = 5;
	k(mas);
	return 0;
}
void k(int *a)
{
	int *b = new int[5];
	int bc;
	b[0] = 1;
	memcpy(a, b,sizeof(a));
	cout << a[0] << endl;
	system("pause");
}