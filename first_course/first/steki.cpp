#include <iostream>
using namespace std;
struct stack
{
	int inf;
	stack *adr;
};
void AddStack(stack *, int);
void DeleteOtr(stack *);
void ScreenResult(stack *);
int main()
{
	int i, n,k;
	stack *pop,*pop1;
	pop = new stack;
	pop->adr = NULL;
	cout << "Vvedite n: "; cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Vvedite chislo: "; cin >> k;
		AddStack(pop,k);
	}
	pop1 = pop;
	DeleteOtr(pop);
	ScreenResult(pop1);
	system("pause");
	return 0;
}
void AddStack(stack *pop, int k)
{
	stack *b = new stack;
	b->adr = pop;
	b->inf = k;
	pop= b;

}
void DeleteOtr(stack *pop)
{
	stack *b = pop->adr;
	if (b == NULL) return;
	if (b->inf < 0)
	{
		pop->adr = b->adr;
		delete b;
	}
	else pop = pop->adr;
	DeleteOtr(pop);

}
void ScreenResult(stack *pop)
{
	while (pop->adr != NULL)
	{
		stack *b = pop;
		cout << b->adr->inf<<endl;
		pop = b->adr;
		delete b;
	}
}