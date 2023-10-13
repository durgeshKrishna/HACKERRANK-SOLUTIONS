/*#include <stdio.h>
#include <stdlib.h>

// Data structure to store a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to perform inorder traversal on the tree
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to check if a given node is a leaf node or not
int isLeaf(struct Node* node) {
    return (node->left == NULL && node->right == NULL);
}

// Function to convert a binary tree into a full tree by removing half nodes
struct Node* truncate(struct Node* root) {
    // base case: empty tree
    if (root == NULL) {
        return NULL;
    }

    // recursively truncate the left and right subtrees first
    root->left = truncate(root->left);
    root->right = truncate(root->right);

    // do nothing if the current node is a leaf node or has two children
    if ((root->left && root->right) || isLeaf(root)) {
        return root;
    }

    // if the current node has exactly one child, delete it and replace
    // it with the child node
    struct Node* child = (root->left) ? root->left : root->right;
    free(root);
    return child;
}

// Function to create a binary tree from user input
struct Node* create() {
    int x;
    struct Node* new = NULL;
    printf("\nEnter the data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1) {
        return NULL;  // Return NULL to indicate no node
    }

    new = (struct Node*)malloc(sizeof(struct Node));
    new->data = x;

    printf("\nEnter the data (left child) for %d: ", x);
    new->left = create();

    printf("\nEnter the data (right child) for %d: ", x);
    new->right = create();

    return new;
}

int main() {
    struct Node* root = NULL;
    printf("-1 for no node");
    root = create();

    if (root == NULL) {
        printf("\nTree is empty.\n");
    } else {
        printf("\nInorder traversal of the binary tree:\n");
        inorder(root);
    }

    // Convert the tree into a full tree and perform other operations if needed

    // Clean up the tree (free memory) if needed

    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left, * right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void printInoder(struct node* root)
{
    if (root != NULL)
    {
        printInoder(root->left);
        printf("%d ", root->data);
        printInoder(root->right);
    }
}

// Removes all nodes with only one child and returns
// new root (note that root may change)
struct node* RemoveHalfNodes(struct node* root)
{
    if (root == NULL)
        return NULL;

    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);

    if (root->left == NULL && root->right == NULL)
        return root;

    /* if current nodes is a half node with left
    child NULL left, then its right child is
    returned and replaces it in the given tree */
    if (root->left == NULL)
    {
        struct node* new_root = root->right;
        free(root); // To avoid memory leak
        return new_root;
    }

    /* if current nodes is a half node with right
    child NULL right, then its right child is
    returned and replaces it in the given tree */
    if (root->right == NULL)
    {
        struct node* new_root = root->left;
        free(root); // To avoid memory leak
        return new_root;
    }

    return root;
}

// Data structure to store a binary tree node
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a binary tree from user input
struct Node* create()
{
    int x;
    struct Node* new;
    new = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the data (-1 for no node): ");
    scanf("%d", &x);

    if (x == -1)
    {
        return NULL;  // Return NULL to indicate no node
    }

    new->data = x;
    printf("\nEnter the data (left child) for %d: ", x);
    new->prev = create();
    printf("\nEnter the data (right child) for %d: ", x);
    new->next = create();
    return new;
}

int main()
{
    struct Node* root;
    struct node* NewRoot = NULL;
    printf("-1 for no node");
    root = create();

    if (root == NULL)
    {
        printf("\nTree is empty.\n");
    }
    else
    {
        printf("\nInorder traversal of the binary tree:\n");
        printInoder(root);
    }

    // Convert the tree into a full tree
    NewRoot = RemoveHalfNodes(root);

    printf("\nInorder traversal of the modified tree:\n");
    printInoder(NewRoot);

    // Clean up the binary tree (free memory) if needed
    // Clean up the modified tree (free memory) if needed

    return 0;
}

