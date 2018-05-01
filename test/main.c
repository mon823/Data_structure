#include<stdio.h>

#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

init(HeapType *h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType *h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) {
			child++;
		}
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void print_heap(HeapType *h) {
	int i;
	for (i = 1; i <= h->heap_size; i++) {
		printf("%d \n", h->heap[i]);
	}
}

void heap_sort(element a[], int n) {
	int i;
	HeapType h;

	init(&h);
	for (i = 0; i < n; i++) {
		insert_max_heap(&h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(&h);
	}
}


void main(void) {
	int i, arr[101];
	for (i = 0; i < 100; i++) {
		arr[i] = 100 - i ;
	}
	for (i = 0; i < 100; i++) {
		printf("%d \n", arr[i]);
	}
	printf("-------------------------------------------------------------\n");
	heap_sort(arr, 100);
	for (i = 0; i < 100; i++) {
		printf("%d \n", arr[i]);
	}
	printf("-------------------------------------------------------------\n");
}