
#include <stdio.h>
void matMul(int mat1[][100], int mat2[][100], int m, int n, int q, int ans[][100]){
	for(int i=0; i<m;i++){
		for(int j=0;j<q; j++){
			int temp=0;
			for(int k =0;k<n;k++){
				temp+= mat1[i][k] * mat2[k][j]; 	
			}
			ans[i][j]=temp;
		}
	}
}
short check(int n, int p){
	return n == p;
}
void main(){
	int m = 2,n = 2,p = 2,q = 3;
	int mat1[2][2] = {{1,0},{0,1}};
	int mat2[2][3] = {{1,1},{1,1}};
	
	if(!check(n,p)){
		printf("Cannot Multiply Matrices\n");
	}
	else{
		int ans[m][100];
		matMul(mat1,mat2,m,n,q,ans);
		for(int i= 0;i<m;i++){
			for(int j=0;j<q;j++){
				printf("%d ",ans[i][j]);
			}
			printf("\n");
		}


	}

}