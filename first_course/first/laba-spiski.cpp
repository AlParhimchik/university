#include <iostream>
using namespace std;
struct spisok
{
	char b;
	spisok *l;
	spisok *r;
};
void AddElement(spisok **, spisok **,char);
void ScreenResult(spisok *vverx);
void DeleteElement(spisok **);
void DeleteSpisok(spisok *);
int main()
{
	spisok *niz = NULL, *vverx = NULL;
	char b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		AddElement(&niz, &vverx, b);
	}
	cout << "-------" << endl;
	cout << "Isxodniy spisok:" << endl;
	ScreenResult(vverx);
	spisok *current = vverx, *vverx_new = NULL , *niz_new = NULL;
	for (int i = 0; i <n ; i++)
	{
		if (int(current->b )<48 || int(current->b) > 57)
		{
			AddElement(&niz_new,&vverx_new,current->b);
			if (current == vverx)
			{
				vverx = vverx->l;
			}
			DeleteElement(&current);
		}
		else current = current->l;
	}
	//////выводим два разделённых списка//////
	cout << "-------" << endl;
	if (vverx == NULL) cout << "V spiske nety elementov" << endl;
	ScreenResult(vverx);
	cout << "-----------" << endl;
	if (vverx_new == NULL) cout << "v spiske nety elementov" << endl;
	ScreenResult(vverx_new);
	/////освобождаем память//////
	DeleteSpisok(vverx);
	DeleteSpisok(vverx_new);
	cout << "---------------" << endl;
	system("pause");
	return 0;
}
void DeleteSpisok(spisok *vverx)
{
	spisok *k;
	while (vverx != NULL)
	{
		k = vverx;
		vverx = vverx->l;
		delete k;
	}
}
void DeleteElement(spisok **current)
{
	spisok *k = (*current);
	(*current) = k->l;
	if (k->r!=NULL) k->r->l = *current;
	if (*current != NULL) (*current)->r = k->r;
	*current = k->l;
	delete k;
}
void ScreenResult(spisok *vverx)
{
	spisok *k = vverx;
	while (k != NULL)
	{
		cout << k->b << endl;
		k = k->l;
	}
}
void AddElement(spisok **niz, spisok **vverx, char b)
{
	spisok *k = new spisok;
	if (*niz == NULL) *niz = k;
	k->b = b;
	k->l = *vverx;
	k->r = NULL;
	if (*vverx!=NULL) (*vverx)->r = k;
	*vverx = k;

}