//============================================================================
// Name        : A2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class node
{
	char key[10];
	char data[10];
	node* left;
	node* right;
	friend class BST;
public:
	node(){left=NULL;right=NULL;}
	node(char* k ,char * d){strcpy(key,k);strcpy(data,d);right=NULL;left=NULL;}
};
class BST
{
	node* root;
public:
	BST(){root=NULL;}
	void insertNode( );
	void inorderRec(node*);
	void displayInorder();
	void search();
	void update();
	void displayDesce();
	void desec(node* temp);
	void deleteNode();

};
void BST::deleteNode()
{

}
void BST::displayDesce()
{
	desec(root);
}
void BST::desec(node* temp)
{
	if(temp==NULL)
		return;
	inorderRec(temp->right);
	cout<<setw(14)<<temp->key<<"   "<<temp->data<<"\n";
	inorderRec(temp->left);
}
void BST::update()
{
	char k[10];
	cout<<"Enter keyword to be updated :";
	cin>>k;
	node* temp=root;
	while(temp!=NULL)
	{
		int n=strcmp(temp->key,k);
		if(n==0)
			break;
		else if(n<0)
			temp=temp->right;
		else
			temp=temp->left;
	}
	if(temp==NULL)
	{
		cout<<"\nKeyword not Found\n ";
	}
	else
	{
		cout<<"\n Keyword found \n";
		cout<<" Keyword :"<<temp->key<<endl;
		cout<<" Meaning :"<<temp->data<<endl;
		cout<<"\n Enter updated values :";
		cout<<"\n Keyword :";
		cin>>temp->key;
		cout<<"Meaning :";
		cin>>temp->data;

		cout<<"\n Values Updated !"<<endl;
	}
}
void BST::search()
{
	char k[10];
	cout<<"\nEnter keyword :";
	cin>>k;
	int count=0;
	node* temp=root;
	while(temp!=NULL)
	{
		int n=strcmp(temp->key,k);
		count++;
		if(n==0)
		break;
		else if(n<0)
			temp=temp->right;
		else
			temp=temp->left;
	}
	if(temp==NULL)
		cout<<"\n Keyword not Found !\n";
	else
	{
		cout<<"\nKeyword Found \n";
		cout<<"Keyword :"<<temp->key<<endl;
		cout<<"Meaning :"<<temp->data<<endl;
		cout<<"No. of Comparisons : "<<count<<endl;
	}
}
void BST::inorderRec(node* temp)
{
	if(temp==NULL)
		return;
	inorderRec(temp->left);
	cout<<setw(14)<<temp->key<<"   "<<temp->data<<"\n";
	inorderRec(temp->right);
}
void BST::displayInorder()
{
	inorderRec(root);
}
void BST::insertNode()
{
	char k[10],d[10];
	cout<<"Enter keyword :";
	cin>>k;
	cout<<"Enter meaning :";
	cin>>d;
	int flag=0;
	node* temp=root,*temp2=root;
	if(temp==NULL)
	{
		root=new node(k,d);
	}
	else
	{
		while(temp!=NULL)
		{
			int n=strcmp(temp->key,k);
			if(n<0)
			{
				temp2=temp;
				temp=temp->right;
				flag=0;
			}
			else
			{
				temp2=temp;
				temp=temp->left;
				flag=1;
			}
		}
		if(flag==1)
		{
			temp2->left=new node(k,d);
		}
		else
		{
			temp2->right=new node(k,d);
		}
	}
}
int main() {
	BST z;
	z.insertNode();
	z.insertNode();
	z.insertNode();
	z.insertNode();
	z.insertNode();
	z.insertNode();
	z.insertNode();
	z.displayInorder();
	z.update();
	z.displayInorder();
	return 0;

}
