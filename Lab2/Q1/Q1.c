#include <stdio.h>
#include <stdlib.h>
#define MIN(x,y) x>y?y:x

int GCD(int x, int y){
int opcount = 0, gcd =1;
for(int i = MIN(x,y);i>0;i--, opcount++)
	if(x%i ==0 && y%i ==0){
		gcd = i;
		break;
	}
printf("%d,", opcount);
return x+y;
}
int main(){
	int a,b;
	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);
	for(int i=0;i<15;i++)
	printf("%d\n", GCD(rand()%30000 +1 ,rand()%300000+1));
return 0;
}
