//============================================================================
// Name        : A6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<iomanip>
using namespace std;
class data
{
	string key;
	string value;
	friend class LinearWReplace;
public:
	data()
	{
		key="*";
		value="*";
	}
};

class LinearWReplace
{
	data arr[10];
public:
	void insertWReplace();
	void insertReplace();
	void delEntry();
	void search();
	void display();

};
void LinearWReplace::insertReplace()
{
	string skey,svalue;
	cout<<"Enter Key : ";
	cin>>skey;
	cout<<"Enter Value :";
	cin>>svalue;
	int n=(int)skey[0];
	n=n%10;
	int i=n,f=0,t;
	string tkey,tvalue;
	if(arr[i].key!="*")
	{
		t=i;
		do
		{
			if(arr[i].key=="*")
			{
				f=1;
				break;
			}
			i++;
			i=i%10;
		}while(i!=n);
		if(f==0)
		{
			cout<<"\nTabel is empty\n";
		}
		else
		{
			tkey=arr[t].key;
			tvalue=arr[t].value;
			arr[t].key=skey;
			arr[t].value=svalue;
			arr[i].key=tkey;
			arr[i].value=tvalue;
			cout<<"\nElement added\n";
		}
	}
	else
	{
		arr[i].key=skey;
		arr[i].value=svalue;
	}
}
void LinearWReplace::delEntry()
{
	string k;
	cout<<"\nEnter key :";
	cin>>k;
	int n=(int)k[0];
	n=n%10;
	int i=n,f=0;
	do
	{
		if(k==arr[i].key)
		{
			f=1;
			break;
		}
		i++;
		i=i%10;
	}while(i!=n);
	if(f==0)
	{
		cout<<"\nKey not found \n";
	}
	else
	{
		arr[i].key="*";
		arr[i].value="*";
		cout<<"\nElement Deleted\n";
	}
}
void LinearWReplace::search()
{
	string k;
	cout<<"\nEnter key :";
	cin>>k;
	int n=(int)k[0];
	n=n%10;
	int i=n,f=0;
	do
	{
		if(k==arr[i].key)
		{
			f=1;
			break;
		}
		i++;
		i=i%10;
	}while(i!=n);
	if(f==0)
	{
		cout<<"\nKey not found \n";
	}
	else
	{
		cout<<"\nKey found\n";
		cout<<"Key :"<<arr[i].key<<endl;
		cout<<"Value :"<<arr[i].value<<endl;
	}
}
void LinearWReplace::display()
{
	string k,v;
	cout<<"\n+---------------------------+";
	cout<<"\n|        HASH-TABEL         |";
	cout<<"\n+-------------+-------------+";
	cout<<"\n|     KEY     |    VALUE    |";
	cout<<"\n+-------------+-------------+";
	for(int i=0;i<10;i++)
	{
		if(arr[i].key=="*")
		{
			k="";
			v="";
		}
		else
		{
			k=arr[i].key;
			v=arr[i].value;
		}
		cout<<"\n|"<<setw(8)<<k<<setw(6)<<"|"<<setw(8)<<v<<setw(6)<<"|";
		cout<<"\n+-------------+-------------+";
	}
}
void LinearWReplace::insertWReplace()
{
	string skey,svalue;
	cout<<"Enter Key : ";
	cin>>skey;
	cout<<"Enter Value :";
	cin>>svalue;
	int n=(int)skey[0];
	n=n%10;
	int i=n,f=0;
	do{
		if(arr[i].key=="*")
		{
			f=1;
			break;
		}
		i++;
		i=i%10;
	}while(i!=n);
	if(f==0)
		cout<<"\nTabel is full\n";
	else
	{
		arr[i].key=skey;
		arr[i].value=svalue;
		cout<<"\nInsertion Successful\n";
	}
}
int main() {
	int n;
	LinearWReplace z;
	while(1)
	{
		cout<<"\n******MENU*******\n";
		cout<<"1. Insert(Without Replacement)\n";
		cout<<"2. Insert(With Replacement)\n";
		cout<<"3. Delete\n";
		cout<<"4. Search\n";
		cout<<"5. Exit\n";
		cout<<"Enter your choice: ";
		cin>>n;
		if(n==5)
			break;
		switch(n)
		{
		case 1:
			z.insertWReplace();
			z.display();
			break;
		case 2:
			z.insertReplace();
			z.display();
			break;
		case 3:
			z.delEntry();
			z.display();
			break;
		case 4:
			z.search();
			break;
		}
	}
	return 0;
}
