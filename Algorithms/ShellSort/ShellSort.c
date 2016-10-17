#include <stdio.h>


void shell_sort(int *a, int size){
	int i, j, inc, temp;//inc为希尔排序增量
	inc = size/2;
	while(inc >0) {
		for(i=0; i<size; i++){//插入排序 
			j = i;
			temp = a[i];
			while((j>=inc) && (a[j-inc]>temp)){
				a[j] = a[j-inc];
				j = j - inc;
			}
			a[j] = temp;
		}
		if(inc/2 !=0) {
			inc = inc/2;
		}else if( inc == 1){
			inc = 0;
		}else{
			inc = 1;
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
	shell_sort(a,size);
	printf("sorted array:  ");
	Traverse(a,size);
}
