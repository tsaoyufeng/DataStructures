#include<stdio.h> 
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int bool;
typedef int E;
typedef struct NODE {
	struct NODE *next; //next pointer field
	int data; //data field
} Node, *LinkedList;


//
LinkedList initLinkedList(){
	LinkedList head = (LinkedList)malloc(sizeof(Node));
	if (head == NULL) {
		exit(0);
	}
	head->next = NULL;
	return head;
}

bool add(LinkedList L, E element) {
	LinkedList new_node = (LinkedList)malloc(sizeof(Node));
	if (new_node == NULL) {
		exit(0);
	}
	LinkedList cursor = L;
	while (cursor->next != NULL) {
		cursor = cursor->next;	
	}
	new_node->next = NULL;
	new_node->data = element;
	cursor->next = new_node;
	return TRUE;
}



bool addFirst(LinkedList L, E element) {
	LinkedList new_node = (LinkedList)malloc(sizeof(Node));
	if (new_node == NULL) {
		exit(0);
	}
	new_node->data = element;
	new_node->next = L->next;
	L->next = new_node;
	return TRUE;
}



bool insert(LinkedList L, int index, E element) {
	LinkedList cursor;
	cursor = L;
	for (int i = 0; i < index; i++) {
		cursor = cursor->next;
	}
	LinkedList new_node = (LinkedList)malloc(sizeof(Node));
	new_node->data = element;
	new_node->next = cursor->next;
	cursor->next = new_node;
	printf("insert\n");
	printf("new_node->data=%d\n", new_node->data);
	return TRUE;
}



void clear() {
	
}



E get(LinkedList L, int index) {
	LinkedList cursor = L;
	for (int i = 0; i <= index; i++){
		cursor = cursor->next;
	}
	return cursor->data;
}



int indexOf(LinkedList L, E element) {
	LinkedList cursor = L;
	for (int i = 0; i < size(L); i++) {
		cursor = cursor->next;
		if (cursor->data == element) {
			return i;
		}
	}
	return -1;
}



E del(LinkedList L, int index) {
	LinkedList cursor = L;
	for (int i = 0; i < index; i++){
		cursor = cursor->next;
	}
	E del = cursor->next->data;
	cursor->next = cursor->next->next;
	return del;
}



E set(LinkedList L, int index, E element){
	LinkedList cursor = L;
	for (int i = 0; i <= index; i++){
		cursor = cursor->next;
	}
	E pre = cursor->data;
	cursor->data = element;
	return pre;
}



bool isEmpty(LinkedList L) {
	if (L->next == NULL) {
		return TRUE;
	}
	return FALSE;
}

int size(LinkedList L) {
	int i = 0;
	LinkedList cursor = L->next;
	while (TRUE) {
		cursor = cursor->next;
		++i;
		if (cursor->next == NULL) {
			++i;
			break;
		}
	}
	return i;
}



void printList(LinkedList L) {
	LinkedList cursor = L->next;
	while (TRUE) {
		printf("%d", cursor->data);
		cursor = cursor->next;
		if(cursor->next == NULL) {
			printf("%d", cursor->data);
			break;
		}
	}
	printf("\n");
}



void main(){
	LinkedList L = initLinkedList();
	insert(L, 0, 5);
	insert(L, 0, 4);
	insert(L, 0, 3);
	insert(L, 0, 2);
	printList(L);
	add(L, 6);
	add(L, 7);
	add(L, 8);
	add(L, 9);
	printList(L);
	addFirst(L, 1);
	addFirst(L, 0);
	printList(L);
	printf("get=%d\n",get(L, 9));
	set(L, 4, 0);
	printList(L);
	printf("size=%d\n", size(L));
	del(L, 4);
	printList(L);
	printf("indexof9=%d\n", indexOf(L, 9));
}
////在带头结点的单链线性表L（L为头指针，单链表可由头指针唯一确定）中第i个位置之前插入元素e 
//int insert( Node *root, int i, int e ){
//	Node *cursor, *new_node;
//	cursor = root;
//	int j = -1;
//	while ( cursor && j<i-1 ){
//		cursor = cursor->link;
//		j++;
//	} 
//	//if ( !p || j>i-1 ) return 0;
//	new_node = (Node *)malloc(sizeof(Node));
//	new_node->value = e;
//	new_node->link = cursor->link;
//	cursor->link = new_node;
//	return TRUE;
//}
//
////删除第i个元素，由e返回 
//int ListDelete(Node *root, int i) {
//	Node *cursor, *q;
//	cursor = root;
//	int j = -1;
//	while( cursor->link && j<i-1){//令cursor 指向i的前驱 
//		cursor = cursor->link;
//		j++;
//	}
//	//if(!(p->next) || j>i-1) return 0;
//	q = cursor->link;//q指向第i个元素 
//	cursor->link = q->link;//cursor指向i的后驱 
//	//*e = q->data;
//	//free(q);//释放结点 
//	return q->value;
//}
//
////获取第i个元素，由e返回 
//int GetElem( LinkList L, int i, ElemType *e) {
//	LinkList p;
//	p = L->next;
//	int j = 1;
//	while( p && j<i){
//		p = p->next;
//		j++;
//	}
//	if( !p || j>i) return 0;//第i个元素不存在
//	*e = p->data;
//	return 1; 
//}
 

