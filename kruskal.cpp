#include<iostream>
#include<algorithm>
using namespace std;
class Edge
{
public:
	int source;
	int dest;
	int weight;
};

bool compare(Edge a, Edge b)
{
	return a.weight < b.weight;
}

int findParent(int v, int *parent)
{
	if(v == parent[v])
		return v;
	return findParent(parent[v], parent);
}

void kruskal(Edge *input, int n, int e)
{
	sort(input, input + e, compare);
	Edge *output = new Edge[n - 1];

	int *parent = new int[n];
	for(int i = 0; i < n; i++)
		parent[i] = i;

	int i = 0, count = 0;
	while(count != n - 1)
	{
		Edge currentEdge = input[i];
		int sourceParent = findParent(currentEdge.source, parent);
		int destParent = findParent(currentEdge.dest, parent);

		if(sourceParent != destParent)
		{
			output[count] = currentEdge;
			count++;
			parent[sourceParent] = destParent;
		}
		i++;
	}

	cout<< endl;
	for(int i = 0; i < n - 1; i++)
	{
		if(output[i].source < output[i].dest)
			cout<< output[i].source<< " "<< output[i].dest<< " "<< output[i].weight<< endl;
		else
			cout<< output[i].dest<< " "<< output[i].source<< " "<< output[i].weight<< endl;
	}
}

int main()
{
	int n, e;
	cin>> n>> e;

	Edge *input = new Edge[e];
	for(int i = 0; i < e; i++)
	{
		int s, d, w;
		cin>> s>> d>> w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}

	kruskal(input, n, e);

	return 0;
}