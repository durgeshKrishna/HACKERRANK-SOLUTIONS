#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int heap[30];
int size = 0, choice = 0;
void swap(int a, int b) {
    int temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}
void minPercolateUp(int i) {
    while (i > 1) {
        int parent = floor(i / 2);
        if (heap[parent] > heap[i]) {
            swap(parent, i);
            i = parent;
        } else {
            break;
        }
    }
}
void minPercolateDown(int n, int i) {
    while (1) {
        int small = i;
        int l = 2 * i;
        int r = 2 * i + 1;
        if (l <= n && heap[l] < heap[small])
            small = l;
        if (r <= n && heap[r] < heap[small])
            small = r;
        if (small != i) {
            swap(i, small);
            i = small;
        } else {
            break;
        }
    }
}
void deleteRootMin() {
    if (size < 1) {
        printf("\n Heap is empty.");
        return;
    }

    heap[1] = heap[size];
    size--;
    minPercolateDown(size, 1);
}
void maxPercolateUp(int i) {
    while (i > 1) {
        int parent = floor(i / 2);
        if (heap[parent] < heap[i]) {
            swap(parent, i);
            i = parent;
        } else {
            break;
        }
    }
}
void maxPercolateDown(int n, int i) {
    while (1) {
        int large = i;
        int l = 2 * i;
        int r = 2 * i + 1;
        if (l <= n && heap[l] > heap[large])
            large = l;
        if (r <= n && heap[r] > heap[large])
            large = r;
        if (large != i) {
            swap(i, large);
            i = large;
        } else {
            break;
        }
    }
}
void deleteRootMax() {
    if (size < 1) {
        printf("\n Heap is empty.");
        return;
    }

    heap[1] = heap[size];
    size--;
    maxPercolateDown(size, 1);
}
void printHeap() {
    int i;
	for ( i = 1; i <= size; i++)
        printf("\n %d", heap[i]);
}
int main() {
    int n, ele,i, ch, ind, key;
    printf("\n Choose a heap type:\n 1->Min Heap\n 2->Max Heap\n");
    scanf("\n %d", &choice);

    switch (choice) {
        case 1: // Min Heap
            printf("\n Enter the number of elements to be inserted into the heap:");
            scanf("\n %d", &n);

            for ( i = 0; i < n; i++) {
                scanf("\n %d", &ele);
                size++;
                heap[size] = ele;
                minPercolateUp(size);
            }

            do {
                printf("\n 1->Insert\n 2->Delete Root\n 3->Build Heap\n 4->Increase Key\n 5->Decrease Key\n 6->Remove Key\n 7->Exit");
                printf("\n Enter the choice to be performed:");
                scanf("\n %d", &ch);

                switch (ch) {
                    case 1: // Insert
                        printf("\n Enter element to insert:");
                        scanf("\n %d", &ele);
                        size++;
                        heap[size] = ele;
                        minPercolateUp(size);
                        printf("\n The min heap:");
                        printHeap();
                        break;
                    case 2: // Delete Root
                        deleteRootMin();
                        printf("\n The min heap:");
                        printHeap();
                        break;
                    case 3: // Build Heap
                        printf("\n Enter element for building heap:");
                        scanf("\n %d", &ele);
                        heap[++size] = ele;
                        minPercolateUp(size);
                        printf("\n The min heap:");
                        printHeap();
                        break;
                    case 4: // Increase Key
                        printf("\n Enter index to modify:");
                        scanf("\n %d", &ind);
                        printf("\n Enter new key value:");
                        scanf("\n %d", &key);
                        heap[ind] = key;
                        minPercolateUp(ind);
                        printf("\n The min heap:");
                        printHeap();
                        break;
                    case 5: // Decrease Key
                        printf("\n Enter index to modify:");
                        scanf("\n %d", &ind);
                        printf("\n Enter new key value:");
                        scanf("\n %d", &key);
                        heap[ind] = key;
                        minPercolateDown(size, ind);
                        printf("\n The min heap:");
                        printHeap();
                        break;
                    case 6: // Remove Key
                        printf("\n Enter position to remove:");
                        scanf("\n %d", &key);
                        if (key < 1 || key > size) {
                            printf("\n Invalid position.");
                        } else {
                            heap[key] = INT_MIN;
                            minPercolateUp(key);
                            deleteRootMin();
                        }
                        printf("\n The min heap:");
                        printHeap();
                        break;
                    case 7: // Exit
                        break;
                    default:
                        printf("\n Invalid choice");
                }
            } while (ch != 7);

            break;

        case 2: // Max Heap
            printf("\n Enter the number of elements to be inserted into the heap:");
            scanf("\n %d", &n);

            for ( i = 0; i < n; i++) {
                scanf("\n %d", &ele);
                size++;
                heap[size] = ele;
                maxPercolateUp(size);
            }

            do {
                printf("\n 1->Insert\n 2->Delete Root\n 3->Build Heap\n 4->Increase Key\n 5->Decrease Key\n 6->Remove Key\n 7->Exit");
                printf("\n Enter the choice to be performed:");
                scanf("\n %d", &ch);

                switch (ch) {
                    case 1: // Insert
                        printf("\n Enter element to insert:");
                        scanf("\n %d", &ele);
                        size++;
                        heap[size] = ele;
                        maxPercolateUp(size);
                        printf("\n The max heap:");
                        printHeap();
                        break;
                    case 2: // Delete Root
                        deleteRootMax();
                        printf("\n The max heap:");
                        printHeap();
                        break;
                    case 3: // Build Heap
                        printf("\n Enter element for building heap:");
                        scanf("\n %d", &ele);
                        heap[++size] = ele;
                        maxPercolateUp(size);
                        printf("\n The max heap:");
                        printHeap();
                        break;
                    case 4: // Increase Key
                        printf("\n Enter index to modify:");
                        scanf("\n %d", &ind);
                        printf("\n Enter new key value:");
                        scanf("\n %d", &key);
                        heap[ind] = key;
                        maxPercolateUp(ind);
                        printf("\n The max heap:");
                        printHeap();
                        break;
                    case 5: // Decrease Key
                        printf("\n Enter index to modify:");
                        scanf("\n %d", &ind);
                        printf("\n Enter new key value:");
                        scanf("\n %d", &key);
                        heap[ind] = key;
                        maxPercolateDown(size, ind);
                        printf("\n The max heap:");
                        printHeap();
                        break;
                    case 6: // Remove Key
                        printf("\n Enter position to remove:");
                        scanf("\n %d", &key);
                        if (key < 1 || key > size) {
                            printf("\n Invalid position.");
                        } else {
                            heap[key] = INT_MAX;
                            maxPercolateUp(key);
                            deleteRootMax();
                        }
                        printf("\n The max heap:");
                        printHeap();
                        break;
                    case 7: // Exit
                        break;
                    default:
                        printf("\n Invalid choice");
                }
            } while (ch != 7);

            break;

        default:
            printf("\n Invalid choice");
            break;
    }

    return 0;
}

