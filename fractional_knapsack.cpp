#include<iostream>
using namespace std;
class Knapsack
{
public:
	double val;
	double weight;
	char comm;
	double pu_val;
};

class OP
{
public:
	char comm;
	double f;
};

bool compare(Knapsack a, Knapsack b)
{
	return a.pu_val > b.pu_val;
}

void optimise(Knapsack *input,int n, int knap_weight)
{
	double sum = 0.0, final_val = 0.0;
	sort(input, input + n, compare);

	OP *output = new OP[n];
	for(int i = 0; i < n; i++)
		output[i].f = 0.0;

	for(int i = 0; i < n; i++)
	{
		if(sum + input[i].weight <= knap_weight)
		{
			sum += input[i].weight;
			final_val += input[i].val;
			output[i].comm = input[i].comm;
			output[i].f = 1.0;
		}
		else
		{
			double remain = knap_weight - sum;
			final_val += input[i].val + remain/input[i].weight;
			output[i].comm = input[i].comm;
			output[i].f = remain/input[i].weight;
			break;
		}
	}

	for(int i = 0; i < n; i++)
	{
		cout<< output[i].comm<< " "<< output[i].f<< endl;
	}
	cout<< final_val<< endl;

}

int main()
{
	int n, knap_weight;
	cin>> n>> knap_weight;

	Knapsack *input = new Knapsack[n];
	for(int i = 0; i < n; i++)
	{
		char c;
		double v, w, p;
		cin>> c>> v>> w;
		p = v/w;
		input[i].comm = c;
		input[i].val = v;
		input[i].weight = w;
		input[i].pu_val = p;
	}

	optimise(input, n, knap_weight);

}