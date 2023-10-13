#include <stdio.h>
#include <stdlib.h>

// Data structure to store a binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find the total number of nodes in a binary tree
int size(struct Node* root)
{
    if (root == NULL) {
        return 0;
    }

    return 1 + size(root->left) + size(root->right);
}

// Function to check if a given binary tree is a complete binary tree
// and each node has a higher value than its parent
int isHeap(struct Node* root, int i, int n)
{
    // base case
    if (root == NULL) {
        return 1;
    }

    // not a complete binary tree: out of valid index range
    if (i >= n) {
        return 0;
    }

    // current node has a higher value than its left or right child
    if ((root->left && root->left->data <= root->data) ||
        (root->right && root->right->data <= root->data)) {
        return 0;
    }

    // check for left and right subtree
    return isHeap(root->left, 2 * i + 1, n) && isHeap(root->right, 2 * i + 2, n);
}

// Function to check if a given binary tree is a min-heap or not
int isMinHeap(struct Node* root)
{
    int i = 0;
    return isHeap(root, i, size(root));
}

int main()
{
    /* Construct the following tree
               2
             /   \
            /     \
           3       4
          / \     / \
         /   \   /   \
        5     6 8    10
    */

    struct Node* root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
    root->right->left = newNode(8);
    root->right->right = newNode(1);

    if (isMinHeap(root)) {
        printf("The given binary tree is a min-heap");
    }
    else {
        printf("The given binary tree is not a min-heap");
    }

    return 0;
}

