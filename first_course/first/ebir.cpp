#include <iostream>
#include <string>
using namespace std;
template <class T1> 
void lolka(T1);
class xerchik
{
public:
	int t;
	xerchik()
	{
		t = 20;
	}
};
class xuichik :public xerchik
{
public:
	int nigga;
	xuichik():nigga(10)
	{
		t = 10;
	}
};
int main()
{
	xerchik Xer;
	xuichik Xui;
	//template <xerchik>
	lolka<xerchik>(Xer);
	lolka<xuichik>(Xui);
	system("pause");
}
template <class T1>
void lolka(T1 xui)
{
	cout << xui.t << endl;
}