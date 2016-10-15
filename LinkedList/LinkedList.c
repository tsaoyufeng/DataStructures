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

//在带头结点的单链线性表L（L为头指针，单链表可由头指针唯一确定）中第i个位置之前插入元素e 
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

//删除第i个元素，由e返回 
int ListDelete(LinkList L, int i, ElemType *e) {
	LinkList p, q;
	p = L;
	int j = 0;
	while( p->next && j<i-1){//令p 指向i的前驱 
		p = p->next;
		j++;
	}
	if(!(p->next) || j>i-1) return 0;
	q = p->next;//q指向第i个元素 
	p->next = q->next;//p指向i的后驱 
	*e = q->data;
	free(q);//释放结点 
	return 1;
}

//获取第i个元素，由e返回 
int GetElem( LinkList L, int i, ElemType *e) {
	LinkList p;
	p = L->next;
	int j = 1;
	while( p && j<i){
		p = p->next;
		j++;
	}
	if( !p || j>i) return 0;//第i个元素不存在
	*e = p->data;
	return 1; 
}
 
int main(){
	int N;
	ElemType X;
	LinkList L;
	int gete;
	int dele;
	L = InitList();
	scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        int flag = ListInsert(L, 1, X);
        if ( flag==0 ) printf("Wrong Answer\n");
    }
	for ( LinkList P=L->next; P; P = P->next ) printf("%d ", P->data);
	ListDelete( L, 1, &dele);
	printf("\n%d", dele);
	GetElem(L, 1, &gete);
	printf("\n%d", gete);
    return 0;
}
