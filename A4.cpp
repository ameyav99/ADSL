//============================================================================
// Name        : A4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class queue
{
	string a[10];
	int rear;
public:
	queue(){rear=-1;}
	void push(string );
	void pop();
	string top();
	bool empty();
	bool present(string );
};
bool queue::present(string x)
{
	for(int i=0;i<10;i++)
	{
		if(a[i]==x)
			return true;
	}
	return false;
}
void queue::push(string c)
{
	rear++;
	a[rear]=c;
}
string queue::top()
{
	return a[0];
}
void queue::pop()
{
	for(int i=0;i<9;i++)
	{
		a[i]=a[i+1];
	}
	rear--;
}
bool queue::empty()
{
	if(rear==-1)
		return true;
	return false;
}
class node
{
	string name;
	int cost;
	node* e;
	node* d;
	friend class graph;
public:
	node(){e=NULL;d=NULL;cost=0;}
};
class graph
{
	node* start;
public:
	graph(){start=NULL;}
	void addEdge();
	void deleteEdge();
	void addVertex();
	void deleteVertex();
	void inDegree();
	void outDegree();
	void traverseGraph();
	void displayGraph();
};
void graph::traverseGraph()
{
	string x;
	cout<<"\nEnter starting city :";
	cin>>x;

	node* temp=start;
	while(temp!=NULL)
	{
		if(temp->name==x)
			break;
		temp=temp->d;
	}
	if(temp==NULL)
	{
		cout<<"\nCity not found\n";
		return;
	}

	queue curr;
	queue visit;
	curr.push(x);

	while(!curr.empty())
	{
		x=curr.top();
		cout<<x<<" ";
		visit.
		push(x);
		curr.pop();
		temp=start;
		while(temp->name!=x)
		{
			temp=temp->d;
		}
		temp=temp->e;
		while(temp!=NULL)
		{
			if(!visit.present(temp->name))
				curr.push(temp->name);
			temp=temp->e;
		}
	}
}
void graph::inDegree()
{
	node* temp2;
	node* temp=start;
	string c;
	int count=0;
	cout<<"\nEnter City: ";
	cin>>c;
	while(temp!=NULL)
	{
		temp2=temp->e;
		while(temp2!=NULL)
		{
			if(temp2->name==c)
				count++;
			temp2=temp2->e;
		}
		temp=temp->d;
	}
	cout<<"\nIndegree of "<<c<<" : "<<count;

}
void graph::outDegree()
{
	string c;
	cout<<"\nEnter City: ";
	cin>>c;
	node* temp=start;
	while(temp!=NULL)
	{
		if(temp->name==c)
			break;
		temp=temp->d;
	}
	if(temp==NULL)
	{
		cout<<"\nCity not found!!\n";
		return;
	}
	else
	{
		int count=0;
		while(temp->e!=NULL)
		{
			count++;
			temp=temp->e;
		}
		cout<<"Out degree of "<<c<<" : "<<count<<endl;

	}

}
void graph:: displayGraph()
{
	node* temp=start;
	while(temp!=NULL)
	{
		cout<<"\n"<<temp->name<<" ->";
		node* temp2= temp->e;
		while(temp2!=NULL)
		{
			cout<<temp2->name<<"  ";
			temp2=temp2->e;
		}
		cout<<"\n";
		temp=temp->d;
	}

}
void graph::deleteVertex()
{
	cout<<"x";
	string c;
	cout<<"\nEnter City :";
	cin>>c;
	node* temp3;
	node* temp2=start;
	node* temp=start;
	while(temp->name!=c)
	{
		temp2=temp;
		temp=temp->d;
		if(temp==NULL)
			break;
	}
	if(temp==NULL)
	{
		cout<<"\nCity not found!\n";
		return;
	}
	else
	{
		if(temp==start)
		{
			start=temp->d;
		}
		else
			temp2->d=temp->d;
		temp3=temp;
		while(temp!=NULL)
		{
			temp3=temp;
			temp=temp->e;
			delete temp3;

		}
		temp=start;
		while(temp!=NULL)
		{
			temp2=temp->e;
			temp3=temp;
			while(temp2!=NULL)
			{
				if(temp2->name==c)
					break;
				temp3=temp2;
				temp2=temp2->e;
			}
			if(temp2!=NULL)
			{
				temp3->e=temp2->e;
				delete temp2;
			}
			temp=temp->d;
		}
	}
}
void graph:: addVertex()
{
	node* temp=new node();
	cout<<"\nEnter city: ";
	cin>>temp->name;
	if(start==NULL)
	{
		start=temp;
		cout<<"Vertex added";
		return;
	}
	node* temp2 =start;
	while(temp2->d!=NULL)
	{
		temp2=temp2->d;
	}
	temp2->d=temp;
	cout<<"Vertex added"<<"\n";
}
void graph::addEdge()
{
	int time;
	string sCity,dCity;
	cout<<"\nStarting city :";
	cin>>sCity;
	node* temp=start;
	while(temp->name!=sCity)
	{
		temp=temp->d;
		if(temp==NULL)
			break;
	}
	if(temp==NULL)
	{
		cout<<"\nStarting City not found !";
		return;
	}
	else
	{
		node* temp2=start;
		cout<<"\nDestination city: ";
		cin>>dCity;
		while(temp2!=NULL)
		{
			if(temp2->name==dCity)
				break;
			temp2=temp2->d;
		}
		if(temp2==NULL)
		{
			cout<<"\nDestination city not found!!\n";
			return;
		}
		while(temp->e!=NULL)
		{
			temp=temp->e;
			if(temp->name==dCity)
			{
				cout<<"\nDestination city already present!!\n";
				return;
			}
		}
		cout<<"\nTime :";
		cin>>time;
		temp->e=new node();
		temp->e->name=dCity;
		temp->e->cost=time;
	}
	cout<<"\nEdege added!!";
}
void graph::deleteEdge()
{
	node* temp2;
	node* temp=start;
	string sCity,dCity;
	cout<<"\nStarting city :";
	cin>>sCity;
	while(temp->name!=sCity)
	{
		temp=temp->d;
		if(temp==NULL)
			break;
	}
	if(temp==NULL)
	{
		cout<<"\nStarting city not found !!\n";
		return;
	}
	else
	{
		cout<<"\nDestination city :";
		cin>>dCity;
		temp2=temp;
		while(temp->name!=dCity)
		{
			temp2=temp;
			temp=temp->e;
			if(temp==NULL)
				break;
		}
		if(temp==NULL)
		{
			cout<<"\nDestination city not found\n ";
			return;
		}
		else
		{
			temp2->e=temp->e;
			delete temp;
			cout<<"\nEdge deleted!!\n";
		}
	}
}

int main() {
	graph z;
	int n;
	while(1)
	{
		cout<<"\n*****MENU*****\n";
		cout<<"1. Add City\n";
		cout<<"2. Add Path\n";
		cout<<"3. Delete City\n";
		cout<<"4. Delete Path\n";
		cout<<"5. Find InDegree\n";
		cout<<"6. Find OutDegree\n";
		cout<<"7. Traverse Graph(BFS)\n";
		cout<<"8. Exit\n";
		cout<<"Enter your choice :";
		cin>>n;
		if(n==8)
			break;
		switch(n)
		{
		case 1:
			z.addVertex();
			break;
		case 2:
			z.addEdge();
			break;
		case 3:
			z.deleteVertex();
			break;
		case 4:
			z.deleteEdge();
			break;
		case 5:
			z.inDegree();
			break;
		case 6:
			z.outDegree();
			break;
		case 7:
			cout<<"\nGraph Traversal :";
			z.traverseGraph();
			break;
		}


	}
	return 0;
}
