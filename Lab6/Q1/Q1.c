#include <stdio.h>
#include <stdlib.h>

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

node* in(int ele, node* s, node*e){
	for(node* p = s;p<=e;p++){
		if(p->nodeNum==ele) return p;
	}
	return NULL;
}
void top(node *g, short *v, int i, int *ret, int* ptr)
{
    if (!v[i])
    {
        v[i] = 1;
        for (int j = 0; j < g[i].edgeNum; j++)
        {
            top(g, v, g[i].edges[j],ret,ptr);
        }
        ret[(*ptr)++] = g[i].nodeNum;
    }
}

void main()
{
    node* g = (node*)calloc(6, sizeof(node));
    int z[] = {}, o[] = {}, two[]={3}, three[]={1}, four[] = {0,1}, five[]={2,0};
    short v[6]={0}; 
    int ret[6] = {0};
    int itr = 0;
    g[0] = *makeNode(z,0,0); 
    g[1] = *makeNode(o,1,0);
    g[2] = *makeNode(two,2,1);
    g[3] = *makeNode(three,3,1);
    g[4] = *makeNode(four,4,2);
    g[5] = *makeNode(five,5,2);
    for(int i=0;i<6;i++)
    top(g,v,i,ret,&itr);
    for(int i=5;i>=0;i--){
        printf("%d ", ret[i]);
    }
}