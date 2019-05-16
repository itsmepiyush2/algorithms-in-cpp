#include<iostream>
using namespace std;

int partition(int a[], int l, int r)
{
	int pivot = a[r];
	int i = l - 1;
	for(int j = l; j < r; j++)
	{
		if(a[j] < pivot)
		{
			i++;
			swap(a[j], a[i]);
		}
	}
	swap(a[i + 1], a[r]);
	return (i + 1);
}

void quicksort(int a[], int l, int r)
{
	if(l < r)
	{
		int pivot = partition(a, l, r);
		quicksort(a, l, pivot - 1);
		quicksort(a, pivot + 1, r);
	}
}

int main()
{
	int n;
	cin>> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin>> a[i];

	quicksort(a, 0, n - 1);

	for(int i = 0; i < n; i++)
		cout<< a[i]<< " ";
	cout<< endl;

	return 0;
}