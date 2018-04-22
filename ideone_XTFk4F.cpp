
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
node *search(int data)
{
	int dat;
	dat=data;
	int b=1;
	//Temporary variable for traversal
	node *temp=new node;
	temp=root;
	//while loop for searching node by node 
	while(1)
		{
		//	temp=root;
			if(temp->data > dat)
			{
				if(temp->left==NULL)
				{
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
				       
		
			break;
				}
				else
				{
					temp=temp->right;
				}
			}
			else if(temp->data == dat)
			{
			b=0;
			break;
			}
		}
		
		
		
if(b==0)
cout<<"\nData is present";
else
cout<<"\nData is not present";

return temp;
}

void deletenode(int d)
{
      node *amma=new node;
      node *temp=new node;
      node *child=new node;
      node *grandchild=new node;
      child=NULL;
      grandchild=NULL;
      temp=search(d);
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
      else if(temp->left!=NULL && temp->right!=NULL)
      {
      	child=temp->left;
      	if(child->right==NULL)
      	{
      		child->parent=amma;
      		grandchild=temp->right;
      		child->right=grandchild;
      		grandchild->parent=child;
      	   	temp->parent=NULL;
		temp->left=NULL;
		temp->right=NULL;
		temp->data=0;
		delete temp;
      	}
      	else
		{
			while(child->right->right!=NULL)
		{
      			child=child->right;
		}
			grandchild=child->right;
			temp->data=grandchild->data;
			child->right=NULL;
			delete grandchild;
	            }
      }
      else if(temp->left==NULL || temp->right==NULL)
      {
      	
      	if(temp->left!=NULL)
      	{
      		child=temp->left;
      		if(amma->left==temp)
      		{
      			amma->left=child;
      		}
      		else if(amma->right==temp)
      		{
      			amma->right=child;
      		}
      	   	child->parent=amma;
      		temp->parent=NULL;
      		temp->left=NULL;
      		delete temp;
      	
      	}
      	else if(temp->right!=NULL)
      	{
      		child=temp->right;
      		if(amma->right==temp)
      		{
      			amma->right=child;
      		}
      		else if(amma->left==temp)
      		{
      			amma->left=child;
      		}
      	   	child->parent=amma;
      		temp->parent=NULL;
      		temp->right=NULL;
      		delete temp;
      		
      	}
      	
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
int a,n,k,achoice,bchoice,s,d;
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
		cout<<"\nEnter option\t1)Insert\t2)Search\t3)Delete\t4)Dislay";
		cin>>achoice;
		switch(achoice)
		{
			case 1: insert();
				break;
			case 2:	cout<<"\n Enter the element to be searched";
				cin>>s;
				search(s);
				break;
			case 3: cout<<"\n Enter the element to be deleted";
				cin>>d;
				deletenode(d);
				break;
			case 4: a=display(root);
			cout<<"\n";
				break;
		}
	cout<<"\n Do you wanna do somemore actions?  If yes press 1 if no press 0";
	cin>>bchoice;
	}while(bchoice==1);
	return 0;
}
