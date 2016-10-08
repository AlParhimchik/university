#include <fstream>
#include <math.h>
using namespace std;
int main()
{
	ifstream f1("input.txt");
	ofstream f2("output.txt");
	int st[78][78], i, j, nacx[10000], nacy[10000], x, y, n, m;
	int x1, y1, x2, y2, nac=0, con;
	char a[78][78];
	const int nx[5] = { 0,1,0,-1 }, ny[5] = { 1,0,-1,0 };
	f1 >> m >> n;
	for (i = 0; i <= n+1; i++)
		for (j = 0; j <= m+1; j++)
		{
			if (i == 0 || j == 0 || j == m + 1 || i == n + 1)
				a[i][j] = 'X'; 
			else
			f1 >> a[i][j];
			st[i][j] = 1000;
		}
	/*for (i = 0; i <= n + 1; i++)
	{
		for (j = 0; j <= m + 1; j++)
			f2 << a[i][j];
		f2 << endl;
	}
	*/
	f1 >> y1 >>x1 >> y2 >> x2;
	while (x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0)
	{
		for (i = 0; i <= n + 1; i++)
			for (j = 0; j <= m + 1; j++)
			{
				st[i][j] = 1000;
			}

		nacx[nac] = x1;
		nacy[nac] = y1;
		st[x1][y1] = 0;
		nac = 0;
		con = 1;
		while (nac != con)
		{
			x = nacx[nac];
			y = nacy[nac];
			for (i = 0; i < 4; i++)
			{
				while(1)
				{ 
				if (x+nx[i]>=0&& x+nx[i]<=n+1 &&y+ny[i]<=m+1&&y+ny[i]>=0 )
					if (st[x + nx[i]][y + ny[i]]>st[x][y] + 1)
						if (a[x+nx[i]][y+ny[i]]!='.'|| (x+nx[i]==x2 && y+ny[i]==y2))
					{
						
						nacx[con] = x+nx[i] ;
						nacy[con] = y+ny[i] ;
						st[x+nx[i]][y+ny[i]] = st[x][y] + 1;
						con++;
					}	
			}
			nac++;
		}
		if (st[x2][y2] == 1000) f2 << "0"; 
		else f2 << st[x2][y2];
		f2 << endl;
		f1 >> y1 >> x1 >> y2 >> x2;
	}
	
	return 0;
}