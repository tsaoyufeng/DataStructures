#include<stdio.h> 
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int bool;
typedef int E;
typedef struct NODE {
	struct NODE *next; //next pointer field
	int data; //data field
} Node, *LinkedList;


//
LinkedList initLinkedList(){
	LinkedList head = (LinkedList)malloc(sizeof(Node));
	if (head == NULL) {
		exit(0);
	}
	head->next = NULL;
	return head;
}

bool add(LinkedList L, E element) {
	LinkedList new_node = (LinkedList)malloc(sizeof(Node));
	if (new_node == NULL) {
		exit(0);
	}
	LinkedList cursor = L;
	while (cursor->next != NULL) {
		cursor = cursor->next;	
	}
	new_node->next = NULL;
	new_node->data = element;
	cursor->next = new_node;
	return TRUE;
}



bool addFirst(LinkedList L, E element) {
	LinkedList new_node = (LinkedList)malloc(sizeof(Node));
	if (new_node == NULL) {
		exit(0);
	}
	new_node->data = element;
	new_node->next = L->next;
	L->next = new_node;
	return TRUE;
}



bool insert(LinkedList L, int index, E element) {
	LinkedList cursor;
	cursor = L;
	for (int i = 0; i < index; i++) {
		cursor = cursor->next;
	}
	LinkedList new_node = (LinkedList)malloc(sizeof(Node));
	new_node->data = element;
	new_node->next = cursor->next;
	cursor->next = new_node;
	return TRUE;
}



void clear(LinkedList L) {
	LinkedList p = L->next;
	LinkedList q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}



E get(LinkedList L, int index) {
	LinkedList cursor = L;
	for (int i = 0; i <= index; i++){
		cursor = cursor->next;
	}
	return cursor->data;
}

int size(LinkedList L) {
	int i = 0;
	LinkedList cursor = L->next;
	while (cursor) {
		cursor = cursor->next;
		++i;
	}
	return i;
}

int indexOf(LinkedList L, E element) {
	LinkedList cursor = L;
	for (int i = 0; i < size(L); i++) {
		cursor = cursor->next;
		if (cursor->data == element) {
			return i;
		}
	}
	return -1;
}



E del(LinkedList L, int index) {
	LinkedList cursor = L;
	for (int i = 0; i < index; i++){
		cursor = cursor->next;
	}
	E del = cursor->next->data;
	cursor->next = cursor->next->next;
	return del;
}



E set(LinkedList L, int index, E element){
	LinkedList cursor = L;
	for (int i = 0; i <= index; i++){
		cursor = cursor->next;
	}
	E pre = cursor->data;
	cursor->data = element;
	return pre;
}



bool isEmpty(LinkedList L) {
	if (L->next == NULL) {
		return TRUE;
	}
	return FALSE;
}


bool destroy(LinkedList L) {
	clear(L);
	free(L);
	return TRUE;
}



void printList(LinkedList L) {
	LinkedList cursor = L->next;
	while (TRUE) {
		printf("%d", cursor->data);
		cursor = cursor->next;
		if(cursor->next == NULL) {
			printf("%d", cursor->data);
			break;
		}
	}
	printf("\n");
}



void main(){
	LinkedList L = initLinkedList();
	insert(L, 0, 5);
	insert(L, 0, 4);
	insert(L, 0, 3);
	insert(L, 0, 2);
	printList(L);
	add(L, 6);
	add(L, 7);
	add(L, 8);
	add(L, 9);
	printList(L);
	addFirst(L, 1);
	addFirst(L, 0);
	printList(L);
	printf("get=%d\n",get(L, 9));
	set(L, 4, 0);
	printList(L);
	printf("size=%d\n", size(L));
	del(L, 4);
	printList(L);
	printf("indexof9=%d\n", indexOf(L, 9));
	clear(L);
	printf("size=%d\n", size(L));
}


