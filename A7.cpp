//============================================================================
// Name        : A7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<iomanip>
using namespace std;
class pairs
{
	string name;
	int count;
	string attr[5];
	int next;
	friend class symbolTableW;
public:
	pairs()
	{
		name="";
		count=0;
		next=-1;
	}
};
class symbolTableW
{
	pairs arr[10];
public:
	void display();
	void add();
	void deletePair();
	void retrive();
	void modify();
};
void symbolTableW::retrive()
{
	int n;
	string z;
	cout<<"\nEnter name :";
	cin>>z;
	n=(int)z[0];
	n=n%10;
	int flag=0,i=0;
	while(flag!=1)
	{
		if(arr[n].name!=z)
		{
			if(arr[n].next==-1)
				break;
			else
				n=arr[n].next;
		}
		else
			flag=1;
	}
	if(flag!=1)
	{
		cout<<"\n Name not found\n";
	}
	else
	{
		cout<<"\nEntry found\n";
		cout<<"NAME :"<<arr[n].name<<"\n";
		cout<<"ATTRIBUTES :\n";
		for(int i=0;i<arr[n].count;i++)
		{
			cout<<i+1<<". "<<arr[n].attr[i]<<"\n";
		}
	}

}
void symbolTableW::display()
{
	cout<<"\n+----+----------+----------+-----+";
	cout<<"\n|"<<setw(4)<<"No."<<"|"<<setw(10)<<"NAME"<<"|"<<setw(10)<<"ATTRIBUTES"<<"|"<<setw(5)<<"NEXT"<<"|";
	for(int i=0;i<10;i++)
	{
		cout<<"\n+----+----------+----------+-----+";
		cout<<"\n|"<<setw(4)<<i+1<<"|"<<setw(10)<<arr[i].name<<"|"<<setw(10)<<""<<"|"<<setw(5)<<arr[i].next+1<<"|";

		for(int j=0;j<arr[i].count;j++)
		{
			cout<<"\n|"<<setw(4)<<""<<"|"<<setw(10)<<""<<"|"<<setw(10)<<arr[i].attr[j]<<"|"<<setw(5)<<""<<"|";
		}
	}
	cout<<"\n+----+----------+----------+-----+\n";
}
void symbolTableW::add()
{
	char y='y';
	int i=0;;
	pairs temp;
	cout<<"Enter Name :";
	cin>>temp.name;
	while(((y=='Y')||(y=='y'))&&i<5)
	{
		cout<<"Enter attr "<<i+1<<":";
		cin>>temp.attr[i];
		temp.count++;
		cout<<"Enter 'Y' to add more attributes ";
		cin>>y;
		i++;
	}
	int n=0;
	n=(int)temp.name[0];
	n=n%10;
	int flag=0;
	i=n+1;
	if(arr[n].name=="")
	{
		arr[n]=temp;
		flag=1;
	}
	else
	{
		 while(flag!=1)
		 {
			 if(arr[n].next!=-1)
			 {
				 n=arr[n].next;
				 i=n+1;
				 i=i%10;
			 }
			 else
			 {
				 while(i!=n)
				 {
					 if(arr[i].name=="")
					 {
						 arr[i]=temp;
						 arr[n].next=i;
						 flag=1;
						 break;
					 }
					 i++;
				 }
				 if(i==n)
					 break;
			 }
		 }
	}
	if(flag==0)
	{
		cout<<"\nTable is full\n";
	}
	else
		cout<<"\nInsertion successful\n";
}
int main() {
	symbolTableW a;
	a.add();
	a.add();
	a.display();
	a.add();
	a.display();
	return 0;
}
