#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

void lcs(char *x, char *y, int m, int n)
{
	int c[m + 1][n + 1];
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0 || j == 0)
				c[i][j] = 0;
			else if(x[i - 1] == y[j - 1])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}
	}
	int index = c[m][n];
	char lcs[index + 1];
	lcs[index] = '\0';

	int i = m, j = n;
	while(i > 0 && j > 0)
	{
		if(x[i - 1] == y[j - 1])
		{
			lcs[index - 1] = x[i - 1];
			index--;
			i--;
			j--;
		}
		else if(c[i - 1][j] > c[i][j - 1])
			i--;
		else
			j--;
	}

	cout<< endl;
	cout<< lcs<< endl;
	cout<< c[m][n]<< endl;
}

int main()
{
	char x[20], y[20];
	cin.getline(x, 20);
	cin.getline(y, 20);
	int m = strlen(x);
	int n = strlen(y);

	lcs(x, y, m, n);

	return 0;
}