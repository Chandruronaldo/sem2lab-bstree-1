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

//search function
node *search()
{
	int a;
	cout<<"\nEnter the element you want to search";
	cin>>a;
	int b=1;
	//Temporary variable for traversal
	node *temp=new node;
	temp=root;
	//while loop for searching node by node 
	while(temp->left!=NULL && temp->right!=NULL)
	{
		if(temp->data>a)
		{
			temp=temp->left;
		}
		else if(temp->data<a)
		{
			temp=temp->right;
		}
		else if(temp->data==a)
		{b=0;
		break;}
	}
if(b==0)
cout<<"\nData is present";
else
cout<<"\nData is not present";

return temp;
}

/*void deletenode(int d)
{
      node *amma=new node;
      node *temp=new node;
      temp=search();
      amma=temp->parent;
      
      if(temp->left ==NULL && temp->right == NULL)
      {
      	if(amma->left->left==NULL)
      	{
      		amma->left=NULL;
      	}
      	else if(amma->right->right==NULL)
      	{
      		amma->right=NULL;
      	}
      }
}*/
//In order display function
int display(node *temp)
{
	if(temp==NULL)
	{
		return 0;
	}
	display(temp->left);
	cout<<"\t"<<temp->data<<"--";
	
	display(temp->right);
	//cout<<"\t"<<temp->data<<"--";
}

int main()
{
	int a,n,k,achoice,bchoice;
	cout<<"\nEnter the initial tree";
	cout<<"\n enter the number of nodes";
            cin>>n;
	cout<<"\n enter the node keys";
	for(int i=0;i<n;i++)
	{
		insert();
	}
	cout<<"\n";
	//a=display(root);
	do{
		cout<<"\nEnter option\n1)Insert\n2)Search\n3)Dislay";
		cin>>achoice;
		switch(achoice)
		{
			case 1: insert();
				break;
			case 2: search();
				break;
			case 3: a=display(root);
			cout<<"\n";
				break;
		}
	cout<<"\n Do you wanna do somemore actions?  If yes press 1 if no press 0";
	cin>>bchoice;
	}while(bchoice==1);
	
	return 0;
}
