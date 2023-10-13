#include<stdio.h>

#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};


struct node *create()
{
	struct node *newnode=(struct node *) malloc(sizeof(struct node));
	int x;
	printf("\nENTER THE DATA(-1 for NULL)");
	scanf("%d",&x);
	if(x==-1)
	{
		return 0;
	}
	newnode->data=x;
	printf("ENTER THE LEFT CHILD  for %d ",x);
	
	newnode->left=create();
	printf("ENTER THE RIGHT CHILD  for %d ",x);
	
	newnode->right=create();
	return newnode;
}
int spiral(struct node *root)
{
	struct node *oddstack[50];
	struct node *evenstack[50];
	int oddtop=-1;
	int eventop=-1;
	
	if(root==NULL)
	{
		return 0;
	}
	
	oddstack[++oddtop]=root;
	
	int oddlevel=1;
	
	while(oddtop >=0 || eventop >=0)
	{
		if(oddlevel)
		{
			while(oddtop>=0)
			{
				struct node *curr=oddstack[oddtop--];
				printf("%d\t",curr->data);
				
				if(curr->right)
				{
					evenstack[++eventop]=curr->right;
				}
				if(curr->left)
				{
					evenstack[++eventop]=curr->left;
				}
			}
		}
		else
		{
			while(eventop>=0)
			{
				struct node *curr=evenstack[eventop--];
				printf("%d\t",curr->data);
				
				if(curr->left)
				{
					oddstack[++oddtop]=curr->left;
				}
				if(curr->right)
				{
					oddstack[++oddtop]=curr->right;
				}
			}
			
		}
		oddlevel=!oddlevel;
	}
	
 	
}
int main()
{
	struct node *root=NULL;
	root=create();
	
	spiral(root);
    
    
    
}
