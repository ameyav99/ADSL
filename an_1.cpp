//============================================================================
// Name        : a_1.cpp
// Author      : Ameya Vyavahare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node;
class stack
{
	node*  arr[50];
	int front;
public:
	stack()
	{
		front= -1;
	}
	node* top()
	{
		return arr[front];
	}
	void push(node* temp)
	{
		front++;
		arr[front]=temp;
	}
	void pop()
	{
		front--;
	}
	bool empty()
	{
		if(front==-1)
			return true;
		else
			return false;
	}

};
class node
{
	int data;
	node* left;
	node* right;
	friend class BinaryTree;
public:
	node(){data=0;left=NULL;right=NULL;}
	node(int x){data=x;left=NULL;right=NULL;}
};
class BinaryTree
{
	node* root;
public:
	BinaryTree(){root=NULL;}
	node* returnRoot(){return root;}
	void insertnode();
	void inorderRec(node*);
	void inorder();
	void postorderRec(node*);
	void postorder();
	void preorderRec(node* );
	void preorder();
	void copy(node*,node*);
	void operator =(BinaryTree );
	void mirrorBinaryTree(BinaryTree);
	void mirror(node*,node*);
	void deleteTree(node*&);
	void printInternalNodes();
	void printLeafNodes();
	bool checkEqual(BinaryTree);
	void check(node*,node*,int &);
	void deleteFTree();
};

bool BinaryTree::checkEqual(BinaryTree x)
{
    if(x.root==NULL && root==NULL)
        return true;
	int flag=1;
	check(root,x.root,flag);
	if(flag==0)
		return false;
	else
		return true;
}
void BinaryTree::check(node* temp1,node* temp2,int& flag)
{
	if(flag==0)
		return;
	if(temp1->data!=temp2->data)
	{
		flag=0;
		return;
	}
	if(temp1->right!=NULL)
	{
		if(temp2->right==NULL)
		{
			flag=0;
			return;
		}
		else
		{
			check(temp1->right,temp2->right,flag);
		}
	}
	else
	{
		if(temp2->right!=NULL)
		{
			flag=0;
			return;
		}
	}
	if(temp1->left!=NULL)
	{
		if(temp2->left==NULL)
		{
			flag=0;
			return;
		}
		else
		{
			check(temp1->left,temp2->left,flag);
		}
	}
	else
	{
		if(temp2->left!=NULL)
		{
			flag=0;
			return;
		}
	}
}
void BinaryTree::printInternalNodes()
{
	stack s;
	int flag=0;
	node* temp=root;
	do
	{
		flag=0;
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		if(temp->right!=NULL)
		{
			if(temp!=root)
			cout<<temp->data<<" ";
			temp=temp->right;
			flag=1;
		}
		else
		{
			if(temp->left!=NULL&&temp!=root)
				cout<<temp->data<<" ";
			temp=NULL;
		}
	}while(!s.empty()||flag==1);
}
void BinaryTree::printLeafNodes()
{
	stack s;
	int flag=0;
	node* temp=root;
	do
	{
		flag=0;
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		if(temp->right!=NULL)
		{
			temp=temp->right;
			flag=1;
		}
		else
		{
			if(temp->left==NULL)
				cout<<temp->data<<" ";
			temp=NULL;
		}
	}while(!s.empty()||flag==1);
}
void BinaryTree::deleteFTree()
{
    deleteTree(root);
}
void BinaryTree::deleteTree(node*&temp)
{
	if(temp==NULL)
		return;
	deleteTree(temp->right);
	deleteTree(temp->left);
	delete temp;
	temp=NULL;
}
void BinaryTree::mirrorBinaryTree(BinaryTree x)
{
	root=new node();
	mirror(root,x.root);
}
void BinaryTree::mirror(node* temp1,node* temp2)
{
	temp1->data=temp2->data;
	if(temp2->right!=NULL)
	{
		temp1->left=new node();
		mirror(temp1->left,temp2->right);
	}
	if(temp2->left!=NULL)
	{
		temp1->right=new node();
		mirror(temp1->right,temp2->left);
	}
}
void BinaryTree::operator =(BinaryTree z)
{
	if(z.root==NULL)
    {
        cout<<"\n No nodes are present\n";
        return;
    }
	root=new node();
	node* temp=z.root;
	copy(root,temp);
}
void BinaryTree::copy(node* temp1,node* temp2)
{
	temp1->data=temp2->data;
	if(temp2->left!=NULL)
	{
		temp1->left=new node();
		copy(temp1->left,temp2->left);
	}
	if(temp2->right!=NULL)
	{
		temp1->right=new node();
		copy(temp1->right,temp2->right);
	}
}
void BinaryTree::insertnode()
{
    int n;
    cout<<"\nEnter no. of nodes:";
    cin >>n;
    for(int i=0;i<n;i++)
    {
	char c;
	node* temp=new node;
	cout<<"\nEnter data :";
	cin>>temp->data;
	if(root==NULL)
	{
		root=temp;
		cout<<"Element added at root\n";
	}
	else
    {
	int flag=0;
	node* p=root;
	while(flag==0)
	{
		cout<<"Add at the left or right of "<<p->data<<"(l or r):";
		cin>>c;
		if(c=='r')
		{
			if(p->right==NULL)
			{
				p->right=temp;
				flag=1;
			}
			else
			{
				p=p->right;
			}
		}
		else if(c=='l')
		{
			if(p->left==NULL)
			{
				p->left=temp;
				flag=1;
			}
			else
			{
				p=p->left;
			}
		}
	}

	cout<<"\nElement added\n";
    }
    }
}
void BinaryTree::inorderRec(node* temp)
{
	if(temp==NULL)
		return;
	inorderRec(temp->left);
	cout<<temp->data<<" ";
	inorderRec(temp->right);
}
void BinaryTree::postorderRec(node* temp)
{
	if(temp==NULL)
		return;
	postorderRec(temp->left);
	postorderRec(temp->right);
	cout<<temp->data<<" ";
}
void BinaryTree::preorderRec(node* temp)
{
	if(temp==NULL)
		return;
	cout<<temp->data<<" ";
	preorderRec(temp->left);
	preorderRec(temp->right);
}
void BinaryTree::inorder()
{
	stack  s;
	node* temp =root;
	if(temp==NULL)
    {
        cout<<"\n No nodes are present\n";
        return;
    }
	s.push(temp);
	int flag=1;
	while(!s.empty())
	{
		while(temp->left!=NULL&&flag==1)
			{
				temp=temp->left;
				s.push(temp);
			}
		temp=s.top();
		s.pop();
		cout<<temp->data<<" ";
		if(temp->right!=NULL)
		{
			temp=temp->right;
			s.push(temp);
			flag=1;
		}
		else
			flag=0;
	}
}
void BinaryTree::postorder()
{
	stack  s;
	node* temp=root;
	if(temp==NULL)
    {
        cout<<"\n No nodes are present\n";
        return;
    }
	do
	{
		while(temp!=NULL)
		{
			if(temp->right!=NULL)
				s.push(temp->right);
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		if(temp->right!=NULL&&temp->right==s.top())
		{
			s.pop();
			s.push(temp);
			temp=temp->right;
		}
		else
		{
			cout<<temp->data<<" ";
			temp=NULL;
		}
	}while(!s.empty());
}
void BinaryTree::preorder()
{
	stack  s;
	node* temp=root;
	if(temp==NULL)
    {
        cout<<"\n No nodes are present\n";
        return;
    }
	int flag=0;
	do
	{
		flag=0;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		if(temp->right!=NULL)
		{
			temp=temp->right;
			flag=1;

		}
		else
		{
			temp=NULL;
		}
	}while(!s.empty()||flag==1);
}
int main() {
	BinaryTree z,x,y,m;
	int n;
	while(1)
	{
		cout<<"\n*****MENU******\n";
		cout<<"1. Insert Nodes \n";
		cout<<"2. Inorder Traversal\n";
		cout<<"3. Postorder Traversal\n";
		cout<<"4. Preorder Traversal\n";
		cout<<"5. Copy Tree\n";
		cout<<"6. Delete Tree\n";
		cout<<"7. Create Mirror Image\n";
		cout<<"8. Display leaf and Internal Nodes\n";
		cout<<"9. Compare Binary Tree\n";
		cout<<"10.Exit\n";
		cout<<"Enter your choice:";
		cin>>n;
		if(n==10)
			break;
		switch(n)
		{
		case 1:
			z.insertnode();
			break;
		case 2:
			cout<<"\nInorder traversal:\n";
			cout<<"\nUsing recursion :";
			z.inorderRec(z.returnRoot());
			cout<<"\nWithout recursion:";
			z.inorder();
			break;
		case 3:
			cout<<"\nPostorder traversal:\n";
			cout<<"\nUsing recursion :";
			z.postorderRec(z.returnRoot());
			cout<<"\nWithout recursion:";
			z.postorder();
			break;
		case 4:
			cout<<"\nPreorder traversal:\n";
			cout<<"\nUsing recursion :";
			z.preorderRec(z.returnRoot());
			cout<<"\nWithout recursion:";
			z.preorder();
			break;
		case 5:
			x=z;
			cout<<"\n Tree Copied\n";
			cout<<"\nInorder Traversal of :\n";
			cout<<" Original Tree: ";
			z.inorderRec(z.returnRoot());
			cout<<"\n Copied Tree:  ";
			x.inorderRec(x.returnRoot());
			break;
		case 6:
			z.deleteFTree();
			cout<<"\nTree Deleted!!\n";
			break;
		case 7:
			y.mirrorBinaryTree(z);
			cout<<"\n Mirror image created\n";
			cout<<"\nInorder Traversal of :\n";
			cout<<" Original Tree: ";
			z.inorderRec(z.returnRoot());
			cout<<"\n Mirror Tree: ";
			y.inorderRec(y.returnRoot());
			break;
		case 8:
			cout<<"\nLeaf Nodes:";
			z.printLeafNodes();
			cout<<"\nInternal Nodes: ";
			z.printInternalNodes();
			break;
        case 9:
            cout<<"\nEnter tree to be compared \n";
            m.insertnode();
            if(z.checkEqual(m)==true)
                cout<<"\nTrees are equal \n";
            else
                cout<<"\nTrees are not equal\n";
            break;
		}
	}

}