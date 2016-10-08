#include <iostream>
class prob
{
public:
	int k;
	prob()
	{
		k = 0;
	}
};
template <typename T> 
class st
{
public:
	int d = 1;
	prob pr;
	st(T pr1)
	{
		pr = pr1;
		d = pr1.k;
	}
	st()
	{
		d = 3;
	}
};
class tank
{
public:
	int x, y, t;
	tank()
	{
		x = 10;
	}
};
class enemy
{
public:
	int x, y, t, z;
	enemy()
	{
		y = 30;
	}
};
template <class T,class T1>
void chk(T,T1);
using namespace std;
int main()
{
	prob warr;
	warr.k = 10;
	st<prob> stdd(warr);
	st<int> std;
	cout << stdd.d << endl;
	tank Tank;
	enemy Enemy;
	chk<tank, enemy>(Tank,Enemy);
	system("pause");
 	return 0;
}
template <class T, class T1>
void chk(T tank1, T1 tank2)
{
	cout << tank1.x << " " << tank2.y << endl;
}

