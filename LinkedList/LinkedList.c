#include<stdio.h> 
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int ElemType;

typedef struct NODE {
	ElemType data;//数据域 
	struct NODE *next;//指针域 
} Node, *LinkList;


//构建一个空的线性链表 
LinkList InitList(){
	LinkList L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	return L;
}

//在带头结点的单链线性表L中第i个位置之前插入元素e 
int ListInsert( LinkList L, int i, ElemType e ){
	LinkList p, s;
	p = L;
	int j = 0;
	while ( p && j<i-1 ){
		p = p->next;
		j++;
	} 
	if ( !p || j>i-1 ) return 0;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}
 
int main(){
	int N;
	ElemType X;
	LinkList L;
	L = InitList();
	scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        int flag = ListInsert(L, 1, X);
        if ( flag==0 ) printf("Wrong Answer\n");
    }
	for ( LinkList P=L->next; P; P = P->next ) printf("%d ", P->data);
    return 0;
}
