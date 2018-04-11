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

void insert_first(ListNode **phead, ListNode *node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}
void insert_last(ListNode **phead, ListNode *node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
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
	p = p->link;
	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d->", p->data);
	p = p->link;
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
	insert_first(&list1, create_node(10, NULL));
	insert_first(&list1, create_node(20, NULL));
	insert_last(&list1, create_node(30, NULL));
	display(list1);
	return 0;
}