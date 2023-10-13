#include <stdio.h>
#include <stdlib.h>

// Data structure to store a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform inorder traversal on the tree
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Function to build a binary tree from the given parent array
struct Node* createTree(int parent[], int n) {
    
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(i);
    }
   struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = nodes[i];
        } else {
            if (nodes[parent[i]]->left == NULL) {
                nodes[parent[i]]->left = nodes[i];
            } else {
                nodes[parent[i]]->right = nodes[i];
            }
        }
    }

    return root;
}

int main() {
    int n;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    int parent[n];
    printf("Enter the parent array (use -1 for root and space-separated values): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
    }
    struct Node* root = createTree(parent, n);
    printf("Inorder traversal of the binary tree: ");
    inorder(root);
	return 0;
}
