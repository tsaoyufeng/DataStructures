#include <stdio.h> 
#include <stdlib.h>

typedef int ElemType;

typedef struct node {
	ElemType data;
	struct node *next;
}Node, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
} LinkQueue;

int InitQueue( LinkQueue *Q ){
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(Node));
	if(!Q->front) exit(0) ;
	(Q->front)->next = NULL;
	return 1;
}

int EnQueue( LinkQueue *Q, ElemType e ){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(Node));
	if(!p) exit(0);
	p->data = e;
	p->next = NULL;
	(Q->rear)->next = p;
	Q->rear = p;
	return 1;
}

int DeQueue( LinkQueue *Q, ElemType *e ){
	QueuePtr p;
	if(Q->front == Q->rear) return 0;
	p = (Q->front)->next;
	*e = p->data;
	(Q->front)->next = p->next;
	if(Q->rear == p) Q->rear = Q->front;
	free(p);
	return 1;
}

int QueueTraverse( LinkQueue Q ){
	while(Q.front < Q.rear){
		printf("%d\t", (Q.front->next)->data);
		Q.front = Q.front->next;
	}
}

void main(){
	LinkQueue Q;
	InitQueue(&Q);
	EnQueue(&Q,11);
	EnQueue(&Q,22);
	EnQueue(&Q,33);
	QueueTraverse(Q);
}
