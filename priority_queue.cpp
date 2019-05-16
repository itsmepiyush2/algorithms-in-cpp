#include<iostream>
using namespace std;
struct node
{
	int data;
	int priority;
	struct node *next;
};
struct node *start = NULL;

void insert_node(int data, int priority)
{
	struct node *temp = new(struct node), *p;
	temp->data = data;
	temp->priority = priority;

	p = start;
	if(start == NULL || start->priority < temp->priority)
	{
		temp->next = start;
		start = temp;
	}
	else
	{
		while(p->next != NULL && p->next->priority <= temp->priority)
		{
			p = p->next;
			temp->next = p->next;
			p->next = temp;
		}
	}
}

void delete_node()
{
	if(start == NULL)
		cout<< "Underflow"<< endl;
	else
		start = start->next;
}

void display()
{
	struct node *p;
	p = start;
	while(p != NULL)
	{
		cout<< p->data<< ","<< p->priority<< " ";
		p = p->next;
	}
	cout<< endl;
}

int main()
{
	int data, priority, choice;
	while(1)
	{
		cout<< "1. Insert\n2. Delete\n3. Exit ";
		cin>> choice;
		switch(choice)
		{
			case 1: cout<< "Data: ";
					cin>> data;
					cout<< "Priority: ";
					cin>> priority;
					insert_node(data, priority);
					display();
					break;
			case 2: delete_node();
					display();
					break;
			case 3: return 0;
		}
	}
	return 0;
}