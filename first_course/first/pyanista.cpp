#include <iostream>
#include <ctime>
using namespace std;
class stek
{
private:
	int zvanie;
	stek *inf;

public:
	stek()
	{
		zvanie = 6+rand() % 9;
		inf = NULL;
	}
	void AddOldElement(stek *);
	void AddElement();
	void Randomize();
	 bool Ñompare(stek*);
	 static int Chek(stek *,stek *);
};

int main()
{
	int t = 0;
	//srand(time(0));
	stek *player1 = new stek;
	stek *player2 = new stek;
	player1->Randomize();
	player2->Randomize();
	while (t<10000)
	{
		switch (player1->Ñompare(player2))
		{
		case true: player1->AddOldElement(player2); break;
		case false:player2->AddOldElement(player1); break;
		}
		switch (stek::Chek(player1,player2))
		{
		case 1:cout << "Win player 1"; break;
		case 2:cout << "Win player 2"; break;
		case 3:break;
		default:
			exit;
			
		}
		t++;
		cout << t << endl;
	}

	system("pause");
	return 0;
}
/*stek* stek::ReturnEnd(stek* a)
{

}*/
void stek::Randomize()
{
	for (int i = 0; i < 3; i++)
	{
		AddElement();
		zvanie = rand() % 9 + 6;
	}
}
void stek::AddElement()
{
	stek *a = new stek;
	a->inf = inf;
	a->zvanie = zvanie;
	inf = a;
}
bool stek::Ñompare(stek*a)
{
	if (zvanie > a->zvanie) return true;
	return false;
}
void stek::AddOldElement(stek *b)
{
	int k;
	stek *a = new stek,*c;
	a = this;
	while (a->inf!=NULL)
	{
		if (a->inf->inf == NULL)
		{
			c=a->inf;
			a->inf = NULL;
		}else
		a = a->inf;
	}
	k = c->zvanie;
	c->zvanie = zvanie;
	c->inf = inf;
	zvanie = k;
	inf = c;
	stek *ka = new stek;
	ka->zvanie = zvanie;
	ka->inf = inf;
	zvanie = ka->zvanie;
	inf = ka;
	while (b->inf!=NULL)
	{
		if (b->inf->inf == NULL)
		{
			c = b;
			b->inf = NULL;
		}
		else
		b =b->inf;
	}
	delete c;

}
int stek::Chek(stek *player1,stek *player2)
{
	if (player1->inf == NULL) return 2; else
		if (player2->inf == NULL) return 1; else
			return 3;
}
