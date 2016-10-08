#include <iostream> 

using namespace std;

struct spis
{
	int inf;
	spis * next, *prev;
};

void push_tail(int, spis*&, spis *&);
void print_tail(spis*, spis *);
void delete_spis(spis *, spis *);
void poisk(spis *, spis *, spis*, spis*);

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
	delete_spis(head, tail);
	poisk(head, tail, head1, tail1);
	print_tail(head1, tail1);
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

void poisk(spis *head, spis *tail, spis* head1, spis* tail1)
{
	spis *t, *l;
	for (t = head; t != tail; t = t->next)
	{
		int inf = t->inf;
		for (l = t->next; l != NULL; l = l->next)
		{
			if (inf == l->inf)
			{
				push_tail(inf, head1, tail1);
				l = l->next;
			}
			else l = l->next;
		}
	}
}
