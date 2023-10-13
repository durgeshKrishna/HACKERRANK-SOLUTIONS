#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createTree() {
    int x;
    struct TreeNode* new = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!new) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("\nEnter the data: ");
    scanf("%d", &x);
    if (x == -1) {
        free(new);
        return NULL;
    }

    new->val = x;

    printf("\nEnter the data -left child for the %d (-1 for no left child): ", x);
    new->left = createTree();

    printf("\nEnter the data -right child for the %d (-1 for no right child): ", x);
    new->right = createTree();

    return new;
}
bool isValidBST(struct TreeNode* root, struct TreeNode* minNode, struct TreeNode* maxNode) {
    if (root == NULL)
        return true;
    if (minNode && root->val <= minNode->val)
        return false;
    if (maxNode && root->val >= maxNode->val)
        return false;

    return isValidBST(root->left, minNode, root) &&
           isValidBST(root->right, root, maxNode);
}
bool isBST(struct TreeNode* root) {
    return isValidBST(root, NULL, NULL);
}
int main() {
    struct TreeNode* root = NULL;
    printf("-1 for no child\n");
    root = createTree();
    if (isBST(root)) {
        printf("The binary tree is a valid BST.\n");
    } else {
        printf("The binary tree is not a valid BST.\n");
    }


    return 0;
}

