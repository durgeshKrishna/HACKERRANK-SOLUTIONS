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
struct bnode *mirror(struct bnode *root)
{
	struct bnode *temp;
	if(root==NULL)
	return 0;
	else
	{
		mirror(root->left);
		mirror(root->right);
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
struct bnode *inorder(struct bnode *root)
{
	struct bnode *root1=root;
	if(root==NULL)
	{
		return root1;
	}
	else
	{
		inorder(root->left);
		printf("\n the data for the inorder:%d",root->data);
		inorder(root->right);
	}
}
int main()
{
	struct bnode *root,*root1;
	root=create();
	inorder(root);
	root1=mirror(root);
	printf("\n\n\n");
	inorder(root1);
}
