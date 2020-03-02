    #include<iostream>
#include<iomanip>
using namespace std;
class Graph
{
	int arr[10][10];
	string name[10];
	int count;
public:
	Graph();
	int index(string );
	void addVertex();
	void addEdge();
	void display();
	void primsAlgo();
	void kruskalsAlgo();
	int minindex(int*,int*);
};
int Graph::minindex(int mst_set[],int key[])
{
	int mini,min=999999;
	for(int i=0;i<count;i++)
	{
		if(key[i]<min)
		{
			if(mst_set[i]!=1)
			{
				min=key[i];
				mini=i;
			}
		}
	}
	return mini;
}
Graph::Graph()
{
	count=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			arr[i][j]=-1;
	}
}
int Graph::index(string x)
{
    for(int i=0;i<count;i++)
	{
		if(name[i]==x)
			return i;
	}
	return -1;
}
void Graph::addVertex()
{
	cout<<"\nEnter City : ";
	cin>>name[count];
	count++;
	cout<<"\nCity Added\n";
}
void Graph::addEdge()
{
	string c1,c2;
	int cost;
	cout<<"\nEnter City 1: ";
	cin>>c1;
	if(index(c1)==-1)
	{
		cout<<"\nCity not found!!\n";
		return;
	}
	cout<<"Enter City 2 :";
	cin>>c2;
	if(index(c2)==-1)
	{
		cout<<"\nCity not found!!\n";
		return;
	}
	cout<<"Enter Cost :";
	cin>>cost;
	arr[index(c1)][index(c2)]=cost;
	arr[index(c2)][index(c1)]=cost;
	cout<<"\nEdge Added\n";
}
void Graph::display()
{
	cout<<setw(10)<<"";
	for(int i=0;i<count;i++)
		cout<<setw(10)<<name[i];
	cout<<"\n";
	for(int i=0;i<count;i++)
	{
		cout<<setw(10)<<name[i];
		for(int j=0;j<count;j++)
			cout<<setw(10)<<arr[i][j];
		cout<<"\n";
	}
}
void Graph ::primsAlgo()
{
	int mst_set[count];
	int keyset[count];
	for(int i=0;i<count;i++)
	{
		mst_set[i]=0;
		keyset[i]=999999;
	}
	keyset[0]=0;
	for(int i=0;i<count;i++)
	{
		int n=minindex(mst_set,keyset);
		mst_set[n]=1;
		for(int j=0;j<count;j++)
		{
			if(arr[n][j]!=-1)
			{
				if(keyset[j]>arr[n][j])
					keyset[j]=arr[n][j];
			}
		}
	}
	int result=0;
	for(int i=0;i<count;i++)
	{
		result+=keyset[i];
	}
	cout<<"Minimum cost :"<<result;
}
int main()
{
	Graph z;
	int n;
	while(1)
	{
		cout<<"\n*******MENU*********\n";
		cout<<"1. Add city\n";
		cout<<"2. Add edge\n";
		cout<<"3. Display Matrix\n";
		cout<<"4. Minimum cost(prims)\n";
		cout<<"5. Exit\n";
		cout<<"Enter your choice: ";
		cin>>n;
		switch(n)
		{
		case 1:
			z.addVertex();
			break;
		case 2:
			z.addEdge();
			break;
		case 3:
			z.display();
			break;
		case 4:
			z.primsAlgo();
			break;
		case 5:
			return 0;
			break;
		default:
			cout<<"\nINVALID OPTION \n";
			break;
		}
	}

}
