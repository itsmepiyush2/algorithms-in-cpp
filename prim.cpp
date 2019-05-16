#include<iostream>
using namespace std;
#define INF 1e7

int extractMin(int *weight, bool *visited, int n)
{
	int minVertex = -1;
	for(int i = 0; i < n; i++)
	{
		if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
			minVertex = i;
	}
	return minVertex;
}

void prim(int **edges, int n, int e)
{
	int *parent = new int[n];
	int *weight = new int[n];
	bool *visited = new bool[n];

	for(int i = 0; i < n; i++)
	{
		weight[i] = INF;
		visited[i] = false;
	}
	weight[0] = 0;
	parent[0] = -1;

	for(int i = 0; i < n; i++)
	{
		int minVertex = extractMin(weight, visited, n);
		visited[minVertex] = true;

		for(int j = 0; j < n; j++)
		{
			if(edges[minVertex][j] != 0)
			{
				if(edges[minVertex][j] < weight[j] && !visited[j])
				{
					weight[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	cout<< endl;
	for(int i = 1; i < n; i++)
	{
		if(parent[i] < i)
			cout<< parent[i]<< " "<< i<< " "<< weight[i]<< endl;
		else
			cout<< i<< " "<< parent[i]<< " "<< weight[i]<< endl;
	}
}

int main()
{
	int n, e;
	cin>> n>> e;

	int **edges = new int*[n];
	for(int i = 0; i < n; i++)
	{
		edges[i] = new int[n];
		for(int j = 0; j < n; j++)
			edges[i][j] = 0;
	}
	for(int i = 0; i < e; i++)
	{
		int f, s, w;
		cin>> f>> s>> w;
		edges[f][s] = w;
		edges[s][f] = w;
	}

	prim(edges, n, e);

	for(int i = 0; i < n; i++)
		delete [] edges[i];
	delete [] edges;

	return 0;
}
