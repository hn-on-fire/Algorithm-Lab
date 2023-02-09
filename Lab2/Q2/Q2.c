#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) x>y?y:x
 short isPrime(int x, int* count){
	for(int i = x/2;i>1;i--, *count++)
		if(x%i ==0)
			return 0;
	return 1;
}
 int GCD(int m, int n){
	int count = 0;
	int fac = MIN(m,n);
	int gcd =1;
	for(int i = fac;i>1;i--, count++){
		if(isPrime(i,&count))
			while(m%i ==0 && n%i==0)
				{m = m/i; n= n/i; gcd*=i;}
	}
	printf("%d,", count);
	return m+n;
}

int main(){
	for(int i=0;i<15;i++)
	printf("%d\n",GCD(rand()%2000+1,rand()%2000+1));
	return 0;
}
