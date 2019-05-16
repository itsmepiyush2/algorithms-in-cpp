#include<iostream>
using namespace std;
class Student
{
public:
	string name;
	int roll;
};

int partition(Student *s, int l, int r)
{
	int pivot = s[r].roll;
	int i = l - 1;
	for(int j = l; j < r; j++)
	{
		if(s[j].roll < pivot)
		{
			i++;
			swap(s[j], s[i]);

		}
	}
	swap(s[i + 1], s[r]);
	return (i + 1);
}

void quicksort(Student *s, int l, int r)
{
	if(l < r)
	{
		int pivot = partition(s, l, r);
		quicksort(s, l, pivot - 1);
		quicksort(s, pivot + 1, r);
	}
}

int main()
{
	Student *s = new Student[8];
	for(int i = 0; i < 8; i++)
	{
		string n;
		int r;
		cin>> n>> r;
		s[i].name = n;
		s[i].roll = r;
	}

	quicksort(s, 0, 7);

	for(int i = 0; i < 8; i++)
		cout<< s[i].roll<< " "<<s[i].name<< endl;

	return 0;
}