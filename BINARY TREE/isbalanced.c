#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

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
    new->prev = create();

    printf("\nEnter the data (right child) for %d: ", x);
    new->next = create();

    return new;
}

// Function to check if a binary tree is balanced
int maxDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->prev);
    int rightDepth = maxDepth(root->next);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

bool isBalanced(struct Node* root) {
    if (root == NULL) {
        return true;
    }

    int leftDepth = maxDepth(root->prev);
    int rightDepth = maxDepth(root->next);

    if (abs(leftDepth - rightDepth) <= 1 && isBalanced(root->prev) && isBalanced(root->next)) {
        return true;
    }

    return false;
}

int main() {
    struct Node* root = NULL;
    printf("-1 for no node");
    root = create();

    if (isBalanced(root)) {
        printf("\nThe binary tree is balanced.\n");
    } else {
        printf("\nThe binary tree is not balanced.\n");
    }

    // Clean up the tree (free memory) if needed

    return 0;
}

