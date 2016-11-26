#include <stdio.h> 
#include <stdlib.h> 

#define LIST_INIT_CAPACITY 10//存储空间的初始分配量
#define LIST_INCREMENT 10//存储空间的分配增量 
#define TRUE 1
#define FALSE 0


typedef int bool;
typedef int E;//元素类型 


typedef struct {
	E *base;//基址
	int size;//当前元素个数 
	int capacity;//当前分配的存储容量（以sizeof(ElemType)为单位） 
}ArrayList; 

//Constructs an empty list with an initial capacity of ten.
ArrayList initArrayList() {
	ArrayList L;
	L.base = (E *)malloc(LIST_INIT_CAPACITY * sizeof(E));
	if(!L.base) {
		exit(0); //存储分配失败 ，退出
	}
	L.size = 0;
	L.capacity = LIST_INIT_CAPACITY; 
	return L;
}

//Appends the specified element to the end of this list.
void append(ArrayList *L, E element) {
	if (L->size >= L->capacity) {
		E *new_base = (E *)realloc(L->base, (L->capacity + LIST_INCREMENT) * sizeof(E));
		if(!new_base) {
			exit(0);
		}
		L->base = new_base;//新基址 
		L->capacity = L->capacity + LIST_INCREMENT;
	}
	int index = L->size;
	L->base[index] = element;
	++L->size;
}

//Inserts the specified element at the specified position in this list.
bool insert(ArrayList *L, int index, E element) {
	if (index < 0 || index > L->size) {
		return FALSE;
	}
	if (L->size >= L->capacity) {
		E *new_base = (E *)realloc(L->base, (L->capacity + LIST_INCREMENT) * sizeof(E));
		if(!new_base) {
			exit(0);
		}
		L->base = new_base;//新基址 
		L->capacity = L->capacity + LIST_INCREMENT;
	}
	int cursor = L->size - 1;
	while (cursor >= index) {
		L->base[cursor + 1] = L->base[cursor];
		--cursor;
	}
	L->base[index] = element;
	++L->size;
	return TRUE;
}

//Removes all of the elements from this list.
bool clear(ArrayList *L) {
	L->size = 0;
	return TRUE;
}

//Returns the element at the specified position in this list.
E get(ArrayList L, int index) {
	if (index < 0 || index > L.size - 1) {
		return FALSE;
	}
	return L.base[index];
}

//Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.
int indexOf(ArrayList L, E element) {
	for (int i = 0; i <= L.size - 1; i++) {
		if (L.base[i] == element) {
			return i;
		}
	}
	return -1;
}

//Returns true if this list contains no elements.
bool isEmpty(ArrayList L) {
	if (L.size == 0) {
		return TRUE;
	} else {
		return FALSE;
	}
}

//Removes the element at the specified position in this list.
E delete(ArrayList *L, int index) {
	if (index < 0 || index > L->size - 1) {
		exit(0);
	}
	E del = L->base[index];
	int cursor = index;
	while (cursor <= L->size - 1) {
		L->base[cursor] = L->base[cursor + 1];
		++cursor;
	}
	--L->size;
	return del;
}

//Replaces the element at the specified position in this list with the specified element.
E set(ArrayList *L, int index, E element) {
	if (index < 0 || index > L->size - 1) {
		exit(0);
	}
	E pre = L->base[index];
	L->base[index] = element;
	return pre;
}

//Returns the number of elements in this list.
int size(ArrayList L) {
	return L.size;
}

bool destroy(ArrayList *L) {
	free(L->base);
	return TRUE;
}
void printList(ArrayList L) {
	for (int i = 0; i <= L.size - 1; i++) {
		printf("%d", L.base[i]);
	}
	printf("\n");
}

void main(){
	ArrayList L = initArrayList();
	append(&L, 3);
	append(&L, 2);
	append(&L, 2);
	append(&L, 4);
	printList(L);
	printf("indexOf5=%d\n", indexOf(L, 5));
	E cc = delete(&L, 0);
	printList(L);
	printf("cc=%d", cc);
	
}




