#include	<iostream>
#include    <stdio.h>
#include <conio.h>
#include<cstdio>
#include <io.h>
#include <ctime>
//////// внести в одну функцию для вывода на экран и в файл 
struct tovar
{
	char Naimenovanie[20]="";
	int Kol_vo, Cost;

};

int menu();
void ZapisToFile(char *,char (*array)[20]);
void ReadData(char *);
void Result(char *,bool);
void sort(char *,bool);
void Errors(int);
void sort_viborom(tovar *,int);
void sort_qsort_nerekyrsivno(tovar *,int);
void search(char *);
int search_binarniy(tovar *,int,int);
int search_lineiniy(tovar*,int,int);

using namespace std;
int main()
{
	char array[][20] = { "xleb","moloko","kefir","baton","miaso","shokolad"};
	char file_name[20] = "";
	while (1)
	{
		switch (menu())
		{
		case 1: {ZapisToFile(file_name,array); break; };
		case 2: {ReadData(file_name); break; };
		case 3: {Result(file_name, true); break; };
		case 4: {Result(file_name, false); break; };
		case 5: {sort(file_name, false); break; };
		case 6: {sort(file_name, true); break; };
		case 7: {search(file_name); break; };
			case 8: {system("cls"); cout << "Good Luck" << endl; system("pause"); exit(0); };
			default:
			{
				Errors(3);
			}
		}
	}
	return 0;
}
int menu()
{
	system("cls");
	cout << "Vibetite pynkt menu:\n";
	cout << "1.Zapisar' v fail" << endl;
	cout << "2.Proshitat' dannie" << endl;
	cout << "3.Vivesti v fail" << endl;
	cout << "4.Vivesti na ekran" << endl;
	cout << "5.QuickSort" << endl;
	cout << "6.Sortirovka viborom" << endl;
	cout << "7.Poisk elementa" << endl;
	cout << "8.Vixod iz menu" << endl;
	char i[20] = "";
	cin>>(i);
	return atoi(i);
}
void ZapisToFile(char *file_name,char (*array)[20])
{
	FILE *fl;
	if (strlen(file_name)==0) 
	{
		cout << "vvedite nazvanie faila:" << endl;
		cin >> file_name;
		strcat(file_name, ".txt");
	}
	if ((fl = fopen(file_name, "wb")) == NULL)
	{
		Errors(4);
		return;
	}
	cout << "1)Vvesti dannie s klaviatyri\n2)Sgeneririgat' dannie\n";
	
	char t;
	cin >> t;
	if (t == '1')
	{
		t = 'y';
		tovar list;
		while (t == 'y')
		{
			cout << "vvedite informatsiy ob tovare:\n";
			cout << "Vvedite naimenovanie: ";
			cin >> list.Naimenovanie;
			cout << "Vvedite kol-vo: \n"; cin >> list.Kol_vo;
			cout << "Vvedite stoimost': "; cin >> list.Cost;
			fwrite(&list, sizeof(tovar), 1, fl);
			cout << "bydete vvodit' ewe ? (y/n)"; cin >> t;
		}
	}
	if (t == '2')
	{
		srand(time(NULL));
		int kol_vo;
		cout << "vvedite kol-vo tovarov: "; cin >> kol_vo;
		for (int i = 0; i < kol_vo; i++)
		{
			tovar list;
			strcat(list.Naimenovanie, array[rand() % 6]);
			list.Kol_vo =1+ rand() % 100;
			list.Cost =1+ rand() % 200;
			fwrite(&list,sizeof(tovar),1,fl);
		}

	}
	else
	{
		cout << "viberite pravil'no!!\n";
		fclose(fl);
		ZapisToFile(file_name,array);
		
	}
	fclose(fl);
}
void ReadData(char * file_name)
{
	FILE *fl;
	int n,i;
	if ((fl = fopen(file_name, "rb")) == NULL)
	{
		Errors(1);
		return;
	}
	n = filelength(fileno(fl))/ sizeof(tovar);
	tovar spisok;
	for (i = 0; i < n; i++)
	{
		
		
		if (fread(&spisok, sizeof(tovar), 1, fl) != 1)
		{
			Errors(2);
			return;
		}
		cout << i + 1 << " tovar:\n";
		cout << spisok.Naimenovanie<<endl;
		cout << spisok.Kol_vo<<endl;
		cout << spisok.Cost<<endl;
		cout << "----------\n";
	}
	getch();
	fclose(fl);
}
void Result(char *file_name,bool status)
{
	FILE *fl;
	if ((fl = fopen(file_name, "rb")) == NULL)
	{
		Errors(1);
		return;
	}
	int n = (filelength(fileno(fl)) / sizeof(tovar));
	char file[20] = "";
	FILE *fl2;
	if (status)
	{
		cout << "Vvedite nazvanie faila:\n ";
		cin >> file;
		if ((fl2 = fopen(file, "wb")) == NULL)
		{
			Errors(1);
			return;
		}
	}
	tovar spisok;
	for (int i = 0; i < n; i++)
	{
		if (fread(&spisok, sizeof(tovar), 1, fl) != 1)
		{
			Errors(2);
			return;
		}
		if (spisok.Cost > 10 && spisok.Cost < 100)
			if (status) fprintf(fl2,"%s %d",&spisok.Naimenovanie,spisok.Cost);
			else
			cout << spisok.Naimenovanie<<" "<<spisok.Cost  << endl;
	}
	getch();
	fclose(fl);
	if (status) fclose(fl2);
}
void Errors(int owibka)
{

	if (owibka == 1)
	{
		cout << "Owibka pri otkritii faila dlya chteniya\nVozmojno vi ego ne sozdali(pynkt1.)\n";
	}
	if (owibka == 2)
	{
		cout << "Owibka pri chtenii dannix iz faila\n";
	}
	if (owibka == 3)
	{
		cout << "VVedite pravil'no!!\n" << endl;
	}
	if (owibka == 4)
	{
		cout << "owibka pri sozdanii faila!!" << endl;
	}
	cout << "Press any key to continue!";
	getch();
	

}
void sort(char *file_name, bool status)
{
	FILE *fl;
	int fl_length;
	if ((fl = fopen(file_name, "rb")) == NULL)
	{
		Errors(4);
		return;
	}
	fl_length = filelength(fileno(fl)) / sizeof(tovar);
	tovar *spisok = new tovar[fl_length];
	fread(spisok, sizeof(tovar), fl_length, fl);
	fclose(fl);
	switch (status)
	{
	case false:
	{
		sort_qsort_nerekyrsivno(spisok, fl_length); break;
		
	}
	case true:sort_viborom(spisok,fl_length); break;
	}
	
	for (int i = 0; i < fl_length; i++)
	{
		cout << i + 1 << " tovar:\n" << spisok[i].Naimenovanie << " " << spisok[i].Cost << "\n";
	}
	getch();
	delete[] spisok;
}
void sort_viborom(tovar *spisok, int fl_length)
{
	int imin, i, j;
	tovar t;
	for (i = 0; i < fl_length - 1; i++)
	{
		imin = i;
		for (j = i + 1; j < fl_length; j++)
			if (strcmp(spisok[imin].Naimenovanie , spisok[j].Naimenovanie)==1) imin = j;
		if (imin != i)
		{
			t = spisok[imin];
			spisok[imin] = spisok[i];
			spisok[i] = t;
		}
	}
}
void sort_qsort_nerekyrsivno(tovar *spisok, int fl_length)
{
	struct sort
	{
		int niz, verx;
	}*stack;
	stack = new sort[fl_length];
	tovar t;
	int i, j, x, s = 0, left, right;
	stack[s].niz = 0; stack[s].verx = fl_length - 1;
	while (s != -1)
	{
		left = stack[s].niz;
		right = stack[s].verx;
		s--;
		while (left < right)
		{
			i = left;
			j = right;
			x = spisok[(left + right) / 2].Cost;
			while (i <= j)
			{
				while (spisok[i].Cost < x) i++;
				while (spisok[j].Cost > x) j--;
				if (i <= j)
				{
					t = spisok[i];
					spisok[i] = spisok[j];
					spisok[j] = t;
					i++;
					j--;
				}
			}
			if (j - left < right - i)
			{
				if (i < right)
				{
					s++;
					stack[s].niz = i;
					stack[s].verx = right;
				}
				right = j;

			}
			else
			{
				if (j > left)
				{
					s++;
					stack[s].niz = left;
					stack[s].verx = j;
				}
				left = i;
			}
		}
	}
}
void search(char *file_name)
{
	FILE *fl;
	int fl_length;
	if ((fl = fopen(file_name, "rb")) == NULL)
	{
		Errors(4);
		return;
	}
	fl_length = filelength(fileno(fl)) / sizeof(tovar);
	tovar *spisok = new tovar[fl_length];
	fread(spisok, sizeof(tovar), fl_length, fl);
	fclose(fl);
	cout << "1)Lineyniy poisk\n2)Dvoichniy poisk\n";
	int i,key,result;
	cin >> i;
	cout << "key: ";
	cin >> key;
	switch (i)
	{
	case 1:result=search_lineiniy(spisok,fl_length,key); break;
	case 2:result=search_binarniy(spisok, fl_length, key); break;
	default:delete[] spisok; return;
	}
	if (result == -1) cout << "dannogo elementa net\n";
	else cout <<spisok[result].Naimenovanie << endl;
	getch();
	delete[] spisok;
}
int search_lineiniy(tovar *spisok, int fl_length, int key)
{
	int i = 0;
	spisok[fl_length].Cost = key;
	while (spisok[i].Cost != key) i++;
	if (i != fl_length) return i;
	else return -1;
}
int search_binarniy(tovar *spisok, int fl_length, int key)
{
	sort_qsort_nerekyrsivno(spisok, fl_length);
	int left = 0,  r = fl_length-1,x;
	while (left < r)
	{
		x = (left + r) / 2;
		if (key > spisok[x].Cost) left = x+1;
		else r = x ;
	}
	if (spisok[r].Cost == key) return r; 
	else return -1;
}
