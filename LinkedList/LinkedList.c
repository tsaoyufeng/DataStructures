#include<stdio.h> 
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int ElemType;

typedef struct NODE {
	ElemType data;//������ 
	struct NODE *next;//ָ���� 
} Node, *LinkList;


//����һ���յ��������� 
LinkList InitList(){
	LinkList L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
	return L;
}

//�ڴ�ͷ���ĵ������Ա�L��LΪͷָ�룬���������ͷָ��Ψһȷ�����е�i��λ��֮ǰ����Ԫ��e 
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

//ɾ����i��Ԫ�أ���e���� 
int ListDelete(LinkList L, int i, ElemType *e) {
	LinkList p, q;
	p = L;
	int j = 0;
	while( p->next && j<i-1){//��p ָ��i��ǰ�� 
		p = p->next;
		j++;
	}
	if(!(p->next) || j>i-1) return 0;
	q = p->next;//qָ���i��Ԫ�� 
	p->next = q->next;//pָ��i�ĺ��� 
	*e = q->data;
	free(q);//�ͷŽ�� 
	return 1;
}

//��ȡ��i��Ԫ�أ���e���� 
int GetElem( LinkList L, int i, ElemType *e) {
	LinkList p;
	p = L->next;
	int j = 1;
	while( p && j<i){
		p = p->next;
		j++;
	}
	if( !p || j>i) return 0;//��i��Ԫ�ز�����
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
