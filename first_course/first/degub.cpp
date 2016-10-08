#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;
int main()
{
	char array[5][7] = {"xleb","moloko","kefir","baton"};
	char t[20]="";
	srand(time(NULL));
	for (int i= 0; i < 1000; i++)
	{
		char t[20] = "";
		strcat(t, array[rand() % 4]);
		cout << t << endl;
		cout << rand() % 1000;
	}
	getch();
	return 0;
}