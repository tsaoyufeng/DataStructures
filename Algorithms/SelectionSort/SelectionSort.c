#include <stdio.h>

void selection_sort( int *a, int size){
	int i, j, min;
	for (i = 0; i < size - 1; i++ ){
		min = i;
		for ( j = i + 1; j < size; j++){//Find the minimum element in the list.
			if( a[j] < a[min] ){
				min = j;
			}
		}
		int temp;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
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
	selection_sort(a,size);
	printf("sorted array:  ");
	Traverse(a,size);
}
