#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100//�洢�ռ��ʼ������
#define STACKINCREMENT 10//�洢�ռ�������� 

typedef int ElemType;
 
 
typedef struct{
	ElemType *base;//ջ��ָ�룬��ջ����ǰ�����ٺ�base��ֵΪNULL 
	ElemType *top;//ջ��ָ�� 
	int stacksize;//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}Stack;

//����һ����ջ 
int InitStack( Stack *S){
	S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if( !S->base) exit(0);//�洢����ʧ��
	S->top = S->base;
	S->stacksize =  STACK_INIT_SIZE;
	return 1;
}

//����ջ 
int DestroyStack( Stack *S ){
	free(S->base);
}


int ClearStack( Stack *S ){
	S->top = S->base;
	return 1;
}


int StackEmpty( Stack S ){
	if(S.top == S.base){
		return 1;//ջΪ�շ���1 
	}else{
		return 0;//ջ��Ϊ�շ���0 
	}
	
}


int StackLength( Stack S){
	return S.stacksize;
}

//��ȡջ��Ԫ�أ���e���� 
int GetTop( Stack S, ElemType *e){
	if( S.top == S.base) return 0;//ջΪ�� 
	*e = *(S.top-1) ;
	return 1;
}


int Push( Stack *S, ElemType e){
	if(S->top - S->base >= S->stacksize){
		S->base = (ElemType *)realloc ( S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));//׷�Ӵ洢�ռ� 
		if(!S->base) exit(0);//�洢����ʧ��
		S->top = S->base + S->stacksize;
		S->stacksize = S->stacksize + STACKINCREMENT; 
	}
	*S->top = e;
	S->top++;
	return 1;	
}


int Pop( Stack *S, ElemType *e){
	if(S->top == S->base) return 0;
	*e = *(S->top-1);
	S->top--;
	return 1;
}


void main(){
	Stack S;
	ElemType pope;
	ElemType gettope;
	InitStack(&S);
	for(int i = 0; i<= 4; i++){
		Push(&S, i);
	}
	for(int i = 1; i<=S.top-S.base; i++){
		printf("%d", *(S.top-i));
	}
	Pop(&S, &pope);
	printf("\n%d\n", pope);
	GetTop( S, &gettope);
	printf("%d", gettope);
	
	
}


