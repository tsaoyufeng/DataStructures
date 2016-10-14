#include <stdio.h> 
#include <stdlib.h> 

#define LIST_INIT_SIZE 100//存储空间的初始分配量
#define LISTINCREMENT 10//存储空间的分配增量 
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define ERROR 1 
#define OK 0

typedef int bool;
typedef int ElemType;//元素类型 
//定义一个顺序表 
typedef struct {
	ElemType *elem;//基址
	int length;//当前长度 
	int listsize;//当前分配的存储容量（以sizeof(ElemType)为单位） 
}List; 

//初始化 
int InitList(List *L) {
	 L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	 if(!L->elem) exit(OVERFLOW);//存储分配失败 ，退出
	 L->length = 0;
	 L->listsize = LIST_INIT_SIZE; 
	 return OK;
}

// 销毁 
int DestroyList(List *L){
	free(L->elem);
	L->length = 0;
	L->listsize = 0;
	return OK;
}

//重置为空表 
int ClearList(List *L){
	L->length = 0;
	return OK;
}

//判断是否为空 
bool ListEmpty( List L){
	if(L.length == 0){
		return TRUE;
	}else{
		return FALSE;
	}
}

//返回长度（元素个数） 
int ListLength( List L){
	return L.length;
}

//用e返回L中第i个数据元素的值 
int GetElem(List L, int i, ElemType *e){
	if(i < 1 || i > L.length+1) return ERROR;//i值不合法
	*e = L.elem[i-1];
	return OK;
}

//返回L中第一个与target满足关系compare()的 数据元素的位序 
int LocateElem(List L, ElemType target, int(*compare)(ElemType, ElemType)){
	for(int i = 0; i < L.length; i++){
		if((*compare)(L.elem[i], target)){
			return i+1;
		}
	}
}

//用pre_e返回cur_e的前驱 
int PriorElem(List L, ElemType cur_e, ElemType *pre_e){
	for(int i = 0; i < L.length; i++){
		if(L.elem[i] == cur_e){
			*pre_e = L.elem[i-1];
			return OK;
		}
	}
}

//用next_e返回cur_e的后驱
int NextElem(List L, ElemType cur_e, ElemType *next_e){
	for(int i = 0; i < L.length; i++){
		if(L.elem[i] == cur_e){
			*next_e = L.elem[i+1];
			return OK;
		}
	}
}

//在顺序表L中第i格位置之前插入新的元素e 
int ListInsert( List *L, int i, ElemType e){
	ElemType *p;
	if(i < 1 || i > L->length+1) return ERROR;//i值不合法
	if(L->length >= L->listsize){//当前存储空间已满，增加分配 
		ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase)  return ERROR;//存储分配失败 
		L->elem = newbase;//新基址 
		L->listsize = L->listsize + LISTINCREMENT;
	}
	ElemType *q = &(L->elem[i-1]) ;
	for(p = &(L->elem[L->length-1]); p >= q; --p){//循环后移 
		*(p+1) = *p;
	}
	*q = e;//插入e 
	++L->length;//表长增1
	return OK; 
}

//在顺序表L中删除第i个元素，并用e返回其值 
int ListDelete( List *L, int i, ElemType *e){
	ElemType *p, *q;
	if(i<1 || i>L->length) return ERROR;//i值不合法
	p = &(L->elem[i-1]) ;
	*e = *p;
	q = L->elem + L->length-1;//表尾元素的位置
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

//void Union(SqList *La, SqList Lb) {  // 算法2.1
//  // 将所有在线性表Lb中但不在La中的数据元素插入到La中
//  int La_len,Lb_len,i;
//  ElemType e;
//  La_len = ListLength(La);          // 求线性表的长度  
//  Lb_len = ListLength(Lb);
//  for (i=1; i<=Lb_len; i++) {
//    GetElem(Lb, i, e);              // 取Lb中第i个数据元素赋给e
//    if (!LocateElem(La, e, equal))  // La中不存在和e相同的数据元素
//      ListInsert(La, ++La_len, e);  // 插入
//  }
//} // union

