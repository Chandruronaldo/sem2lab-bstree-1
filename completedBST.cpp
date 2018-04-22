
#include<iostream>
using namespace std;

// Class for the structure of the node
class node
{
	public:
	int data;
	node * parent;
	node * left;
	node * right;
		
	node()
	{ data=0;
	parent=NULL;
	left=NULL;
	right=NULL;
}
} *root;

//Insertion function
void insert()
{
	int dat;
	cout<<"\nEnter data";
	cin>>dat;
	//1. temporary node for traversal
	node *temp=new node;
	//2. node to be added
	node *add=new node;
	add->data=dat;
	add->left=NULL;
	add->right=NULL;
	add->parent=NULL;
	temp->data=0;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	
	//basecase
	if(root==NULL)
	{
		root=add;
		root->parent=NULL;
		root->left=NULL;
		root->right=NULL;
		
	}
	
	else
	{	
		temp=root;
		//Finding the leaf
	
		while(1)
		{
		//	temp=root;
			if(temp->data > dat)
			{
				if(temp->left==NULL)
				{
				       
			temp->left=add;
			add->parent=temp;
			break;
				}
				else
				{
					temp=temp->left;
				}
			}
			else if(temp->data < dat)
			{

				if(temp->right==NULL)
				{
				       
			temp->right=add;
			add->parent=temp;
			break;
				}
				else
				{
					temp=temp->right;
				}
			}
			else if(temp->data == dat)
			{
				NULL;
			}
		}
		
		//Once found the node is installed in correct position
		
	}
}


//In order display function
int display(node *temp)
{
	if(temp==NULL)
	{
		return 0;
	}
	display(temp->left);
	cout<<temp->data<<"-->";
	
	display(temp->right);
	
}

int main()
{
int a,n,achoice,bchoice;
	cout<<"\nEnter the initial tree";
	cout<<"\n enter the number of nodes";
            cin>>n;
	cout<<"\n enter the node keys";
	for(int i=0;i<n;i++)
	{
		insert();
	}
	cout<<"\n";
	a=display(root);
	do{
		cout<<"\nEnter option\t1)Insert\t2)Dislay";
		cin>>achoice;
		switch(achoice)
		{
			case 1: insert();
				break;
			
			case 2: a=display(root);
			cout<<"\n";
				break;
		}
	cout<<"\n Do you wanna do somemore actions?  If yes press 1 if no press 0";
	cin>>bchoice;
	}while(bchoice==1);
	return 0;
}
