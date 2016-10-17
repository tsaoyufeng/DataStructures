#include <stdio.h> 


void insertion_sort( int *a, int size){
	int i, j, k;
	for( i = 1; i < size; i++ ){
		k = a[i];//��ȡ��i��Ԫ�� 
		j = i - 1;
		while( (j >= 0)&&(k < a[j]) ){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = k;
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
	printf("�������������鳤�ȣ�");
	scanf("%d",&size);
	int i = 0;
	int a[size];
	while(i<size) {
		scanf("%d",a+i);
		i++;
	}
	printf("unsorted array:");
	Traverse(a,size);
	insertion_sort(a,size);
	printf("sorted array:  ");
	Traverse(a,size);
}
