#include <stdio.h>

void heap_sort( int *a, int size){
	
}


void Traverse(int *a, int size){
	for(int i = 0; i<size; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
}

void main(){
	int size;
	printf("请输入您的数组长度：");
	scanf("%d",&size);
	int i = 0;
	int a[size];
	while(i<size) {
		scanf("%d",a+i);
		i++;
	}
	printf("unsorted array:");
	Traverse(a,size);
	heap_sort(a,size);
	printf("sorted array:  ");
	Traverse(a,size);
}
