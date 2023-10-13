#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

bool isCompleteBT(struct node* root)
{
	if (root == NULL)
		return true;
	struct node* queue[1000];
	int front = 0, rear = 0;
	bool flag = false;
	queue[rear++] = root;
	while (front < rear)
	{
		struct node* temp = queue[front++];
		if (temp == NULL)
		{
			flag = true;
		}
		else
		{
			if (flag == true)
				return false;
			queue[rear++] = temp->left;
			queue[rear++] = temp->right;
		}
	}
	return true;
}
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);
	if (isCompleteBT(root))
		printf("Complete Binary Tree\n");
	else
		printf("NOT Complete Binary Tree\n");

	return 0;
}
