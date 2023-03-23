#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int ele;
    struct Node* l;
    struct Node* r;
} node;
node **graph;
int graphSize = 0;
node* makeNode(int e)
{
    node *n = (node *)malloc(sizeof(node));
    n->ele = e;
    n->l = NULL;
    n->r = NULL;
    return n;
}


int count(node* n, int* opcount){
    if(!n) return 0;
    (*opcount)++;
    return 1 + count(n->l,opcount) + count(n->r,opcount); 
}
void main(){
    node n = *makeNode(1);
    n.l = makeNode(2);
    n.l->l = makeNode(3);
    n.l->r = makeNode(4);
    n.r = makeNode(6);
    int opcount = 0;
    int county= count(n.l->l,&opcount);
    printf("%d %d",county, opcount); 
}