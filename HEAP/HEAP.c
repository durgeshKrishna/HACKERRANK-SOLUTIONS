#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int arr[MAX_SIZE];
int n = 0; // Start with index 1
void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
void Heap(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && A[left] > A[largest]) {
        largest = left;
    }
    if (right <= n && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(A, i, largest);
        Heap(A, n, largest);
    }
}
void BuildHeap(int A[], int n) {
    int i;
    for (i = n / 2; i >= 1; i--) {
        Heap(A, n, i);
    }
}
int DeleteRoot(int A[]) {
    if (n == 0) {
        printf("Heap is empty. Cannot delete.\n");
        return -1;
    }
    int deletedElement = A[1];
    A[1] = A[n];
    n--;
    Heap(A, n, 1);
    return deletedElement;
}
int DeleteNode(int A[], int node) {
    int i;
    for (i = 1; i <= n; i++) {
        if (node == A[i]) {
            break;
        }
    }
    if (i == n + 1) {
        printf("Node not found in the heap.\n");
        return -1;
    }
    int deletedElement = A[i];
    A[i] = A[n];
    n--;
    Heap(A, n, i);
    return deletedElement;
}

void IncKey(int A[], int node) {
    int i;
    for (i = 1; i <= n; i++) {
        if (node == A[i]) {
            break;
        }
    }
    if (i == n + 1) {
        printf("Node not found in the heap.\n");
        return;
    }
    int key;
    printf("\nEnter the key to increase: ");
    scanf("%d", &key);
    A[i] = A[i] + key;
    BuildHeap(A, n);
}

void DecKey(int A[], int node) {
    int i;
    for (i = 1; i <= n; i++) {
        if (node == A[i]) {
            break;
        }
    }
    if (i == n + 1) {
        printf("Node not found in the heap.\n");
        return;
    }
    int key;
    printf("\nEnter the key to decrease: ");
    scanf("%d", &key);
    A[i] = A[i] - key;
    BuildHeap(A, n);
}

void Print(int A[], int n) {
    int i;
    printf("Heap: [");
    for (i = 1; i <= n; i++) {
        printf("%d", A[i]);
        if (i < n) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete root node and heapify\n");
        printf("3. Delete a specific node and heapify\n");
        printf("4. Increase key\n");
        printf("5. Decrease key\n");
        printf("6. Display the heap\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (n >= MAX_SIZE) {
                    printf("Heap is at maximum capacity (%d). Cannot insert more elements.\n", MAX_SIZE);
                } else {
                    printf("Enter the element to insert: ");
                    int key;
                    scanf("%d", &key);
                    n++;
                    arr[n] = key;
                    BuildHeap(arr, n);
                    printf("Element inserted successfully.\n");
                }
                break;
            case 2:
                if (n > 0) {
                    int deletedElement = DeleteRoot(arr);
                    printf("Deleted root element: %d\n", deletedElement);
                } else {
                    printf("Heap is empty. Cannot delete.\n");
                }
                break;
            case 3:
                printf("Enter the element to delete: ");
                int nodeToDelete;
                scanf("%d", &nodeToDelete);
                if (n > 0) {
                    int deletedElement = DeleteNode(arr, nodeToDelete);
                    if (deletedElement != -1) {
                        printf("Deleted element: %d\n", deletedElement);
                    }
                } else {
                    printf("Heap is empty. Cannot delete.\n");
                }
                break;
            case 4:
                printf("Enter the node to increase key: ");
                int nodeToInc;
                scanf("%d", &nodeToInc);
                if (n > 0) {
                    IncKey(arr, nodeToInc);
                } else {
                    printf("Heap is empty. Cannot increase key.\n");
                }
                break;
            case 5:
                printf("Enter the node to decrease key: ");
                int nodeToDec;
                scanf("%d", &nodeToDec);
                if (n > 0) {
                    DecKey(arr, nodeToDec);
                } else {
                    printf("Heap is empty. Cannot decrease key.\n");
                }
                break;
            case 6:
                Print(arr, n);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    return 0;
}

