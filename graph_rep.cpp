#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, e;
	cin>> n>> e;

	vector<pair<int, int> >v[n];

	for(int i = 0; i < e; i++)
	{
		int v1, v2, w;
		cin>> v1>> v2>> w;
		v[v1].push_back(make_pair(v2, w));
		v[v2].push_back(make_pair(v1, w));
	}

	for(int i = 0; i < n; i++)
	{
		cout<< i;
		for(int j = 0; j < v[i].size(); j++)
			cout<< " -> "<< v[i][j].first<< ","<< v[i][j].second;
		cout<< endl;
	}
	return 0;
}