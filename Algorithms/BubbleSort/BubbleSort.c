#include <stdio.h>

void bubble_sort(int *a, int size){
	int i, j;
	for(i=0; i<(size-1); i++){
		for(j=0; j<(size-(i+1)); j++){
			if(a[j] > a[j+1]){
				int temp;
				temp = a[j+1];
				 a[j+1] = a[j];
				 a[j] = temp;
			}
		}
	}
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
	bubble_sort(a,size);
	printf("sorted array:  ");
	Traverse(a,size);
}
