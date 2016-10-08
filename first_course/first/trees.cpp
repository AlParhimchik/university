#include <iostream>
using namespace std;
void q_sort(int **,int,int);

struct tree
{
	int inf;
	tree *right;
	tree *left;
};
void obxod_straight(tree *);
void obxod_obratn(tree *);
void obxod_simm(tree *);
void obxod(tree *,int &);
void poisk(tree *,int,int&);
tree * AddElements(tree *,int*,int,int);

int main()
{
	tree *tr = NULL;
	int n,i,inf,sum=0;
	
	cout << "vvedite kol-vo elementov"; cin >> n;
	int *mas = new int[n];
	for (i = 0; i < n; i++)
		cin >> mas[i];
	q_sort(&mas,0,n-1);
	for (i = 0; i < n; i++)
		cout << mas[i] << " ";
	cout << endl;
	cout << "-------" << endl;
	tr = AddElements(tr,mas,0,n-1);
	obxod_straight(tr);
	cout << endl<<"-----------" << endl;
	obxod_obratn(tr);
	cout <<endl<< "-----------" << endl;
	obxod_simm(tr);
	cout << endl;
	obxod(tr,sum);
	poisk(tr,sum/(n-1),inf);
	system("pause");
	return 0;

}
void q_sort(int **ma, int left, int right)
{
	int *mas = *ma;
	int l = left, r = right, x, m;
	m = mas[(l + r) / 2];
	do
	{
		while (mas[l] < m && l<right) l++;
		while (mas[r] > m && r>left) r--;
		if (l<=r)
		{
			x = mas[l];
			mas[l] = mas[r];
			mas[r] = x;
			l++;
			r--;
		}
	} while (l<=r);
	if (left<r) q_sort(&mas,left,r);
	if (right>l) q_sort(&mas,l,right);
}
tree *AddElements(tree *tr, int *mas, int l, int r)
{
	if (l > r) return NULL;
	int x = (l + r) / 2;
	tree *n = new tree, *sr=tr, *sp = tr;
	n->inf = mas[x];
	n->left=AddElements(tr, mas, l, x - 1);
	n->right=AddElements(tr, mas, x+1,r);
	return n;
}
void obxod_straight(tree *tr)
{
	if (tr == NULL) return;
	cout << tr->inf << " ";
	obxod_straight(tr->left);
	obxod_straight(tr->right);
}
void obxod_obratn(tree *tr)
{
	if (tr == NULL) return;
	obxod_obratn(tr->left);
	obxod_obratn(tr->right);
	cout << tr->inf << " ";
}
void obxod_simm(tree *tr)
{
	if (tr == NULL) return;
	obxod_simm(tr->left);
	cout << tr->inf << " ";
	obxod_simm(tr->right);
}
void obxod(tree *tr,int &sum)
{
	if (tr == NULL) return;
	sum += tr->inf;
	obxod(tr->left,sum);
	obxod(tr->right,sum);
}
void poisk(tree *tr, int sum, int &inf)
{
	if (tr == NULL) return;
	if (abs(tr->inf - sum)) inf = tr->inf;
	poisk(tr->left,sum,inf);
	poisk(tr->right,sum,inf);
}
