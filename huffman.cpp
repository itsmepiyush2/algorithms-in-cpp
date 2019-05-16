#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct minHeapNode
{
	char a;
	int freq;
	minHeapNode *left, *right;
	minHeapNode(char a, int freq)
	{
		this->a = a;
		this->freq = freq;
		left = NULL;
		right = NULL;
	}
};

struct compare
{
	bool operator()(minHeapNode *l, minHeapNode *r)
	{
		return l->freq > r->freq;
	}
};

void printCode(minHeapNode *root, string s)
{
	if(!root)
		return;
	if(root->a != '$')
		cout<< root->a<< " : "<< s<< endl;
	printCode(root->left, s + "0");
	printCode(root->right, s + "1");
}

void huffman(char a[], int freq[], int n)
{
	minHeapNode *left, *right, *top;
	priority_queue< minHeapNode* , vector<minHeapNode*> , compare> minHeap;

	for(int i = 0; i < n; i++)
		minHeap.push(new minHeapNode(a[i], freq[i]));

	while(minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new minHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	printCode(minHeap.top(), "");
}

int main()
{
	int n;
	cin>> n;
	char a[n];
	int freq[n];

	for(int i = 0; i < n; i++)
		cin>> a[i]>> freq[i];

	huffman(a, freq, n);

	return 0;
}