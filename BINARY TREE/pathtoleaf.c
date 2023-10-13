#include <stdio.h>
#include <stdlib.h>

// Data structure to store a binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to check if a given node is a leaf node or not
int isLeaf(struct Node* node)
{
    return (node->left == NULL && node->right == NULL);
}

// Recursive function to find and print paths from the root node to every leaf node
void printRootToLeafPaths(struct Node* node, int path[], int pathLen)
{
    // base case
    if (node == NULL) {
        return;
    }

    // include the current node in the path
    path[pathLen] = node->data;
    pathLen++;

    // if a leaf node is found, print the path
    if (isLeaf(node))
    {
    	int i;
        for ( i = 0; i < pathLen; i++) {
            printf("%d", path[i]);
            if (i < pathLen - 1) {
                printf(" —> ");
            }
        }
        printf("\n");
    }

    // recur for the left and right subtree
    printRootToLeafPaths(node->left, path, pathLen);
    printRootToLeafPaths(node->right, path, pathLen);
}

// The main function to print paths from the root node to every leaf node
void printRootToLeafPathsWrapper(struct Node* node)
{
    // array to store root-to-leaf path
    int path[1000];
    printRootToLeafPaths(node, path, 0);
}

// Function to create a binary tree using user input
struct Node* createBinaryTree()
{
    struct Node* root = NULL;
    int x;
    printf("Enter the data for the root node (-1 to stop): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;
    }

    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;

    printf("Enter left child for %d:\n", x);
    root->left = createBinaryTree();

    printf("Enter right child for %d:\n", x);
    root->right = createBinaryTree();

    return root;
}

int main()
{
    printf("Binary Tree Construction:\n");
    struct Node* root = createBinaryTree();

    if (root != NULL) {
        printf("\nRoot-to-Leaf Paths in Desired Fashion:\n");
        printRootToLeafPathsWrapper(root);
    }
    else {
        printf("Empty tree.\n");
    }

    // Clean up the tree (free memory) if needed

    return 0;
}

