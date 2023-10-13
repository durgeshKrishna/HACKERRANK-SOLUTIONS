#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Data structure to store a binary tree node
struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Function to check if each node of a binary tree has exactly one child
bool isSkewedTree(struct Node* root)
{
    // Base case: empty tree
    if (root == NULL) {
        return true;
    }

    // Return false if both the left child and the right child
    // exist for a node
    if (root->left && root->right) {
        return false;
    }

    // Recur for the left and right subtrees
    return isSkewedTree(root->left) && isSkewedTree(root->right);
}

int main()
{
    struct Node* root = newNode(15);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->left->left = newNode(18);
    root->right->left->right=newNode(20);
    root->right->left->left->right = newNode(20);

    bool isSkewed = isSkewedTree(root);
    if (isSkewed) {
        printf("The binary tree is skewed\n");
    }
    else {
        printf("The binary tree is not skewed\n");
    }

    return 0;
}

