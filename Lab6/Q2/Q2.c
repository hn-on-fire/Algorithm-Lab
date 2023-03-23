#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x >= y) ? x : y);
typedef struct Node
{
    int nodeNum;
    int *edges;
    int edgeNum;
} node;
node **graph;
int graphSize = 0;
node *makeNode(int *e, int num, int edges)
{
    node *n = (node *)malloc(sizeof(node));
    n->edges = e;
    n->edgeNum = edges;
    n->nodeNum = num;
    return n;
}
void print(short* v){
    for(int i=0;i<6;i++)
    printf("%d ", v[i]);
    printf("\n");
}
int dfs(int fr,int to, node *graph,short* v, int cost, short* flag)
{
    print(v);
    printf("fr-%d to-%d\n",fr,to);
    if (fr == to){
        printf("returning %d\n", cost);
        *flag = 1;
        return cost;
    }
    v[fr] = 1;
    for(int i =0;i<graph[fr].edgeNum;i++){
        if(!v[graph[fr].edges[i]])
        cost = MAX(cost,dfs(graph[fr].edges[i],to,graph,v,cost+1,flag));
        //printf("%d cost", cost);
    }
    return (*flag)?cost:0;

}
void main(){
      node* g = (node*)calloc(6, sizeof(node));
    int z[] = {1}, o[] = {0,2,3}, two[]={1,4}, three[]={1}, four[] = {5,2}, five[]={4};
    short v[6]={0}; 
    int ret[6] = {0};
    int itr = 0;
    g[0] = *makeNode(z,0,2); 
    g[1] = *makeNode(o,1,3);
    g[2] = *makeNode(two,2,2);
    g[3] = *makeNode(three,3,1);
    g[4] = *makeNode(four,4,2);
    g[5] = *makeNode(five,5,1);
    short flag =0;
    int cost = 0;
    for(int i=0;i<5;i++){
        short v[6] = {0};
        for(int j=0;j<5;j++){
            int d = dfs(i,j,g,v,0,&flag);
            cost = cost>d?cost:d;
        }
    }
    //short flag = 0;
    printf("%d COST", cost+1);
    //cost = dfs(5,1,g,v,0,&flag);
    //printf("%d \n", MAX(3,2));
}
