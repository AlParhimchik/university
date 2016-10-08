#include <iostream>
#include <conio.h>
#include <stdlib.h>
void CreateFileAndVvodChisel(char *);
bool DoTasks(char*);
void WriteToFile( bool);
void WriteToDisplay(bool);
const int t = 3;
using namespace std;
int main()
{
	char file_name[20] = "";
	bool status = false;
	
	CreateFileAndVvodChisel(file_name);
	cout << "fail sozdan.\n";
	cout << "----------------------\n";
	status=DoTasks(file_name);
	WriteToFile(status);
	cout << "Informatsiya yspewno vivedena f fail\n";
	cout << "----------------------\n";
	WriteToDisplay(status);
	return 0;
}
void CreateFileAndVvodChisel(char *file_name)
{
		int a[t];
	cout << "vvedite nazvanie faila dlya zapisi: ";
	cin.getline(file_name, 20);
	strcat(file_name, ".txt");
	FILE *fl;
	if ((fl = fopen(file_name, "wb"))== NULL)
	{
		cout << "fatal error" << endl;
		getch();
		exit(1);
	}
	cout << "vvedite "<< t<<" chisel!\n";
	for (int i = 0; i < t; i++)
	{
		cout << i + 1 << "-oe chislo = "; cin >> a[i];
	}
	if (fwrite(a, sizeof(int), t, fl) != t)
	{
		cout << "Error\n";
		getch();
		exit(4);
	}
	fclose(fl);
}
bool DoTasks(char *file_name)
{
	FILE *fl;
	int a[t], i, sum=0;
	if ((fl = fopen(file_name, "rb")) == NULL)
	{
		cout << "Fatal error!\n";
		getch();
		exit(1);

	}
	fread(a, sizeof(int), t, fl);
	for (i = 0; i < t; i++) sum += a[i];
	for (i = 0; i < t; i++)
	{
		if (a[i]<0)
			if (fabs(a[i])>sum / t) return true;
	}
	fclose(fl);
	return false;
}
void WriteToFile( bool status)
{
	FILE *fl;
	char file_name[20] = "",status_string[20]="";
	
	cout << "Vvedite nazvanite faila dlya vivoda: \n";
	cin >> file_name;
	if ((fl = fopen(file_name, "wb")) == NULL)
	{
		cout << "Fatal error!\n";
		getch();
		exit(3);

	}
	switch (status)
	{
	case true: strcat(status_string,"est'"); break;
	case false: strcat(status_string, "nety"); break;
	}
	fwrite(status_string, sizeof(char), strlen(status_string), fl);
	fclose(fl);
}
void WriteToDisplay(bool status)
{
	switch (status)
	{
	case true:cout <<  "est'\n"; break;
	case false:cout <<  "nety\n"; break;
	}
	getch();
}
