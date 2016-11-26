/*****************************************************************************
 * An array implementation of a stack.
 *
 *****************************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_CAPACITY 10//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量 
#define TRUE 1;
#define FALSE 0;

typedef int E;
typedef int bool;
 
 
typedef struct{
	E *base;	//array
	int top;	//reference to the top element
	int maxsize;
} ArrayStack;

/**
  * Creates a Stack of the size initialCapacity
  */
ArrayStack initArrayStack() {
	ArrayStack S;
	S.base = (E *)malloc(STACK_INIT_CAPACITY * sizeof(E));
	S.maxsize = STACK_INIT_CAPACITY;
	S.top = -1;
	return S;
}

/**
  * Tests if the stack is empty.
  */
bool isEmpty(ArrayStack S) {
	return S.top == -1;
}

/**
  * Returns the top item without its removal.
  */
E peek(ArrayStack S) {
	if (isEmpty(S)) {
		printf("Stack is empty");
		exit(0);
	}
	return S.base[S.top];
}

/**
  * Removes and returns the item at the top of this stack.
  */
E pop(ArrayStack *S) {
	E e = peek(*S);
	S->base[S->top] = NULL;
	S->top--;
	return e;
}

/**
  * Inserts an item onto the top of the stack.
  */
void push(ArrayStack *S, E element) {
	if (S->top == S->maxsize - 1) {
		S->base = (E *)realloc(S->base, (S->maxsize + STACKINCREMENT) * sizeof(E));
		S->maxsize = S->maxsize + STACKINCREMENT;
	}
	S->top++;
	S->base[S->top] = element;
}

/**
  * Removes all items from the Stack.
  */
void clear(ArrayStack *S) {
	for (int i = 0; i <= S->top; i++) {
		S->base[i] = NULL;
	}
	S->top = -1;
}

void destroy(ArrayStack *S) {
	clear(S);
	free(S->base);
}

void printStack(ArrayStack S) {
	printf("ArrayStack:");
	for (int i = 0; i <= S.top; i++) {
		printf("%d", S.base[i]);
	}
	printf("\n");
}

void main(){
	ArrayStack S = initArrayStack();
	for (int i = 0; i <= 9; i++) {
		push(&S, i);
	}
	printStack(S);
	pop(&S);
	pop(&S);
	printStack(S);
	printf("isEmpty=%d\n", isEmpty(S));
	printf("peek=%d\n", peek(S));
	clear(&S);
	printf("isEmpty=%d\n", isEmpty(S));
}


