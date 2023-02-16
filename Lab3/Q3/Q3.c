#include<stdio.h>
    
    short isSubsetsum(int arr[],int n,int sum){
        if(sum==0){
            return 1;
        }
        if(n==0 & sum!=0){
            return 0;
        }
        if(arr[n-1]>sum){
            return isSubsetsum(arr,n-1,sum);
        }
        return isSubsetsum(arr,n-1,sum) || isSubsetsum(arr,n-1,sum-arr[n-1]);
    }
    
    short partition(int arr[],int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        return isSubsetsum(arr,n,sum/2);
    }
    
    int main(){
        int arr[] = {1,2,6,7};
        int n=4;
        if(partition(arr,n)){
        	printf("True\n");
        }else{
        	printf("False\n");
        }
        
        return 0;
    }
