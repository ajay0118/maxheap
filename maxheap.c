#include <stdio.h>

#define MAX_SIZE 100

struct MaxHeap {
    int arr[MAX_SIZE];
    int size;
};

void initializeHeap(struct MaxHeap *heap) {
    heap->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MaxHeap *heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap->arr[index] > heap->arr[parent]) {
        swap(&heap->arr[index], &heap->arr[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(struct MaxHeap *heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heap->size && heap->arr[leftChild] > heap->arr[largest]) {
        largest = leftChild;
    }

    if (rightChild < heap->size && heap->arr[rightChild] > heap->arr[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&heap->arr[index], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

void insert(struct MaxHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full! Cannot insert %d\n", value);
    } else {
        heap->arr[heap->size] = value;
        heapifyUp(heap, heap->size);
        heap->size++;
        printf("%d inserted into the heap\n", value);
    }
}

int extractMax(struct MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty! Cannot extract maximum\n");
        return -1; // Return an error value
    } else {
        int maxValue = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapifyDown(heap, 0);
        return maxValue;
    }
}

void display(struct MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
    } else {
        printf("Heap elements: ");
        for (int i = 0; i < heap->size; ++i) {
            printf("%d ", heap->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct MaxHeap maxHeap;
    initializeHeap(&maxHeap);

    int choice, value;

    do {
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&maxHeap, value);
                break;
            case 2:
                value = extractMax(&maxHeap);
                if (value != -1) {
                    printf("Extracted maximum value: %d\n", value);
                }
                break;
            case 3:
                display(&maxHeap);
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

