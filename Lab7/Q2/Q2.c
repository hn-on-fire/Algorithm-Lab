#include <stdio.h>
#include <stdlib.h>

int arr[] = {2,5,3,6, -3, 78, 0};
int len = 7;
void printy(int* arr, int l){
    for(int i =0;i<l; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void quicksort(int* a, int l, int* opcount){
    printy(a,l);
    printf("Entered with length %d\n",l);
    if (l<=1)return;
    int i = 1,j = l-1,count =2;
    while(j>=i){
            printf("%di %dj \n", a[i],a[j]);
    for(;i<l;i++){
        (*opcount)++;
        if (a[i]>*a){
            printf("In Break i = %d, a[i] = %d, *a = %d\n", i,a[i],*a);
            break;
        }
    }
    for(;j>0;j--){
        printf("j = %d, a[j] = %d \n", j,a[j]);
        (*opcount)++;
        if (a[j]<*a){
            printf("In Break j = %d, a[j] = %d \n", j,a[j]);
            break;
        }
    }
    if(j>i){
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    else{
        int t = a[0];
        a[0] = a[j];
        a[j] = t;
    }
    count--;
    }
    
    if(j<0)return;
    printy(a,l);
    quicksort(a,j,opcount);
    quicksort(a+j+1, l-j-1,opcount);
    
}

    void main(){
        int opcount = 0;
        quicksort(arr,len,&opcount);
        for(int i =0;i<len;i++){
            printf("%d ",arr[i]);
        }
    }