/*****************************************************************************
 * A linked list-based implementation of a stack.
 *
 *****************************************************************************/
 
#include <stdio.h> 
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef int E;
typedef int bool;

typedef struct NODE{
	E data;
	struct NODE *next;
}Node, *ListStack;

/**
  * Creates a Stack
  */
ListStack initListStack(){
	ListStack top = NULL;
	return top;
}

/**
  * Tests if the stack is empty.
  */
bool isEmpty(ListStack s) {
	return s == NULL;
}

/**
  * Inserts a new item into the stack.
  */
ListStack push( ListStack s, E element ) {
	ListStack new_node = (ListStack)malloc(sizeof(Node));
	if(new_node == NULL) {
		exit(0);
	}
	new_node->data = element;
	new_node->next = s;
	s = new_node;
	return s;
}


ListStack pop(ListStack s) {
	if (isEmpty(s)) {
		printf("Stack is empty");
		exit(0);
	}
	ListStack temp = s;
	s = s->next;
	free(temp);
	return s;
}

E peek(ListStack s) {
	if (isEmpty(s)) {
		printf("Stack is empty");
		exit(0);
	}
	return s->data;
}

ListStack clear(ListStack s) {
	if (isEmpty(s)) {
		printf("Stack is empty");
		exit(0);
	}
	ListStack p = s;
	ListStack q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	s = NULL;
	return s;
}


void printStack(ListStack s) {
	if (isEmpty(s)) {
		printf("Stack is empty");
		exit(0);
	}
	printf("ListStack:");
	while(s) {
		printf("%d", s->data);
		s = s->next;
	}
	printf("\n");
}

void main(){
	ListStack s = initListStack();
	s = push(s, 3);
	s = push(s, 4);
	s = push(s, 5);
	s = push(s, 6);
	printf("isEmpty=%d\n", isEmpty(s));
	printf("peek=%d\n", peek(s));
	s = pop(s);
	printf("peek=%d\n", peek(s));
	printStack(s);
	s = clear(s);
	printf("isEmpty=%d\n", isEmpty(s));	
}
