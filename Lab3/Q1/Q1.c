#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
int bubble_sort1(int size, int* ptr){
	for(int i=0;i<size-1; i++)
		for(int j =0;j<size-i-1;j++){
			if(*(ptr+j)<*(ptr+j+1))
				swap(ptr+j, ptr+j+1);
			}
		}
int bubble_sort2(int size, int* ptr){
	int opcount =0;
	for(int i=0;i<size-1; i++)
		for(int j =0;j<size-i-1;j++){
			opcount++;
			if(*(ptr+j)>*(ptr+j+1)){
				swap(ptr+j, ptr+j+1);
				opcount++;
			}
			}
			return opcount;
		}

void main(){
	for(int i =0;i<15; i++){
		int num = rand()%100+1;
		int a[num];
		for(int j =0;j<num;j++)
			a[j] = rand()%100+1;
		bubble_sort1(num,a);
		printf("%d,%d\n", num, bubble_sort2(num,a));
	}
}