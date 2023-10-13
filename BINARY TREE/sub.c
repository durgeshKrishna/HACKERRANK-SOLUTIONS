
    #include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct bnode
{
	int data;
	struct bnode *left,*right;
};
struct bnode *create()
{
	struct bnode *node;
	node=(struct bnode*)malloc(sizeof(struct bnode));
	int ele;
	printf("\n enter the data for the binary tree:");
	scanf("\n%d",&ele);
	if(ele==-1)
	{
		printf("\n no child is created");
		return 0;
	}
	node->data=ele;
	printf("\n the left child of the binary tree:%d",ele);
	node->left=create();
	printf("\n the right child of the binary tree:%d",ele);
	node->right=create();
	return node;
}
int inorder(struct bnode *root,int arr1[],int &i)
{
	if(root==NULL)
	{
		return 0;
	}
	inorder(root->left,arr1,i);
	arr1[i++]=root->data;
	inorder(root->right,arr1,i);
	return i;
}
int preorder(struct bnode *root,int arr2[],int &j)
{
	if(root==NULL)
	{
		return 0;
	}
	arr2[j++]=root->data;
	preorder(root->left,arr2,j);
	preorder(root->right,arr2,j);
	return j;
}
int subarray(int arr[],int arr1[],int m,int n)
{
	int j,i;
	for(i=0;i<=m-n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i+j]!=arr1[j])
			break;
		}
		if(j==n)
		return 1;
	}
	return 0;
}
bool subtree(struct bnode *root,struct bnode *root1)
{
	if(root==NULL)
	return false;
	if(root1==NULL)
	return true;
	int arr1[30],arr2[30],i=0,j=0,arr11[30],arr22[30],m=0,n=0;
	m=inorder(root,arr1,i);
	n=inorder(root1,arr2,j);
	arr1[i]='\0';
	arr2[j]='\0';
	printf("\n m n%d \t %d",m,n);
	if(subarray(arr1,arr2,m,n)==0)
	return false;
	i=0,j=0;
	m=preorder(root,arr11,i);
	n=preorder(root1,arr22,j);
	arr11[i]='\0',arr22[j]='\0';
	if(subarray(arr11,arr22,m,n)==0)
		return false;
	return true;	
}
int main()
{
	struct bnode *root=NULL,*root1=NULL;
	root=create();
	printf("\n the subtree of the binary tree:");
	root1=create();
	if(subtree(root,root1))
	printf("\n tree is subtree");
	else
	printf("\n tree is not a subtree");
}


