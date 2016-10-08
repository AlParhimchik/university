#include <iostream>
struct stk
{
	int k;
	stk *a;
};

stk* addelement(stk*);
stk* IfElementNull(stk*,int &);
using namespace std;


int main()
{
	int i, n;
	stk *new_stk = new stk;
	new_stk->a = NULL;
	cout << "vvedite n!"; cin >> n;
	for (i = 0; i < n; i++)
	{
		new_stk=addelement(new_stk);

	}
	int inc = 0,k;
	do
	{
		new_stk = IfElementNull(new_stk, k);
		if (k < 0) inc++;
	} while (new_stk->a != NULL);
	cout << inc << endl;
	system("pause");
	return 0;
}
stk* addelement(stk *new_stk)
{
	int k;
	stk *b=new stk;
	cout << "vvedite element"; cin >> k;
	b->a = new_stk;
	b->k = k;
	return b;

}
stk* IfElementNull(stk*new_stk,int &k)
{
	stk *b;
	
	k = new_stk->k;
	b = new_stk->a;
	delete new_stk;
	return b;
}