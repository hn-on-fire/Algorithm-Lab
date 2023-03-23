#include <stdio.h>
#include <stdlib.h>
 typedef struct Node{
 	int nodeNum;
 	struct Node* l;
    struct Node* r; 
    short bf;
 } node;
node* makeNode(int num){
	node* n = (node*)malloc(sizeof(node));
	n->l = NULL;
	n->r= NULL;
	n->nodeNum= num;
	return n;
}
int getDepth(node* n){
    if(!n) return 0;
    int ele = n->nodeNum;
    printf("%d:: node\n" , ele);
    int l = getDepth(n->l);
    int r = getDepth(n->r);
    return l>r?l+1:r+1;
}
void  calcBF(node* n){
    if(!n)return;
    int ele = n->nodeNum;
    //int ld = getDepth(n->l);
    //int rd = getDepth(n->r);
    n->bf = getDepth(n->l) - getDepth(n->r);
    calcBF(n->l); calcBF(n->r);
}
void tp(node* n){
    if(!n) return;
    printf("Ele: %d, BF: %d\n",n->nodeNum, n->bf);
    tp(n->l);
    tp(n->r);
}
void main(){
    node* n = makeNode(11);
    n->r = makeNode(5);
    n->r->r = makeNode(3);
    n->r->r->l = makeNode(7);
    n->l = makeNode(15);
    calcBF(n);
    tp(n);
}
