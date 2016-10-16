#include <stdio.h> 
#include <stdlib.h>

#define MAXQSIZE 100

typedef int ElemType;

typedef struct {
	ElemType *base;
	int front;
	int rear;
}Queue;

int InitQueue( Queue *Q ){
	Q->base = (ElemType *)malloc(MAXQSIZE * sizeof(ElemType)) ;
	if(!Q->base) exit(0);
	Q->front = Q->rear = 0;
	return 1;
}

int EnQueue( Queue *Q, ElemType e ){
	Q->base[Q->rear] = e;
	Q->rear++;
	return 1;
}

int DeQueue( Queue *Q, ElemType *e){
	*e = Q->base[Q->front];
	Q->front++;
	return 1;
}

int QueueTraverse( Queue Q){
	printf("Queue:");
	while(Q.front < Q.rear){
		printf("%d  ", Q.base[Q.front]);
		Q.front++;
	}
	printf("\n");
	return 1;
}

void main(){
	int e;
	Queue Q;
	InitQueue(&Q);
	EnQueue(&Q, 11);
	EnQueue(&Q, 22);
	EnQueue(&Q, 33);
	EnQueue(&Q, 44);
	EnQueue(&Q, 55);
	QueueTraverse(Q);
	DeQueue( &Q, &e );
	printf("e=%d\n",e);
	QueueTraverse(Q);
}
