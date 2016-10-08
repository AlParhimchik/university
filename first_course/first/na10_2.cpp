/*#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
	ifstream f1("input.txt");
	ofstream f2("output.txt");
	int  **a,nacx[5] = { 0,1,0,-1 }, nacy[5] = { 1,0,-1,0 }, i, x = 1, y = 0 , k = 0,n;
	 f1 >> n;
	a = new int *[n+2];
	unsigned int start_time = clock();
	for (i = 0; i < n + 2; i++)
	{
		a[i] = new int[n + 2];
		for (int j = 0; j < n + 2; j++)
		{
			if (i == 0 || i == n + 1 || j == 0 || j == n + 1) a[i][j] = 1;  else a[i][j] = 0;
		}
	}
	for (i = n*n; i > 0; i--)
	{
		x += nacx[k];
		y += nacy[k];
		a[x][y] = i;
		if (a[x + nacx[k]][y + nacy[k]] != 0)
		{
			if (k == 3) k = 0; 
			else k++;
		}
		
	}
	for (i = 1; i < n+1; i++)
	
		for (int j = 1; j < n + 1; j++)
		{//	f2 << setw(5) <<a[i][j] << " ";
		//f2 << endl;
		}
	for (i = 0; i < n + 2; i++)
		delete[]a[i];
	delete[] a;

	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time;
	f2 << search_time;// искомое время
	return 0;
}*/