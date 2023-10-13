//LCA
#include<stdio.h>
#include<stdlib.h>
struct bnode
{
 int data;
 struct bnode *lchild;
 struct bnode *rchild;
};
struct bnode *create()
{
 int x;
 struct bnode *new_node=(struct bnode *)malloc(sizeof(struct bnode *));
 printf("enter the data(-1 for NULL): ");
 scanf("%d",&x);
 if(x==-1)
 {
  return 0;
 }
 new_node->data=x;
 printf("\nenter the left child for %d: ",x);
 new_node->lchild=create();
 printf("\nenter the right child for %d: ",x);
 new_node->rchild=create();
 return new_node;
}
void printinorder(struct bnode *root)
{
 if(root!=NULL)
 {
  printinorder(root->lchild);
  printf("%d ",root->data);
  printinorder(root->rchild);
 }
}
struct bnode *LCA(struct bnode *root,int x,int y)
{
 if(root==NULL)
    return NULL; else if(root->data==x || root->data==y)
    return root;
 struct bnode *left=LCA(root->lchild,x,y);
 struct bnode *right=LCA(root->rchild,x,y);
 if(left!=NULL && right!=NULL)
    return root;
 else if(left!=NULL)
    return left;
 else//right!=NULL
    return right;
}
int main()
{
 int val1,val2;
 struct bnode *root=NULL;
 root=create();
 printf("inorder traversal of binary tree is: ");
 printinorder(root);
 printf("\nenter val1: ");
 scanf("%d",&val1);
 printf("\nenter val2: ");
 scanf("%d",&val2);
 struct bnode *res=LCA(root,val1,val2);
 printf("\nlowest common ancestor is: %d ",res->data);
 printf("\n");
 return 0;
}.
