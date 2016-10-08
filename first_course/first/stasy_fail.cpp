#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
using namespace std;

////////////////////////////////////
struct Avtomobily
{
	char marka[20];
	int year;
	double obyem, rashod;
};
////////////////////////////////////

int menu();//Меню
char *filename(char *);//имя файла
void newfile(char *);//создание файла
void list(char *);//создание списка машин
void openfile(char *);//открытие и чтение 
void result(char *,bool);//вывод данных 
//void result(char *,bool);//вывод данных в текстовый файл

int main()
{
	char name[20] ="";
	while (true)
	{
		switch (menu())
		{
		case 1: filename(name); break;
		case 2: newfile(name); break;
		case 3: list(name); break;
		case 4: openfile(name); break;
		case 5: result(name,true); break;
		case 6: result(name,false); break;
		case 7: return 0;
		default: "CHOOSE CORRECTLY!";
		}
		puts("Press any key to continue");
		_getch(); system("cls");
	}
	system("pause");
}
//////////////////////////////////
int menu()
{
	cout << "CHOOSE:" << endl;
	cout << "1. Enter filename" << endl;
	cout << "2. New file" << endl;
	cout << "3. Enter list" << endl;
	cout << "4. Open file" << endl;
	cout << "5. Output the result" << endl;
	cout << "6. Output into the file" << endl;
	cout << "7. Exit" << endl;
	int i;
	cin >> i;
	return i;
}
///////////////////////////////////////
char *filename(char *name)
{
	if (strlen(name)) return name;
	cout << "Enter file name" << endl;
	cin >> name;
	return name;
}
///////////////////////////////////////
void newfile(char *name)
{
	FILE *fl;
	if ((fl = fopen(name, "wb")) == NULL)
	{
		cout << "Error while trying to build" << endl;
		exit(1);
	}
	cout << "OK" << endl;
	fclose(fl);
}
///////////////////////////////////////
void list(char *name)
{
	int nstr;
	FILE *fl;
	Avtomobily car[100];
	if ((fl = fopen(name, "rb+")) == NULL)
	{
		cout << "Error while trying to build" << endl;
		exit(1);
	}
	cout << "Enter the number of cars " << endl;
	cin >> nstr;
	for (int i = 0; i < nstr; i++)
	{
		cout << "Enter " << i + 1 << " mark: ";
		cin >> car[i].marka;
		cout << "Enter the year: ";
		cin >> car[i].year;
		cout << "Enter V of the engine(ex: 2.0): ";
		cin >> car[i].obyem;
		cout << "Enter the amount of petrol per 100 km(ex: 7.3 litres/100km): ";
		cin >> car[i].rashod;
		fwrite(&car[i], sizeof(Avtomobily), 1, fl);
	}
	fclose(fl);
}
/////////////////////////////
void openfile(char *name)
{
	int nstr;
	FILE *fl;
	Avtomobily car[100];
	if ((fl = fopen(name, "rb")) == NULL)
	{
		cout << "Error while opening" << endl;
		exit(1);
	}
	nstr = 0; Avtomobily avto;
	while (true)
	{
		int chten = fread(&avto, sizeof(Avtomobily), 1, fl);
		if (chten != 1) break;
		car[nstr] = avto;
		cout << car[nstr].marka << " " << car[nstr].year << " " << car[nstr].obyem << " " << car[nstr].rashod << endl;
		nstr++;
	}
	fclose(fl);
}
////////////////////////////////
void result(char *name, bool status)
{
	Avtomobily car[100];
	FILE *fl;
	int nstr;
	if ((fl = fopen(name, "rb")) == NULL)
	{
		cout << "Error while opening" << endl;
		exit(1);
	}
	nstr = filelength(fileno(fl)) / sizeof(Avtomobily);
	Avtomobily perem;
	fread(car, sizeof(Avtomobily), nstr, fl);
	fclose(fl);
	for (int i = 0; i < nstr - 1; i++)
		for (int j = i + 1; j < nstr; j++)
			if (car[i].rashod>car[j].rashod)
			{
				perem = car[i];
				car[i] = car[j];
				car[j] = perem;
			}
	char namef[20];
	FILE *mah;
	if (!status)
	{
		cout << "Enter file name" << endl;
		cin >> namef;
		if ((mah = fopen(namef, "w")) == NULL)
		{
			cout << "Error while building textfile" << endl;
			exit(1);
		}
	}
	for (int i = 0; i < nstr; i++)
		if (car[i].year >= 2004)
		{
			if (status) cout << car[i].marka << " " << car[i].year << " " << car[i].obyem << " " << car[i].rashod << endl;
			else fprintf(mah, "%s,%e,%e,%d", car[i].marka, car[i].obyem, car[i].rashod, car[i].year);
		}
	 if (!status) fclose(mah);
}
////////////////////////////////
/*void resulfile(char *name)
{
	FILE *fl;
	int nstr;
	Avtomobily car[100];
	char namef[20];
	FILE *mah;
	cout << "Enter file name" << endl;
	cin >> namef;
	if ((mah = fopen(namef, "w")) == NULL)
	{
		cout << "Error while building textfile" << endl;
		exit(1);
	}
	if ((fl = fopen(name, "rb")) == NULL)
	{
		cout << "Error while opening" << endl;
		exit(1);
	}
	nstr = filelength(fileno(fl)) / sizeof(Avtomobily);
	Avtomobily perem;
	for (int i = 0; i < nstr - 1; i++)
	{
		fread(&car[i], sizeof(Avtomobily), 1, fl);
		for (int j = i + 1; j < nstr; j++)
			if (car[i].rashod>car[j].rashod)
			{
				perem = car[i];
				car[i] = car[j];
				car[j] = perem;
			}
	}
	for (int i = 0; i < nstr; i++)
	{
		if (car[i].year >= 2004)
			fprintf(mah, "%s,%e,%e,%d", car[i].marka, car[i].obyem, car[i].rashod, car[i].year);
	}
	fclose(fl);
	fclose(mah);
}
*/