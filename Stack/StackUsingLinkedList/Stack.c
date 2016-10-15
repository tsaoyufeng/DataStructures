#include <stdio.h> 
#include <stdlib.h>

typedef int ElemType;

typedef struct node{
	ElemType data;
	struct node *next;
}Node, *LinkList;

//��ʼ��ջ������һ��ͷָ�� 
int InitStack(LinkList L){
	L = NULL;
	return 1;
}

LinkList Push( LinkList L, ElemType e ) {
	LinkList temp = (LinkList)malloc(sizeof(Node));
	if(temp == NULL) exit(0);
	temp->data = e;
	temp->next = L;
	L = temp;//ͷָ����Զָ��ջ��Ԫ�أ�ջ��Ԫ����Զָ��NULL 
	return L;	
}

//��ջ��ջ��Ԫ����e���� 
int Pop( LinkList L, ElemType *e) {
	LinkList temp = L;
	*e = L->data;
	L = L->next;
	free(temp);
	return 1;
}

int StackTraverse( LinkList L){
	LinkList current;
	current = L;
	if(current != NULL){
		printf("Stack:");
		do{
			printf("%d  ", current->data);
			current = current->next;
		}while(current != NULL);
		printf("\n");
	}
}

void main(){
	LinkList L = NULL;
	InitStack( L );
	L = Push( L, 44);
	L = Push( L, 33);
	L = Push( L, 22);
	L = Push( L, 11);
	StackTraverse(L);
}
