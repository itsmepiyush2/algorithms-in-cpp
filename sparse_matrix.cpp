#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int matrix[6][6];
	vector<int> val;
	vector<int> xloc;
	vector<int> yloc;

	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			cin>> matrix[i][j];
			if(matrix[i][j] != 0)
			{
				val.push_back(matrix[i][j]);
				xloc.push_back(i);
				yloc.push_back(j);
			}
		}
	}

	for(int i = 0; i < val.size(); i++)
	{
		cout<< xloc[i]<< " "<< yloc[i]<<" "<< val[i]<< endl;;
	}

	return 0;

}