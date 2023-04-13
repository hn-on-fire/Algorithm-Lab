
#include <stdio.h>
#define max(x,y) (x>y)?x:y
#define no 3

int knapSack(int W, int wt[], int val[], int n, int mat[][50])
{
    // Base Case
    if (n == 0 || W == 0){
        mat[n][W] = 0;
        return 0;
    }

    if (wt[n - 1] > W){
        mat[W][n] =  knapSack(W, wt, val, n - 1,mat);
        return mat[n][W];
    }

    else{
        mat[n][W] = max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1,mat),
            knapSack(W, wt, val, n - 1,mat));
            return mat[n][W];}
}
 
int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int matty[4][50] = {0};
    printf("%d", knapSack(W, weight, profit, no, matty));
    return 0;
    }