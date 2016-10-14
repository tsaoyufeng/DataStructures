#include <stdio.h> 
#include <stdlib.h> 

#define LIST_INIT_SIZE 100//�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10//�洢�ռ�ķ������� 
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define ERROR 1 
#define OK 0

typedef int bool;
typedef int ElemType;//Ԫ������ 
//����һ��˳��� 
typedef struct {
	ElemType *elem;//��ַ
	int length;//��ǰ���� 
	int listsize;//��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ�� 
}List; 

//��ʼ�� 
int InitList(List *L) {
	 L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	 if(!L->elem) exit(OVERFLOW);//�洢����ʧ�� ���˳�
	 L->length = 0;
	 L->listsize = LIST_INIT_SIZE; 
	 return OK;
}

// ���� 
int DestroyList(List *L){
	free(L->elem);
	L->length = 0;
	L->listsize = 0;
	return OK;
}

//����Ϊ�ձ� 
int ClearList(List *L){
	L->length = 0;
	return OK;
}

//�ж��Ƿ�Ϊ�� 
bool ListEmpty( List L){
	if(L.length == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}

//���س��ȣ�Ԫ�ظ����� 
int ListLength( List L){
	return L.length;
}

//��e����L�е�i������Ԫ�ص�ֵ 
int GetElem(List L, int i, ElemType *e){
	if(i < 1 || i > L.length+1) return ERROR;//iֵ���Ϸ�
	*e = L.elem[i-1];
	return OK;
}

//����L�е�һ����target�����ϵcompare()�� ����Ԫ�ص�λ�� 
int LocateElem(List L, ElemType target, int(*compare)(ElemType, ElemType)){
	for(int i = 0; i < L.length; i++){
		if((*compare)(L.elem[i], target)){
			return i+1;
		}
	}
}

//��pre_e����cur_e��ǰ�� 
int PriorElem(List L, ElemType cur_e, ElemType *pre_e){
	for(int i = 0; i < L.length; i++){
		if(L.elem[i] == cur_e){
			*pre_e = L.elem[i-1];
			return OK;
		}
	}
}

//��next_e����cur_e�ĺ���
int NextElem(List L, ElemType cur_e, ElemType *next_e){
	for(int i = 0; i < L.length; i++){
		if(L.elem[i] == cur_e){
			*next_e = L.elem[i+1];
			return OK;
		}
	}
}

//��˳���L�е�i��λ��֮ǰ�����µ�Ԫ��e 
int ListInsert( List *L, int i, ElemType e){
	ElemType *p;
	if(i < 1 || i > L->length+1) return ERROR;//iֵ���Ϸ�
	if(L->length >= L->listsize){//��ǰ�洢�ռ����������ӷ��� 
		ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)  return ERROR;//�洢����ʧ�� 
		L->elem = newbase;//�»�ַ 
		L->listsize = L->listsize + LISTINCREMENT;
	}
	ElemType *q = &(L->elem[i-1]) ;
	for(p = &(L->elem[L->length-1]); p >= q; --p){//ѭ������ 
		*(p+1) = *p;
	}
	*q = e;//����e 
	++L->length;//����1
	return OK; 
}

//��˳���L��ɾ����i��Ԫ�أ�����e������ֵ 
int ListDelete( List *L, int i, ElemType *e){
	ElemType *p, *q;
	if(i<1 || i>L->length) return ERROR;//iֵ���Ϸ�
	p = &(L->elem[i-1]) ;
	*e = *p;
	q = L->elem + L->length-1;//��βԪ�ص�λ��
	for(++p; p<=q; ++p) {
		*(p-1) = *p;
	}
	--L->length;
	return OK;
}

void ListTraverse(List L){
	for(int i=0; i< L.length; i++){
		printf("%d", L.elem[i]) ;
	} 
}

int equal(ElemType j, ElemType k){
	if(j == k){
		return TRUE;
	}else{
		return FALSE;
	}
}

void main(){
	List La;
	List Lb;
	InitList(&La);
	InitList(&Lb);
	ListInsert( &La, 1, 2);
	ListInsert( &La, 2, 3);
	ListInsert( &La, 3, 1);
	ListInsert( &La, 4, 4);
	ListTraverse(La);
	printf("\n");
	int locate = LocateElem(La, 2, equal);
	printf("%d\n", locate);
	int pre;
	PriorElem(La, 1, &pre);
	printf("%d\n", pre);
	int nex;
	NextElem(La, 1, &nex);
	printf("%d\n", nex);
}

//void Union(SqList *La, SqList Lb) {  // �㷨2.1
//  // �����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
//  int La_len,Lb_len,i;
//  ElemType e;
//  La_len = ListLength(La);          // �����Ա�ĳ���  
//  Lb_len = ListLength(Lb);
//  for (i=1; i<=Lb_len; i++) {
//    GetElem(Lb, i, e);              // ȡLb�е�i������Ԫ�ظ���e
//    if (!LocateElem(La, e, equal))  // La�в����ں�e��ͬ������Ԫ��
//      ListInsert(La, ++La_len, e);  // ����
//  }
//} // union

