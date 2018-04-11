#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct LisNode *link;
}ListNode;

ListNode *create_node(element data, ListNode *link) {	//노드를 동적 생성
	ListNode *new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL);
	new_node->data = data;
	new_node->link = link;
	return new_node;
}

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) {
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) {
		new_node->link = *phead;
		*phead = new_node;
	}
	else {
		new_node->link = p;
		p->link = new_node;
	}
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed) {
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

void display(ListNode *head){
	ListNode *p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}

void display_recur(ListNode *head) {
	ListNode *p = head;
	if (p != NULL) {
		printf("%d->", p->data);
		display_recur(p->link);
	}
}

ListNode *search(ListNode *head, int x) {
	ListNode *p = head;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->link;
	}
	return p;
}

ListNode *concat(ListNode *head1, ListNode *head2) {
	ListNode *p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL)return head1;
	else {
		p = head1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
		return head1;
	}
}

int main(void) {
	ListNode *list1 = NULL;
	ListNode *list2 = NULL;
	ListNode * p;

	insert_node(&list1, NULL, create_node(10, NULL));
	insert_node(&list1, NULL, create_node(20, NULL));
	insert_node(&list1, NULL, create_node(30, NULL));
	display(list1);

	remove_node(&list1, NULL, list1);
	display(list1);

	insert_node(&list2, NULL, create_node(60, NULL));
	insert_node(&list2, NULL, create_node(70, NULL));
	insert_node(&list2, NULL, create_node(80, NULL));
	display(list2);

	list1 = concat(list1, list2);
	display_recur(list1);
	printf("\n");

	p = search(list1, 20);
	printf("%d\n", p->data);

	return 0;
}