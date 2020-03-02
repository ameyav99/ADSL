#include<iostream>
using namespace std;
class node
{
	int data;
	node* left;
	node* right;
	int flag;
	friend class TBT;
public:
	node(){left=NULL;right=NULL;flag=0;}
};
class TBT
{
	node* root;
public:
	TBT(){root=NULL;}
	void insert();
	void inorder();
	void preorder();
};
void TBT::insert()
{
	char c;
	int n;

	cout<<"\nEnter no of nodes to insert :";
	cin>>n;
	while(n!=0)
	{
	node* temp=new node();
	cout<<"\nEnter data : ";
	cin>>temp->data;
	if(root==NULL)
	{
		root=temp;
		cout<<"\nElement added at root\n";
	}
	else
	{
		node* p=root;
		int f=0;
		while(f==0)
		{
			cout<<"Add left or right (l/r) of "<<p->data<<" :";
			cin>>c;
			if(c=='l')
			{
				if(p->left==NULL)
				{
					p->left=temp;
					temp->right=p;
					temp->flag=1;
					f=1;
				}
				else
				{
					p=p->left;
				}
			}
			else
			{
				if(p->right==NULL)
				{
					p->right=temp;
					f=1;
				}
				else
				{
					if(p->flag==0)
						p=p->right;
					else
					{
						temp->right=p->right;
						p->right=temp;
						p->flag=0;
						temp->flag=1;
						f=1;
					}
				}
			}
		}
		cout<<"\nElement Added\n";
	}
	n--;
	}
}
void TBT::inorder()
{
	int f=1;
	node* temp=root;
	while(temp!=NULL)
	{
		while(temp->left!=NULL&&f==1)
		{
			temp=temp->left;
		}
		cout<<temp->data<<" ";
		if(temp->flag==1)
		{
			temp=temp->right;
			f=0;
		}
		else
		{
			temp=temp->right;
			f=1;
		}
	}
}
void TBT::preorder()
{
	int f=1;
	node* temp=root;
	while(temp!=NULL)
	{
		while(temp->left!=NULL&&f==1)
		{
			cout<<temp->data<<" ";
			temp=temp->left;
		}
		if(temp->left==NULL)
		{
			cout<<temp->data<<" ";
		}
		if(temp->flag==1)
		{
			temp=temp->right;
			f=0;
		}
		else
		{
			temp=temp->right;
			f=1;
		}
	}
}
int main()
{
	TBT z;
	int n;
	while(1)
	{
		cout<<"\n******MENU********\n";
		cout<<"1. Insert data\n";
		cout<<"2. Inorder\n";
		cout<<"3. Preorder\n";
		cout<<"4. Exit\n";
		cout<<"Enter your choice :";
		cin>>n;
		if(n==4)
			break;
		switch(n)
		{
		case 1:
			z.insert();
			break;
		case 2:
			cout<<"\nInorder :";
			z.inorder();
			break;
		case 3:
			cout<<"\nPreorder :";
			z.preorder();
			break;
		default:
			cout<<"\nINVALID CHOICE !!\n";
			break;
		}
	}
}
