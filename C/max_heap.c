#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct MaxHeap {
  int *data;
  int size;
  int capacity;
} MaxHeap;

MaxHeap *createHeap(int capacity) {
  MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
  heap->capacity = capacity;
  heap->data = (int *)malloc(capacity * sizeof(int));
  heap->size = 0;
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

// void heapify_up(MaxHeap *heap, int index) {
//   while (index != 0 && heap->data[getParent(index)] < heap->data[index]) {
//     swap(&heap->data[getParent(index)], &heap->data[index]);
//     index = getParent(index);
//   }
// }
//
// recursive heapify_up

void heapify_up(MaxHeap *heap, int index) {
  if (index == 0)
    return;
  int parent = getParent(index);
  if (heap->data[parent] < heap->data[index]) {
    swap(&heap->data[parent], &heap->data[index]);
    heapify_up(heap, parent);
  }
}

void insert(MaxHeap *heap, int value) {
  if (heap->size == heap->capacity) {
    printf("Heap is full\n");
    return;
  }
  heap->data[heap->size] = value;
  heapify_up(heap, heap->size);
  heap->size++;
}

void heapifyDown(MaxHeap *heap, int index) {
  int largest = index;
  int left = getLeft(index);
  int right = getRight(index);
  if (left < heap->size && heap->data[largest] < heap->data[left]) {
    largest = left;
  }
  if (right < heap->size && heap->data[largest] < heap->data[right]) {
    largest = right;
  }
  if (largest != index) {
    swap(&heap->data[largest], &heap->data[index]);
    heapifyDown(heap, largest);
  }
}

int extractMax(MaxHeap *heap) {
  // checking if heap is empty;
  if (heap->size <= 0)
    return -1;
  int max = heap->data[0];
  heap->data[0] = heap->data[heap->size - 1];
  heap->size--;
  heapifyDown(heap, 0);
  return max;
}

void peek(MaxHeap *heap) {
  int top = heap->data[0];
  printf("%d \n", top);
}

int main() {
  MaxHeap *heap = createHeap(10);
  insert(heap, 10);
  insert(heap, 2000);
  insert(heap, 300);
  insert(heap, 2345);
  insert(heap, 1);
  peek(heap);
  extractMax(heap);
  peek(heap);
}
