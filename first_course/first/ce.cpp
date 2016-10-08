#include <iostream> 
#include <conio.h> 
using namespace std;
struct spis
{
	int inf;
	spis * next, *prev;
};

void push_tail(int, spis*&, spis *&);
void print_tail(spis*, spis *);
void delete_spis(spis *, spis *);
void poisk(spis *, spis *, spis*&, spis*&);
void del(spis*&, spis*&);

int main()
{
	spis *head = NULL, *tail = NULL, *head1 = NULL, *tail1 = NULL;
	int inf, n;
	cout << "Vvedite kolichestvo elementov: ";
	cin >> n;
	while (n != 0)
	{
		cin >> inf;
		push_tail(inf, head, tail);
		n--;
	}
	print_tail(head, tail);
	poisk(head,tail,head1,tail1);
	del(head1, tail1);
	print_tail(head1, tail1);
	delete_spis(head, tail);
	getch();
	return 0;
}

void push_tail(int inf, spis* &head, spis *&tail)
{
	spis* el = new spis;
	el->inf = inf;
	if (tail == NULL)
	{
		tail = el;
		head = el;
		el->next = NULL;
		el->prev = NULL;
	}
	else
	{
		el->next = NULL;
		tail->next = el;
		el->prev = tail;
		tail = el;
	}
}

void print_tail(spis* head, spis *tail)
{
	if (tail == NULL)
		cout << "Pusto" << endl;
	else
	{
		cout << "Spisok: " << endl;
		for (spis *t = head; t != 0; t = t->next)	cout << t->inf << endl;
	}
}

void delete_spis(spis *head, spis *tail)
{
	spis *t;
	while (head != NULL)
	{
		t = head;
		head = head->next;
		delete t;
	}
}

void poisk(spis *head, spis *tail, spis*& head1, spis*& tail1)
{
	spis *t = head, *l = head;
	for (t = head; t != tail; t = t->next)
	{
		int inf = t->inf;
		for (l = t->next; l != NULL; l = l->next)
		{
			if (inf == l->inf) push_tail(inf, head1, tail1);
		}
	}
}

void del(spis*&head1, spis*&tail1)
{
	
	spis *t = head1, *l = head1;
	for (t = head1; t != NULL; t = t->next)
	{
		l = t->next;
		while (l != NULL)
		{
			if (t->inf == l->inf)
			{
				spis *v = NULL;
				if (l == tail1)
				{
					v = tail1;
					tail1 = tail1->prev;
					tail1->next = NULL;
					delete v;
					l = NULL;
				}
				else
				{
					v = l;
					l = l->next;
					v->next->prev = v->prev;
					v->prev->next = v->next;
					delete v;
				}
			}
			else
				l = l->next;
		}
	}
}
