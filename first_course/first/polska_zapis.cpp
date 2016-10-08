#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
struct spisok
{
	float inf;
	spisok *left;
	spisok *right;
};
struct stack
{
	char inf;
	stack *pred;
};
int menu();
void Error(int);
void AddElement(stack **,char);
void AddElement(spisok **, spisok **, float);
bool Proverka(string str);
void DeleteElement(stack **);
void DeleteElement(stack **,stack **);
void AddElements(string &);
void DeleteSimvol(spisok **,spisok **);
void Vichislit(string str);
///////////////
int main()
{
	string str;
	while (true)
	{
		switch (menu())
		{
		case 1:AddElements(str);break;
		case 2:Vichislit(str);; break;
		case 3:return 0; break;
		default:
			Error(0);
		}
		system("cls");
	}
}
///////////////
void Vichislit(string str)
{
	system("cls");
	cout << "-----------" << endl;
	cout << str << endl;
	cout << "--------------" << endl;
	bool o=Proverka(str);
	if (o == false) return;
	stack *vverx_skobki = NULL, *vrmn = NULL;
	spisok *niz_simvoli = NULL, *vverx_simvoli = NULL;
	float mas[33];
	int i;
	for (i = 0; i < 33; i++)
		mas[i] = 0;
	for (i = 0; i < str.length(); i++)
	{
		if (str.at(i) >= 'a' && str.at(i) <= 'z')
		{
			if (mas[int(str.at(i))-97] == 0)
			{
				cout << "vvedite " << str.at(i) << ":";
				cin >> mas[int(str.at(i))-97];
			}
			AddElement(&niz_simvoli,&vverx_simvoli, mas[int(str.at(i)) - 97]);
			if (vverx_skobki!=NULL)
				if (vverx_skobki->inf == '*' )
				{
					vverx_simvoli->left->inf *= vverx_simvoli->inf;
					DeleteSimvol(&niz_simvoli, &vverx_simvoli);
					DeleteElement(&vverx_skobki);
				}
				else
					if (vverx_skobki->inf == '/')
					{
						vverx_simvoli->left->inf /= vverx_simvoli->inf;
						DeleteSimvol(&niz_simvoli, &vverx_simvoli);
						DeleteElement(&vverx_skobki);
					}
		}
		if (str.at(i) == '+' || str.at(i) == '-' || str.at(i) == '*' || str.at(i) == '/' || str.at(i)=='(')
			AddElement(&vverx_skobki,str.at(i));
	if (str.at(i) == ')')
		{
			while (vverx_skobki->inf != '(')
			{
				if (vverx_skobki->inf == '+')
				{
					vverx_simvoli->left->inf += vverx_simvoli->inf;
					DeleteSimvol(&niz_simvoli,&vverx_simvoli);
				}
				if (vverx_skobki->inf == '*')
				{
					vverx_simvoli->left->inf *= vverx_simvoli->inf;
					DeleteSimvol(&niz_simvoli, &vverx_simvoli);
				}
				if (vverx_skobki->inf == '/')
				{
					vverx_simvoli->left->inf /= vverx_simvoli->inf;
					DeleteSimvol(&niz_simvoli, &vverx_simvoli);
				}
				if (vverx_skobki->inf == '-')
				{
					vverx_simvoli->left->inf -= vverx_simvoli->inf;
					DeleteSimvol(&niz_simvoli, &vverx_simvoli);
				}
				DeleteElement(&vverx_skobki);
			}
			DeleteElement(&vverx_skobki);
			if (vverx_skobki != NULL)
				if (vverx_skobki->inf == '*' || vverx_skobki->inf == '/')
				{
					if (vverx_skobki->inf == '*') vverx_simvoli->left->inf *= vverx_simvoli->inf;
					if (vverx_skobki->inf == '/') vverx_simvoli->left->inf /= vverx_simvoli->inf;
					DeleteSimvol(&niz_simvoli, &vverx_simvoli);
					DeleteElement(&vverx_skobki);
				}
	
		}
	}
	while (vverx_skobki != NULL)
	{
		if (vverx_skobki->inf == '+')
		{
			vverx_simvoli->left->inf += vverx_simvoli->inf;
			DeleteSimvol(&niz_simvoli, &vverx_simvoli);
		}
		if (vverx_skobki->inf == '*')
		{
			vverx_simvoli->left->inf *= vverx_simvoli->inf;
			DeleteSimvol(&niz_simvoli, &vverx_simvoli);
		}
		if (vverx_skobki->inf == '/')
		{
			vverx_simvoli->left->inf /= vverx_simvoli->inf;
			DeleteSimvol(&niz_simvoli, &vverx_simvoli);
		}
		if (vverx_skobki->inf == '-')
		{
			vverx_simvoli->left->inf -= vverx_simvoli->inf;
			DeleteSimvol(&niz_simvoli, &vverx_simvoli);
		}
		DeleteElement(&vverx_skobki);
	}
		
	DeleteElement(&vverx_skobki);
	cout << "-------------" << endl << str<<"=";
	cout<<vverx_simvoli->inf<<endl;
	getch();

}

void DeleteSimvol(spisok **niz,spisok **vverx)
{
	if (*vverx == NULL) return;
	spisok *b;
	b = *vverx;
	*vverx = (*vverx)->left;
	if (b->left != NULL) (*vverx)->right = NULL;
	delete b;
}
 void AddElements(string &str)
{
	system("cls");
	cout << "Vvedite stroky" << endl;
	cin >> str;
}
void DeleteElement(stack **vverx)
{
	if (*vverx == NULL) return;
	stack *b = (*vverx);
	*vverx = b->pred;
	delete b;
	

}
bool Proverka(string str)
{
	int i;
	stack *stk = NULL;
	stack *stk1 = NULL;
	for (i = 0; i < str.length(); i++)
	{
		if (str.at(i) == '(')
		{
			/*if (stk1 == NULL) AddElement(&stk, '(');
			else
			{
				Error(1);
				return 0;
			}*/
			AddElement(&stk, '(');
		}
		else
		if (str.at(i) == ')')
		{
			if (stk == NULL || stk->inf == ')' || stk1 == NULL)
			{
				Error(1);
				return 0;
			}
			else DeleteElement(&stk);
		}
		else
		if (str.at(i) >= 'a' && str.at(i) <= 'z')
		{
			if (stk1 == NULL)
			{
				AddElement(&stk1, str.at(i));
				if (stk != NULL)
				{
					if (stk->inf != '(') DeleteElement(&stk);
					else
					{
						if (stk->pred != NULL)

						{
							stk->pred->inf = '(';
							DeleteElement(&stk);
						}
						/*else
						{
							Error(1);
							return 0;
						}*/
					}
				}
			}
			else
			{
				Error(1);
				return 0;
			}
		}
		else
		if (str.at(i) == '+' || str.at(i) == '-' || str.at(i) == '*' || str.at(i) == '/')
		{
			if (stk1 == NULL)
			{
				Error(1);
				return 0;
			}
			else
			{
				DeleteElement(&stk1);
				AddElement(&stk,str.at(i));
			}
		}
		else
		{
			Error(1);
			return 0;
		}
	}
	if (stk1 != NULL) DeleteElement(&stk);
 	if (stk != NULL)
	{
		Error(1);
		return 0;
	}
	cout << "Dannie vvedeni pravil'no" << endl;
	cout << "-------------" << endl;
	return true;
}
void AddElement(stack **vverx, char inf)
{
	stack *b = new stack;
	b->inf = inf;
	b->pred = *vverx;
	*vverx = b;
}
void AddElement(spisok **niz,spisok **vverx, float inf)
{
	spisok *b = new spisok;
	b->inf = inf;
	b->right = NULL;
	b->left = *vverx;
	if (*vverx != NULL) (*vverx)->right = b;
	if (niz == vverx)
		*niz = b;
	*vverx = b;
}
int menu()
{
	cout << "1:Vvesri virajenie:"<<endl;
	cout << "2:Vichislit'" << endl;
	cout << "3:viyti" << endl;
	char b;
	cin >> b;

	return (int(b) - 48);
}
void Error(int err)
{
	if (err == 1)
		cout << "Owibka pri proverke!" << endl;
	if (err == 0)
		cout << "Viberite pravil'no " << endl;

	getch();
}
