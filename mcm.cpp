#include<iostream>
using namespace std;

int mcm(int r[], int i, int j)
{
	int min = 1e7, m;
	if(i == j)
		return 0;
	for(int k = i; k < j; k++)
	{
		m = mcm(r, i, k) + mcm(r, k+1, j) + r[i - 1]*r[k]*r[j];
		if(m < min)
			min = m;
	}
	return min;
}

int main()
{
	int n;
	cin>> n;
	int r[n];
	for(int i = 0; i < n; i++)
		cin>> r[i];

	cout<< mcm(r, 1, n - 1)<< endl;

	return 0;
}