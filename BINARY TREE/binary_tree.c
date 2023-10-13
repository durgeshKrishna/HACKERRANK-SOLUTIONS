#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};
struct Node* create(){
	int x;
	struct Node* new;
	new=(struct Node*)malloc(sizeof(struct Node));
	printf("\nEnter the data :");
	scanf("%d",&x);
	if(x==-1){
	  return 0;
	}
	new->data=x;
	printf("\n Enter the data -left child for the %d :",x);
	new->prev=create();
	printf("\n Enter the data -right child for the %d :",x);
	new->next=create();
	return new;
}
int main(){
	struct Node* root;
	printf("-1 for no node");
	root=create();
}
