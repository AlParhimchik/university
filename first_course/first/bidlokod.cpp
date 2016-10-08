#include <fstream>
#include <ctime>
using namespace std;
int main()
{
	ifstream f1("input.txt");
	ofstream f2("output.txt");
	f2 << "Vvedite razmer massiva" << endl;
	int n, k, t, j, n1, i;
	f1 >> n;
	t = n*n;
	int **c;
	c = new int*[n];
	unsigned int start_time = clock();
	for (i = 0; i<n; i++) c[i] = new int[n];

	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			c[i][j] = 0;
		}
	}
	if (n % 2 == 1) k = n / 2 + 1; else k = n / 2;
	n1 = n;


	for (i = 0; i<k; i++)
	{
		j = i;
		while (j<n1)
		{
			c[i][j] = t;
			t--;
			j++;
		}
		j = i + 1;
		while (j<n1)
		{
			c[j][n1 - 1] = t;
			t--;
			j++;
		}
		j = n1 - 2;
		while (j >= i)
		{
			c[n1 - 1][j] = t;
			t--;
			j--;
		}
		j = n1 - 2;
		while (j>i)
		{
			c[j][i] = t;
			t--;
			j--;
		}
		n1--;

	}


	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
		//	f2 << c[i][j] << " ";
		}
		//f2 << endl;
	}
	for (i = 0; i<n; i++) delete[]c[i];
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time;
	f2 << search_time;// искомое время
	delete[]c;
	return 0;
}