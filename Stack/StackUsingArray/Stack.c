#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100//存储空间初始分配量
#define STACKINCREMENT 10//存储空间分配增量 

typedef int ElemType;
 
 
typedef struct{
	ElemType *base;//栈底指针，在栈构造前和销毁后，base的值为NULL 
	ElemType *top;//栈顶指针 
	int stacksize;//当前已分配的存储空间，以元素为单位 
}Stack;

//构造一个空栈 
int InitStack( Stack *S){
	S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if( !S->base) exit(0);//存储分配失败
	S->top = S->base;
	S->stacksize =  STACK_INIT_SIZE;
	return 1;
}

//销毁栈 
int DestroyStack( Stack *S ){
	free(S->base);
}


int ClearStack( Stack *S ){
	S->top = S->base;
	return 1;
}


int StackEmpty( Stack S ){
	if(S.top == S.base){
		return 1;//栈为空返回1 
	}else{
		return 0;//栈不为空返回0 
	}
	
}


int StackLength( Stack S){
	return S.stacksize;
}

//获取栈顶元素，由e返回 
int GetTop( Stack S, ElemType *e){
	if( S.top == S.base) return 0;//栈为空 
	*e = *(S.top-1) ;
	return 1;
}


int Push( Stack *S, ElemType e){
	if(S->top - S->base >= S->stacksize){
		S->base = (ElemType *)realloc ( S->base, (S->stacksize + STACKINCREMENT) * sizeof(ElemType));//追加存储空间 
		if(!S->base) exit(0);//存储分配失败
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


