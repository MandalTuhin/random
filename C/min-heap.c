// creating the heap structure;
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct MinHeap {
  int *data;
  int capacity;
  int size;
} MinHeap;

MinHeap *createHeap(int capacity) {
  MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
  heap->capacity = capacity;
  heap->size = 0;
  heap->data = (int *)malloc(sizeof(int) * capacity);
  return heap;
}

int getParent(int i) { return (i - 1) / 2; }
int getLeft(int i) { return 2 * i + 1; }
int getRight(int i) { return 2 * i + 2; }

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
  while (index > 0 && heap->data[getParent(index)] > heap->data[index]) {
    swap(&heap->data[index], &heap->data[getParent(index)]);
    index = getParent(index);
  }
}

void insert(MinHeap *heap, int value) {
  if (heap->size == heap->capacity) {
    printf("Heap is Full\n");
    return;
  }
  heap->data[heap->size] = value;
  heapifyUp(heap, heap->size);
  heap->size++;
}

// Extract Min + Heapify Down

void heapifyDown(MinHeap *heap, int index) {
  int smallest = index;
  int left = getLeft(index);
  int right = getRight(index);

  if (left < heap->size && heap->data[left] < heap->data[smallest])
    smallest = left;
  if (right < heap->size && heap->data[right] < heap->data[smallest])
    smallest = right;

  if (smallest != index) {
    swap(&heap->data[index], &heap->data[smallest]);
    heapifyDown(heap, smallest);
  }
}

int extractMin(MinHeap *heap) {
  if (heap->size <= 0)
    return -1;

  int root = heap->data[0];
  heap->data[0] = heap->data[heap->size - 1];
  heap->size--;
  heapifyDown(heap, 0);
  return root;
}

int main() {
  MinHeap *heap = createHeap(10);
  insert(heap, 10);
  insert(heap, 5);
  insert(heap, 15);
  insert(heap, 3);

  printf("Extracted Min: %d\n", extractMin(heap)); // should be 3
  printf("Extracted Min: %d\n", extractMin(heap)); // should be 5
}
