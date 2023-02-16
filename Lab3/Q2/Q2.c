#include<stdio.h>
#include<stdlib.h>

int match(int s1, int s2, char* w1, char* w2){
	int opcount=0;
	for (int i =0;i<s2-s1+1;i++){
		short flag =1;
		for(int j =0;j<s1; j++){
			opcount++;
			if(*(w2+j)!=*(w1+j)){
				flag =0;
				break;
			}
		}
		if(flag==1){
			return opcount;
		}
	}
	return opcount;
}

void main(){
	char a[2] = {'a', 'b'};
	char b[1] = {'b'};
	printf("%d,%d\n",3,match(1,2,b,a));	
	char c[3] = {'a', 'a','c'};
	char d[1] = {'c'};
	printf("%d,%d\n",4,match(1,3,d,c));	
	char e[4] = {'a', 'a','a','l'};
	char f[2] = {'a','l'};
	printf("%d,%d\n",6,match(2,4,f,e));	
	char g[5] = {'a', 'a','a','a','l'};
	char h[3] = {'a','a','l'};
	printf("%d,%d\n",8,match(3,5,h,g));
	char i[6] = {'a', 'a','a','a','a','k'};
	char j[3] = {'a','a','k'};
	printf("%d,%d\n",9,match(3,6,j,i));	
	char k[7] = {'a', 'a','a','a','a','a','k'};
	char l[4] = {'a','a','a','k'};
	printf("%d,%d\n",11,match(4,7,l,k));
	char m[8] = {'a', 'a','a','a','a','a','a','k'};
	char n[5] = {'a','a','a','a','k'};
	printf("%d,%d\n",13,match(5,8,n,m));
	char o[9] = {'a', 'a','a','a','a','a','a','a','k'};
	char p[5] = {'a','a','a','a','k'};
	printf("%d,%d\n",14,match(5,9,p,o));

}