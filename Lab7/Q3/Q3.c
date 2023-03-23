#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN(x,y) (x<y)?x:y
int arr[] = {2,5,3,6,7,0,9};
int len = 7;


void printy(int* arr, int l){
    for(int i =0;i<l; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void mergsort(int* a, int l, int* opcount){
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
    mergsort(a,j,opcount);
    mergsort(a+j+1, l-j-1,opcount);
    
}

int* combine(int* a ,int al, int*b , int bl){
    printy(a,al);
    printy(b,bl);
    int* ret = calloc(al+bl, sizeof(int));
    int i =0, j =0, itr =0;
    while(itr<al+bl){
    if(i==al-1){
        for(;itr<al+bl;itr++,j++){ret[itr] = b[j];}
    }
    else if(j==bl-1){
        for(;itr<al+bl;itr++,i++){ret[itr] = a[i];}
    }
    else {
        ret[itr] = MIN(a[i],b[j]);
        itr++;
        (a[i]<b[j])?i++:j++;
    }}
    return ret;
}

int* mergesort(int* a, int l, int* opcount){
    printf("Entered with length %d and arr = ", l);
    printy(a,l);
    if(l>1){
       return combine(mergesort(a,ceil((double)l/2.0),opcount),ceil((double)l/2.0f),mergesort(a+(int)floor((double)l/2.0),floor((double)l/2.0f),opcount),floor((double)l/2.0f));
    }
    return a;
    
}

    int main(){
        int opcount = 0;
        mergsort(arr,len,&opcount);
        for(int i =0;i<7;i++){
            printf("%d ",arr[i]);
        }
        return 0;
    }