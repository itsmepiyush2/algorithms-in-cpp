#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<bool> visited;
vector<vector<int> > graph;

void edge(int a, int b)
{
	graph[a].push_back(b);
	graph[b].push_back(a);
}

void dfs(int u)
{
	stack<int> s;
	s.push(u);
	visited[u] = true;

	while(!s.empty())
	{
		int f = s.top();
		s.pop();
		cout<< f<< " ";
		for(auto i = graph[f].begin(); i != graph[f].end(); i++)
		{
			if(!visited[*i])
			{
				s.push(*i);
				visited[*i] = true;
			}
		}
	}
}

int main()
{
	int n, e;
	cin>> n>> e;

	visited.assign(n, false);
	graph.assign(n, vector<int>());

	for(int i = 0; i < e; i++)
	{
		int a, b;
		cin>> a>> b;
		edge(a, b);
	}

	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
			dfs(i);
	}

	return 0;
}