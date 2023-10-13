#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bnode {
    char data[3]; 
    struct bnode* left;
    struct bnode* right;
};
struct bnode* create() {
    struct bnode* node;
    node = (struct bnode*)malloc(sizeof(struct bnode));
    char ele[3]; 
    printf("\nEnter the data for the binary tree (-1 to stop):");
    scanf("%s", ele);
    if (strcmp(ele, "-1") == 0) { 
        printf("\nNo child is created");
        return NULL;
    }
    strcpy(node->data, ele);
    printf("\nThe left child of the binary tree (%s):", ele);
    node->left = create();
    printf("\nThe right child of the binary tree (%s):", ele);
    node->right = create();
    return node;
}
int isOperator(char* str) {
    return (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 || strcmp(str, "/") == 0);
}
int evaluate(struct bnode* root) {
    if (root == NULL) {
        return 0;
    }
    if (!isOperator(root->data)) {
         return atoi(root->data);
    }
    int leftValue = evaluate(root->left);
    int rightValue = evaluate(root->right);
	 if (strcmp(root->data, "+") == 0) {
        return leftValue + rightValue;
    } else if (strcmp(root->data, "-") == 0) {
        return leftValue - rightValue;
    } else if (strcmp(root->data, "*") == 0) {
        return leftValue * rightValue;
    } else if (strcmp(root->data, "/") == 0) {
        if (rightValue != 0) {
            return leftValue / rightValue;
        } else {
            printf("Error: Division by zero\n");
            exit(1);
        }
    }
    return 0;
}
int main() {
    struct bnode* root = NULL;
    int result;
    root = create();
    result = evaluate(root);
    printf("\nResult: %d\n", result);
    return 0;
}

