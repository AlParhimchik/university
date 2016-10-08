#include <iostream>
#include <math.h>
#include <conio.h>
struct stud
{
	int nomer;
	int god;
	char fio[10];
};

void vvod(int, stud*);
void sozd(stud *, int, int, stud*);
stud *poisk(stud*, stud*, int, int);
using namespace std;
int main()
{
	int n = 2, i, M = 20;
	stud *student = new stud[n];
	stud* el=NULL;
	vvod(n, student);
	stud *H = new stud[M];
	for (i = 0; i<M; i++) H[i].god = -1;
	sozd(student, M, n, H);

	el = poisk(student, H, M, n);
	if (el == NULL) cout << "ne naydeno" << endl;
	else
		cout << el->god << endl;
	getch();

	delete[]student;
	delete[]H;
	return 0;
}

void vvod(int n, stud* student)
{
	int i = 0;
	for (i = 0; i<n; i++)
	{
		cout << "Vvedite fio: ";
		cin >> student[i].fio;
		flush(cout);
		cout << "Vvedite nomer: ";
		cin >> student[i].nomer;
		flush(cout);
		cout << "Vvedite god: ";
		cin >> student[i].god;
		flush(cout);
	}
	cout << endl;
}

void sozd(stud * student, int M, int n, stud *H)
{
	for (int i = 0; i<n; i++)
	{
		int k = student[i].god%M;
		if (H[k].god != -1)
		{
			int c = 1 + (student[i].god % (M - 2));
			while (H[k].god != -1)
			{
				k -= c;
				if (k<0) k = (k + M) % M;
				//if (k>M) break;
			}
		}
		H[k] = student[i];
	}
}

stud *poisk(stud* student, stud* H, int M, int n)
{
	int l;
	cout << "Vvedite god: ";
	cin >> l;
	int k = l%M;
		int c = 1 + (l % (M - 2));
		while (H[k].god != l)
		{
			if (H[k].god== -1) return 0;
			k -= c;
			if (k < 0) k = (k + M) % M;
			//if (k>M) break;
		}
		return (&H[k]);
//	}

}